#include "songalbum.h"

SongAlbum::SongAlbum()
{
    m_album_id = -1;
    m_cover = "";
    m_genre = "";
}

SongAlbum::SongAlbum(int album_id, QString cover, QString genre)
{
    m_album_id = album_id;
    m_cover = cover;
    m_genre = genre;
}

SongAlbum::~SongAlbum()
{

}

QString SongAlbum::getCover() const
{
    return m_cover;
}

QString SongAlbum::getGenre() const
{
    return m_genre;
}

int SongAlbum::getAlbumId() const{
    return m_album_id;
}
