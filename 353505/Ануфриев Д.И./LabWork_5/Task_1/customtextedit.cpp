#include "customtextedit.h"
#include "qevent.h"

CustomTextEdit::CustomTextEdit()
{
    isCorrectWord = true;
    setLocale(QLocale());
}

void CustomTextEdit::inputMethodEvent(QInputMethodEvent *event)
{
    if(event->commitString() != "")
    {
        QKeyEvent keyEvent(QEvent::KeyPress, Qt::Key_unknown, Qt::NoModifier, event->commitString());
        emit keyPressed(&keyEvent);

        QTextCharFormat format;
        QTextCursor cursor = this->textCursor();
        QString text = this->toPlainText();

        if(cursor.position() + event->commitString().size() <= text.size())
        {
            cursor.setPosition(cursor.position() + event->commitString().size(), QTextCursor::KeepAnchor);

            if(text.mid(cursor.position() - event->commitString().size(), event->commitString().size()) == event->commitString())
            {
                format.setForeground(QColor("#52F24D")); // Устанавливаем зеленый цвет
                cursor.setCharFormat(format);

                emit inputCorrectChar();
            }
            else
            {
                if(!QString(" ,.;:()[]{}。").contains(text[cursor.position() - 1]))
                {
                    isCorrectWord = false;
                }

                format.setForeground(QColor("#D20000")); // Устанавливаем красный цвет
                cursor.setCharFormat(format);

                emit inputIncorrectChar();
            }

            cursor.setPosition(cursor.position());
            this->setTextCursor(cursor);
        }

        if(cursor.position() == text.size()) //&& text[text.size() - 1] != '.'
        {
            if(isCorrectWord) emit oneWordWasInputed();
            emit endOfInput();
        }

        if(cursor.position() < text.size() &&
            !QString(" ,.;:()[]{}。").contains(text[cursor.position() - 1]) &&
            QString(" ,.;:()[]{}。").contains(text[cursor.position()]))
        {
            if(isCorrectWord) emit oneWordWasInputed();
            isCorrectWord = true;
        }
    }
    event->ignore();

}

void CustomTextEdit::keyPressEvent(QKeyEvent *event)
{
    emit keyPressed(event);

    if(event->key() != Qt::Key_Left && event->key() != Qt::Key_Right && event->key() != Qt::Key_Up && event->key() != Qt::Key_Down
        && event->key() != Qt::Key_CapsLock && event->key() != Qt::Key_Shift && event->key() != Qt::Key_Backspace && event->key() != Qt::Key_Tab
        && event->key() != Qt::Key_Enter && event->key() != Qt::Key_Control && event->key() != Qt::Key_Alt && event->modifiers() != Qt::GroupSwitchModifier
        && !(event->modifiers() == (Qt::AltModifier | Qt::GroupSwitchModifier))
        && !(event->modifiers() == (Qt::ShiftModifier | Qt::MetaModifier))
        && !(event->modifiers() == (Qt::ShiftModifier | Qt::GroupSwitchModifier)))
    {
        QTextCharFormat format;
        QTextCursor cursor = this->textCursor();
        QString text = this->toPlainText();


        if(cursor.position() < text.size())
        {
            cursor.setPosition(cursor.position() + 1, QTextCursor::KeepAnchor);

            if(QChar(text[cursor.position() - 1]) == event->text())
            {
                format.setForeground(QColor("#52F24D")); // Устанавливаем красный цвет
                cursor.setCharFormat(format);

                emit inputCorrectChar();
            }
            else
            {
                if(!QString(" ,.;:()[]{}。").contains(text[cursor.position() - 1]))
                {
                    isCorrectWord = false;
                    qDebug() << "is incorrect word";
                }

                format.setForeground(QColor("#D20000")); // Устанавливаем красный цвет
                cursor.setCharFormat(format);

                emit inputIncorrectChar();
            }

            cursor.setPosition(cursor.position());
            this->setTextCursor(cursor);
        }

        if(cursor.position() == text.size()) //&& text[text.size() - 1] != '.'
        {
            if(isCorrectWord) emit oneWordWasInputed();
            emit endOfInput();
        }

        if(cursor.position() < text.size() &&
            !QString(" ,.;:()[]{}。").contains(text[cursor.position() - 1]) &&
            QString(" ,.;:()[]{}。").contains(text[cursor.position()]))
        {
            if(isCorrectWord) emit oneWordWasInputed();

            isCorrectWord = true;
        }
    }

}

void CustomTextEdit::mousePressEvent(QMouseEvent *event)
{
    event->ignore();
}

void CustomTextEdit::mouseDoubleClickEvent(QMouseEvent *event)
{
    event->ignore();
}
