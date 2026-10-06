#include "song.h"

Song::Song()
{
    m_song_id = -1;
    m_album_id = -1;
    m_duration = -1;
    m_title = "";
    m_artist = "";
    m_genre = "";
    m_cover = "";
}

Song::Song(int song_id, int album_id, int duration,
     QString title, QString artist, QString genre, QString cover)
{
    m_song_id = song_id;
    m_album_id = album_id;
    m_duration = duration;
    m_title = title;
    m_artist = artist;
    m_genre = genre;
    m_cover = cover;
}

Song::~Song()
{

}

int Song::getSongId() const
{
    return m_song_id;
}

int Song::getAlbumId() const
{
    return m_album_id;
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

QString Song::getGenre() const
{
    return m_genre;
}

QString Song::getCover() const
{
    return m_cover;
}
