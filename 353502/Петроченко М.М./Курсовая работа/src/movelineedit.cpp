//
// Created by acryoz on 5/4/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MoveLineEdit.h" resolved

#include "movelineedit.h"
#include "ui_movelineedit.h"

MoveLineEdit::MoveLineEdit(QWidget* parent)
    : QLineEdit(parent), ui(new Ui::MoveLineEdit) {
    ui->setupUi(this);
}

void MoveLineEdit::mousePressEvent(QMouseEvent* ev) {
    this->clear();
    QLineEdit::mousePressEvent(ev);
}

MoveLineEdit::~MoveLineEdit() {
    delete ui;
}
