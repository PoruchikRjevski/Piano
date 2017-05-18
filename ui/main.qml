import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.0
import sound.environment 1.0

Item {
    id: mainItem;

//    focus: true

    height: 500;
    width: 480;

    Controls {
        id: controls

        focus: false

        height: 150

        Layout.fillWidth: true
        Layout.fillHeight: true

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        anchors.leftMargin: 30
        anchors.rightMargin: 50

        Keys.onPressed: {
            if (event.isAutoRepeat) {
                return
            }

            keyboard.pressKeyFunc(event.key)

            event.accepted = true
        }
        Keys.onReleased: {
            if (event.isAutoRepeat) {
                return
            }

            keyboard.releaseKeyFunc(event.key)

            event.accepted = true
        }
    }

    PianoKeyboard {
        id: keyboard

        focus: true

        anchors.top: controls.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        anchors.topMargin: 20
        anchors.leftMargin: 30
        anchors.rightMargin: 50

        Keys.onPressed: {
            if (event.isAutoRepeat) {
                return
            }

            keyboard.pressKeyFunc(event.key)

            event.accepted = true
        }
        Keys.onReleased: {
            if (event.isAutoRepeat) {
                return
            }

            keyboard.releaseKeyFunc(event.key)

            event.accepted = true
        }
    }


}
