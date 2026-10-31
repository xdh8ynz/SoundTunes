import QtQuick 2.0
import Sailfish.Silica 1.0
import Aurora.Controls 1.0
import ".."

Page {
    id: trackDetailPage
    allowedOrientations: Orientation.All

    property var track

    property bool isLikedTrack: false
    property bool isLoadingData: true

    readonly property int msInMin: 60000
    readonly property int msInSec: 1000
    readonly property int minTwoDigitNumber: 10

    function formatDuration(duration)
    {
        var minutes = Math.floor(duration / msInMin)
        var seconds = Math.floor(duration % msInMin / msInSec)

        var minutesStr = minutes < minTwoDigitNumber ? "0" + minutes : minutes.toString()
        var secondsStr = seconds < minTwoDigitNumber ? "0" + seconds : seconds.toString()

        return minutesStr + ":" + secondsStr
    }

    function changeStatusTrack()
    {
        if (isLikedTrack)
        {
            dao.deleteSong(track.songId)

            imageCacheManager.clear(track.path)
        }
        else{
            dao.insertSong(
                    track.songId,
                    track.title,
                    track.artist,
                    track.genre,
                    track.cover,
                    track.path,
                    track.duration,
                    track.albumId,
                    track.albumName,
                    track.albumYear,
                    track.countTracks
            )

            imageCacheManager.save(track.cover, track.songId)
        }

        isLikedTrack = !isLikedTrack
        pageStack.pop()
    }

    function checkTrackInDatabase()
    {
        isLoadingData = true
        isLikedTrack = dao.isSongInFavourites(track.songId);
        isLoadingData = false;
    }

    function updateImageOnDb(path, songId)
    {
        dao.setPath(songId, path)
        musicSearchController.updatePath(songId, path)
    }

    Connections {
        target: imageCacheManager
        onImageDownloaded:
        {
            console.log("ПАРАМЕТРЫ")
            console.log(arguments[0])
            console.log(arguments[1])

            updateImageOnDb(arguments[0], arguments[1])
        }
    }

    Component.onCompleted: {
        checkTrackInDatabase();
    }

    Dao {
        id: dao
    }

    AppBar {
        id: header
        headerText: qsTr("About track")
        background: false
        headerClickable: false
        content: [
            AppBarSpacer { },
                AppBarButton {
                    icon.source: "image://theme/icon-splus-favorite-selected"
                    onClicked: changeStatusTrack()
                    opacity: isLikedTrack ? 1.0 : 0.5
            }
        ]
    }

    SilicaFlickable {
        visible: !isLoadingData

        anchors{
            top: header.bottom
            bottom: parent.bottom
            left: parent.left
            right: parent.right
            topMargin: Theme.paddingLarge
            leftMargin: Theme.horizontalPageMargin
            rightMargin: Theme.horizontalPageMargin
        }

        contentHeight: layout.height + Theme.paddingLarge

        Column {
            id: layout
            width: parent.width

            Column{
                id: trackComponent
                width: parent.width
                spacing: Theme.paddingLarge

                Column{
                    width: parent.width
                    spacing: Theme.paddingMedium

                    Label{
                        text: qsTr("Title")
                        truncationMode: TruncationMode.Elide
                        width: parent.width
                        font.bold: true
                    }

                    Label {
                        text: track.title ? track.title : qsTr("Unknown")
                        truncationMode: TruncationMode.Elide
                        width: parent.width
                    }
                }

                Column {
                    width: parent.width
                    spacing: Theme.paddingMedium

                    Label{
                        text: qsTr("Artist")
                        truncationMode: TruncationMode.Elide
                        width: parent.width
                        font.bold: true
                    }

                    Label {
                        text: track.artist ? track.artist : qsTr("Unknown")
                        color: Theme.primaryColor
                        truncationMode: TruncationMode.Elide
                        width: parent.width
                    }
                }

                Column{
                    width: parent.width
                    spacing: Theme.paddingMedium

                    Label{
                        text: qsTr("Duration")
                        truncationMode: TruncationMode.Elide
                        width: parent.width
                        font.bold: true
                    }

                    Label {
                        text: track.duration > 0 ? formatDuration(track.duration) : qsTr("Unknown")
                        truncationMode: TruncationMode.Elide
                        width: parent.width
                    }
                }

                Column {
                    width: parent.width
                    spacing: Theme.paddingMedium

                    Label{
                        text: qsTr("Genre")
                        font.bold: true
                        truncationMode: TruncationMode.Elide
                        width: parent.width
                    }

                    Label {
                        text: track.genre ? track.genre : qsTr("Unknown genre")
                        truncationMode: TruncationMode.Elide
                        width: parent.width
                    }
                }
            }

            Item{
                width: parent.width
                height: Theme.paddingLarge
            }

            Column{
                id: albumComponent
                width: parent.width
                spacing: Theme.paddingLarge

                Label{
                    text: qsTr("Album")
                    font.bold: true
                    truncationMode: TruncationMode.Elide
                    width: parent.width
                }

                Item {
                    width: parent.width
                    height: Theme.itemSizeHuge

                    Image {
                        id: albumCover
                        width: Theme.itemSizeHuge
                        height: Theme.itemSizeHuge
                        source: track.path || track.cover || "image://theme/icon-l-sounds"
                        fillMode: Image.PreserveAspectCrop
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.topMargin: Theme.paddingMedium
                        asynchronous: true

                        BusyIndicator{
                            id: indicator
                            anchors.fill: parent
                            running: albumCover.status === Image.Loading
                        }

                        Timer {
                            interval: 1000
                            running: albumCover.status === Image.Loading
                            onTriggered: {
                                if (albumCover.status === Image.Loading) {
                                    albumCover.source = "image://theme/icon-l-sound"
                                }
                                indicator.running = false
                            }
                        }

                        onStatusChanged: {
                            if (status === Image.Error && source === track.path)
                            {
                                source = track.cover
                            }
                            else if (status === Image.Error && source === track.cover)
                            {
                                source = "image://theme/icon-l-sound"
                            }
                        }
                    }

                    Column {
                        anchors.left: albumCover.right
                        anchors.leftMargin: Theme.paddingLarge
                        anchors.right: parent.right
                        anchors.verticalCenter: parent.verticalCenter
                        spacing: Theme.paddingSmall + Theme.paddingMedium

                        Label {
                            text: track.albumName ? track.albumName : qsTr("Unknown title")
                            truncationMode: TruncationMode.Elide
                            width: parent.width
                        }

                        Label {
                            text: track.albumYear > 0 ? track.albumYear : qsTr("Year unknown")
                            color: Theme.primaryColor
                            truncationMode: TruncationMode.Elide
                            width: parent.width
                        }

                        Label {
                            text: track.countTracks > 0 ? track.countTracks + " " +
                                                            qsTr("tracks"): qsTr("Count unknown")
                            color: Theme.secondaryColor
                            truncationMode: TruncationMode.Elide
                            width: parent.width
                        }
                    }
                }

            }

            VerticalScrollDecorator { }
        }
    }

    BusyIndicator {
        anchors.centerIn: parent
        size: BusyIndicatorSize.Large
        running: isLoadingData
        visible: isLoadingData
    }
}
