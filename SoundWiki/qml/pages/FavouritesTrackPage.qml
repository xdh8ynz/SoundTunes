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
                        trackId: model.id,
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
                    text: model.title
                    font.pixelSize: Theme.fontSizeMedium
                    font.bold: true
                    color: Theme.highlightColor
                    truncationMode: TruncationMode.Elide
                    width: parent.width
                }

                Label {
                    text: model.artist
                    font.pixelSize: Theme.fontSizeSmall
                    color: Theme.primaryColor
                    truncationMode: TruncationMode.Elide
                    width: parent.width
                }

                Label {
                    text: model.genre
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
               {id: 1, title: "Digital Bath", artist: "Deftones", genre: "Alternative Metal", cover: ""},
               {id: 2, title: "Phantom Bride", artist: "Deftones", genre: "Space Rock", cover: ""},
               {id: 3, title: "Never Let Me Down Again", artist: "Depeche Mode", genre: "Synthpop", cover: ""},
               {id: 4, title: "It's No Good", artist: "Depeche Mode", genre: "Synthpop", cover: ""},
               {id: 5, title: "Universal Soldier", artist: "Depeche Mode", genre: "Synthpop", cover: ""},
               {id: 6, title: "Just Can't Get Enough", artist: "Depeche Mode", genre: "Synthpop", cover: ""},
               {id: 7, title: "People Are People", artist: "Depeche Mode", genre: "Synthpop", cover: ""},
               {id: 8, title: "Blasphemous Rumours", artist: "Depeche Mode", genre: "Synthpop", cover: ""},
               {id: 9, title: "Behind The Wheel", artist: "Depeche Mode", genre: "Synthpop", cover: ""},
               {id: 10, title: "Precious", artist: "Depeche Mode", genre: "Synthpop", cover: ""},
               ]

            trackModel.append(tracks)
            isLoadingTracks = false
        }
    }

   }
