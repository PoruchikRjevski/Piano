import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    visible: true
    width: 560
    height: 480

    RowLayout {
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        PianoKeyboard {
            id: mainOctav
            visible: true
            focus: true

            anchors.fill: parent;
        }
    }
}
