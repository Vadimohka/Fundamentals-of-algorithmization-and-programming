#pragma once

#include <QLineEdit>
#include <QKeyEvent>

#ifndef LONGLONGVAL_H
#define LONGLONGVAL_H

class CustomLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    CustomLineEdit(QWidget *parent = nullptr) : QLineEdit(parent), minusAllowed(true) {}

protected:
    void keyPressEvent(QKeyEvent *event)
    {
        if (event->key() == Qt::Key_Backspace)
        {
           
            QString currentText = text();
            if (!currentText.isEmpty())
            {
                QChar lastChar = currentText.at(0);
                if (lastChar == '-')
                {
                    minusAllowed = true; 
                }
                currentText.chop(1); 
                setText(currentText);
            }
        }
        else
        {
         
            QChar inputChar = event->text().at(0);

            if (inputChar.isDigit() || inputChar == '-')
            {
              
                if (inputChar == '-')
                {
                    if (minusAllowed)
                    {
                        minusAllowed = false; // Запретить дополнительные знаки минуса
                        QLineEdit::keyPressEvent(event);
                    }
                }
                else
                {
                    minusAllowed = false;
                    QLineEdit::keyPressEvent(event);
                }
            }
            else
            {
                // Игнорировать другой ввод
                event->ignore();
            }
        }
    }

private:
    bool minusAllowed; 
};

#endif
