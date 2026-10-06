#include "yandexmusicclient.h"

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QDebug>
#include <memory>

YandexMusicClient::YandexMusicClient(QObject *parent): QObject(parent)
{
    m_manager.reset(new QNetworkAccessManager());
}

YandexMusicClient::~YandexMusicClient()
{

}

void YandexMusicClient::searchSongs(QString query)
{
    qDebug() << "Поиск музыки " << query;

    QNetworkRequest request;
    QUrl url;
    QUrlQuery urlQuery;

    urlQuery.addQueryItem("text", query);
    urlQuery.addQueryItem("page", 0);
    urlQuery.addQueryItem("type", "track");
    urlQuery.addQueryItem("nococrrect", "false");
    url.setUrl("https://api.music.yandex.net/search");
    url.setQuery(urlQuery);

    request.setUrl(url);
    request.setRawHeader("Accept", "application/json");

    QNetworkReply *reply = m_manager->get(request);


    connect(reply, &QNetworkReply::finished, this,
            [this, reply]() {
                onSongsReceived(reply);
            });

    connect(reply, &QNetworkReply::finished, reply, &QObject::deleteLater);
}

void YandexMusicClient::onSongsReceived(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NetworkError::NoError)
    {
        qDebug() << "Песни получены";
        qDebug() << QString(reply->readAll());
    }
    else{
        qDebug() << "Ошибка запроса";
        qDebug() << reply->errorString();

        emit onSongsSearchFailed();
    }
}
