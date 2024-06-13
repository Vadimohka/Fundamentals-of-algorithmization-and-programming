#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <QObject>
#include <QKeyEvent>
#include <QTimer>
#include "keys.h"

const int SECS_IN_MIN = 60;
const int MS_IN_SEC = 1000;

class InputAnalizer : public QObject
{
    Q_OBJECT

private:
    const int ROW_LENGTH = 47;
    bool _isRunning = false;
    QString _checkText;
    VirtualKeyboard* _aimBoard;
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
    InputAnalizer(QString checkText, VirtualKeyboard* boardPtr, Language curLang, QObject *parent = nullptr);
    Language languge() const;
    double accuracy() const;
    double words() const;
    int seconds() const;
    bool isRunning() const;
    void setLanguage(Language newCurLang);
    void setText(QString checkText);
    void finishCheck();

public slots:
    void slotStartCheck();
    void slotOnTimer();

signals:
    void textChanged(QChar);
    void endCheck();
    void updateStat();
};

#endif // VALIDATOR_H
