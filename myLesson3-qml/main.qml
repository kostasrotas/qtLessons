import QtQuick
import QtQuick 2.11
import QtQuick.Controls 2.10
import BallObject 1.0


Window {
    width: 200
    height: 200
    visible: true
    color: "#f8e45c"
    title: qsTr("Hello World")

    Rectangle {
        id:redBall
        property int ppos:0
        Connections {
                target: ballObject
                function onPosChanged(pos) {
                        console.log("pos has changed "+pos)
                        redBall.ppos=pos
                    }
                //onPosChanged: console.log("pos has changed!")
            }
        x: 46
        y: 137-ppos
        width: 48
        height: width
         color: "red"
         border.color: "black"
         border.width: 1
         radius: width*0.5
    }

    Button {
        x: 115
        y: 119
        width: 58
        height: 30
            text: "Slow"
            onClicked: {
                ballObject.changeStartSpeed(8)
                ballObject.startBall()
            }
        }

    Button {
        x: 115
        y: 155
        width: 58
        height: 30
            text: "Fast"
            onClicked: {
                ballObject.changeStartSpeed(15)
                ballObject.startBall()
            }
    }

        Text {
            id: text1
            x: 88
            y: 22
            color: "black"
            text: "Counter:"+ballObject.pressCounter
            font.pixelSize: 16
            styleColor: "#ffffff"
        }
}
