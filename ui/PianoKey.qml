import QtQuick 2.7
import sound.gen 1.0

Rectangle {
    property string name: "note"
    property string nameClr: "black"
    property string borderClr: "black"
    property int note: Enums.UNDEF

    id: key
    width: 80
    color: "white"
    border.width: 1
    border.color: borderClr
    radius: 5

    anchors.topMargin: -10

    Text {
        id: noteText
        text: name
        color: nameClr
        anchors.bottom: parent.bottom
        anchors.bottomMargin: parent.height/6
        anchors.horizontalCenter: parent.horizontalCenter
    }

    function onPressedKey() {
        anchors.bottomMargin += 5
        noteText.anchors.bottomMargin += 1

        generator.playNote(note)
    }
    function onReleasedKey() {
        anchors.bottomMargin -= 5
        noteText.anchors.bottomMargin -= 1
    }

    MouseArea {
        anchors.fill: parent
        onPressed: {
            key.onPressedKey()
        }
        onReleased: {
            key.onReleasedKey()
        }
    }
}
