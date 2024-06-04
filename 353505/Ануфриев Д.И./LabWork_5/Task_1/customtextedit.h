#ifndef CUSTOMTEXTEDIT_H
#define CUSTOMTEXTEDIT_H

#include "qevent.h"
#include <QTextEdit>

class CustomTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    CustomTextEdit();

    void inputMethodEvent(QInputMethodEvent *event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;

signals:
    void inputOfText(QInputMethodEvent* event);
    void keyPressed(QKeyEvent* event);
    void oneWordWasInputed();
    void endOfInput();
    void inputIncorrectChar();
    void inputCorrectChar();


private:
    bool isCorrectWord;
};

#endif // CUSTOMTEXTEDIT_H
