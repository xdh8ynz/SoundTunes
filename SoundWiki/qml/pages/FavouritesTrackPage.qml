import QtQuick 2.0
import Sailfish.Silica 1.0
import Aurora.Controls 1.0
import ".."

Page {
    id: favouritesPage
    allowedOrientations: Orientation.All

    property var tracks: []
    property bool isLoadingTracks: true

    Component.onCompleted: {
        isLoadingTracks = true
        loadFavouritesTracks()
    }

    onStatusChanged: {
        if (status === PageStatus.Active)
        {
            isLoadingTracks = true
            loadFavouritesTracks()
        }
    }

    function loadFavouritesTracks()
    {
        trackModel.clear()
        dao.retrieveSongs(function (songs){
            for (var i = 0; i < songs.length; i++)
            {
                var song = songs.item(i);
                trackModel.append({
                                  songId: song.id,
                                  title: song.title,
                                  artist: song.artist,
                                  genre: song.genre,
                                  cover: song.cover,
                                  duration: song.duration,
                                  albumId: song.albumId,
                                  albumName: song.albumName,
                                  albumYear: song.albumYear,
                                  countTracks: song.countTracks
                              })
            }
        });

        isLoadingTracks = false
    }

    function removeTrack(index, id)
    {
        dao.deleteSong(id)
        trackModel.remove(index)
    }

    Dao{
        id: dao
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
            onClicked: {
                pageStack.push("TrackDetailPage.qml", {
                track: model,
            })
            }

            menu: ContextMenu {
                MenuItem {
                    text: qsTr("Delete")
                    onClicked: {
                        remorse.execute("Are you sure you want to remove track?",
                        function() { removeTrack(model.index, model.songId) }
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
}
