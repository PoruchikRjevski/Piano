#include "sound_manager.h"

SoundManager::SoundManager(QObject *parent) : QObject(parent)
{
    return;
}

SoundManager::~SoundManager()
{
    return;
}

void SoundManager::genNote(short note)
{
    NoteData curData = {};
    curData._note = note;
    curData._freq = this->getNoteFrequency(note);

    WaveGenerator::genNoteData(curData);

    this->_player->playNote(curData);

    return;
}

void SoundManager::delNote(short note)
{
    this->_player->stopNote(note);

    return;
}

void SoundManager::setCurrentOctave(int octave)
{
    this->_currentOctave = octave;

    return;
}

float SoundManager::getNoteFrequency(int note)
{
    float freq = (NOTES_PER_OCTAVE * this->_currentOctave) + note;
    freq -= NOTE_440_NUM;
    freq /= NOTES_PER_OCTAVE;
    freq = NOTE_440_FREQ * pow(2, freq);

    qDebug() << freq;

    return freq;
}

//void SoundManager::genNoteData(NoteData &data, const float &freq)
//{
//    for (unsigned long i = 0; i < data._dataSize; i += 2) {
//        data._data[i] = sin(i * 2 * M_PI * freq / SAMPLE_RATE);
//        data._data[i + 1] = data._data[i];
////        buffer._data[i + 1] = sin(i * 2 * M_PI * (freq + 1) / SAMPLE_RATE);
//    }

//    return;
//}

bool SoundManager::initEnvironment()
{
    this->_player = new SoundPlayer();
    if (!this->_player->initPlayer()) {
        QMessageBox errorMsg;
        errorMsg.critical(0,"Error","Can't init XAudio2 instruments!");
        errorMsg.show();

        return false;
    }

    return true;
}
