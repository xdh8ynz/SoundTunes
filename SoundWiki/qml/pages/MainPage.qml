import QtQuick 2.0
import Sailfish.Silica 1.0
import Aurora.Controls 1.0

Page {
    id: searchPage

    property bool isTryingSearch: false
    property bool noTracksFound: false

    // TODO: убрать
    property bool isSuccessfulSearch: true

    property var tracks: [
    {id: 1, title: "Digital Bath", artist: "Deftones", genre: "Alternative Metal", cover: ""},
    {id: 2, title: "Phantom Bride", artist: "Deftones", genre: "Space Rock", cover: ""},
    {id: 3, title: "All I Nead", artist: "Radiohead", genre: "Art Rock", cover: ""},
    {id: 5, title: "Digital", artist: "Joy Division", genre: "Post-punk", cover: ""},
    {id: 5, title: "Isolation", artist: "Joy Division", genre: "Post-punk", cover: ""},
    {id: 6, title: "On the Level", artist: "Mac DeMarco", genre: "Psychedelic Pop", cover: ""},
    {id: 7, title: "Chamber Of Reflection", artist: "Mac DeMarco", genre: "Synthpop", cover: ""},
    {id: 8, title: "Never Let Me Down Again", artist: "Depeche Mode", genre: "Synthpop", cover: ""},
    ]

    ListModel {
        id: trackModel
    }

    function searchTracks()
    {
        var query = searchField.text.trim()

        if (query.length === 0)
        {
            return
        }

        noTracksFound = false
        isTryingSearch = true
        trackModel.clear()
        timer.restart()
    }

    AppBar {
        id: header
        headerText: "SoundWiki"
        background: false
        headerClickable: true
        content: [
            AppBarSpacer { },
                AppBarButton {
                    icon.source: "image://theme/icon-splus-favorite-selected"
                    onClicked: pageStack.push("TrackDetailPage.qml", {
                    trackId: model.id,
                })
            }
        ]
    }

    SearchField {
        id: searchField

        anchors {
            top: header.bottom
            left: parent.left
            right: parent.right
            margins: Theme.paddingLarge
        }

        placeholderText: "Введите запрос..."
        EnterKey.onClicked: searchTracks()
        onTextChanged: {
            noTracksFound = false
        }
    }

    SilicaListView {
        id: resultsList

        anchors {
            top: searchField.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
            topMargin: Theme.horizontalPageMargin
            bottomMargin: Theme.horizontalPageMargin
        }

        model: trackModel

        delegate: ListItem {
            width: resultsList.width
            contentHeight: Theme.itemSizeMedium + Theme.paddingLarge * 2

            onClicked: {
                pageStack.push("TrackDetailPage.qml", {
                trackId: model.id,
            })
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
            running: isTryingSearch
            visible: isTryingSearch
        }

        Column {
            id: absenceTrackComponent
            anchors.centerIn: parent
            width: parent.width
            spacing: Theme.paddingMedium
            visible: noTracksFound

            Image {
                anchors.horizontalCenter: parent.horizontalCenter
                source: "image://theme/icon-l-search"
                width: Theme.itemSizeLarge
                height: Theme.itemSizeLarge
                opacity: 0.5
            }

            Label {
                text: "Ничего не нашли"
                font.pixelSize: Theme.fontSizeMedium
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                width: parent.width
                wrapMode: Text.Wrap
            }

            Label {
                text: "Попробуйте написать по-другому"
                font.pixelSize: Theme.fontSizeSmall
                color: Theme.secondaryColor
                horizontalAlignment: Text.AlignHCenter
                width: parent.width
                wrapMode: Text.Wrap
            }
        }
    }

    Timer {
        id: timer
        interval: 2000
        onTriggered: {
            isTryingSearch = false

            if (isSuccessfulSearch)
            {
                trackModel.append(tracks)
                noTracksFound = false
            }
            else{
                noTracksFound = true
            }
        }
    }
}
