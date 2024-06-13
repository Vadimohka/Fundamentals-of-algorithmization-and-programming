//
// Created by acryoz on 26.05.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->grid = new QGridLayout;
    this->vbox = new QVBoxLayout;
    this->deque_rep = new QLabel;
    this->pop_back_button = new QPushButton("pop_back");
    QObject::connect(this->pop_back_button, SIGNAL(clicked()), this,
                     SLOT(popBack()));
    this->push_back_button = new QPushButton("push_back");
    QObject::connect(this->push_back_button, SIGNAL(clicked()), this,
                     SLOT(pushBack()));
    this->pop_front_button = new QPushButton("pop_front");
    QObject::connect(this->pop_front_button, SIGNAL(clicked()), this,
                     SLOT(popFront()));
    this->push_front_button = new QPushButton("push_front");
    QObject::connect(this->push_front_button, SIGNAL(clicked()), this,
                     SLOT(pushFront()));
    this->line_edit = new QLineEdit;
    this->line_edit->setValidator(new QIntValidator(-100, 100));
    this->grid->addWidget(this->pop_back_button, 0, 0);
    this->grid->addWidget(this->push_back_button, 0, 1);
    this->grid->addWidget(this->pop_front_button, 1, 0);
    this->grid->addWidget(this->push_front_button, 1, 1);
    this->vbox->addWidget(this->deque_rep);
    this->vbox->addWidget(this->line_edit);
    this->vbox->addLayout(this->grid);
    this->setLayout(this->vbox);
}

void MainWindow::popBack() {
    this->deque.pop_back();
    this->upd();
}

void MainWindow::pushBack() {
    this->deque.push_back(this->line_edit->text().toInt());
    this->upd();
}

void MainWindow::popFront() {
    this->deque.pop_front();
    this->upd();
}

void MainWindow::pushFront() {
    this->deque.push_front(this->line_edit->text().toInt());
    this->upd();
}

void MainWindow::upd() {
    QString txt;
    for (auto val : this->deque) {
        txt += QString::number(val) + ", ";
    }
    txt.chop(2);
    this->deque_rep->setText(txt);
}

MainWindow::~MainWindow() {
    delete ui;
}
