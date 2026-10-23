import QtQuick 2.0
import Sailfish.Silica 1.0
import Aurora.Controls 1.0

Page {
    id: searchPage
    allowedOrientations: Orientation.All

    property bool isTryingSearch: false
    property bool noTracksFound: false
    property bool errorWhenFound: false
    property var favouritesTracks: []
    property var songModel: musicSearchController.songModel

    function searchTracks()
    {
        noTracksFound = false;
        isTryingSearch = true;
        musicSearchController.searchSounds(searchField.text.trim());
    }

    function updateInfoComponent(source, label, subLabel)
    {
        iconInfo.source = source;
        labelInfo.text = label;
        subLabelInfo.text = subLabel;
    }

    function handleSongSearchFinished()
    {
        if (songModel.rowCount() === 0)
        {
            noTracksFound = true;
            updateInfoComponent("image://theme/icon-l-search",
                                qsTr("They didn't find anything"),
                                qsTr("Try writing it differently"));
        }

        isTryingSearch = false;
    }

    function handleServerError()
    {
        noTracksFound = true;
        updateInfoComponent("image://theme/icon-l-computer",
                            qsTr("The server is temporarily unavailable"),
                            qsTr("Try again later"));
        isTryingSearch = false;
    }


    function handleNetworkError()
    {
        noTracksFound = true;
        updateInfoComponent("image://theme/icon-l-wlan-3",
                            qsTr("A network error occurred"),
                            qsTr("Check your Internet connection"));
        isTryingSearch = false;
    }

    function handleSongSearchFailed()
    {
        noTracksFound = true;
        updateInfoComponent("image://theme/icon-l-diagnostic",
                            qsTr("An error occurred while trying to search tracks"),
                            qsTr("Try again later"));
        isTryingSearch = false;
    }

    Connections {
        target: musicSearchController
        onSongSearchFinished: {
            handleSongSearchFinished();
        }
        onServerError: {
            handleServerError();
        }
        onNetworkError: {
            handleNetworkError();
        }
        onSongSearchFailed: {
            handleSongSearchFailed();
        }
    }

    AppBar {
        id: header
        headerText: qsTr("SoundWiki")
        background: false
        headerClickable: false
        content: [
            AppBarSpacer { },
                AppBarButton {
                    icon.source: "image://theme/icon-splus-favorite-selected"
                    onClicked: pageStack.push("FavouritesTrackPage.qml", {
                                     tracks: favouritesTracks,
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
            topMargin: Theme.paddingLarge
            leftMargin: Theme.horizontalPageMargin
            rightMargin: Theme.horizontalPageMargin
        }

        placeholderText: qsTr("Enter a query...")
        EnterKey.onClicked: {
            searchField.focus = false
            searchTracks()
        }

        onTextChanged: {
            noTracksFound = false
            iconInfo.source = ""
            labelInfo.text = ""
            subLabelInfo.text = ""
        }
    }

    SilicaListView {
        id: trackList

        clip: true

        anchors {
            top: searchField.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
            topMargin: Theme.paddingLarge
            bottomMargin: Theme.horizontalPageMargin
        }

        model: songModel

        delegate: ListItem {
            width: trackList.width
            contentHeight: Theme.itemSizeMedium + Theme.paddingLarge * 2
            onClicked: {
                pageStack.push("TrackDetailPage.qml", {
                track: model,
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
                id: trackCover
                width: Theme.itemSizeMedium
                height: Theme.itemSizeMedium
                source: model.cover || "image://theme/icon-l-sound"
                fillMode: Image.PreserveAspectCrop
                anchors.verticalCenter: parent.verticalCenter
                asynchronous: true

                BusyIndicator{
                    anchors.fill: parent
                    running: trackCover.status === Image.Loading
                }

                onStatusChanged: {
                    if (status === Image.Error)
                    {
                        source = "image://theme/icon-l-sound"
                    }
                }
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
            running: isTryingSearch
            visible: isTryingSearch
        }

        Column {
            id: infoComponent
            anchors.centerIn: parent
            width: parent.width
            spacing: Theme.paddingMedium
            visible: noTracksFound

            Image {
                id: iconInfo
                anchors.horizontalCenter: parent.horizontalCenter
                source: ""
                width: Theme.itemSizeLarge
                height: Theme.itemSizeLarge
                opacity: 0.5
                asynchronous: true
            }

            Label {
                id: labelInfo
                text: ""
                font.pixelSize: Theme.fontSizeMedium
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                width: parent.width
                wrapMode: Text.Wrap
            }

            Label {
                id: subLabelInfo
                text: ""
                font.pixelSize: Theme.fontSizeSmall
                color: Theme.secondaryColor
                horizontalAlignment: Text.AlignHCenter
                width: parent.width
                wrapMode: Text.Wrap
            }
        }
    }
}
