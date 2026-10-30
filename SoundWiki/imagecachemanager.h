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

    Q_INVOKABLE void save(QString url);
    Q_INVOKABLE void clear(QString path);

signals:
    void imageDownloaded(const QString &path);

private slots:
    void download(QNetworkReply *reply);

private:
    std::unique_ptr<QNetworkAccessManager> m_manager;
    QString m_cache_directory = QStandardPaths::writableLocation(QStandardPaths::CacheLocation);

    void requestImage(QString url);
    QString generateFileName(QString url, QString extension);
    QString getExtension(QString contentType);
};

#endif // IMAGECACHEMANAGER_H
