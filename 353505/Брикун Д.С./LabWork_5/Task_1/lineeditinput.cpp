#include "lineeditinput.h"
#include "qevent.h"
#include <QTimer>

LineEditInput::LineEditInput(QWidget *parent) : QLineEdit(parent)
{

}

void LineEditInput::keyPressEvent(QKeyEvent *event)
{
    // this->moveCursor(QTextCursor::End);
    // this->setCursorPosition();
    // this->textCursor().movePosition(QTextCursor::End);
    this->setCursorPosition(this->text().length());;
    if (event->nativeScanCode() == 22 || event->nativeScanCode() == 110 || event->nativeScanCode() == 115 || event->nativeScanCode() == 111 || event->nativeScanCode() == 113 || event->nativeScanCode() == 114 || event->nativeScanCode() == 116 || event->nativeScanCode() == 119 || event->nativeScanCode() == 104) return;
    QLineEdit::keyPressEvent(event);
    if (!this->isReadOnly()){
        int code = event->nativeScanCode();
        bool proc = !(event->text().isEmpty());
        if (event->text() == " ") proc = true;

        emit keyPressed(code, proc);
    }
}

void LineEditInput::keyReleaseEvent(QKeyEvent *event)
{
    //if (event->nativeScanCode() == 22 || event->nativeScanCode() == 110 || event->nativeScanCode() == 115 || event->nativeScanCode() == 111 || event->nativeScanCode() == 113 || event->nativeScanCode() == 114 || event->nativeScanCode() == 116 || event->nativeScanCode() == 119 || event->nativeScanCode() == 104) return;
    QLineEdit::keyReleaseEvent(event);
    int code = event->nativeScanCode();
    emit keyReleased(code);
}

void LineEditInput::inputMethodEvent(QInputMethodEvent *event)
{
    if (!event->commitString().isEmpty()){
        for (auto i : event->commitString()) {
            this->setText(this->text() + i);
            emit keyPressed(-1, true);
        }
        return;
    }
    QString text = event->preeditString();
    QChar ch = ' ';
    for (int i = text.size() - 1; i >= 0; --i) {
        if (((text[i].toLatin1() >= 'a' && text[i].toLatin1() <= 'z') ||
            (text[i].toLatin1() >= 'A' && text[i].toLatin1() <= 'Z'))){
            ch = text[i];
            break;
        }
    }
    // char aaa = ch.toLatin1();
    // qDebug() << (int)aaa;
    if (ch.isLetter()){
        ch = ch.toLower();
        int code = -1;
        if (ch == 'a') code = 38;
        if (ch == 'b') code = 56;
        if (ch == 'c') code = 54;
        if (ch == 'd') code = 40;
        if (ch == 'e') code = 26;
        if (ch == 'f') code = 41;
        if (ch == 'g') code = 42;
        if (ch == 'h') code = 43;
        if (ch == 'i') code = 31;
        if (ch == 'j') code = 44;
        if (ch == 'k') code = 45;
        if (ch == 'l') code = 46;
        if (ch == 'm') code = 58;
        if (ch == 'n') code = 57;
        if (ch == 'o') code = 32;
        if (ch == 'p') code = 33;
        if (ch == 'q') code = 24;
        if (ch == 'r') code = 27;
        if (ch == 's') code = 39;
        if (ch == 't') code = 28;
        if (ch == 'u') code = 30;
        if (ch == 'v') code = 55;
        if (ch == 'w') code = 25;
        if (ch == 'x') code = 53;
        if (ch == 'y') code = 29;
        emit keyPressed(code, code == -1);
        if (code != -1){
            QTimer *timer = new QTimer(this);
            connect(timer, &QTimer::timeout, [code, timer, this](){
                emit keyReleased(code);
                timer->deleteLater();
            });
            int delayMilliseconds = 500;
            timer->setSingleShot(true);
            timer->start(delayMilliseconds);
        }
    } else {
// qDebug() << "code -1" << ch;
        // emit keyPressed(-1, true);
    }
    QLineEdit::inputMethodEvent(event);
}

