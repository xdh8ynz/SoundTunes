#ifndef SONG_H
#define SONG_H

#include <QObject>

class Song
{   
public:
    Song();
    Song(int song_id, int album_id, int duration,
         QString title, QString artist, QString genre, QString cover);

    ~Song();

    int getSongId() const;
    int getAlbumId() const;
    int getDuration() const;
    QString getTitle() const;
    QString getArtist() const;
    QString getGenre() const;
    QString getCover() const;

private:
    int m_song_id;
    int m_album_id;
    int m_duration;
    QString m_title;
    QString m_artist;
    QString m_genre;
    QString m_cover;
};

Q_DECLARE_METATYPE(Song)

#endif // SONG_H
