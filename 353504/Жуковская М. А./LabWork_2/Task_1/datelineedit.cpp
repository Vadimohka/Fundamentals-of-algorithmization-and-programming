#include "datelineedit.h"

DateLineEdit::DateLineEdit() {}

void DateLineEdit::keyPressEvent(QKeyEvent *event)
{
    QString currentText = this->text();

    if ((event->key() >= Qt::Key_0 && event->key() <= Qt::Key_9) || event->key() == Qt::Key_Period)
    {
        currentText += event->text();
    }

    else if (event->key() == Qt::Key_Backspace)
    {
        if (!currentText.isEmpty())
        {
            currentText.chop(1);
        }
    }

    this->setText(currentText);

    QLineEdit::keyPressEvent(event);
}
