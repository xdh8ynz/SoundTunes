#ifndef YANDEXMUSICCLIENT_H
#define YANDEXMUSICCLIENT_H

#include <QNetworkAccessManager>
#include <QJsonObject>
#include <memory>
#include "types/song.h"
#include "types/songalbum.h"

class YandexMusicClient: public QObject
{
    Q_OBJECT
public:
    explicit YandexMusicClient(QObject *parent = nullptr);
    ~YandexMusicClient();

    void searchSongs(QString query);
signals:
    void onSongsSearchFailed();
    void onSongsSearchSuccess(QList<Song> songs);

public slots:
    void onSongsReceived(QNetworkReply *reply);

private:
    static constexpr int MaxCountSongsInList = 50;
    static constexpr int CoverSize = 100;

    std::unique_ptr<QNetworkAccessManager> m_manager;

    QList<Song> parseSongsList(QString response);
    Song parseSongObject(QJsonObject song_object);
    Album parseSongAlbum(QJsonObject song_album_object);
    QString getArtistSongName(QJsonObject artist_object);
};

#endif // YANDEXMUSICCLIENT_H
