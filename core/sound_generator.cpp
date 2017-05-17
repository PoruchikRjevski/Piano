#include "sound_generator.h"

SoundManager::SoundManager(QObject *parent) : QObject(parent)
{
//    this->initXAudio();
//    this->init();

    return;
}

SoundManager::~SoundManager()
{
    return;
}

void SoundManager::addNote(int note)
{
    /// get freq for note
    /// add note to vector of notes
    /// generate 1 second for vector of notes
    ///
    qDebug() << "note freq: " << this->getNoteFrequency(note);

    return;
}

void SoundManager::setCurrentOctave(int octave)
{
    this->_currentOctave = octave;

    qDebug() << "octave setted: " << octave;

    return;
}

float SoundManager::getNoteFrequency(int note)
{
    float freq = (NOTES_PER_OCTAVE * this->_currentOctave) + note;
    freq -= NOTE_440_NUM;
    freq /= NOTES_PER_OCTAVE;
    freq = NOTE_440_FREQ * qPow(2, freq);

    return freq;
}

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

void SoundManager::initXAudio()
{
//    CoInitializeEx(nullptr, 0);

//    unsigned long bufferSize = 44100 * 2;

//    WAVEFORMATEX *waveFormatextBuf = new WAVEFORMATEX();

//    bufferSamples = new short[bufferSize];
//    buffer = new BYTE[bufferSize];

//    aBuffer = new XAUDIO2_BUFFER;

//    if (FAILED(XAudio2Create(&xAudio2, 0, XAUDIO2_DEFAULT_PROCESSOR))) {
//        CoUninitialize();

//        qDebug() << "can't create xAudio2";

//        return;
//    }

//    if (FAILED(xAudio2->CreateMasteringVoice(&masteringVoice))) {
//        xAudio2->Release();

//        CoUninitialize();

//        qDebug() << "cant create mastering voice";

//        return;
//    }

//    double totalTime = 0;
//    for (int i = 0; i < bufferSize - 1; i += 2) {
//        double time = totalTime / 44100;

//        short curSample = 100 * qSin(2 * M_PI * 500);

//        bufferSamples[i] = curSample;
//        bufferSamples[i + 1] = curSample;

//        totalTime++;
//    }

//    memcpy(buffer, bufferSamples, bufferSize);

//    aBuffer->PlayBegin = 0;
//    aBuffer->PlayLength = 0;
//    aBuffer->LoopCount = XAUDIO2_LOOP_INFINITE;
//    aBuffer->pAudioData = buffer;

//    qDebug() << "buf samples: " << bufferSize;


//    if(FAILED(xAudio2->CreateSourceVoice(&sourceVoice, waveFormatextBuf))) {
//        xAudio2->Release();

//        CoUninitialize();

//        qDebug() << "cant create source voice";

//        return;
//    }

//    if (FAILED(sourceVoice->Start(0, XAUDIO2_COMMIT_NOW))) {
//        qDebug() << "loshara";
//    }

//    sourceVoice->SubmitSourceBuffer(aBuffer);



//    sourceVoice->Start();

    return;
}
