#include "imagecachemanager.h"
#include <QUrlQuery>
#include <QNetworkRequest>
#include <QFile>
#include <QDir>
#include <QCryptographicHash>

ImageCacheManager::ImageCacheManager(QObject *parent)
    : QObject{parent}
{
    m_manager.reset(new QNetworkAccessManager());
    connect(m_manager.get(), &QNetworkAccessManager::finished, this, &ImageCacheManager::download);
}

ImageCacheManager::~ImageCacheManager()
{

}

void ImageCacheManager::save(QString url)
{
    requestImage(url);
}

void ImageCacheManager::clear(QString path)
{
    if (QFile::exists(path))
    {
        QFile::remove(path);
    }
}

void ImageCacheManager::requestImage(QString url)
{
    QNetworkRequest request;
    request.setUrl(url);
    m_manager->get(request);
}

void ImageCacheManager::download(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NetworkError::NoError)
    {
        qDebug() << "Не удалось загрузить изображение: "
                 << reply->error();
        return;
    }

    QByteArray image = reply->readAll();

    QString contentType = reply->header(QNetworkRequest::ContentTypeHeader)
                              .toString()
                              .toLower();

    QString extension = "";

    if (contentType.contains("jpeg") || contentType.contains("jpg"))
    {
        extension = ".jpg";
    }
    else if (contentType.contains("webp"))
    {
        extension = ".webp";
    }
    else{
        extension = ".png";
    }

    QString localPath = generateFileName(reply->request().url().toString(), extension);
    QString absolutePath = QDir(m_cache_directory).filePath(localPath);

    QFile file(absolutePath);
    if (!file.open(QIODevice::ReadWrite))
    {
        qDebug() << "Не удалось сохранить изображение в файл: "
                 << absolutePath;
        return;
    }

    file.write(image);
    file.close();

    qDebug() << "Изображение сохранено по пути: " + absolutePath;
    imageDownloaded(absolutePath);
}

QString ImageCacheManager::generateFileName(QString url, QString extension)
{
    QByteArray hash = QCryptographicHash::hash(url.toUtf8(), QCryptographicHash::Md5);
    return QString(hash.toHex()) + extension;
}
