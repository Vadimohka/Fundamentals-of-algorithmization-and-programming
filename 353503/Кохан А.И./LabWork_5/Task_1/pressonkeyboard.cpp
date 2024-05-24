#include "pressonkeyboard.h"
#include <QTimer>
#include "qevent.h"

PressOnKeyboard::PressOnKeyboard(QWidget *parent)
    : QLineEdit(parent)
{}

void PressOnKeyboard::keyPressEvent(QKeyEvent *event)
{
    qDebug() << event->key();
    this->setCursorPosition(this->text().length());
    QLineEdit::keyPressEvent(event);
    bool checkSpace = !(event->text().isEmpty());
    if (event->text() == " ") {
        checkSpace = true;
    }
    qDebug() << event->nativeScanCode();
    emit keyPressed(event->nativeScanCode(), checkSpace);
    QLineEdit::clear();
}

void PressOnKeyboard::keyReleaseEvent(QKeyEvent *event)
{
    QLineEdit::keyReleaseEvent(event);
    emit keyReleased(event->nativeScanCode());
}
