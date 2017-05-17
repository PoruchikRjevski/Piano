#ifndef SOUND_GENERATOR_H
#define SOUND_GENERATOR_H

#include <QObject>
#include <QDebug>
#include <QMessageBox>
#include <QtQml>
#include <QVector>
#include <QtMath>

#include "xaudio2.h"

#include "sound_player.h"

#define NOTES_PER_OCTAVE        12
#define NOTE_440_NUM            69
#define NOTE_440_FREQ           440

#define SAMPLE_RATE             44100

class SoundManager : public QObject
{
    Q_OBJECT
    Q_ENUMS(Notes)
    Q_ENUMS(Octaves)

public:
    SoundManager(QObject *parent = 0);
    ~SoundManager();


    bool initEnvironment();

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
    void addNote(int note);

    void setCurrentOctave(int octave);

private:
    float getNoteFrequency(int note);


    int _currentOctave;


    SoundPlayer *_player;


    /// XAUDIO2
    void initXAudio();

//    IXAudio2 *xAudio2 = NULL;
//    IXAudio2MasteringVoice *masteringVoice;
//    IXAudio2SourceVoice *sourceVoice;
//    XAUDIO2_BUFFER *aBuffer;

//    static long bufferSize = 44100 * 2;
//    short *bufferSamples;
//    BYTE *buffer;

//    XAudio2 _xAudio;
//    IXAudio2 _xAudio;
//    IXAudio2MasteringVoice * _masteringVoice;
//    IXAudio2SourceVoice * _sourceVoice;


};


#endif // SOUND_GENERATOR_H
