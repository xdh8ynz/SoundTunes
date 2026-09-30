import QtQuick 2.0
import Sailfish.Silica 1.0
import Aurora.Controls 1.0

Page {
    id: favouritesPage
    allowedOrientations: Orientation.All

    property var tracks: []
    property bool isLoadingTracks: true

    Component.onCompleted: {
        loadFavouritesTracks()
    }

    function loadFavouritesTracks()
    {
        isLoadingTracks = true
        timerFavourites.restart()
    }

    function removeTrack(index, id)
    {
        trackModel.remove(index)
    }

    ListModel {
        id: trackModel
    }

    AppBar {
        id: header
        headerText: qsTr("Favourites")
        background: false
        headerClickable: true
    }

    SilicaListView {
        id: trackList

        anchors {
            top: header.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
            topMargin: Theme.horizontalPageMargin
            bottomMargin: Theme.horizontalPageMargin
        }

        model: trackModel

        delegate: ListItem {
            width: trackList.width
            contentHeight: Theme.itemSizeMedium + Theme.paddingLarge * 2

            menu: ContextMenu {
                MenuItem {
                    text: qsTr("About track")
                    onClicked: {
                        pageStack.push("TrackDetailPage.qml", {
                        track: model,
                    })
                }
                }
                MenuItem {
                    text: qsTr("Delete")
                    onClicked: {
                        remorse.execute("Are you sure you want to remove track?",
                        function() { removeTrack(model.index, model.id) }
                      )
                }
            }
        }

        RemorsePopup {
            id: remorse
        }

        Row {
            id: trackRow

            anchors {
                fill: parent
                margins: Theme.paddingLarge
            }

            spacing: Theme.paddingLarge

            Image {
                width: Theme.itemSizeMedium
                height: Theme.itemSizeMedium
                source: model.cover || "image://theme/icon-l-sound"
                fillMode: Image.PreserveAspectCrop
                anchors.verticalCenter: parent.verticalCenter
            }

            Column {
                anchors.verticalCenter: parent.verticalCenter
                width: parent.width - Theme.itemSizeMedium - Theme.paddingLarge * 2
                spacing: Theme.paddingSmall / 2

                Label {
                    text: model.title ? model.title : qsTr("Unknown title")
                    font.pixelSize: Theme.fontSizeMedium
                    font.bold: true
                    color: Theme.highlightColor
                    truncationMode: TruncationMode.Elide
                    width: parent.width
                }

                Label {
                    text: model.artist ? model.artist : qsTr("Unknown artist")
                    font.pixelSize: Theme.fontSizeSmall
                    color: Theme.primaryColor
                    truncationMode: TruncationMode.Elide
                    width: parent.width
                }

                Label {
                    text: model.genre ? model.genre : qsTr("Unknown genre")
                    font.pixelSize: Theme.fontSizeExtraSmall
                    color: Theme.secondaryColor
                    truncationMode: TruncationMode.Elide
                    width: parent.width
                }
            }
        }

        VerticalScrollDecorator {}
    }

        BusyIndicator {
            anchors.centerIn: parent
            size: BusyIndicatorSize.Large
            running: isLoadingTracks
            visible: isLoadingTracks
        }
    }

    Timer {
        id: timerFavourites
        interval: 2000
        onTriggered: {
           tracks = [
               {id: 1, title: "Digital Bath", artist: "Deftones", genre: "Alternative Metal", cover: "", albumId: 0, duration: 293050},
               {id: 2, title: "Phantom Bride", artist: "Deftones", genre: "Space Rock", cover: "", albumId: 1, duration: 393050},
               {id: 3, title: "Never Let Me Down Again", artist: "Depeche Mode", genre: "Synthpop", cover: "", albumId: 2, duration: 293050},
               {id: 4, title: "It's No Good", artist: "Depeche Mode", genre: "Synthpop", cover: "", albumId: 3, duration: 293050},
               {id: 5, title: "Universal Soldier", artist: "Depeche Mode", genre: "Synthpop", cover: "", albumId: 4, duration: 493250},
               {id: 6, title: "Just Can't Get Enough", artist: "Depeche Mode", genre: "Synthpop", cover: "", albumId: 5, duration: 693150},
               {id: 7, title: "People Are People", artist: "Depeche Mode", genre: "Synthpop", cover: "", albumId: 6, duration: 383052},
               {id: 8, title: "Blasphemous Rumours", artist: "Depeche Mode", genre: "Synthpop", cover: "", albumId: 7, duration: 293050},
               {id: 9, title: "Behind The Wheel", artist: "Depeche Mode", genre: "Synthpop", cover: "", albumId: 8, duration: 393150},
               {id: 10, title: "Precious", artist: "Depeche Mode", genre: "Synthpop", cover: "", albumId: 9, duration: 886150},
               ]

            trackModel.append(tracks)
            isLoadingTracks = false
        }
    }
}
