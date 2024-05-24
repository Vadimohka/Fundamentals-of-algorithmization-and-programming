//
// Created by acryoz on 5/4/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_EndMenu.h" resolved

#include "endmenu.h"
#include "ui_endmenu.h"

EndMenu::EndMenu(QWidget* parent) : QWidget(parent), ui(new Ui::EndMenu) {
    ui->setupUi(this);
    this->label = new QLabel("Player won");
    this->ok_button = new QPushButton("New game");
    QObject::connect(this->ok_button, SIGNAL(clicked()), this,
                     SLOT(onRematch()));
    this->close_button = new QPushButton("Exit");
    QObject::connect(this->close_button, SIGNAL(clicked()), this,
                     SLOT(onEnd()));

    this->hbox = new QHBoxLayout;
    this->hbox->addWidget(this->ok_button);
    this->hbox->addWidget(this->close_button);

    this->vbox = new QVBoxLayout;
    this->vbox->addWidget(this->label);
    this->vbox->addLayout(this->hbox);
    this->setLayout(this->vbox);
}

void EndMenu::set(uint8_t winner) {
    this->label->setText((winner == 32) ? "Black won" : "White won");
    this->show();
}

void EndMenu::onEnd() {
    this->hide();
    emit end();
}

void EndMenu::onRematch() {
    this->hide();
    emit restart();
}

EndMenu::~EndMenu() {
    delete ui;
}
