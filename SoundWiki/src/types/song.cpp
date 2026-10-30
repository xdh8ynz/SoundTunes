#include "song.h"

Song::Song()
{
    m_song_id = -1;
    m_duration = -1;
    m_title = "";
    m_artist = "";
    m_path = "";
    m_album = Album();
}

Song::Song(int song_id,
           int duration,
           QString title,
           QString artist,
           Album album)
{
    m_song_id = song_id;
    m_duration = duration;
    m_title = title;
    m_artist = artist;
    m_album = album;
    m_path = "";
}

Song::~Song()
{
}

int Song::getSongId() const
{
    return m_song_id;
}

int Song::getDuration() const
{
    return m_duration;
}

QString Song::getTitle() const
{
    return m_title;
}

QString Song::getArtist() const
{
    return m_artist;
}

QString Song::getPath() const
{
    return m_path;
}

Album Song::getAlbum() const
{
    return m_album;
}

void Song::updatePath(QString path)
{
    m_path = path;
}
