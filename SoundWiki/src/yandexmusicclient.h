#ifndef YANDEXMUSICCLIENT_H
#define YANDEXMUSICCLIENT_H

#include <QNetworkAccessManager>
#include <memory>

class YandexMusicClient: public QObject
{
    Q_OBJECT
public:
    explicit YandexMusicClient(QObject *parent = nullptr);
    ~YandexMusicClient();

    void searchSongs(QString query);

signals:
    void onSongsSearchFailed();

public slots:
    void onSongsReceived(QNetworkReply *reply);

private:
    std::unique_ptr<QNetworkAccessManager> m_manager;
};

#endif // YANDEXMUSICCLIENT_H
