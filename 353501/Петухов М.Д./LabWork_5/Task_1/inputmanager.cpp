#include "inputmanager.h"
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>

InputManager::InputManager(QWidget *parent) : QLineEdit(parent)
{
    
}

void InputManager::setKeyboardInInputManager(QVector<QPushButton*> &vectorArg, QString &strArg, int currentLangArg,
                                                 QVector<QString> &SIMVOLS_Arg, QVector<QString> &simvols_Arg){
    keyboard = vectorArg;
    str = strArg;
    numLanguage = currentLangArg;
    SIMVOLS = SIMVOLS_Arg;
    simvols = simvols_Arg;
}

void InputManager::keyPressEvent(QKeyEvent *keyEvent)
{
    qDebug() << keyEvent->nativeScanCode();
    qDebug() << keyEvent->text();
        if(keyEvent->key() == Qt::Key_Space) {
            if (str[numSimvol] == QChar::Space){
                keyboard[33]->setStyleSheet("background-color: green;");
                //correctPresses++;
                //numSimvol++;
                emit keyPressed(-1, true, numSimvol);
            }
            else{keyboard[33]->setStyleSheet("background-color: red;");
                //incorrectPresses++;
                emit keyPressed(-1, false, numSimvol);
            }
        }
        else{
            int a = keyEvent->nativeScanCode();
            if (a == 50){
                for (int i = 0; i < keyboard.size() - 1; i++){
                    keyboard[i]->setText(SIMVOLS[numLanguage].at(i * 2));
                }
                if (numLanguage == 4){
                    keyboard[4]->setText("لإ");
                    keyboard[16]->setText("لأ");
                    keyboard[27]->setText("لآ");
                }
            }
            if (a < 24 || a == 36 || a == 37 || a == 49 || a == 50 || a == 51 || a > 65 || a == 62 || a == 63 || a == 64) {
                return;
            }
            if (a >= 38 && a <= 48) a -= 2;
            if (a >= 52) a -= 5;
            a -= 24;
        
            bool correctCurrent;

            int keyCode = a;
            if (keyboard[keyCode]->text() == keyEvent->text() && keyEvent->text() == str[numSimvol]){
                keyboard[keyCode]->setStyleSheet("background-color: green;");
                    correctCurrent = true;
            }
            else{keyboard[keyCode]->setStyleSheet("background-color: red;");
                correctCurrent = false;
            }
            emit keyPressed(keyCode, correctCurrent, numSimvol);
        }
    QLineEdit::keyPressEvent(keyEvent);
    QLineEdit::clear();
}

void InputManager::keyReleaseEvent(QKeyEvent *keyEvent)
{
    if(keyEvent->key() == Qt::Key_Space) {
        keyboard[33]->setStyleSheet("background-color: #f0f0f0;color: #000000");
    }
    else{
        int a = keyEvent->nativeScanCode();
        if (a == 50){
            for (int i = 0; i < keyboard.size() - 1; i++){
                keyboard[i]->setText(simvols[numLanguage].at(i * 2));
            }
            if (numLanguage == 4){
                keyboard[27]->setText("لا");
            }
        }
        else{
            if (a < 24 || a == 36 || a == 37 || a == 49 || a == 50 || a == 51 || a > 65 || a == 62 || a == 63 || a == 64) {
                return;
            }
            if (a >= 38 && a <= 48) a -= 2;
            if (a >= 52) a -= 5;
            a -= 24;
            int keyCode = a;
            keyboard[keyCode]->setStyleSheet("background-color: #f0f0f0;color: #000000");
        }
    }
    QLineEdit::keyReleaseEvent(keyEvent);
    emit keyReleased(1);
}

void InputManager::inputMethodEvent(QInputMethodEvent *e) {
    if(numLanguage == 5 || numLanguage == 7){
            QString text = e->preeditString();
            QString commitStr = e->commitString();

            if(commitStr.isEmpty() && !text.isEmpty()){
                for(int i = 0; i < keyboard.size(); i++){
                    keyboard[i]->setStyleSheet("background-color: #f0f0f0;color: #000000");
                }
            }

            int keyCode = -1;

            QChar c = ' ';
            for (int i = text.size() - 1; i >= 0; --i)
            {
                if ((text[i].toLatin1() >= 'a' && text[i].toLatin1() <= 'z') ||
                        (text[i].toLatin1() >= 'A' && text[i].toLatin1() <= 'Z'))
                {
                    c = text[i];
                    break;
                }
            }
            if (c.isLetter())
            {
                c = c.toLower();

                if (c == 'a') keyCode = 38;
                if (c == 'b') keyCode = 56;
                if (c == 'c') keyCode = 54;
                if (c == 'd') keyCode = 40;
                if (c == 'e') keyCode = 26;
                if (c == 'f') keyCode = 41;
                if (c == 'g') keyCode = 42;
                if (c == 'h') keyCode = 43;
                if (c == 'i') keyCode = 31;
                if (c == 'j') keyCode = 44;
                if (c == 'k') keyCode = 45;
                if (c == 'l') keyCode = 46;
                if (c == 'm') keyCode = 58;
                if (c == 'n') keyCode = 57;
                if (c == 'o') keyCode = 32;
                if (c == 'p') keyCode = 33;
                if (c == 'q') keyCode = 24;
                if (c == 'r') keyCode = 27;
                if (c == 's') keyCode = 39;
                if (c == 't') keyCode = 28;
                if (c == 'u') keyCode = 30;
                if (c == 'v') keyCode = 55;
                if (c == 'w') keyCode = 25;
                if (c == 'x') keyCode = 53;
                if (c == 'y') keyCode = 29;

                int a = keyCode;
                if (a < 24 || a == 36 || a == 37 || a == 49 || a == 50 || a == 51 || a > 65 || a == 62 || a == 63 || a == 64) {
                    return;
                }
                if (a >= 38 && a <= 48) a -= 2;
                if (a >= 52) a -= 5;
                a -= 24;
                keyCode = a;

                keyCodes.push_back(keyCode);
            }

        ///qDebug() << commitStr << "\n";
        if(!commitStr.isEmpty()){
            chineseWritenWords.push_back(commitStr);

            qDebug() << commitStr << "\n";
            for(int i = 0; i < commitStr.length(); i++){
                qDebug() << commitStr[i] << "\n";
                qDebug() << str[numSimvol] << "\n";        
                if(commitStr[i] != str[numSimvol]){
                    for(int i = 0; i < keyCodes.size(); i++){
                        qDebug() << keyCodes[i] << "\n"; 
                        keyboard[keyCodes[i]]->setStyleSheet("background-color: red;");
                    }
                    keyCodes.clear();
                    emit keyPressed(0, false, numSimvol);
                }
                else{
                    for(int i = 0; i < keyCodes.size(); i++){
                        keyboard[keyCodes[i]]->setStyleSheet("background-color: green;");
                    }
                    keyCodes.clear();
                    emit keyPressed(-1, true, numSimvol);
                }
            }
        }

        QLineEdit::inputMethodEvent(e);
    }
}