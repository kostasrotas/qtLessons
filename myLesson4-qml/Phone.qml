import QtQuick 2.0
import QtQuick.Controls 2.1

import PhoneModel 1.0

ApplicationWindow {

    width: 640
    height: 480
    property alias nameTextEdit: nameTextEdit
    property alias phoneTextEdit: phoneTextEdit
    title: qsTr("Tel. Data")

    Text {
        id: nameText
        x: 103
        y: 122
        width: 157
        height: 37
        text: qsTr("Name")
        font.pixelSize: 30
    }

    Text {
        id: phoneText
        x: 103
        y: 193
        width: 157
        height: 37
        text: qsTr("Telephone")
        font.pixelSize: 30
    }

    TextEdit {
        id: nameTextEdit
        x: 302
        y: 122
        width: 199
        height: 37
        text: qsTr("")
        font.pixelSize: 25
    }

    TextEdit {
        id: phoneTextEdit
        x: 302
        y: 193
        width: 199
        height: 37
        text: qsTr("")
        font.pixelSize: 25
    }

    Button {
        id: button
        x: 440
        y: 301
        text: qsTr("Close")
        onClicked: {            
            phoneModel.addPersonData(nameTextEdit.text,phoneTextEdit.text)
            phone.visible=false
            phoneModel.updateCounter()
        }
    }

}
