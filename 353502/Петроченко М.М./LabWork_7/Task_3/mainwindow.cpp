//
// Created by acryoz on 26.05.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->solver = new TaskSolver();

    this->label = new QLabel;

    this->find_button = new QPushButton("find");
    QObject::connect(this->find_button, SIGNAL(clicked()), this, SLOT(find()));
    this->line_edit = new QLineEdit;
    this->line_edit->setValidator(new QIntValidator(0, INT32_MAX));

    this->vbox = new QVBoxLayout;
    this->grid = new QGridLayout;

    this->random_button = new QPushButton("randomize");
    QObject::connect(this->random_button, SIGNAL(clicked()), this,
                     SLOT(rand()));

    this->do_task_button = new QPushButton("do task");
    QObject::connect(this->do_task_button, SIGNAL(clicked()), this,
                     SLOT(doTask()));
    this->table = new QTableWidget;

    this->grid->addWidget(this->random_button, 0, 0);
    this->grid->addWidget(this->do_task_button, 0, 1);
    this->grid->addWidget(this->line_edit, 1, 0);
    this->grid->addWidget(this->find_button, 1, 1);
    this->vbox->addWidget(this->table);
    this->vbox->addLayout(this->grid);
    this->vbox->addWidget(this->label);
    this->setLayout(this->vbox);
}

void MainWindow::rand() {
    this->solver->randomise();
    this->upd();
}

void MainWindow::upd() {
    this->solver->fill(this->table);
}

void MainWindow::doTask() {
    auto res = this->solver->doTask();
    this->label->setText((res.first == INT32_MAX)
                             ? "Empty"
                             : "Smallest key: " + QString::number(res.first));
}

void MainWindow::find() {
    auto found = this->solver->find(this->line_edit->text().toInt());
    if (found.first != -1) {
        this->label->setText("Found key " + QString::number(found.first) +
                             " with value " + found.second);
    }
}

MainWindow::~MainWindow() {
    delete ui;
}
