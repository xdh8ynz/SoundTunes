#ifndef IMAGECACHEMANAGER_H
#define IMAGECACHEMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <memory>
#include <QNetworkReply>
#include <QStandardPaths>

class ImageCacheManager : public QObject
{
    Q_OBJECT
public:
    explicit ImageCacheManager(QObject *parent = nullptr);
    ~ImageCacheManager();

    Q_INVOKABLE void save(QString url, int songId);
    Q_INVOKABLE void clear(QString path);

signals:
    void imageDownloaded(const QString &path, const int &songId);

private slots:
    void download(QNetworkReply *reply);

private:
    std::unique_ptr<QNetworkAccessManager> m_manager;
    QString m_cache_directory = QStandardPaths::writableLocation(QStandardPaths::CacheLocation);
    QString generateFileName(QString url, QString extension);
    QString getExtension(QString contentType);
};

#endif // IMAGECACHEMANAGER_H
