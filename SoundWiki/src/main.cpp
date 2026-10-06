#include <auroraapp.h>
#include <QtQuick>

#include "controllers/musicsearchcontroller.h"
#include "types/song.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> application(Aurora::Application::application(argc, argv));
    application->setOrganizationName(QStringLiteral("ru.ac.uniyar"));
    application->setApplicationName(QStringLiteral("SoundWiki"));

    qRegisterMetaType<Song>("Song");
    qRegisterMetaType<QList<Song>>("QList<Song>");

    qmlRegisterType<MusicSearchController>("ru.ac.uniyar", 1, 0, "MusicSearchController");

    QScopedPointer<QQuickView> view(Aurora::Application::createView());
    view->setSource(Aurora::Application::pathTo(QStringLiteral("qml/SoundWiki.qml")));
    view->show();

    return application->exec();
}
