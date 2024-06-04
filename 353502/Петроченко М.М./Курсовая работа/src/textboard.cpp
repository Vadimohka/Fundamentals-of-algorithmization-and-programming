//
// Created by acryoz on 5/2/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TextBoard.h" resolved

#include "textboard.h"
#include "ui_textboard.h"

TextBoard::TextBoard(QWidget* parent)
    : QTextEdit(parent), ui(new Ui::TextBoard) {
    ui->setupUi(this);
    this->setFontPointSize(16);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    this->setAlignment(Qt::AlignJustify);
    QFont font("JetBrains");
    font.setStyleHint(QFont::Monospace);
    this->setFont(font);
    this->setReadOnly(true);
    this->setFixedSize(MAX_BOARD_WIDTH, MAX_BOARD_HEIGHT);
    this->setTextInteractionFlags(Qt::TextEditable);
    this->setCursorWidth(0);
}

void TextBoard::wheelEvent(QWheelEvent* e) {}

void TextBoard::dragMoveEvent(QDragMoveEvent* e) {}

void TextBoard::mouseMoveEvent(QMouseEvent* e) {}

void TextBoard::keyPressEvent(QKeyEvent* e) {}

TextBoard::~TextBoard() {
    delete ui;
}
