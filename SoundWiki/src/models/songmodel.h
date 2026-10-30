#ifndef SONGMODEL_H
#define SONGMODEL_H

#include "../types/song.h"

#include <QObject>
#include <QAbstractListModel>

class SongModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles
    {
        SongIdRole = Qt::UserRole + 1,
        TitleRole,
        ArtistRole,
        GenreRole,
        CoverRole,
        PathRole,
        AlbumIdRole,
        DurationRole,
        AlbumNameRole,
        AlbumYearRole,
        AlbumCountTracks
    };

    explicit SongModel(QObject *parent = nullptr);
    ~SongModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;

    void clear();
    void updateSongs(QList<Song> songs);
    bool updatePath(int songId, const QString &path);

private:
    QList<Song> m_songs;

    bool isCorrectIndex(QModelIndex index) const;
};

#endif // SONGMODEL_H
