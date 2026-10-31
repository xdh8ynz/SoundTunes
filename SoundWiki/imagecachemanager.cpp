#include "imagecachemanager.h"
#include <QUrlQuery>
#include <QNetworkRequest>
#include <QFile>
#include <QDir>
#include <QCryptographicHash>

ImageCacheManager::ImageCacheManager(QObject *parent)
    : QObject{parent}
{
    QDir().mkpath(m_cache_directory);

    m_manager.reset(new QNetworkAccessManager());
    connect(m_manager.get(), &QNetworkAccessManager::finished, this, &ImageCacheManager::download);
}

ImageCacheManager::~ImageCacheManager()
{

}

bool ImageCacheManager::isCached(QString path)
{
    QFileInfo info(path);
    return !path.isEmpty() && info.exists() && info.size() > 0;
}

void ImageCacheManager::save(QString url, int songId)
{
    if (url.isEmpty())
        return;

    const QString key = QUrl(url).toString();
    const QString absolutePath =
        QDir(m_cache_directory).filePath(generateFileName(key));

    if (isCached(absolutePath))
    {
        emit imageDownloaded(absolutePath, songId);
        return;
    }

    QNetworkRequest request;
    request.setUrl(key);
    request.setAttribute(QNetworkRequest::User, songId);
    m_manager->get(request);
}

void ImageCacheManager::clear(QString path)
{
    if (path.isEmpty())
    {
        return;
    }

    if (QFile::exists(path))
    {
        QFile::remove(path);
    }
}

void ImageCacheManager::download(QNetworkReply *reply)
{
    reply->deleteLater();

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

    const QString key = reply->request().url().toString();
    const QString absolutePath =
        QDir(m_cache_directory).filePath(generateFileName(key));


    if (isCached(absolutePath))
    {
        emit imageDownloaded(absolutePath, songId);
        return;
    }

    QFile file(absolutePath);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Truncate))
    {
        qDebug() << "Не удалось создать файл: "
                 << absolutePath;
        return;
    }

    QByteArray image = reply->readAll();

    if (image.isEmpty())
    {
        file.close();
        file.remove();
        return;
    }

    if (file.write(image) != image.size())
    {
        file.close();
        file.remove();
        return;
    }

    file.close();
    qDebug() << "Изображение сохранено по пути:"
             << absolutePath << "для песни:" << songId;

    emit imageDownloaded(absolutePath, songId);
}

QString ImageCacheManager::generateFileName(QString url)
{
    QByteArray hash = QCryptographicHash::hash(url.toUtf8(), QCryptographicHash::Md5);
    return QString::fromLatin1(hash.toHex());
}
