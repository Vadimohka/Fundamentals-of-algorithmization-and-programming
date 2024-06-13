//
// Created by acryoz on 5/9/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Keyboard.h" resolved

#include "../headers/keyboard.h"
#include "ui_keyboard.h"

Keyboard::Keyboard(QWidget* parent) : QWidget(parent), ui(new Ui::Keyboard) {
    ui->setupUi(this);
    this->setFocusPolicy(Qt::StrongFocus);
    this->layout_index = 0;
    this->current_layout = layouts[this->layout_index];
    this->buttons = QVector<QPushButton*>(47);
    for (int i = 0; i < BUTTON_QUANTITY; ++i) {
        this->buttons[i] = new QPushButton;
    }
    for (int i = 0; i < BUTTON_QUANTITY; ++i) {
        this->buttons[i]->setText(this->current_layout.at(i));
        this->buttons[i]->setMinimumSize(BUTTON_SIZE, BUTTON_SIZE);
        this->buttons[i]->setFocusPolicy(Qt::NoFocus);
    }

    this->number_row = new QHBoxLayout;
    this->first_row = new QHBoxLayout;
    this->second_row = new QHBoxLayout;
    this->third_row = new QHBoxLayout;
    this->vbox = new QVBoxLayout;
    this->vbox->addLayout(this->number_row);
    this->vbox->addLayout(this->first_row);
    this->vbox->addLayout(this->second_row);
    this->vbox->addLayout(this->third_row);

    this->backspace_button = new QPushButton("Backspace");
    this->backspace_button->setMinimumSize(2 * BUTTON_SIZE, BUTTON_SIZE);
    this->backspace_button->setFocusPolicy(Qt::NoFocus);

    this->space_button = new QPushButton("");
    this->space_button->setMinimumSize(3 * BUTTON_SIZE, BUTTON_SIZE);
    this->space_button->setFocusPolicy(Qt::NoFocus);

    this->vbox->addWidget(this->space_button);

    for (int i = NUMBER_ROW_CUMULATIVE; i < NUMBER_ROW; ++i) {
        this->number_row->addWidget(this->buttons[i]);
        this->buttons[i]->setText(this->current_layout.at(i));
    }
    this->number_row->addWidget(this->backspace_button);
    for (int i = FIRST_ROW_CUMULATIVE; i < SECOND_ROW_CUMULATIVE; ++i) {
        this->first_row->addWidget(this->buttons[i]);
        this->buttons[i]->setText(this->current_layout.at(i));
    }
    for (int i = SECOND_ROW_CUMULATIVE; i < THIRD_ROW_CUMULATIVE; ++i) {
        this->second_row->addWidget(this->buttons[i]);
        this->buttons[i]->setText(this->current_layout.at(i));
    }
    for (int i = THIRD_ROW_CUMULATIVE; i < BUTTON_QUANTITY; ++i) {
        this->third_row->addWidget(this->buttons[i]);
        this->buttons[i]->setText(this->current_layout.at(i));
    }
    this->setLayout(this->vbox);
}

Keyboard::~Keyboard() {
    delete ui;
}

void Keyboard::updateLayout() {
    for (int i = NUMBER_ROW_CUMULATIVE; i < NUMBER_ROW; ++i) {
        this->buttons[i]->setText(this->current_layout.at(i));
        this->buttons[i]->setStyleSheet(normal_style);
    }
    for (int i = FIRST_ROW_CUMULATIVE; i < SECOND_ROW_CUMULATIVE; ++i) {
        this->buttons[i]->setText(this->current_layout.at(i));
        this->buttons[i]->setStyleSheet(normal_style);
    }
    for (int i = SECOND_ROW_CUMULATIVE; i < THIRD_ROW_CUMULATIVE; ++i) {
        this->buttons[i]->setText(this->current_layout.at(i));
        this->buttons[i]->setStyleSheet(normal_style);
    }
    for (int i = THIRD_ROW_CUMULATIVE; i < BUTTON_QUANTITY; ++i) {
        this->buttons[i]->setText(this->current_layout.at(i));
        this->buttons[i]->setStyleSheet(normal_style);
    }
    this->space_button->setStyleSheet(normal_style);
    this->backspace_button->setStyleSheet(normal_style);
}

void Keyboard::shift() {
    for (int i = NUMBER_ROW_CUMULATIVE; i < NUMBER_ROW; ++i) {
        this->buttons[i]->setText(this->current_layout.at(i + SHIFT_OFFSET));
        this->buttons[i]->setStyleSheet(normal_style);
    }
    for (int i = FIRST_ROW_CUMULATIVE; i < SECOND_ROW_CUMULATIVE; ++i) {
        this->buttons[i]->setText(this->current_layout.at(i + SHIFT_OFFSET));
        this->buttons[i]->setStyleSheet(normal_style);
    }
    for (int i = SECOND_ROW_CUMULATIVE; i < THIRD_ROW_CUMULATIVE; ++i) {
        this->buttons[i]->setText(this->current_layout.at(i + SHIFT_OFFSET));
        this->buttons[i]->setStyleSheet(normal_style);
    }
    for (int i = THIRD_ROW_CUMULATIVE; i < BUTTON_QUANTITY; ++i) {
        this->buttons[i]->setText(this->current_layout.at(i + SHIFT_OFFSET));
        this->buttons[i]->setStyleSheet(normal_style);
    }
}

void Keyboard::keyPressEvent(QKeyEvent* ev) {
    if (ev->key() == Qt::Key_Space) {
        this->space_button->setStyleSheet(pressed_style);
    } else if (ev->key() == Qt::Key_Backspace) {
        this->backspace_button->setStyleSheet(pressed_style);
    } else if (ev->key() == Qt::Key_Shift) {
        this->shifted = true;
        this->shift();
        return;
    } else if (ev->text() == "ﻻ") {
        this->buttons[41]->setStyleSheet(pressed_style);  //b
    } else if (ev->text() == "ﻹ") {
        this->buttons[17]->setStyleSheet(pressed_style);  //shift t
    } else if (ev->text() == "ﻷ") {
        this->buttons[30]->setStyleSheet(pressed_style);  //shift g
    } else if (ev->text() == "ﻵ") {
        this->buttons[41]->setStyleSheet(pressed_style);  //shift b
    } else {
        if (!this->current_layout.contains(ev->text())) {
            return;
        } else if (this->shifted) {
            int button_index =
                this->current_layout.indexOf(ev->text()) - BUTTON_QUANTITY;
            if (button_index < 0 || button_index >= 47) {
                return;
            }
            this->buttons[button_index]->setStyleSheet(pressed_style);
        } else {
            int button_index = this->current_layout.indexOf(ev->text());
            if (button_index < 0 || button_index >= 47) {
                return;
            }
            this->buttons[button_index]->setStyleSheet(pressed_style);
        }
    }
    emit pressed(ev->text());
}

void Keyboard::setNewLayout(int layout) {
    this->current_layout = layouts[layout];
    this->updateLayout();
}

void Keyboard::nextLayout() {
    if (this->layout_index == LAYOUT_NUMBER - 1) {
        this->layout_index = 0;
    } else {
        this->layout_index += 1;
    }
    this->current_layout = layouts[layout_index];
}

void Keyboard::keyReleaseEvent(QKeyEvent* ev) {
    if (ev->key() == Qt::Key_Shift) {
        this->shifted = false;
    }
    if (this->shifted) {
        this->shift();
    } else {
        this->updateLayout();
    }
}
