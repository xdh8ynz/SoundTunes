#ifndef SONGMODEL_H
#define SONGMODEL_H

#include "../types/song.h"

#include <QObject>
#include <QAbstractListModel>

class SongModel: public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        SongIdRole = Qt::UserRole + 1,
        TitleRole,
        ArtistRole,
        GenreRole,
        CoverRole,
        AlbumIdRole,
        DurationRole,
    };

    explicit SongModel(QObject *parent = nullptr);
    ~SongModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;

    void clear();
    void updateSongs(QList<Song> songs);

private:
    QList<Song> m_songs;

    bool isCorrectIndex(QModelIndex index);
};

#endif // SONGMODEL_H
