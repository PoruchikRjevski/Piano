#ifndef SOUND_PLAYER_H
#define SOUND_PLAYER_H

#include "xaudio2.h"

class SoundPlayer
{
public:
    SoundPlayer();
    ~SoundPlayer();


    bool initPlayer();
    void deinitPlayer();

private:
    IXAudio2 *_engine = nullptr;
    IXAudio2MasteringVoice *_masterVoice = nullptr;



};

#endif // SOUND_PLAYER_H
