#include "sound_player.h"

SoundPlayer::SoundPlayer()
{
    return;
}

SoundPlayer::~SoundPlayer()
{
    this->deinitPlayer();

    return;
}

void SoundPlayer::playNote(NoteData &data)
{
    XAUDIO2_BUFFER aBuffer = {};

    // create source voice
    if (FAILED(this->_engine->CreateSourceVoice(&data._voice, &this->_waveFormatex))) {
        return;
    }

    // create audio buffer
    aBuffer.AudioBytes = data._dataSize * SAMPLE_BITS / BYTE_S;
    aBuffer.pAudioData = reinterpret_cast<BYTE *>(data._data);
    aBuffer.Flags = XAUDIO2_END_OF_STREAM;
    aBuffer.LoopCount = XAUDIO2_NO_LOOP_REGION;

    // submit buffer to source
    if (FAILED(data._voice->SubmitSourceBuffer(&aBuffer))) {
        return;
    }

    data._voice->Start();

    this->_sourceVoices.insert(pair<short, NoteData>(data._note, data));

    return;
}

void SoundPlayer::stopNote(short &note)
{
    auto it = this->_sourceVoices.find(note);

    if (it != this->_sourceVoices.end()) {
        it->second._voice->Stop();
        it->second._voice->FlushSourceBuffers();
        it->second._voice->DestroyVoice();

        delete [] it->second._data;

        this->_sourceVoices.erase(it);
    }

    return;
}

bool SoundPlayer::initPlayer()
{
    CoInitializeEx(nullptr, 0);

    if (FAILED(XAudio2Create(&this->_engine,
                             0,
                             XAUDIO2_DEFAULT_PROCESSOR))) {
        return false;
    }

    if (FAILED(this->_engine->CreateMasteringVoice(&this->_masterVoice,
                                                   XAUDIO2_DEFAULT_CHANNELS,
                                                   XAUDIO2_DEFAULT_SAMPLERATE))) {
        this->deinitPlayer();

        return false;
    }

    this->initWaveFormat();

    return true;
}

void SoundPlayer::deinitPlayer()
{
    this->_engine->Release();

    CoUninitialize();

    return;
}

void SoundPlayer::setVolume(float volume)
{
    this->_masterVoice->SetVolume(volume);

    return;
}

void SoundPlayer::initWaveFormat()
{
    this->_waveFormatex.wBitsPerSample = SAMPLE_BITS;
    this->_waveFormatex.nAvgBytesPerSec = SAMPLE_RATE * CHANNELS * SAMPLE_BITS / BYTE_S;
    this->_waveFormatex.nChannels = CHANNELS;
    this->_waveFormatex.nBlockAlign = CHANNELS * SAMPLE_BITS / BYTE_S;
    this->_waveFormatex.wFormatTag = WAVE_FORMAT_IEEE_FLOAT;
    this->_waveFormatex.nSamplesPerSec = SAMPLE_RATE;
    this->_waveFormatex.cbSize = 0;

    return;
}
