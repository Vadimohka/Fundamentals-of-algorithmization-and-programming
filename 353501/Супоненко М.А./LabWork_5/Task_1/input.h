#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <QLineEdit>
#include <QPushButton>

class InputManager : public QLineEdit
{
    Q_OBJECT

public:
    InputManager();
    InputManager(QWidget *parent = nullptr);

    QVector<QPushButton*> keyboard;
    QString str;

    QString chineseWritenWords;

    QVector<int> keyCodes;

    void setKeyboardInInputManager(QVector<QPushButton*> &vectorArg, 
    QString &strArg, int currentLangArg,  QVector<QString> &SIMVOLS_Arg, 
    QVector<QString> &simvols_Arg);

    int numSimvol = 0;
    int numLanguage;

    QVector<QString> SIMVOLS;
    QVector<QString> simvols;
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void inputMethodEvent(QInputMethodEvent *event) override;
signals:
    void keyPressed(int, bool, int &);
    void keyReleased(int);
};

#endif // INPUTMANAGER_H