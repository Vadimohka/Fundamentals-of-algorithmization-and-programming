#ifndef TRAINER_H
#define TRAINER_H

#include "keyboard.h"
#include <QObject>
#include <QKeyEvent>
#include <QTimer>

class Trainer : public QObject
{
    Q_OBJECT

private:
    const int ROW_LENGTH = 47;

    bool _isRunning = false;
    QString _checkText;
    Keyboard* _aimBoard;
    QTimer* _timer;
    Language _curLang;
    std::array<QString, 7> _keyboardLayout;
    int _correctIn = 0;
    int _sumIn = 0;
    int _wordsCntr = 0;
    QChar _lastChar;
    int _timerCntr = 0;

    bool eventFilter(QObject *target, QEvent *event) override;
    int provideIndex(QString keyText);
    void setColor(QString keyText);

public:
    Trainer(QString checkText, Keyboard* boardPtr, Language curLang, QObject *parent = nullptr);

    Language languge() const;
    double accuracy() const;
    double words() const;
    int seconds() const;
    bool isRunning() const;
    void setLanguage(Language newCurLang);
    void setText(QString checkText);

    void finishCheck();

public slots:
    void StartCheck();
    void OnTimer();

signals:
    void textChanged(QChar);
    void endCheck();
    void updateStat();
};

#endif // TRAINER_H
