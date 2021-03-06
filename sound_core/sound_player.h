#ifndef SOUND_PLAYER_H
#define SOUND_PLAYER_H

#include <map>
#include <iterator>

#include "sound_data.h"

using std::map;
using std::pair;

class SoundPlayer
{
public:
    SoundPlayer();
    ~SoundPlayer();

    void playNote(NoteData &data);
    void stopNote(short &note);

    bool initPlayer();
    void deinitPlayer();

    void setVolume(float volume);

private:
    void initWaveFormat();

    IXAudio2 *_engine = nullptr;
    IXAudio2MasteringVoice *_masterVoice = nullptr;

    WAVEFORMATEX _waveFormatex;

    map<short, NoteData> _sourceVoices;
};

#endif // SOUND_PLAYER_H
