#include "musicsearchcontroller.h"
#include "../types/song.h"

#include <QtDebug>
#include <QTimer>

MusicSearchController::MusicSearchController(QObject *parent) : QObject(parent)
{
    m_song_model.reset(new SongModel());

    m_music_client.reset(new YandexMusicClient());
    QObject::connect(m_music_client.get(), &YandexMusicClient::onSongsSearchSuccess,
                     this, &MusicSearchController::onSearchFinished);
    QObject::connect(m_music_client.get(), &YandexMusicClient::onSongsSearchFailed,
                     this, &MusicSearchController::onSearchFailed);
}

MusicSearchController::~MusicSearchController()
{
}

void MusicSearchController::searchSounds(QString query)
{
    m_song_model->clear();
    emit songModelChanged();

    m_music_client->searchSongs(query);
}

SongModel *MusicSearchController::songModel() const
{
    return m_song_model.get();
}

void MusicSearchController::onSearchFinished(QList<Song> songs)
{
    m_song_model->updateSongs(songs);
    emit songModelChanged();
    emit songSearchFinished();
}

void MusicSearchController::onSearchFailed()
{
    qDebug() << "Не удалось получить список треков по запросу";
    emit songSearchFinished();
}
