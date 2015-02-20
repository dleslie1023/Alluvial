import QtQuick 2.4
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

Item {
    property alias artistText: artistText
    property alias albumText: albumText
    property alias albumArt: albumArt

    id: listView
    width: 640
    height: 480
    transformOrigin: Item.Center



    GridLayout {
        id: gridLayout1
        x: 1
        y: 0
        width: 640
        height: 480
        z: -1

        Rectangle {
            id: rectangle1
            y: 0
            width: 640
            height: 480
            color: "#62d4eb"
            z: -2
            scale: 1
        }
    }

    Grid {
    }

    ColumnLayout {
        x: 61
        y: 39

Rectangle {
        id: albumDetail
        width: 251
        height: 99
        color: "#0d4aa9"

        Text {
            id: artistText
            x: 171
            y: 34
            width: 75
            height: 19
            text: qsTr("Text")
            horizontalAlignment: Text.AlignRight
            font.pixelSize: 16
        }

        Text {
            id: albumText
                x: 100
                y: 2
                width: 145
                height: 31
                text: qsTr("Text")
                font.family: "Arial"
                font.bold: true
                horizontalAlignment: Text.AlignRight
                font.pixelSize: 28
        }

        Image {
            id: albumArt
            x: 0
            y: 1
            width: 100
            height: 100
            source: "./container-background.jpg"
        }


    }

Rectangle {
        id: songListBackground
        width: 414
        height: 268
        color: "#a4d0fb"

        ListView {
            id: songList
            x: 1
            y: 0
            width: 412
            height: 264
            cacheBuffer: 239
            flickableDirection: Flickable.HorizontalAndVerticalFlick
            delegate: Item {
                x: 5
                width: 80
                height: 40
                Row {
                    id: row1
                    Rectangle {
                        width: 40
                        height: 40
                        color: colorCode
                    }

                    Text {
                        text: name
                        font.bold: true
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    spacing: 10
                }
            }
            model: ListModel {
                ListElement {
                    name: "Grey"
                    colorCode: "grey"
                }

                ListElement {
                    name: "Red"
                    colorCode: "red"
                }

                ListElement {
                    name: "Blue"
                    colorCode: "blue"
                }

                ListElement {
                    name: "Green"
                    colorCode: "green"
                }
            }
        }
    }
    }
}

