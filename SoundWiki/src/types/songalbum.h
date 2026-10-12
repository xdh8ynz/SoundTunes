#ifndef SONGALBUM_H
#define SONGALBUM_H

#include <QObject>

class SongAlbum
{
public:
    SongAlbum();
    SongAlbum(int album_id, QString cover, QString genre);

    ~SongAlbum();

    QString getCover() const;
    QString getGenre() const;
    int getAlbumId() const;

private:
    QString m_cover;
    QString m_genre;
    int m_album_id;
};

#endif // SONGALBUM_H
