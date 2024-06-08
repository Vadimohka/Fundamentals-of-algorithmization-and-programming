#ifndef SETTINGS_H
#define SETTINGS_H

#include "mainmenu.h"

class Settings : public QDialog {
    Q_OBJECT
public:
    Settings(QWidget *parent = nullptr);
    void reject();
    void setState();
    void revertState();
    void readSettings();
    void writeSettings();
signals:
    void bgmAdjust(int);
    void sfxAdjust(int);
private slots:
    void bgmChanged();
    void sfxChanged();
    void confirm();
private:
    int bgm;
    int sfx;
    QLabel *bgmLabel;
    QLabel *sfxLabel;
    QSlider *bgmSlider;
    QSlider *sfxSlider;
    QSpinBox *bgmSpinBox;
    QSpinBox *sfxSpinBox;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
};

#endif // SETTINGS_H
