#ifndef TRAINING_H
#define TRAINING_H

#include <QLineEdit>
#include <QKeyEvent>

class Training: public QLineEdit
{
    Q_OBJECT
public:
    Training();
    Training(QWidget *parent = nullptr);
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void inputMethodEvent(QInputMethodEvent *event) override;

signals:
    void keyPressed(int, bool);
    void keyReleased(int);
    void lastCharacterEntered(QChar character);

};

#endif // TRAINING_H
