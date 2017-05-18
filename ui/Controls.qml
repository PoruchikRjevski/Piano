import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.0
import sound.environment 1.0

Rectangle {
    id: controlsRect

    function setVolume(volume) {
        sound_manager.changeVolume(volume)
    }

    function setOctave(octave) {
        sound_manager.setCurrentOctave(octave)
    }

    Component.onCompleted: {
        volumeMain.value = 0.5
        setVolume(0.5)
        octavesBox.currentIndex = 4
        octavesBox.setOctave("-First")
    }

    RowLayout {
        anchors.fill: parent

        anchors.topMargin: 20

        ColumnLayout {
            Button {
                id: closeBtn

                text: qsTr("Close")

                onClicked: {
                    sound_manager.closeApp()
                }
            }
            RowLayout {
//                CheckBox {
//                    id: sustainOpt
//                    focus: false
//                    text: qsTr("Sustain")

//                    onCheckedChanged: {
//                        if (checked) {
//                            sound_manager.sustainOn()
//                        }
//                        else {
//                            sound_manager.sustainOff()
//                        }
//                    }
//                }

                ComboBox {
                    id: octavesBox

                    function setOctave(octaveName) {
                        var octaveId = 0
                        if (octaveName === "-Sub Contr") {
                            octaveId = Enums.SUB_CONTR_OCTAVE
                        }
                        if (octaveName === "-Contr") {
                            octaveId = Enums.CONTR_OCTAVE
                        }
                        if (octaveName === "-Big") {
                            octaveId = Enums.BIG_OCTAVE
                        }
                        if (octaveName === "-Small") {
                            octaveId = Enums.SMALL_OCTAVE
                        }
                        if (octaveName === "-First") {
                            octaveId = Enums.FIRST_OCTAVE
                        }
                        if (octaveName === "-Second") {
                            octaveId = Enums.SEC_OCTAVE
                        }
                        if (octaveName === "-Third") {
                            octaveId = Enums.THIRD_OCTAVE
                        }
                        if (octaveName === "-Fourth") {
                            octaveId = Enums.FOURTH_OCTAVE
                        }
                        if (octaveName === "-Fives") {
                            octaveId = Enums.FIVES_OCTAVE
                        }

                        console.log(octaveId)
                        sound_manager.setCurrentOctave(octaveId)
                    }

                    model : ListModel {
                        id: octavesModel

                        ListElement {
                            text: "-Sub Contr"
                        }
                        ListElement {
                            text: "-Contr"
                        }
                        ListElement {
                            text: "-Big"
                        }
                        ListElement {
                            text: "-Small"
                        }
                        ListElement {
                            text: "-First"
                        }
                        ListElement {
                            text: "-Second"
                        }
                        ListElement {
                            text: "-Third"
                        }
                        ListElement {
                            text: "-Fourth"
                        }
                        ListElement {
                            text: "-Five"
                        }
                    }

                    onCurrentIndexChanged: {
                        setOctave(octavesModel.get(currentIndex).text)
                    }
                }
            }
        }

        Dial {
            id: volumeMain

            from: 0
            to: 1

            Layout.fillHeight: true
            Layout.fillWidth: true

            onPositionChanged: {
                setVolume(position)
            }
        }
    }

}
