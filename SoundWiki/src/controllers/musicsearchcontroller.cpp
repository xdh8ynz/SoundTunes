#include "musicsearchcontroller.h"
#include "../types/song.h"

#include <QtDebug>
#include <QTimer>


MusicSearchController::MusicSearchController(QObject *parent): QObject(parent)
{
    m_song_model.reset(new SongModel());
    m_music_client.reset(new YandexMusicClient());
}

MusicSearchController::~MusicSearchController()
{

}

void MusicSearchController::searchSounds(QString query)
{
    m_song_model->clear();
    emit songModelChanged();

    m_music_client->searchSongs(query);
    QTimer::singleShot(3000, this, &MusicSearchController::onSearchFinished);
}

SongModel* MusicSearchController::songModel() const
{
    return m_song_model.get();
}

// TODO: change (обработчик сигнала от клиента)
// TODO + будет принимать параметр
void MusicSearchController::onSearchFinished()
{
    QList<Song> songs;
    songs.append(Song(0, 0, 293050,
                      "Digital Bath", "Deftones", "Alternative Metal", ""));
    songs.append(Song(2, 0, 393050,
                      "Phantom Bride", "Deftones", "Space Rock", ""));


    m_song_model->updateSongs(songs);
    emit songModelChanged();

    emit songSearchFinished();
}
