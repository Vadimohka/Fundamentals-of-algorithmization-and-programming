#include "consoleedit.h"



ConsoleEdit::ConsoleEdit()
{
    this->setTextInteractionFlags(Qt::TextEditorInteraction);
    isInput = false;
}

void ConsoleEdit::keyPressEvent(QKeyEvent *event)
{
    if(this->textCursor().hasSelection())
    {
        QTextCursor cursor = this->textCursor();
        cursor.clearSelection();
        this->setTextCursor(cursor);
    }
    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_Down)
    {

    }
    else if (event->key() == Qt::Key_Left)
    {
        QTextCursor cursor = textCursor();
        if (cursor.positionInBlock() == 0)
        {

        }
        else QTextEdit::keyPressEvent(event);
    }
    else if (event->key() == Qt::Key_Backspace)
    {
        QTextCursor cursor = textCursor();
        if (cursor.positionInBlock() == 0)
        {

        }
        else QTextEdit::keyPressEvent(event);
    }
    else
    {
        if(event->key() == Qt::Key_Enter || event->key() == 16777220)
        {
            QString text = this->toPlainText();
            QStringList lines = text.split("\n");

            if (!lines.isEmpty()) {
                currentString = lines.last();
                emit inputFinished();
                isInput = false;
            }

            if(!currentString.isEmpty()) qDebug() << currentString;
        }

        QTextEdit::keyPressEvent(event);
    }
}

void ConsoleEdit::mousePressEvent(QMouseEvent *event)
{
}

void ConsoleEdit::mouseDoubleClickEvent(QMouseEvent *event)
{

}

void ConsoleEdit::print(QString string)
{
    this->insertPlainText(string);
    QTextCursor cursor = textCursor();
    cursor.movePosition(QTextCursor::End);
    setTextCursor(cursor);
}

void ConsoleEdit::print(std::string string)
{
    this->insertPlainText(QString::fromStdString(string));
    QTextCursor cursor = textCursor();
    cursor.movePosition(QTextCursor::End);
    setTextCursor(cursor);
}

void ConsoleEdit::print(const char *string)
{
    this->insertPlainText(QString(string));
    QTextCursor cursor = textCursor();
    cursor.movePosition(QTextCursor::End);
    setTextCursor(cursor);
}

void ConsoleEdit::print(wchar_t ch)
{
    std::wstring str;
    str += ch;
    this->insertPlainText(QString::fromStdWString(str));

    QTextCursor cursor = textCursor();
    cursor.movePosition(QTextCursor::End);
    setTextCursor(cursor);
}

QString ConsoleEdit::input(QEventLoop &loop)
{
    loop.exec();
    QString ret = currentString;
    return ret;
}

QString ConsoleEdit::getCurrentString()
{
    return currentString;
}

