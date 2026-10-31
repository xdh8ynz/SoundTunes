#ifndef YANDEXMUSICCLIENT_H
#define YANDEXMUSICCLIENT_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QTimer>
#include <memory>
#include "types/song.h"
#include "types/songalbum.h"

class YandexMusicClient : public QObject
{
    Q_OBJECT
public:
    explicit YandexMusicClient(QObject *parent = nullptr);
    ~YandexMusicClient();

    void searchSongs(QString query);
    void cancelSearch();
signals:
    void onSongsSearchFailed();
    void onSongsSearchSuccess(QList<Song> songs);
    void onNetworkError();
    void onServerError();

public slots:
    void onSongsReceived(QNetworkReply *reply);

private slots:
    void onSearchTimerFinished();

private:
    static constexpr int MaxCountSongsInList = 20;
    static constexpr int CoverSize = 600;
    static constexpr int SearchIntervalMs = 10000;
    static constexpr int MinNetworkCode = 0;
    static constexpr int MaxNetworkCode = 99;
    static constexpr int MinServerCode = 401;
    static constexpr int MaxServerCode = 499;

    std::unique_ptr<QNetworkAccessManager> m_manager;
    std::unique_ptr<QNetworkReply> m_reply;
    std::unique_ptr<QTimer> m_timer;

    QList<Song> parseSongsList(QString response);
    Song parseSongObject(QJsonObject song_object);
    Album parseSongAlbum(QJsonObject song_album_object);
    QString getArtistSongName(QJsonObject artist_object);
};

#endif // YANDEXMUSICCLIENT_H
