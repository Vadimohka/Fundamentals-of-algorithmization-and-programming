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
            // Обработка нажатия клавиши Backspace
            // Удаление последнего символа из строки
            QString currentText = text();
            if (!currentText.isEmpty())
            {
                QChar lastChar = currentText.at(0);
                if (lastChar == '-')
                {
                    minusAllowed = true; // Разрешить ввод знака минус
                }
                currentText.chop(1); // Удалить последний символ
                setText(currentText);
            }
        }
        else
        {
            // Получение введенного символа
            QChar inputChar = event->text().at(0);

            // Проверка, является ли символ цифрой, знаком минуса или знаком плюса
            if (inputChar.isDigit() || inputChar == '-')
            {
                // Если введен знак минуса, проверяем, разрешен ли он
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
    bool minusAllowed; // Разрешить ввод знака минус
};

#endif
