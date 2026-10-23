#include "yandexmusicclient.h"

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QDebug>
#include <memory>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

YandexMusicClient::YandexMusicClient(QObject *parent) : QObject(parent)
{
    m_manager.reset(new QNetworkAccessManager());
}

YandexMusicClient::~YandexMusicClient()
{
}

void YandexMusicClient::searchSongs(QString query)
{
    QNetworkRequest request;
    QUrl url;
    QUrlQuery url_query;

    url_query.addQueryItem("text", query);
    url_query.addQueryItem("page", 0);
    url_query.addQueryItem("type", "track");
    url_query.addQueryItem("nococrrect", "false");
    url.setUrl("https://api.music.yandex.net/search");
    url.setQuery(url_query);

    request.setUrl(url);
    request.setRawHeader("Accept", "application/json");

    QNetworkReply *reply = m_manager->get(request);

    connect(reply, &QNetworkReply::finished, this,
            [this, reply]()
            {
                onSongsReceived(reply);
            });

    connect(reply, &QNetworkReply::finished, reply, &QObject::deleteLater);
}

void YandexMusicClient::onSongsReceived(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NetworkError::NoError)
    {
        QString response = QString(reply->readAll());
        emit onSongsSearchSuccess(parseSongsList(response));
        return;
    }

    int code = static_cast<int>(reply->error());

    qDebug() << "Ошибка запроса";
    qDebug() << code;
    qDebug() << reply->errorString();

    if (code >= 0 && code <= 99)
    {
        // Сетевая ошибка
        emit onNetworkError();

    }
    else if (code >= 401 && code <= 499)
    {
        // Ошибка сервера
        emit onServerError();

    }
    else{
        // Другие ошибки
        emit onSongsSearchFailed();
    }
}

QList<Song> YandexMusicClient::parseSongsList(QString response)
{
    QList<Song> songs;

    QJsonDocument doc = QJsonDocument::fromJson(response.toUtf8());
    if (!doc.isObject())
    {
        return QList<Song>();
    }
    QJsonObject json_object = doc.object();

    QJsonValue result_value = json_object.value("result");
    if (!result_value.isObject())
    {
        return QList<Song>();
    }
    QJsonObject result_object = result_value.toObject();

    QJsonValue tracks_value = result_object.value("tracks");
    if (!tracks_value.isObject())
    {
        return QList<Song>();
    }
    QJsonObject tracks_object = tracks_value.toObject();

    QJsonValue results_value = tracks_object.value("results");
    if (!results_value.isArray())
    {
        return QList<Song>();
    }
    QJsonArray results_array = results_value.toArray();

    for (const QJsonValue &song_value : results_array)
    {
        if (!song_value.isObject())
        {
            continue;
        }
        QJsonObject song_object = song_value.toObject();

        Song song = parseSongObject(song_object);

        if (song.getSongId() == -1)
        {
            continue;
        }

        songs.append(song);

        if (songs.size() > MaxCountSongsInList)
        {
            break;
        }
    }

    return songs;
}

Song YandexMusicClient::parseSongObject(QJsonObject song_object)
{
    QJsonValue song_id_value = song_object.value("id");
    if (!song_id_value.isDouble())
    {
        return Song();
    }
    int song_id = song_id_value.toInt();

    QJsonValue title_value = song_object.value("title");
    if (!title_value.isString())
    {
        return Song();
    }
    QString title = title_value.toString();

    QJsonValue duration_value = song_object.value("durationMs");
    if (!duration_value.isDouble())
    {
        return Song();
    }
    int duration = duration_value.toInt();

    QJsonValue albums_value = song_object.value("albums");
    if (!albums_value.isArray())
    {
        return Song();
    }
    QJsonArray albums_array = albums_value.toArray();

    Album song_album = Album();
    if (!albums_array.isEmpty())
    {
        QJsonValue first_album_value = albums_array.first();
        if (!first_album_value.isObject())
        {
            return Song();
        }
        QJsonObject first_album_object = first_album_value.toObject();
        song_album = parseSongAlbum(first_album_object);
    }

    QJsonValue artists_value = song_object.value("artists");
    if (!artists_value.isArray())
    {
        return Song();
    }
    QJsonArray artists_array = artists_value.toArray();

    QString artist = "";

    if (!artists_array.isEmpty())
    {
        QJsonValue artist_value = artists_array.first();
        if (!artist_value.isObject())
        {
            return Song();
        }
        QJsonObject artist_object = artist_value.toObject();
        artist = getArtistSongName(artist_object);
    }

    return Song(song_id, duration, title, artist, song_album);
}

Album YandexMusicClient::parseSongAlbum(QJsonObject song_album_object)
{
    QJsonValue genre_value = song_album_object.value("genre");
    if (!genre_value.isString())
    {
        return Album();
    }
    QString genre = genre_value.toString();

    QJsonValue album_id_value = song_album_object.value("id");
    if (!album_id_value.isDouble())
    {
        return Album();
    }
    int album_id = album_id_value.toInt();

    QJsonValue cover_value = song_album_object.value("coverUri");
    if (!cover_value.isString())
    {
        return Album();
    }
    QString cover = cover_value.toString();
    cover.replace("%%", QString::number(CoverSize) + "x" + QString::number(CoverSize));
    cover = "https://" + cover;

    QJsonValue album_year_value = song_album_object.value("year");
    if (!album_year_value.isDouble())
    {
        return Album();
    }
    int album_year = album_year_value.toInt();

    QJsonValue album_count_tracks = song_album_object.value("trackCount");
    if (!album_count_tracks.isDouble())
    {
        return Album();
    }
    int count_tracks = album_count_tracks.toInt();

    QJsonValue nameValue = song_album_object.value("title");
    if (!nameValue.isString())
    {
        return Album();
    }
    QString name = nameValue.toString();

    return Album(album_id, album_year, count_tracks, name, cover, genre);
}

QString YandexMusicClient::getArtistSongName(QJsonObject artist_object)
{
    QJsonValue artist_name_value = artist_object.value("name");
    if (!artist_name_value.isString())
    {
        return "";
    }
    return artist_name_value.toString();
}
