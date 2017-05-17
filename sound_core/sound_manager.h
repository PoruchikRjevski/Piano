#ifndef SOUND_GENERATOR_H
#define SOUND_GENERATOR_H

#include <QObject>
#include <QDebug>
#include <QMessageBox>
#include <QtQml>

#include "xaudio2.h"
#include <cmath>
#include "sound_player.h"
#include "wave_generator.h"

using std::pow;

#define NOTES_PER_OCTAVE        12
#define NOTE_440_NUM            69
#define NOTE_440_FREQ           440

class SoundManager : public QObject
{
    Q_OBJECT
    Q_ENUMS(Notes)
    Q_ENUMS(Octaves)

public:
    SoundManager(QObject *parent = 0);
    ~SoundManager();

    bool initEnvironment();

    enum Octaves : short {
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
    enum Notes : short {
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
    void setCurrentOctave(int octave);
    void genNote(short note);
    void delNote(short note);

private:
    float getNoteFrequency(int note);
//    void genNoteData(NoteData &data, const float &freq);

    int _currentOctave;

    SoundPlayer *_player;
};


#endif // SOUND_GENERATOR_H
