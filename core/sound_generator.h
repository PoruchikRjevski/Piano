#ifndef SOUND_GENERATOR_H
#define SOUND_GENERATOR_H

#include <QObject>
#include <QDebug>
#include <QtQml>
#include <QVector>
#include <QtMath>

#include <XAudio2.h>

#define NOTES_PER_OCTAVE        12
#define NOTE_440_NUM            69
#define NOTE_440_FREQ           440

#define SAMPLE_RATE             44100

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
        CONTR_OCTAVE,
        BIG_OCTAVE,
        SMALL_OCTAVE,
        FIRST_OCTAVE,
        SEC_OCTAVE,
        THIRD_OCTAVE,
        FOURTH_OCTAVE,
        FIVE_OCTAVE
    };
    enum Notes {
        UNDEF = -1,
        NOTE_C = 0,
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
    void playNote(int note);

    void setCurrentOctave(int octave);

private:
    float getNoteFrequency(int note);

    int _currentOctave;



};


#endif // SOUND_GENERATOR_H
