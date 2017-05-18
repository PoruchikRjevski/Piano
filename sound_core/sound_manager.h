#ifndef SOUND_GENERATOR_H
#define SOUND_GENERATOR_H

#include <QObject>
#include <QDebug>
#include <QMessageBox>
#include <QtQml>
#include <QQuickView>

#include "xaudio2.h"
#include <cmath>
#include "sound_player.h"
#include "wave_generator.h"

QT_BEGIN_NAMESPACE
class QQuickView;
QT_END_NAMESPACE

using std::pow;

class SoundManager : public QObject
{
    Q_OBJECT
    Q_ENUMS(Notes)
    Q_ENUMS(Octaves)

public:
    SoundManager(QObject *parent = 0);
    ~SoundManager();

    bool initEnvironment();

    void setQmlViewerPtr(QQuickView *view);

    enum Octaves : short {
        SUB_CONTR_OCTAVE = 1,
        CONTR_OCTAVE,
        BIG_OCTAVE,
        SMALL_OCTAVE,
        FIRST_OCTAVE,
        SEC_OCTAVE,
        THIRD_OCTAVE,
        FOURTH_OCTAVE,
        FIVES_OCTAVE
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
    void closeApp();

    void setCurrentOctave(int octave);
    void genNote(short note);
    void delNote(short note);

    void reverbOn();
    void reverbOff();

    void sustainOn();
    void sustainOff();

    void changeVolume(float volume);

private:
    float getNoteFrequency(int note);

    int _currentOctave;

    SoundPlayer *_player;

    QQuickView *_qmlViewer;
};


#endif // SOUND_GENERATOR_H
