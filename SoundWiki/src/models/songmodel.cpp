#include "songmodel.h"

#include <QObject>
#include <QDebug>
#include <QAbstractListModel>

SongModel::SongModel(QObject *parent): QAbstractListModel(parent)
{

}

SongModel::~SongModel()
{

}

int SongModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_songs.count();
}

QVariant SongModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    const Song song = m_songs[index.row()];

    switch (role) {
        case SongIdRole: {
            return song.getSongId();
        }
        case TitleRole: {
            return song.getTitle();
        }
        case ArtistRole: {
            return song.getArtist();
        }
        case GenreRole: {
            return song.getGenre();
        }
        case CoverRole: {
            return song.getCover();
        }
        case AlbumIdRole: {
            return song.getAlbumId();
        }
        case DurationRole: {
            return song.getDuration();
        }
        default: {
            return QVariant();
        }
    }
}

bool SongModel::isCorrectIndex(QModelIndex index)
{
    if (!index.isValid())
    {
        return false;
    }

    if (index.row() >= m_songs.count())
    {
        return false;
    }

    return true;
}

QHash<int, QByteArray> SongModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[SongIdRole] = "songId";
    roles[TitleRole] = "title";
    roles[ArtistRole] = "artist";
    roles[GenreRole] = "genre";
    roles[CoverRole] = "cover";
    roles[AlbumIdRole] = "albumId";
    roles[DurationRole] = "duration";
    return roles;
}


void SongModel::clear()
{
    beginResetModel();
    m_songs.clear();
    endResetModel();
}

void SongModel::updateSongs(QList<Song> songs)
{
    beginResetModel();
    m_songs.clear();
    m_songs.append(songs);
    endResetModel();
}

