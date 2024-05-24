//
// Created by acryoz on 4/30/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_StartMenu.h" resolved

#include "startmenu.h"
#include "ui_startmenu.h"

StartMenu::StartMenu(QWidget* parent) : QWidget(parent), ui(new Ui::StartMenu) {
    ui->setupUi(this);

    this->bot_button = new QPushButton("Play with bot");
    this->player_button = new QPushButton("Play with friend");

    this->black = new QRadioButton("Black");
    this->white = new QRadioButton("White");

    this->vbox = new QVBoxLayout;
    this->vbox->addWidget(this->bot_button);
    this->vbox->addWidget(this->player_button);
    this->vbox->addWidget(this->black);
    this->vbox->addWidget(this->white);

    QObject::connect(this->bot_button, SIGNAL(clicked()), this,
                     SLOT(onBotClick()));
    QObject::connect(this->player_button, SIGNAL(clicked()), this,
                     SLOT(onPlayerClick()));
    this->setLayout(this->vbox);
}

void StartMenu::onBotClick() {
    uint8_t color = 32;
    if (this->white->isChecked()) {
        color = 16;
    }
    emit botChosen(true, color);
    this->hide();
}

void StartMenu::onPlayerClick() {
    emit botChosen(false, 0);
    this->hide();
}

StartMenu::~StartMenu() {
    delete ui;
}
