#ifndef SONG_H
#define SONG_H

#include <QObject>
#include "songalbum.h"

class Song
{   
public:
    Song();
    Song(int song_id,
         int duration,
         QString title,
         QString artist,
         Album album);

    ~Song();

    int getSongId() const;
    int getDuration() const;
    QString getTitle() const;
    QString getArtist() const;
    Album getAlbum() const;

private:
    int m_song_id;
    int m_duration;
    QString m_title;
    QString m_artist;
    Album m_album;
};

Q_DECLARE_METATYPE(Song)

#endif // SONG_H
