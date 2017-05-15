#ifndef SOUND_GENERATOR_H
#define SOUND_GENERATOR_H

#include <QObject>
#include <QDebug>
#include <QtQml>

class SoundGenerator : public QObject
{
    Q_OBJECT
public:
    SoundGenerator(QObject *parent = 0);
    ~SoundGenerator();

    enum Notes {
        NOTE_C,
        NOTE_D
    };
    Q_ENUMS(Notes)

    static void declareQML();

public slots:
    void testMethod(unsigned short note);

private:

};

#endif // SOUND_GENERATOR_H
