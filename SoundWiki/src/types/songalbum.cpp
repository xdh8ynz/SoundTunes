#include "songalbum.h"

Album::Album()
{
    m_album_id = -1;
    m_year = -1;
    m_count_tracks = -1;
    m_title = "";
    m_cover = "";
    m_genre = "";
}

Album::Album(int album_id,
             int year,
             int count_tracks,
             QString title,
             QString cover,
             QString genre)
{
    m_album_id = album_id;
    m_year = year;
    m_count_tracks = count_tracks;
    m_title = title;
    m_cover = cover;
    m_genre = genre;
}

Album::~Album()
{
}

QString Album::getCover() const
{
    return m_cover;
}

QString Album::getGenre() const
{
    return m_genre;
}

QString Album::getTitle() const
{
    return m_title;
}

int Album::getAlbumId() const
{
    return m_album_id;
}

int Album::getYear() const
{
    return m_year;
}

int Album::getCountTracks() const
{
    return m_count_tracks;
}
