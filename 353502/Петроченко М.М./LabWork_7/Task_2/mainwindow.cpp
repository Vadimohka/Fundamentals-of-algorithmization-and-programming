//
// Created by acryoz on 25.05.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setFixedSize(1000, 1000);
    this->vbox = new QVBoxLayout;
    this->tree = new TreeGraph;
    this->vbox->addWidget(this->tree);

    this->grid = new QGridLayout;

    this->validator = new QIntValidator(-50, 50);

    this->del_edit = new QLineEdit;
    this->del_edit->setValidator(this->validator);
    this->add_edit = new QLineEdit;
    this->add_edit->setValidator(this->validator);
    this->add_button = new QPushButton("Add");
    QObject::connect(this->add_button, SIGNAL(clicked()), this, SLOT(add()));
    this->del_button = new QPushButton("Erase");
    QObject::connect(this->del_button, SIGNAL(clicked()), this, SLOT(del()));
    this->grid->addWidget(this->add_edit, 0, 0);
    this->grid->addWidget(this->add_button, 0, 1);
    this->grid->addWidget(this->del_edit, 1, 0);
    this->grid->addWidget(this->del_button, 1, 1);

    this->vbox->addLayout(this->grid);

    this->setLayout(this->vbox);
}

void MainWindow::add() {
    int pos = 0;
    auto str = this->add_edit->text();
    if (this->validator->validate(str, pos) == QValidator::Acceptable) {
        int key = this->add_edit->text().toInt();
        if (this->tree->find(key) == nullptr) {
            this->tree->insertIntoTree({ key, this->add_edit->text() });
        }
    }
    this->add_edit->clear();
}

void MainWindow::del() {
    int pos = 0;
    auto str = this->del_edit->text();
    if (this->validator->validate(str, pos) == QValidator::Acceptable) {
        this->tree->deleteFromTree(this->del_edit->text().toInt());
    }
    this->del_edit->clear();
}

MainWindow::~MainWindow() {
    delete ui;
}
