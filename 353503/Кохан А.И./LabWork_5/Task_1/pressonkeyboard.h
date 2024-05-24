#ifndef PRESSONKEYBOARD_H
#define PRESSONKEYBOARD_H

#include <QLineEdit>

class PressOnKeyboard : public QLineEdit
{
    Q_OBJECT

public:
    explicit PressOnKeyboard(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

signals:
    void keyPressed(int, bool);
    void keyReleased(int);
};

#endif // PRESSONKEYBOARD_H
