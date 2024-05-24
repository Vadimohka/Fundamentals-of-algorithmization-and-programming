#ifndef TRAININGLINE_H
#define TRAININGLINE_H

#include <QLineEdit>
#include <QKeyEvent>

class TrainingLine : public QLineEdit
{
    Q_OBJECT
public:
    TrainingLine();
    TrainingLine(QWidget *parent = nullptr);
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void inputMethodEvent(QInputMethodEvent *event) override;

signals:
    void keyPressed(int, bool);
    void keyReleased(int);
    void lastCharacterEntered(QChar character);

};

#endif // TRAININGLINE_H
