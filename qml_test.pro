QT += qml quick widgets
CONFIG += c++14

TARGET = Piano

CONFIG(debug, debug|release) {
    DEFINES += DEBUG_BUILD
}

CONFIG(release, debug|release) {
    DESTDIR = ../qml_test-bin/

}

INCLUDEPATH += "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Include"
LIBS += -L"C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x86"
LIBS += -lole32

SOURCES += main.cpp \
    sound_core/sound_player.cpp \
    sound_core/sound_manager.cpp \
    sound_core/wave_generator.cpp

HEADERS += \
    sound_core/sound_player.h \
    sound_core/sound_data.h \
    sound_core/sound_manager.h \
    sound_core/wave_generator.h

RESOURCES += qml.qrc

DEFINES += QT_DEPRECATED_WARNINGS


