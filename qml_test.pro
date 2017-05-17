QT += qml quick widgets
CONFIG += c++14

CONFIG(release, debug|release) {
    DESTDIR = ../qml_test-bin/
}

#INCLUDEPATH += "C:/Program Files (x86)/Windows Kits/8.1/Include/um"
#LIBS += -L"C:/Program Files (x86)/Windows Kits/8.1/Lib/winv6.3/um/x86"



INCLUDEPATH += "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Include"
LIBS += -L"C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x86"
LIBS += -lole32

SOURCES += main.cpp \
    core/sound_player.cpp \
    core/sound_manager.cpp

HEADERS += \
    core/sound_player.h \
    core/sound_data.h \
    core/sound_manager.h \
    core/wave_generator.h

RESOURCES += qml.qrc

DEFINES += QT_DEPRECATED_WARNINGS


