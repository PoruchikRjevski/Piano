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

/// @todo: switch on reverberation
void SoundManager::reverbOn()
{
#ifdef DEBUG_BUILD
    qDebug() << "reverb on";
#endif

    return;
}

/// @todo: switch off reverberation
void SoundManager::reverbOff()
{
#ifdef DEBUG_BUILD
    qDebug() << "reverb off";
#endif

    return;
}

/// @todo: switch on sustain
void SoundManager::sustainOn()
{
#ifdef DEBUG_BUILD
    qDebug() << "sustain on";
#endif

    return;
}

/// @todo: switch off sustain
void SoundManager::sustainOff()
{
#ifdef DEBUG_BUILD
    qDebug() << "sustain off";
#endif

    return;
}

void SoundManager::changeVolume(float volume)
{
    this->_player->setVolume(volume);

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

#ifdef DEBUG_BUILD
    qDebug() << "freq: " << freq;
#endif

    return freq;
}

bool SoundManager::initEnvironment()
{
    this->_player = new SoundPlayer();
    if (!this->_player->initPlayer()) {
        QMessageBox errorMsg;
        errorMsg.critical(0,
                          "Error",
                          "Can't init XAudio2 instruments!");
        errorMsg.show();

        return false;
    }

    return true;
}

void SoundManager::setQmlViewerPtr(QQuickView *view)
{
    this->_qmlViewer = view;

    return;
}

void SoundManager::closeApp()
{
    this->_qmlViewer->close();

    return;
}
