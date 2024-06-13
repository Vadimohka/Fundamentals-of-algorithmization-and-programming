#include"keyboard.h"
#include "qpushbutton.h"
#include<mainwindow.h>
#include<magicnumbers.h>
#include<QMessageBox>>

void KeyBoard::setText(QString text)
{
    this->text = text;
    if(this->text == "")
    {
        text = "â";
    }
    text_edit->clear();
    text_edit->setReadOnly(true);
    text_edit->setTextColor(Qt::lightGray);
    QFont font = text_edit->font();
    font.setPointSize(20);
    text_edit->setFont(font);
    text_edit->setLineWrapMode(QTextEdit::WidgetWidth);
    text_edit->setText(text);
}


void KeyBoard::setLanguage(QString str, QString up_str)
{
    this->language = str;
    this->up_language = up_str;
}

void KeyBoard::setLineEdit(QTextEdit *edit)
{
    this->text_edit = edit;
}

void KeyBoard::paintEvent(QPaintEvent* )
{
    QPainter painter(this);
    QString str = language;
    QString up_str = up_language;
    int SPACE = KEY_WIDTH;
    int KEY_SPACING = TEN;

    struct SpecialKey {
        QString name;
        QRect rect;
        QRect nameRect;
    };

    QList<SpecialKey> specialKeys = {

        {"Tab", QRect(TAB_RECT_X, TAB_RECT_Y, TAB_RECT_WIDTH, TAB_RECT_HEIGHT),
         QRect(TAB_RECT_X_OFFSET, TAB_RECT_Y_OFFSET, TAB_RECT_WIDTH, TAB_RECT_HEIGHT)},
        {"Caps Lock", QRect(CAPS_LOCK_RECT_X, CAPS_LOCK_RECT_Y, CAPS_LOCK_RECT_WIDTH, CAPS_LOCK_RECT_HEIGHT),
         QRect(CAPS_LOCK_RECT_X_OFFSET, CAPS_LOCK_RECT_Y_OFFSET, CAPS_LOCK_RECT_WIDTH, CAPS_LOCK_RECT_HEIGHT)},
        {"BackSpace", QRect(BACKSPACE_RECT_X, BACKSPACE_RECT_Y, BACKSPACE_RECT_WIDTH, BACKSPACE_RECT_HEIGHT),
         QRect(BACKSPACE_RECT_X_OFFSET, BACKSPACE_RECT_Y_OFFSET, BACKSPACE_RECT_WIDTH, BACKSPACE_RECT_HEIGHT)},
        {"Enter", QRect(ENTER_RECT_X, ENTER_RECT_Y, ENTER_RECT_WIDTH, ENTER_RECT_HEIGHT),
         QRect(ENTER_RECT_X_OFFSET, ENTER_RECT_Y_OFFSET, ENTER_RECT_WIDTH, ENTER_RECT_HEIGHT)},
        {"Shift L", QRect(SHIFT_L_RECT_X, SHIFT_L_RECT_Y, SHIFT_L_RECT_WIDTH, SHIFT_L_RECT_HEIGHT),
         QRect(SHIFT_L_RECT_X_OFFSET, SHIFT_L_RECT_Y_OFFSET, SHIFT_L_RECT_WIDTH, SHIFT_L_RECT_HEIGHT)},
        {"Shift R", QRect(SHIFT_R_RECT_X, SHIFT_R_RECT_Y, SHIFT_R_RECT_WIDTH, SHIFT_R_RECT_HEIGHT),
         QRect(SHIFT_R_RECT_X_OFFSET, SHIFT_R_RECT_Y_OFFSET, SHIFT_R_RECT_WIDTH, SHIFT_R_RECT_HEIGHT)},
        {"", QRect(SPACE_RECT_X, SPACE_RECT_Y, SPACE_RECT_WIDTH, SPACE_RECT_HEIGHT),
         QRect(SPACE_RECT_X_OFFSET, SPACE_RECT_Y_OFFSET, SPACE_RECT_WIDTH, SPACE_RECT_HEIGHT)}
    };

    painter.setBrush(QBrush(Qt::white));

    for (int i = 0, x = 0, y = 0; i < str.length(); ++i) {
        if (str[i] == ' ') {
            x = 20;
            y += 80;
            SPACE += 20;
            x+= SPACE;
            continue;
        }

        if (language[i]  ==  text[input.size()] || up_language[i] ==  text[input.size()]) {
            painter.setBrush(QBrush(Qt::green));
        } else {
            painter.setBrush(QBrush(Qt::white));
        }

        QRect keyRect(x, y, KEY_WIDTH, KEY_WIDTH);
        painter.drawRect(keyRect);
        keyMap[language[i]] = keyRect;
        keyMap[up_str[i]] = keyRect;

        QRect keyName_low(x + 30, y + 30, KEY_WIDTH, KEY_WIDTH);
        QRect keyName_up(x + 12, y + 12, KEY_WIDTH, KEY_WIDTH);
        painter.drawText(keyName_up, up_language[i]);
        painter.drawText(keyName_low, language[i]);
        x += KEY_WIDTH + KEY_SPACING;

        if(text[input.size()] >= 'A' && text[input.size()] <= 'Z'){
            constKeyPressed["Shift L"] = true;
        }

        else
        {
            constKeyPressed["Shift L"] = false;
        }

        if(text[input.size()] == ' ' && text.size() - 1 != input.size()){
            constKeyPressed[""] = true;
        }
        else{
            constKeyPressed[""] = false;
        }
    }

    for (const SpecialKey& key : specialKeys) {
        constKey[key.name] = key.rect;
        if (constKeyPressed[key.name]) {
            painter.setBrush(QBrush(Qt::green));
        } else {
            painter.setBrush(QBrush(Qt::white));
        }
        painter.drawRect(key.rect);
        painter.drawText(key.nameRect, key.name);
    }
}

void KeyBoard::keyReleaseEvent(QKeyEvent *event)
{
    if(input.size() < text.size() -1){

    if(input.isEmpty())
    {
        emit firstKeyPress();
    }

    QString key = event->text();

    if (key == "\b")
    {
        handleBackspaceKey();
    }
    else if (!key.isEmpty())
    {
        handleCharacterInput(key);
    }

    if(text[input.size()  - 1] == key)
    {
          emit characterTyped(true);
    }
    else
    {
        emit characterTyped(false);
    }
    updateTextDisplay();
    }

    else
    {
        QMessageBox::about(nullptr, "SUCCSEC", "YOU WRITE ALL TEXT, YOU CAN OUT OR START AGAIN");
    }
}


void KeyBoard::handleBackspaceKey()
{
    if (!input.isEmpty()) {
        input.chop(1);
        if (symbols > 0) {
            --symbols;
        }
        QTextCursor cursor = text_edit->textCursor();
        cursor.deletePreviousChar();
        text_edit->setTextCursor(cursor);
    }
}

void KeyBoard::handleCharacterInput(const QString &key)
{
    input += key;
    if (input.isEmpty()) {
        emit firstKeyPress();
    }
}

void KeyBoard::updateTextDisplay()
{    
    text_edit->clear();

    QTextCursor cursor = text_edit->textCursor();

    for(int i = 0; i < input.size(); ++i){
        QTextCharFormat format;

        if(input[i] == text[i] && input.size() <= text.size())
        {
            format.setForeground(QColor(Qt::darkGreen));
        }
        else
        {
            format.setForeground(QColor(Qt::red));
        }
        cursor.insertText(QString(input[i]), format);
    }

    if (input.size() < text.size()) {
        QString remainder = text.mid(input.size());
        QTextCharFormat format;
        format.setForeground(QColor(Qt::lightGray));
        cursor.insertText(remainder, format);
    }

    text_edit->setTextCursor(cursor);
    update();
}

void KeyBoard::reloadtext()
{
    qDebug() << "update";
    input = "";
    text_edit->clear();
    text_edit->setText(text);
}
