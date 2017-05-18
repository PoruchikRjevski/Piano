import QtQuick 2.7
import sound.environment 1.0

Rectangle {
    property string name: "note"
    property string nameClr: "black"
    property string borderClr: "black"
    property int note: Enums.UNDEF

    id: key
    width: 60;
    height: 200;
    color: "white"
    border.width: 1
    border.color: borderClr
    radius: 10

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
        key.border.width = 2;
        noteText.anchors.bottomMargin += 1

        sound_manager.genNote(note)
    }
    function onReleasedKey() {
        anchors.bottomMargin -= 5
        key.border.width = 1;
        noteText.anchors.bottomMargin -= 1

        sound_manager.delNote(note)
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
