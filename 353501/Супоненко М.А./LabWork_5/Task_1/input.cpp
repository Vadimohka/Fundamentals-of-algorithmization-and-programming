#include "input.h"
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>

InputManager::InputManager(QWidget *parent) : QLineEdit(parent)
{
    
}

void InputManager::setKeys(QVector<QPushButton*> &buttons, QString &str, int lang, QVector<QString> &symbols, QVector<QString> &simbols)
{
    keyboard = buttons;
    text = str;
    language = lang;
    symbolsList = symbols;
    simbolsList = simbols;
}

void InputManager::keyPressEvent(QKeyEvent *event)
{
    qDebug() << event->nativeScanCode();
    qDebug() << event->text();

    int keyCode = event->nativeScanCode();

    if (keyCode == 50){
        for (int i = 0; i < keyboard.size() - 1; i++){
            keyboard[i]->setText(symbolsList[language].at(i * 2));
        }
        if (language == 4){
            keyboard[4]->setText("لإ");
            keyboard[16]->setText("لأ");
            keyboard[27]->setText("لآ");
        }
    }

    if (keyCode >= 38 && keyCode <= 52)
    {
        int adjustedCode = keyCode - 24;
        if (adjustedCode >= 38 && adjustedCode <= 48) adjustedCode -= 2;
        if (adjustedCode >= 52) adjustedCode -= 5;

        bool isCorrect = (keyboard[adjustedCode]->text() == event->text() && event->text() == text[numSymbol]);
        
        keyboard[adjustedCode]->setStyleSheet(isCorrect ? "background-color: green;" : "background-color: red;");
        
        emit keyPressed(adjustedCode, isCorrect, numSymbol);
    }

    QLineEdit::keyPressEvent(event);
    QLineEdit::clear();
}

void InputManager::keyReleaseEvent(QKeyEvent *event)
{
    int keyCode = event->nativeScanCode();

    if (keyCode == 50){
        for (int i = 0; i < keyboard.size() - 1; i++){
            keyboard[i]->setText(simbolsList[language].at(i * 2));
        }
        if (language == 4){
            keyboard[27]->setText("لا");
        }
    }
    else{
        if (keyCode >= 38 && keyCode <= 52)
        {
            int adjustedCode = keyCode - 24;
            if (adjustedCode >= 38 && adjustedCode <= 48) adjustedCode -= 2;
            if (adjustedCode >= 52) adjustedCode -= 5;

            keyboard[adjustedCode]->setStyleSheet("background-color: #f0f0f0;color: #000000;");
        }
    }

    QLineEdit::keyReleaseEvent(event);
    emit keyReleased(1);
}

void InputManager::inputMethodEvent(QInputMethodEvent *e)
{
    if(language == 5 || language == 7){
        QString text = e->preeditString();
        QString commitStr = e->commitString();

        if(commitStr.isEmpty() && !text.isEmpty()){
            for(int i = 0; i < keyboard.size(); i++){
                keyboard[i]->setStyleSheet("background-color: #f0f0f0;color: #000000;");
            }
        }

        if(!commitStr.isEmpty()){
            bool isMatch = true;

            for(int i = 0; i < commitStr.length(); i++){
                if(commitStr[i] != text[numSymbol]){
                    isMatch = false;
                    break;
                }
            }

            for(int i = 0; i < keyboard.size(); i++){
                keyboard[i]->setStyleSheet(isMatch ? "background-color: green;" : "background-color: red;");
            }

            emit keyPressed(isMatch ? -1 : 0, isMatch, numSymbol);
        }

        QLineEdit::inputMethodEvent(e);
    }
}
