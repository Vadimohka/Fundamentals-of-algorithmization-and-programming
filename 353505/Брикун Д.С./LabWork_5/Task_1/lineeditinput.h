#ifndef LINEEDITINPUT_H
#define LINEEDITINPUT_H

#include <QLineEdit>

#include <mainwindow.h>

class LineEditInput : public QLineEdit
{
    Q_OBJECT

public:
    LineEditInput();
    LineEditInput(QWidget *parent = nullptr);
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void inputMethodEvent(QInputMethodEvent *event) override;
signals:
    void keyPressed(int, bool);
    void keyReleased(int);
};

#endif // LINEEDITINPUT_H
