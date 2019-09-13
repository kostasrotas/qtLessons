import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

import PhoneModel 1.0

ApplicationWindow {

    visible: true
    width: 640
    height: 480
    property alias totalTextValue: totalText.text
    title: qsTr("Telephones")

    Button {
        id: addButton
        x: 83
        y: 136
        text: qsTr("Add")
        onClicked: {
            phone.visible=true
            phone.nameTextEdit.text=""
            phone.phoneTextEdit.text=""
        }
    }

    Button {
        id: openButton
        x: 83
        y: 70
        text: qsTr("Open")
    }

    Phone{
        id:phone
        visible: false
    }

    Text {
        id: text1
        x: 83
        y: 222
        text: qsTr("Total: ")
        font.pixelSize: 12
    }

    Text {
        id: totalText
        x: 124
        y: 222
        width: 59
        height: 14
        text: qsTr("...")
        font.pixelSize: 12
    }

    Text {
        id: title
        x: 340
        y: 27
        text: qsTr(phoneModel.phoneModelTitleStr)
        font.pixelSize: 12
    }

    Frame {
        id: frame
        x: 214
        y: 70
        width: 277
        height: 166

        ListView {
            anchors.fill: parent
            visible: true
            spacing: 0
            clip: false
            model: phoneModel

            delegate: RowLayout {
                anchors.left: parent.left
                anchors.right: parent.right
                Text { Layout.preferredWidth: 150;text: phoneName}
                Text { Layout.preferredWidth: 200;text: phoneTelephone}
            }
        }
    }

}



/*##^## Designer {
    D{i:8;anchors_x:191;anchors_y:-277}
}
 ##^##*/
