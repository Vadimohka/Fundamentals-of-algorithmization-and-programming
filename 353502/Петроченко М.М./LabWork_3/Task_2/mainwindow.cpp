//
// Created by acryoz on 08.06.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->vbox = new QVBoxLayout;

    this->line_edit1 = new QLineEdit;
    this->line_edit1->setPlaceholderText("m");
    this->line_edit2 = new QLineEdit;
    this->line_edit2->setPlaceholderText("n");
    this->validator1 = new QIntValidator(0, 5);
    this->validator2 = new QIntValidator(0, 3);
    this->line_edit2->setValidator(this->validator2);
    this->line_edit1->setValidator(this->validator1);
    this->label = new QLabel;
    this->button = new QPushButton("do task");
    QObject::connect(this->button, SIGNAL(clicked()), this, SLOT(doTask()));
    this->vbox->addWidget(this->line_edit1);
    this->vbox->addWidget(this->line_edit2);
    this->vbox->addWidget(this->label);
    this->vbox->addWidget(this->button);
    this->setLayout(this->vbox);
}

void MainWindow::doTask() {
    QString m = this->line_edit1->text();
    QString n = this->line_edit2->text();
    int pos = 0;
    if (this->validator1->validate(m, pos) == QValidator::Acceptable &&
        this->validator2->validate(n, pos) == QValidator::Acceptable) {
        this->label->setText(
            QString::number(computeAckermann(m.toInt(), n.toInt())));
    }
    this->line_edit2->clear();
    this->line_edit1->clear();
}

MainWindow::~MainWindow() {
    delete ui;
}
