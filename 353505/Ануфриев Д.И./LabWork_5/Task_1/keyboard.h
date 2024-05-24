#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <QTextEdit>
#include <QPushButton>
#include <QKeyEvent>
#include <QButtonGroup>
#include <QLayout>
#include <QInputMethod>

class Keyboard : public QVBoxLayout
{
    Q_OBJECT
public:
    Keyboard();

    void keyPressEvent(QKeyEvent* event);

    void initializeKeyButtonVector();


    void setBelaruisan();
    void setGerman();
    void setFrench();
    void setArabic();
    void setHebrew();
    void setChinese();
    void clear();

    void setTextEdit(QTextEdit* textEdit);

private:

    QTextEdit* textEdit;
    bool isCorrectWord;

    QVector <QPushButton*> buttons;
    QMap<QString, QPushButton*> keyButtonMap;
    QMap<int, QPushButton*> idsOfButtons;

    QHBoxLayout* firstRow;
    QHBoxLayout* secondRow;
    QHBoxLayout* thirdRow;
    QHBoxLayout* fourthRow;
    QHBoxLayout* fifthRow;

    QPushButton* graveButton;
    QPushButton* num1Button;
    QPushButton* num2Button;
    QPushButton* num3Button;
    QPushButton* num4Button;
    QPushButton* num5Button;
    QPushButton* num6Button;
    QPushButton* num7Button;
    QPushButton* num8Button;
    QPushButton* num9Button;
    QPushButton* num0Button;
    QPushButton* minusButton;
    QPushButton* equalButton;

    QPushButton* tabButton;
    QPushButton* qButton;
    QPushButton* wButton;
    QPushButton* eButton;
    QPushButton* rButton;
    QPushButton* tButton;
    QPushButton* yButton;
    QPushButton* uButton;
    QPushButton* iButton;
    QPushButton* oButton;
    QPushButton* pButton;
    QPushButton* leftSquareScopeButton;
    QPushButton* rightSquareScopeButton;
    QPushButton* backSlashButton;

    QPushButton* capsLockButton;
    QPushButton* aButton;
    QPushButton* sButton;
    QPushButton* dButton;
    QPushButton* fButton;
    QPushButton* gButton;
    QPushButton* hButton;
    QPushButton* jButton;
    QPushButton* kButton;
    QPushButton* lButton;
    QPushButton* semicolonButton;
    QPushButton* apostropheButton;
    QPushButton* enterButton;

    QPushButton* leftShiftButton;
    QPushButton* zButton;
    QPushButton* xButton;
    QPushButton* cButton;
    QPushButton* vButton;
    QPushButton* bButton;
    QPushButton* nButton;
    QPushButton* mButton;
    QPushButton* commaButton;
    QPushButton* dotButton;
    QPushButton* slashButton;
    QPushButton* rightShiftButton;

    QPushButton* leftCtrlButton;
    QPushButton* leftFnButton;
    QPushButton* winButton;
    QPushButton* leftAltButton;
    QPushButton* spaceButton;
    QPushButton* rightAltButton;
    QPushButton* rightFnButton;
    QPushButton* rightCtrlButton;

signals:
    // void oneWordWasInputed();
    // void endOfInput();
    // void inputIncorrectChar();
    // void inputCorrectChar();

};

#endif // KEYBOARD_H
