#ifndef METRONOME_H
#define METRONOME_H

#include "ticker.h"
#include "timer.h"
#include "QWidget"


class Metronome : public QObject
{
    Q_OBJECT
public:

public:
    void createMenu();
    void createVolumeBox();
    void createBPMBox();
    void createButtonBox();
    void createCheckBox();

    QGroupBox *volumeGroupBox;
    QGroupBox *BPMGroupBox;
    QGroupBox *buttonBox;
    QPushButton *playBtn;
    QPushButton *stopBtn;
    QWidget *wdg;
    QSlider *BPMSlider;
    QSlider *volSlider;
    QLabel *volumeLabel;
    QSpinBox *spinBox;
    QLabel *label;
    QCheckBox *firstBeatBox;

    Ticker* ticker;
    Timer* timer;

    Metronome(QObject *parent = 0);
};

#endif // METRONOME_H
