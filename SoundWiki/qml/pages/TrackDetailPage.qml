import QtQuick 2.0
import Sailfish.Silica 1.0
import Aurora.Controls 1.0

Page {
    id: trackDetailPage
    allowedOrientations: Orientation.All

    property var track: ({songId: 0, title: "", artist: "", genre: "", cover: "", albumId: 0, duration: 0})
    property var album: ({albumId: 0, title: "", year:0, cover: "", count: 0})
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
        isLikedTrack = !isLikedTrack
    }

    Component.onCompleted: {
        // TODO: загрузка информации о плейлисте + проверка есть ли в бд
        timer.restart()
    }

    AppBar {
        id: header
        headerText: qsTr("About track")
        background: false
        headerClickable: true
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
                spacing: Theme.paddingMedium

                Label {
                    text: track.title ? track.title : qsTr("Unknown title")
                    font.bold: true
                    truncationMode: TruncationMode.Elide
                    width: parent.width
                }

                Label {
                    text: track.artist ? track.artist : qsTr("Unknown artist")
                    color: Theme.primaryColor
                    truncationMode: TruncationMode.Elide
                    width: parent.width
                }

                Label {
                    text: track.duration > 0 ? formatDuration(track.duration) : qsTr("Unknown duration")
                    color: Theme.secondaryColor
                    truncationMode: TruncationMode.Elide
                    width: parent.width
                }
            }

            Item{
                width: parent.width
                height: 3 * Theme.paddingLarge
            }

            Column{
                id: albumComponent
                width: parent.width
                spacing: Theme.paddingMedium

                Label{
                    text: qsTr("Album")
                    font.bold: true
                    truncationMode: TruncationMode.Elide
                    width: parent.width
                }

                Row {
                    id: albumRow
                    width: parent.width
                    spacing: Theme.paddingLarge

                    Image {
                        width: Theme.itemSizeHuge
                        height: Theme.itemSizeHuge
                        source: album.cover || "image://theme/icon-l-sounds"
                        fillMode: Image.PreserveAspectCrop
                        anchors.verticalCenter: parent.verticalCenter
                    }

                    Column {
                        anchors.verticalCenter: parent.verticalCenter
                        width: parent.width - Theme.itemSizeMedium - Theme.paddingLarge * 2
                        spacing: Theme.paddingSmall / 2

                        Label {
                            text: album.title ? album.title : qsTr("Unknown title")
                            truncationMode: TruncationMode.Elide
                            width: parent.width
                        }

                        Label {
                            text: album.year ? album.year : qsTr("Year unknown")
                            color: Theme.primaryColor
                            truncationMode: TruncationMode.Elide
                            width: parent.width
                        }

                        Label {
                            text: album.count ? album.count + " " + qsTr("tracks"): qsTr("Count unknown")
                            color: Theme.secondaryColor
                            truncationMode: TruncationMode.Elide
                            width: parent.width
                        }
                    }
                     }


            }


            Item{
                width: parent.width
                height: 3 * Theme.paddingLarge
            }

            Column {
                id: genreColumn
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

            VerticalScrollDecorator { }
        }
    }

    BusyIndicator {
        anchors.centerIn: parent
        size: BusyIndicatorSize.Large
        running: isLoadingData
        visible: isLoadingData
    }

    Timer {
        id: timer
        interval: 2000
        onTriggered: {
            album = ({id: 0, title: "Gore", year:2016, cover: "", count: 11})
            isLoadingData = false
        }
    }
}
