#ifndef TICKER_H
#define TICKER_H

#include <QObject>
#include <QtWidgets>
#include <QtMultimedia>


class Ticker : public QObject
{
    Q_OBJECT
public:
    explicit Ticker(QObject *parent = 0);
public slots:
    void playSound();
    void setVolumeLevel(int volLevelRequest);
    void reqToStressFirstBeat();

private:
    void playHigh();
    void playLow();
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    int counter;
    bool stressFirstBeat;
};

#endif // TICKER_H
