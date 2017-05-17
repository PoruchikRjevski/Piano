#ifndef SOUND_DATA_H
#define SOUND_DATA_H

#include "xaudio2.h"

#define BUFFER_SIZE         88200
#define SAMPLE_RATE         44100
#define CHANNELS            2
#define SAMPLE_BITS         32
#define BYTE_S              8
#define FREQ_STEREO_SHIFT   2

struct NoteData {
    unsigned long _dataSize = BUFFER_SIZE;
    float _data[BUFFER_SIZE];
};

#endif // SOUND_DATA_H
