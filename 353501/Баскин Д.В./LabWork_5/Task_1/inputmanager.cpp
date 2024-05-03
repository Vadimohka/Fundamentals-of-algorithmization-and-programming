#include "inputmanager.h"
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>

InputManager::InputManager(QWidget *parent) : QLineEdit(parent)
{

}

void InputManager::keyPressEvent(QKeyEvent *event)
{
    this->setCursorPosition(this->text().length());
    if (event->nativeScanCode() == 22 || event->nativeScanCode() == 110 ||
        event->nativeScanCode() == 115 || event->nativeScanCode() == 111 ||
        event->nativeScanCode() == 113 || event->nativeScanCode() == 114 ||
        event->nativeScanCode() == 116 || event->nativeScanCode() == 119 ||
        event->nativeScanCode() == 104 || event->nativeScanCode() == 9)
    {
        return;
    }
    QLineEdit::keyPressEvent(event);
    int keyCode = event->nativeScanCode();
    bool sp = !(event->text().isEmpty());
    if (event->text() == " ")
    {
        sp = true;
    }
    emit keyPressed(keyCode, sp);
    QLineEdit::clear();
}

void InputManager::keyReleaseEvent(QKeyEvent *event)
{
    QLineEdit::keyReleaseEvent(event);
    int keyCode = event->nativeScanCode();
    emit keyReleased(keyCode);
}

void InputManager::inputMethodEvent(QInputMethodEvent *event)
{
    if (!event->commitString().isEmpty())
    {
        for (QString str : event->commitString())
        {
            this->setText(this->text() + str);
            emit keyPressed(-1, true);
        }
        return;
    }
    QString text = event->preeditString();
    QChar c = ' ';
    for (int i = text.size() - 1; i >= 0; --i)
    {
        if ((text[i].toLatin1() >= 'a' && text[i].toLatin1() <= 'z') ||
             (text[i].toLatin1() >= 'A' && text[i].toLatin1() <= 'Z'))
        {
            c = text[i];
            break;
        }
    }
    if (c.isLetter())
    {
        c = c.toLower();
        int keyCode = -1;
        if (c == 'a') keyCode = 38;
        if (c == 'b') keyCode = 56;
        if (c == 'c') keyCode = 54;
        if (c == 'd') keyCode = 40;
        if (c == 'e') keyCode = 26;
        if (c == 'f') keyCode = 41;
        if (c == 'g') keyCode = 42;
        if (c == 'h') keyCode = 43;
        if (c == 'i') keyCode = 31;
        if (c == 'j') keyCode = 44;
        if (c == 'k') keyCode = 45;
        if (c == 'l') keyCode = 46;
        if (c == 'm') keyCode = 58;
        if (c == 'n') keyCode = 57;
        if (c == 'o') keyCode = 32;
        if (c == 'p') keyCode = 33;
        if (c == 'q') keyCode = 24;
        if (c == 'r') keyCode = 27;
        if (c == 's') keyCode = 39;
        if (c == 't') keyCode = 28;
        if (c == 'u') keyCode = 30;
        if (c == 'v') keyCode = 55;
        if (c == 'w') keyCode = 25;
        if (c == 'x') keyCode = 53;
        if (c == 'y') keyCode = 29;

        emit keyPressed(-1, keyCode == -1);

        if (keyCode != -1)
        {
            QTimer *timer = new QTimer(this);

            connect(timer, &QTimer::timeout,
            [keyCode, timer, this]()
            {
                emit keyReleased(keyCode);
                timer->deleteLater();
            });

            int delay = 500;
            timer->setSingleShot(true);
            timer->start(delay);
        }
    }
    QLineEdit::inputMethodEvent(event);
}
