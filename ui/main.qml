import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    visible: true
    width: 640
    height: 480
//    title: qsTr("Hello World")

    RowLayout {
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        Keyboard {
            id: keyboard
            visible: true

            anchors.top: parent.top;
            anchors.bottom: parent.bottom;
            anchors.left: parent.left;
            anchors.right: parent.right;

        }
    }
}
