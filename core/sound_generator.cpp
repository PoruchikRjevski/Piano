#include "sound_generator.h"

SoundGenerator::SoundGenerator(QObject *parent) : QObject(parent)
{
    return;
}

SoundGenerator::~SoundGenerator()
{
    return;
}

void SoundGenerator::declareQML()
{
    qmlRegisterType<SoundGenerator>("MyQMLEnums", 1, 0, "Notess");

    return;
}

void SoundGenerator::testMethod(unsigned short note)
{
    switch (note) {
    case NOTE_C: {
        qDebug() << "note c";
    } break;
    case NOTE_D: {
        qDebug() << "note d";
    } break;
    }

    return;
}
