#ifndef SONGALBUM_H
#define SONGALBUM_H

#include <QObject>

class Album
{
public:
    Album();
    Album(int album_id,
          int year,
          int count_tracks,
          QString title,
          QString cover,
          QString genre);

    ~Album();

    QString getCover() const;
    QString getGenre() const;
    QString getTitle() const;
    int getAlbumId() const;
    int getYear() const;
    int getCountTracks() const;

private:
    QString m_cover;
    QString m_genre;
    QString m_title;
    int m_album_id;
    int m_year;
    int m_count_tracks;
};

Q_DECLARE_METATYPE(Album)

#endif // SONGALBUM_H
