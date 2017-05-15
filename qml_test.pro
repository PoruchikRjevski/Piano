QT += qml quick

CONFIG += c++14

SOURCES += main.cpp \
    core/sound_generator.cpp

RESOURCES += qml.qrc

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    core/sound_generator.h
