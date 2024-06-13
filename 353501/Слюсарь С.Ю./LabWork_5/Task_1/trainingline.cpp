#include "trainingline.h"

TrainingLine::TrainingLine(QWidget *parent) : QLineEdit(parent)
{
    
}
void TrainingLine::keyPressEvent(QKeyEvent *event)
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
    bool blank_key = !(event->text().isEmpty());
    if (event->text() == " ")
    {
        blank_key = true;
    }
    emit keyPressed(keyCode, blank_key);
}
void TrainingLine::keyReleaseEvent(QKeyEvent *event)
{
    QLineEdit::keyReleaseEvent(event);
    int keyCode = event->nativeScanCode();
    emit keyReleased(keyCode);
}
void TrainingLine::inputMethodEvent(QInputMethodEvent *event)
{
    QLineEdit::inputMethodEvent(event);
    
    QString text = this->text();
    
    if (!text.isEmpty())
    {
        QChar lastChar = text[text.length() - 1];
        emit lastCharacterEntered(lastChar);
    }
}
