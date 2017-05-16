#include "sound_generator.h"

SoundGenerator::SoundGenerator(QObject *parent) : QObject(parent)
{
    return;
}

SoundGenerator::~SoundGenerator()
{
    return;
}

void SoundGenerator::testMethod(float freq)
{
    qDebug() << "note freq: " << freq;

    return;
}
