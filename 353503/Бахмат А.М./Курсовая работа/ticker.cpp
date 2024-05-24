#include "ticker.h"

Ticker::Ticker(QObject *parent) : QObject(parent)
{
    counter = 0;
    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(this);

    playlist->addMedia(QUrl("qrc:/MediaFiles/high.mp3"));
    playlist->addMedia(QUrl("qrc:/MediaFiles/low.mp3"));

    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
    playlist->setCurrentIndex(0);
    player->setPlaylist(playlist);
    player->setVolume(60);
    stressFirstBeat = true;

}

void Ticker::playSound()
{
    if (stressFirstBeat == true)
    {
        if (counter == 0)
        {
            this->playHigh();
        }
        else
            this->playLow();

        if (counter >= 3)
            counter = 0;
        else
            counter++;
    }
    else
    {
        this->playLow();
    }
}

void Ticker::playHigh()
{
    playlist->setCurrentIndex(0);
    player->play();
}

void Ticker::playLow()
{
    playlist->setCurrentIndex(1);
    player->play();
}

void Ticker::setVolumeLevel(int volLevelRequest)
{
    player->setVolume(volLevelRequest);
}

void Ticker::reqToStressFirstBeat()
{
    stressFirstBeat = !stressFirstBeat;
    counter = 0;
}
