import QtQuick 2.0
import Sailfish.Silica 1.0
import ru.ac.uniyar 1.0

ApplicationWindow {
    objectName: "applicationWindow"
    initialPage: Qt.resolvedUrl("pages/MainPage.qml")
    cover: Qt.resolvedUrl("cover/DefaultCoverPage.qml")
    allowedOrientations: defaultAllowedOrientations

    MusicSearchController {
        id: musicSearchController
    }

    ImageCacheManager{
        id: imageCacheManager
    }

    Dao { id: rootDao }

    Connections {
        target: imageCacheManager

        onImageDownloaded: {
            var path = arguments[0]
            var songId = arguments[1]

            if (rootDao.isSongInFavourites(songId)) {
                rootDao.setPath(songId, path)
                musicSearchController.updatePath(songId, path)
            } else {
                imageCacheManager.clear(path)
            }
        }
    }
}
