#include "sound_generator.h"

SoundGenerator::SoundGenerator(QObject *parent) : QObject(parent)
{
    return;
}

SoundGenerator::~SoundGenerator()
{
    return;
}

void SoundGenerator::playNote(int note)
{
//    qDebug() << "note freq: " << this->getNoteFrequency(note);

    return;
}

void SoundGenerator::setCurrentOctave(int octave)
{
    this->_currentOctave = octave;

    qDebug() << "octave setted: " << octave;

    return;
}

float SoundGenerator::getNoteFrequency(int note)
{
    float freq = (NOTES_PER_OCTAVE * this->_currentOctave) + note;
    freq -= NOTE_440_NUM;
    freq /= NOTES_PER_OCTAVE;
    freq = NOTE_440_FREQ * qPow(2, freq);

    return freq;
}
