import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {
    property alias buttonC: buttonC
    property alias buttonD: buttonD
    RowLayout {
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        Button {
            id: buttonC
            text: qsTr("do")
            clip: false
            visible: true
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        Button {
            id: buttonD
            text: qsTr("re")
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}
