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

void ImageCacheManager::save(QString url, int songId)
{
    QNetworkRequest request;
    request.setUrl(url);
    request.setAttribute(QNetworkRequest::User, songId);
    m_manager->get(request);
}

void ImageCacheManager::clear(QString path)
{
    if (QFile::exists(path))
    {
        QFile::remove(path);
    }
}

QString ImageCacheManager::getExtension(QString contentType)
{
    if (contentType.contains("jpeg") || contentType.contains("jpg"))
    {
        return ".jpg";
    }
    else if (contentType.contains("webp"))
    {
        return ".webp";
    }
    else{
        return  ".png";
    }
}

void ImageCacheManager::download(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NetworkError::NoError)
    {
        qDebug() << "Не удалось загрузить изображение: "
                 << reply->error();
        return;
    }

    int songId = reply->request().attribute(QNetworkRequest::User).toInt();

    if (!songId)
    {
        qDebug() << "Не удалось извлечь идентификатор песни из ответа: ";
        return;
    }

    QString contentType = reply->header(QNetworkRequest::ContentTypeHeader)
                              .toString()
                              .toLower();

    QString extension = getExtension(contentType);

    QString localPath = generateFileName(reply->request().url().toString(), extension);
    QString absolutePath = QDir(m_cache_directory).filePath(localPath);

    QFile file(absolutePath);
    if (!file.open(QIODevice::ReadWrite))
    {
        qDebug() << "Не удалось создать файл: "
                 << absolutePath;
        return;
    }

    QByteArray image = reply->readAll();

    file.write(image);
    file.close();

    qDebug() << "Изображение сохранено по пути: " + absolutePath + " для песни: " + songId;
    emit imageDownloaded(absolutePath, songId);
}

QString ImageCacheManager::generateFileName(QString url, QString extension)
{
    QByteArray hash = QCryptographicHash::hash(url.toUtf8(), QCryptographicHash::Md5);
    QString timestamp = QString::number(QDateTime::currentMSecsSinceEpoch());
    return QString::fromLatin1(hash.toHex()) + "_" + timestamp + ".jpg";
}
