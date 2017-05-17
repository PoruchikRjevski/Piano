#ifndef WAVE_GENERATOR_H
#define WAVE_GENERATOR_H

#define _USE_MATH_DEFINES

#include "sound_data.h"
#include <cmath>
#include <iostream>

using std::sin;
using std::exp;



class WaveGenerator
{
public:
    static void genNoteData(NoteData &data)
    {
        data._data = new float[data._dataSize];
        float time = 0;
        for (unsigned long i = 1; i <= data._dataSize; i += 2) {
//            float phase = time * data._freq;
//            float res = 0.4f * sin(phase * i) * exp(-0.0005f * phase * i);
//            res      += 0.6f * sin(2.0f * phase * i) * exp(-0.0005f * phase * i);
            data._data[i - 1] = genValue(data._freq, time);
            data._data[i] = genValue(data._freq + FREQ_STEREO_SHIFT, time);

            time += 1;
        }

        return;
    }
    static float genValue(float freq, unsigned long t)
    {
        float phase = _sinMult * t * freq;
        float res = 0.4f * sin(phase) * exp(SUSTAIN_EXP_POW * phase);
        res      += 0.6f * sin(FREQ_STEREO_SHIFT * phase) * exp(SUSTAIN_EXP_POW * phase);

        return res;
    }

private:
    static const float _sinMult;
};

#endif // WAVE_GENERATOR_H
