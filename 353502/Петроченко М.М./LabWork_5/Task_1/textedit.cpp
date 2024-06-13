//
// Created by acryoz on 5/12/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TextEdit.h" resolved

#include "../headers/textedit.h"
#include "ui_textedit.h"

TextEdit::TextEdit(QWidget* parent) : QTextEdit(parent), ui(new Ui::TextEdit) {
    ui->setupUi(this);
    this->text = QString();
    this->mask = QString();
    this->cursor = this->textCursor();
    this->current_char = 0;
    QFont font("JetBrains");
    font.setPointSize(FONT_SiZE);
    this->setFont(font);
    this->words = 0;
}

void TextEdit::setText(QString string) {
    for (int i = 0; i < string.length(); ++i) {
        this->mask.push_back('n');
    }
    this->text = string;
    this->setTextColor(QColor::fromRgb(140, 140, 140));
    this->setPlainText(string);
}

void TextEdit::terminate() {
    this->reprint();
    this->current_char = 0;
    this->mask.fill('n', this->text.size());
    emit ended(this->words);
}

void TextEdit::text_inputed(QString str) {
    if (str == "\b") {
        if (this->current_char != 0) {
            this->current_char--;
            this->mask[current_char] = 'n';
        }
    } else if (str == this->text[current_char]) {
        this->mask[current_char] = 'g';
        current_char++;
        if (str == " ") {
            this->words++;
        }
    } else {
        this->mask[current_char] = 'r';
        current_char++;
        this->mistakes++;
        emit mistake((double)(this->text.size() - this->mistakes) /
                     this->text.size() * 100);
    }
    if (this->current_char == this->text.size()) {
        this->reprint();
        this->current_char = 0;
        this->mask.fill('n', this->text.size());
        emit ended(this->words);
    }
    this->reprint();
}

void TextEdit::reprint() {
    this->clear();
    QTextCharFormat format;
    for (int i = 0; i < this->text.size(); ++i) {
        if (mask[i] == 'g') {
            format.setForeground(Qt::darkGreen);
        } else if (mask[i] == 'r') {
            format.setForeground(Qt::darkRed);
        } else {
            format.setForeground(Qt::gray);
        }
        cursor.setCharFormat(format);
        cursor.insertText(QString(text[i]));
    }
}

TextEdit::~TextEdit() {
    delete ui;
}
