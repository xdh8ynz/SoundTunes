import QtQuick 2.0
import Sailfish.Silica 1.0
import Aurora.Controls 1.0

Page {
    id: searchPage

    // Флаг поиска
    property bool searching: false

    // Функция поиска
    function performSearch() {
        var query = searchField.text.trim()
        if (query.length === 0) return

        console.log("Ищем:", query)
        searching = true
        trackModel.clear()

        // Имитация задержки поиска
        timer.restart()
    }

    SilicaFlickable {
        anchors.fill: parent
        contentHeight: column.height

        Column {
            id: column
            width: parent.width
            spacing: Theme.paddingLarge

            PageHeader {
                title: "Music Search"
                description: "Поиск музыки"
            }

            // 1. ПОЛЕ ПОИСКА (теперь оно правильное и отдельное)
            AppBarSearchField {
                id: searchField
                anchors {
                    left: parent.left
                    right: parent.right
                    margins: Theme.paddingLarge
                }
                backgroundEnabled: true
                placeholderText: "Введите запрос"

                // onAccepted срабатывает при нажатии Enter на клавиатуре
                EnterKey.onClicked: performSearch()
            }

            // 2. СПИСОК РЕЗУЛЬТАТОВ (теперь он НЕ внутри Row, а сосед Column)
            SilicaListView {
                id: resultsList
                width: parent.width
                // ИСПРАВЛЕНО: searchPage.height вместо page.height
                height: searchPage.height - column.y - Theme.paddingLarge * 2
                model: trackModel

                VerticalScrollDecorator {}

                delegate: ListItem {
                    width: resultsList.width
                    contentHeight: Theme.itemSizeMedium + Theme.paddingLarge * 2

                    onClicked: {
                        pageStack.push("TrackDetailPage.qml", {
                            trackTitle: model.title,
                            trackArtist: model.artist,
                            trackGenre: model.genre,
                            trackCover: model.cover
                        })
                    }

                    Row {
                        anchors {
                            fill: parent
                            margins: Theme.paddingLarge
                        }
                        spacing: Theme.paddingLarge

                        // Обложка трека
                        Image {
                            width: Theme.itemSizeMedium
                            height: Theme.itemSizeMedium
                            // ИСПРАВЛЕНО: реальные ссылки-заглушки, чтобы не было ошибок 404
                            source: model.cover || "image://theme/icon-l-sound"
                            fillMode: Image.PreserveAspectCrop
                            anchors.verticalCenter: parent.verticalCenter

                            Rectangle {
                                anchors.fill: parent
                                color: Theme.secondaryColor
                                opacity: 0.3
                                visible: parent.status === Image.Error
                            }
                        }

                        // Информация о треке
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
                }

                // 3. ИНДИКАТОР ЗАГРУЗКИ (сосед ListView, а не внутри делегата)
                BusyIndicator {
                    anchors.centerIn: parent
                    size: BusyIndicatorSize.Large
                    running: searching
                    visible: searching
                }

                // 4. СООБЩЕНИЕ "НИЧЕГО НЕ НАЙДЕНО" (тоже сосед)
                Label {
                    anchors.centerIn: parent
                    text: "Ничего не найдено"
                    color: Theme.secondaryColor
                    visible: !searching && trackModel.count === 0 && searchField.text.length > 0
                }
            }
        }
    }

    // Модель данных
    ListModel {
        id: trackModel
    }

    // Таймер для имитации поиска
    Timer {
        id: timer
        interval: 500
        onTriggered: {
            // Используем работающие placeholder-картинки
            trackModel.append({
                title: "Bohemian Rhapsody",
                artist: "Queen",
                genre: "Rock",
                cover: ""
            })
            trackModel.append({
                title: "Hotel California",
                artist: "Eagles",
                genre: "Rock",
                cover: ""
            })
            trackModel.append({
                title: "Smells Like Teen Spirit",
                artist: "Nirvana",
                genre: "Grunge",
                cover: ""
            })

            searching = false
        }
    }
}
