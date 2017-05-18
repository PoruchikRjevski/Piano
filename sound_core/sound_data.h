#ifndef SOUND_DATA_H
#define SOUND_DATA_H

#include "xaudio2.h"

#define NOTES_PER_OCTAVE        12
#define NOTE_440_NUM            69
#define NOTE_440_FREQ           440

#define BUFFER_SIZE             176400
#define SAMPLE_RATE             44100
#define CHANNELS                2
#define SAMPLE_BITS             32
#define BYTE_S                  8
#define FREQ_STEREO_SHIFT       2 // shift in Hz for stereo effect
                                  // and for polyphonic sample
#define SUSTAIN_EXP_POW         -0.0001f

struct NoteData {
    short _note;
    unsigned long _dataSize = BUFFER_SIZE;
    float *_data;
    float _freq;
    IXAudio2SourceVoice *_voice;
};

#endif // SOUND_DATA_H
