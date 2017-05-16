import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.0
import sound.gen 1.0

Item {
    id: mainItem
    visible: true

    anchors.fill: parent

    width: 560
    height: 480

    PianoKeyboard {
        id: keyboard
        visible: true
        focus: true

        anchors.fill: parent
    }

    Controls {
        id: controls
        visible: true
        focus: true

        anchors.left: keyboard.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right

    }
}
