#ifndef TRAININGLINE_H
#define TRAININGLINE_H

#include <QLineEdit>
#include <QKeyEvent>

class Train : public QLineEdit
{
    Q_OBJECT
public:
    Train();
    Train(QWidget *parent = nullptr);
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void inputMethodEvent(QInputMethodEvent *event) override;

signals:
    void KeyPressed(int, bool);
    void KeyReleased(int);
    void LastCharacterEntered(QChar character);

};

#endif // TRAININGLINE_H
