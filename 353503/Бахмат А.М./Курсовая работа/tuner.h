#ifndef TUNER_H
#define TUNER_H

#include <QObject>
#include <QMap>
#include <QSoundEffect>

class Tuner : public QObject
{
    Q_OBJECT
public:
    explicit Tuner(QObject *parent = nullptr);

    enum GuitarType {
        SixString,
        SevenString,
        Ukulele,
        FourStringBass,
        FiveStringBass
    };

    void setGuitarType(GuitarType type);
    double getFrequency(int stringNumber);
    void playFrequency(int stringNumber);

private:
    QMap<int, double> frequencies;
    void updateFrequencies();

    GuitarType currentType;
    QSoundEffect soundEffect;
    QByteArray generateSineWave(double frequency, int sampleRate, int duration);
    QString generateSoundFile(double frequency);
};

#endif // TUNER_H


