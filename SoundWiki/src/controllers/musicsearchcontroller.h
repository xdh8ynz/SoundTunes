#ifndef MUSICCONROLLER_H
#define MUSICCONROLLER_H

#include "../types/song.h"
#include "../models/songmodel.h"
#include "../yandexmusicclient.h"

#include <QObject>
#include <memory>

class MusicSearchController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(SongModel *songModel READ songModel NOTIFY songModelChanged)

public:
    explicit MusicSearchController(QObject *parent = nullptr);
    ~MusicSearchController();

    SongModel *songModel() const;

    Q_INVOKABLE void searchSounds(QString query);
    Q_INVOKABLE void clear();
    Q_INVOKABLE void cancelSearch();
signals:
    void songModelChanged();
    void songSearchFinished();
    void songSearchFailed();
    void serverError();
    void networkError();

private slots:
    void onSearchFinished(QList<Song> songs);
    void onSearchFailed();
    void onServerError();
    void onNetworkError();

private:
    std::unique_ptr<SongModel> m_song_model;
    std::unique_ptr<YandexMusicClient> m_music_client;
};

#endif // MUSICCONROLLER_H
