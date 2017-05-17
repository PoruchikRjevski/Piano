#ifndef WAVE_GENERATOR_H
#define WAVE_GENERATOR_H

#include "sound_data.h"
#include <cmath>

using std::sin;

class WaveGenerator
{
public:
    static void genNoteData(NoteData &data, const float &freq)
    {
        for (unsigned long i = 0; i < data._dataSize; i += 2) {
            data._data[i] = 0.01f * sin(i * 2 * M_PI * freq / SAMPLE_RATE);
//            data._data[i + 1] = data._data[i];
            data._data[i + 1] = 0.01f * sin(i * 2 * M_PI * (freq + FREQ_STEREO_SHIFT) / SAMPLE_RATE);
        }

        return;
    }
};

#endif // WAVE_GENERATOR_H
