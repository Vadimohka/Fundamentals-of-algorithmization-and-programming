#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <QLineEdit>

class InputManager : public QLineEdit
{
    Q_OBJECT

public:
    InputManager();
    InputManager(QWidget *parent = nullptr);
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void inputMethodEvent(QInputMethodEvent *event) override;
signals:
    void keyPressed(int, bool);
    void keyReleased(int);
};

#endif // INPUTMANAGER_H
