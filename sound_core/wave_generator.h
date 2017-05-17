#ifndef WAVE_GENERATOR_H
#define WAVE_GENERATOR_H

#define _USE_MATH_DEFINES

#include "sound_data.h"
#include <cmath>


using std::sin;

class WaveGenerator
{
public:
    static void genNoteData(NoteData &data, const float &freq)
    {
        for (unsigned long i = 1; i <= data._dataSize; i += 2) {
            data._data[i - 1] = sin(i * _sinPhaseMult * freq);
            data._data[i] = sin(i * _sinPhaseMult * (freq + FREQ_STEREO_SHIFT));
        }

        return;
    }

private:
    static const float _sinPhaseMult;
};

#endif // WAVE_GENERATOR_H
