#ifndef SOUND_GENERATOR_H
#define SOUND_GENERATOR_H

#include <QObject>
#include <QDebug>

#include <XAudio2.h>

class SoundGenerator : public QObject
{
    Q_OBJECT
    Q_ENUMS(Notes)
    Q_ENUMS(Octaves)
public:
    SoundGenerator(QObject *parent = 0);
    ~SoundGenerator();

    enum Octaves {
        SUB_CONTR_OCTAVE = 1,
        BIG_OCTAVE,
        SMALL_OCTAVE,
        FIRST_OCTAVE,
        SEC_OCTAVE,
        THIRD_OCTAVE,
        FOURTH_OCTAVE
    };

    enum Notes {
        UNDEF = 0,
        NOTE_C,
        NOTE_C_SH,
        NOTE_D,
        NOTE_D_SH,
        NOTE_E,
        NOTE_F,
        NOTE_F_SH,
        NOTE_G,
        NOTE_G_SH,
        NOTE_A,
        NOTE_A_SH,
        NOTE_B
    };

public slots:
    void testMethod(float freq);

private:

};


#endif // SOUND_GENERATOR_H
