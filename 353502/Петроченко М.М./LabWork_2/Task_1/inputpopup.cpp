//
// Created by acryoz on 5.3.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_InputPopup.h" resolved

#include "../headers/inputpopup.h"
#include "ui_inputpopup.h"


InputPopup::InputPopup(QWidget *parent) :
        QWidget(parent), ui(new Ui::InputPopup) {
    ui->setupUi(this);

    this->errorLabel = new QLabel("Invalid input");
    this->errorLabel->setStyleSheet("QLabel { color : red; }");

    this->day_label = new QLabel("Day:");
    this->month_label = new QLabel("Month:");
    this->year_label = new QLabel("Year:");

    this->validator = new QIntValidator(0, 10000);

    this->day_line = new QLineEdit();
    this->day_line->setValidator(this->validator);

    this->month_line = new QLineEdit();
    this->month_line->setValidator(this->validator);

    this->year_line = new QLineEdit();
    this->year_line->setValidator(this->validator);

    this->grid = new QGridLayout;
    this->grid->addWidget(day_label, 0, 0);
    this->grid->addWidget(day_line, 0, 1);
    this->grid->addWidget(month_label, 1, 0);
    this->grid->addWidget(month_line, 1, 1);
    this->grid->addWidget(year_label, 2, 0);
    this->grid->addWidget(year_line, 2, 1);

    this->accept = new QPushButton("Accept");
    QObject::connect(this->accept, SIGNAL(clicked()), this, SLOT(onAccept()));

    this->vbox = new QVBoxLayout;
    this->vbox->addLayout(this->grid);
    this->vbox->addWidget(this->errorLabel);
    this->vbox->addWidget(this->accept);

    this->setLayout(vbox);
    this->errorLabel->hide();
    this->hide();
}


void InputPopup::onAccept() {
    this->date = Date(this->day_line->text().toInt(), this->month_line->text().toInt(),
                      this->year_line->text().toInt());
    if (this->date.isValid()) {
        this->errorLabel->hide();
        emit valid(this->date);
        this->hide();
    } else {
        this->day_line->clear();
        this->month_line->clear();
        this->year_line->clear();
        this->errorLabel->show();
    }
}


Date InputPopup::getDate() {

}


InputPopup::~InputPopup() {
    delete ui;
}
