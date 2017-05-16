QT += qml quick

CONFIG += c++14

CONFIG(release, debug|release) {
    DESTDIR = ../qml_test-bin/
}


INCLUDEPATH += "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Include"
LIBS += -L"C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x86"

SOURCES += main.cpp \
    core/sound_generator.cpp

HEADERS += \
    core/sound_generator.h

RESOURCES += qml.qrc

DEFINES += QT_DEPRECATED_WARNINGS


