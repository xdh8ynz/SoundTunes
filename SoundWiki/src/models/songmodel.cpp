#include "songmodel.h"

#include <QObject>
#include <QDebug>
#include <QAbstractListModel>

SongModel::SongModel(QObject *parent) : QAbstractListModel(parent)
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
    if (!isCorrectIndex(index))
    {
        return QVariant();
    }

    const Song song = m_songs[index.row()];
    const Album album = song.getAlbum();

    switch (role)
    {
        case SongIdRole:
        {
            return song.getSongId();
        }
        case TitleRole:
        {
            return song.getTitle();
        }
        case ArtistRole:
        {
            return song.getArtist();
        }
        case GenreRole:
        {
            return album.getGenre();
        }
        case CoverRole:
        {
            return album.getCover();
        }
        case PathRole: {
            return song.getPath();
        }
        case DurationRole:
        {
            return song.getDuration();
        }
        case AlbumIdRole:
        {
            return album.getAlbumId();
        }
        case AlbumNameRole:
        {
            return album.getTitle();
        }
        case AlbumYearRole:
        {
            return album.getYear();
        }
        case AlbumCountTracks:
        {
            return album.getCountTracks();
        }
        default:
        {
            return QVariant();
        }
    }
}

bool SongModel::isCorrectIndex(QModelIndex index) const
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
    roles[PathRole] = "path";
    roles[DurationRole] = "duration";
    roles[AlbumIdRole] = "albumId";
    roles[AlbumNameRole] = "albumName";
    roles[AlbumYearRole] = "albumYear";
    roles[AlbumCountTracks] = "countTracks";
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

bool SongModel::updatePath(int songId, const QString &path)
{
    for (int row = 0; row < m_songs.size(); ++row) {
        if (m_songs[row].getSongId() == songId) {
            m_songs[row].updatePath(path);
            const QModelIndex idx = index(row, 0);
            emit dataChanged(idx, idx, {Qt::DisplayRole});
            return true;
        }
    }
    return false;
}
