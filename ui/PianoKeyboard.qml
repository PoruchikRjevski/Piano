import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.0
import sound.environment 1.0

Rectangle {
    id: keyboard

    function setOctave(octave) {
        sound_manager.setCurrentOctave(octave)
    }

    Component.onCompleted: {
        keyboard.setOctave(Enums.FIRST_OCTAVE)
    }

    RowLayout {
        anchors.fill: parent

        PianoKey {
            id: noteCKey
            Layout.fillHeight: true

            name: "C-[a]"
            note: Enums.NOTE_C

            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
        }
        PianoKey {
            id: noteDKey
            Layout.fillHeight: true

            name: "D-[s]"
            note: Enums.NOTE_D

            anchors.left: noteCKey.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
        }
        PianoKey {
            id: noteEKey
            Layout.fillHeight: true

            name: "E-[d]"
            note: Enums.NOTE_E

            anchors.left: noteDKey.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
        }
        PianoKey {
            id: noteFKey
            Layout.fillHeight: true

            name: "F-[f]"
            note: Enums.NOTE_F

            anchors.left: noteEKey.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
        }
        PianoKey {
            id: noteGKey
            Layout.fillHeight: true

            name: "G-[g]"
            note: Enums.NOTE_G

            anchors.left: noteFKey.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
        }
        PianoKey {
            id: noteAKey
            Layout.fillHeight: true

            name: "A-[h]"
            note: Enums.NOTE_A

            anchors.left: noteGKey.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
        }
        PianoKey {
            id: noteBKey
            Layout.fillHeight: true

            name: "B-[j]"
            note: Enums.NOTE_B

            anchors.left: noteAKey.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
        }
        PianoKey {
            id: noteDiez1
            Layout.fillHeight: true

            name: "C#-[w]"
            note: Enums.NOTE_C_SH
            width: 60
            color: "black"
            nameClr: "white"
            borderClr: "white"

            anchors.left: noteCKey.horizontalCenter
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 1 * parent.height/4
        }
        PianoKey {
            id: noteDiez2
            Layout.fillHeight: true

            name: "D#-[e]"
            note: Enums.NOTE_D_SH
            width: 60
            color: "black"
            nameClr: "white"

            anchors.left: noteDKey.horizontalCenter
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 1 * parent.height/4
        }
        PianoKey {
            id: noteDiez3
            Layout.fillHeight: true

            name: "F#-[r]"
            note: Enums.NOTE_F_SH
            width: 60
            color: "black"
            nameClr: "white"

            anchors.left: noteFKey.horizontalCenter
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 1 * parent.height/4
        }
        PianoKey {
            id: noteDiez4
            Layout.fillHeight: true

            name: "G#-[t]"
            note: Enums.NOTE_G_SH
            width: 60
            color: "black"
            nameClr: "white"

            anchors.left: noteGKey.horizontalCenter
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 1 * parent.height/4
        }
        PianoKey {
            id: noteDiez5
            Layout.fillHeight: true

            name: "A#-[y]"
            note: Enums.NOTE_A_SH
            width: 60
            color: "black"
            nameClr: "white"

            anchors.left: noteAKey.horizontalCenter
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 1 * parent.height/4
        }
    }

    Keys.onPressed: {
        if (event.isAutoRepeat) {
            return
        }

        switch (event.key) {
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

        event.accepted = true
    }
    Keys.onReleased: {
        if (event.isAutoRepeat) {
            return
        }

        switch (event.key) {
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
}
