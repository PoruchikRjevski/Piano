#include "sound_player.h"

SoundPlayer::SoundPlayer()
{
    return;
}

SoundPlayer::~SoundPlayer()
{

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

    if (FAILED(this->_engine->CreateMasteringVoice(&this->_masterVoice))) {
        this->deinitPlayer();

        return false;
    }

    return true;
}

void SoundPlayer::deinitPlayer()
{
    this->_engine->Release();

    CoUninitialize();

    return;
}
