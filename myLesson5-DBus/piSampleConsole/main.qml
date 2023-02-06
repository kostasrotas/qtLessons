import QtQuick 2.6
import QtQuick.Window 2.6
import QtQuick.Controls 2.2

import PiHandler 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Text {
        id: element
        x: 261
        y: 84
        width: 118
        height: 32
        text: "Handle Pins"
        font.underline: true
        font.family: "Tahoma"
        lineHeight: 0.7
        font.pixelSize: 20
    }

    Text {
        id: element1
        x: 166
        y: 143
        text: qsTr("Read pin :")
        font.pixelSize: 15
    }

    TextEdit {
        id: textEdit
        x: 238
        y: 143
        width: 17
        height: 20
        text: qsTr(piHandler.readPinValue?"1":"0")
        font.pixelSize: 15
    }

    Button {
        id: button
        x: 166
        y: 169
        text: qsTr("Write 0")
        onClicked: {
            piHandler.setWritePin(false)
        }
    }

    Button {
        id: button1
        x: 166
        y: 220
        text: qsTr("Write 1")
        onClicked: {
            piHandler.setWritePin(true)
        }
    }
}
