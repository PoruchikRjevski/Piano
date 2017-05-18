import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.0
import sound.environment 1.0

Rectangle {
    id: keyboardRect

    function pressKeyFunc(key) {
        switch (key) {
        case Qt.Key_A: {
            noteCKey.onPressedKey()
        } break
        case Qt.Key_S: {
            noteDKey.onPressedKey()
        } break
        case Qt.Key_D: {
            noteEKey.onPressedKey()
        } break
        case Qt.Key_F: {
            noteFKey.onPressedKey()
        } break
        case Qt.Key_G: {
            noteGKey.onPressedKey()
        } break
        case Qt.Key_H: {
            noteAKey.onPressedKey()
        } break
        case Qt.Key_J: {
            noteBKey.onPressedKey()
        } break
        case Qt.Key_W: {
            noteDiez1.onPressedKey()
        } break
        case Qt.Key_E: {
            noteDiez2.onPressedKey()
        } break
        case Qt.Key_R: {
            noteDiez3.onPressedKey()
        } break
        case Qt.Key_T: {
            noteDiez4.onPressedKey()
        } break
        case Qt.Key_Y: {
            noteDiez5.onPressedKey()
        } break
        }
    }

    function releaseKeyFunc(key) {
        switch (key) {
        case Qt.Key_A: {
            noteCKey.onReleasedKey()
        } break
        case Qt.Key_S: {
            noteDKey.onReleasedKey()
        } break
        case Qt.Key_D: {
            noteEKey.onReleasedKey()
        } break
        case Qt.Key_F: {
            noteFKey.onReleasedKey()
        } break
        case Qt.Key_G: {
            noteGKey.onReleasedKey()
        } break
        case Qt.Key_H: {
            noteAKey.onReleasedKey()
        } break
        case Qt.Key_J: {
            noteBKey.onReleasedKey()
        } break
        case Qt.Key_W: {
            noteDiez1.onReleasedKey()
        } break
        case Qt.Key_E: {
            noteDiez2.onReleasedKey()
        } break
        case Qt.Key_R: {
            noteDiez3.onReleasedKey()
        } break
        case Qt.Key_T: {
            noteDiez4.onReleasedKey()
        } break
        case Qt.Key_Y: {
            noteDiez5.onReleasedKey()
        } break
        }
    }

    RowLayout {
        anchors.fill: parent;

        PianoKey {
            id: noteCKey

            name: "C-[a]"
            note: Enums.NOTE_C

            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
        }
        PianoKey {
            id: noteDKey

            name: "D-[s]"
            note: Enums.NOTE_D

            anchors.left: noteCKey.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
        }
        PianoKey {
            id: noteEKey

            name: "E-[d]"
            note: Enums.NOTE_E

            anchors.left: noteDKey.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
        }
        PianoKey {
            id: noteFKey

            name: "F-[f]"
            note: Enums.NOTE_F

            anchors.left: noteEKey.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
        }
        PianoKey {
            id: noteGKey

            name: "G-[g]"
            note: Enums.NOTE_G

            anchors.left: noteFKey.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
        }
        PianoKey {
            id: noteAKey

            name: "A-[h]"
            note: Enums.NOTE_A

            anchors.left: noteGKey.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
        }
        PianoKey {
            id: noteBKey

            name: "B-[j]"
            note: Enums.NOTE_B

            anchors.left: noteAKey.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
        }
        PianoKey {
            id: noteDiez1

            name: "C#-[w]"
            note: Enums.NOTE_C_SH
            width: 50
            color: "black"
            nameClr: "white"
            borderClr: "white"

            anchors.left: noteCKey.horizontalCenter
            anchors.leftMargin: width/10
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 1 * parent.height/4
        }
        PianoKey {
            id: noteDiez2

            name: "D#-[e]"
            note: Enums.NOTE_D_SH
            width: 50
            color: "black"
            nameClr: "white"
            borderClr: "white"

            anchors.left: noteDKey.horizontalCenter
            anchors.leftMargin: width/10
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 1 * parent.height/4
        }
        PianoKey {
            id: noteDiez3

            name: "F#-[r]"
            note: Enums.NOTE_F_SH
            width: 50
            color: "black"
            nameClr: "white"
            borderClr: "white"

            anchors.left: noteFKey.horizontalCenter
            anchors.leftMargin: width/10
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 1 * parent.height/4
        }
        PianoKey {
            id: noteDiez4

            name: "G#-[t]"
            note: Enums.NOTE_G_SH
            width: 50
            color: "black"
            nameClr: "white"
            borderClr: "white"

            anchors.left: noteGKey.horizontalCenter
            anchors.leftMargin: width/10
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 1 * parent.height/4
        }
        PianoKey {
            id: noteDiez5

            name: "A#-[y]"
            note: Enums.NOTE_A_SH
            width: 50
            color: "black"
            nameClr: "white"
            borderClr: "white"

            anchors.left: noteAKey.horizontalCenter
            anchors.leftMargin: width/10
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 1 * parent.height/4
        }
    }
}
