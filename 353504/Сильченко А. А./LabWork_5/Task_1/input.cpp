#include "input.h"

Input::Input(QString checkText, Keyboard *boardPtr, Language curLang, QObject *parent)
    : QObject{parent}
    , _checkText(checkText)
    , _aimBoard(boardPtr)
    , _timer(new QTimer(this))
    , _curLang(curLang)
{
    _keyboardLayout = _aimBoard->getLayouts();
    connect(_timer, SIGNAL(timeout()), SLOT(slotOnTimer()));
}


Language Input::languge() const
{
    return _curLang;
}

double Input::accuracy() const
{
    if (_sumIn != 0) {
        return _correctIn / static_cast<double>(_sumIn);
    }
    return 0;
}

double Input::words() const
{
    if (_timerCntr <= SECS_IN_MIN) {
        return _wordsCntr;
    }

    return _wordsCntr * SECS_IN_MIN / static_cast<double>(_timerCntr);
}

int Input::seconds() const
{
    return _timerCntr;
}

bool Input::isRunning() const
{
    return _isRunning;
}


void Input::setLanguage(Language newCurLang)
{
    _curLang = newCurLang;
}

void Input::setText(QString checkText)
{
    _checkText = checkText;
}


void Input::slotStartCheck()
{
    _timer->start(MS_IN_SEC);
    _isRunning = true;
    _correctIn = 0;
    _sumIn = 0;
    _wordsCntr = 0;
    _lastChar = ' ';
    _timerCntr = 0;
}

void Input::slotOnTimer()
{
    ++_timerCntr;
    emit updateStat();
}

void Input::finishCheck()
{
    _timer->stop();
    _isRunning = false;
    _aimBoard->makeGrey();
    emit endCheck();
}


bool Input::eventFilter(QObject *target, QEvent *event)
{
    if (event->type() == QEvent::KeyRelease && _isRunning) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (!_checkText.isEmpty()) {
            setColor(keyEvent->text());
        }
    }

    return QObject::eventFilter(target, event);
}


int Input::provideIndex(QString keyText)
{
    if (keyText == QString(" ")) {
        return ROW_LENGTH;
    }
    if (keyText == QString("\n")) {
        return ROW_LENGTH + 1;
    }
    for (int i = 0; i < ROW_LENGTH; ++i) {
        if (keyText == QString(_keyboardLayout.at(static_cast<int>(_curLang)).at(i)) ||
            keyText == QString(_keyboardLayout.at(static_cast<int>(_curLang)).at(i)).toUpper()) {
            return i;
        }
    }
    for (int j = 0; j < 6; ++j) {
        for (int i = 0; i < ROW_LENGTH; ++i) {
            if (keyText == QString(_keyboardLayout.at(j).at(i)) || keyText == QString(_keyboardLayout.at(j).at(i)).toUpper()) {
                return i;
            }
        }
    }
    return -1;
}

void Input::setColor(QString keyText)
{
    if (!keyText.isEmpty()) {
        keyText = (keyText.at(0) == '\r' ? QString("\n") : keyText);
    }
    int index = provideIndex(keyText);
    if (index == -1) {
        return;
    }

    if (_lastChar != ' ' && keyText.at(0) == ' ') {
        ++_wordsCntr;
    }
    _lastChar = keyText.at(0);

    ++_sumIn;
    if (keyText.at(0) == _checkText.at(0)) {
        ++_correctIn;
        _aimBoard->makeGreen(index);
    } else {
        _aimBoard->makeRed(index);
    }

    _checkText.erase(_checkText.cbegin());
    emit textChanged(_lastChar);

    if (_checkText.isEmpty()) {
        if (keyText.at(0) != ' ') {
            ++_wordsCntr;
        }
        finishCheck();
        return;
    }
}
