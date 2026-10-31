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

    Dao { id: dao }

    Connections {
        target: imageCacheManager

        onImageDownloaded: {
            var path = arguments[0]
            var songId = arguments[1]

            if (dao.setPathIfExists(songId, path)) {
                musicSearchController.updatePath(songId, path)
            } else {
                imageCacheManager.clear(path)
            }
        }
    }
}
