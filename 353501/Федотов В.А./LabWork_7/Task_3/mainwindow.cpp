#include "mainwindow.h"
#include "tasksolver.h"
#include "ui_mainwindow.h"
#include <qpushbutton.h>
#include <stdexcept>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->numElementsBox->setValue(100);
    ui->mapSizeBox->setValue(20);
  
    reset();

    connect(ui->insertBtn, &QPushButton::pressed, this, &MainWindow::insert);
    connect(ui->getBtn, &QPushButton::pressed, this, &MainWindow::get);
    connect(ui->deleteBtn, &QPushButton::pressed, this, &MainWindow::remove);
    connect(ui->minKeyBtn, &QPushButton::pressed, this, &MainWindow::findMinKey);
    connect(ui->resetBtn, &QPushButton::pressed, this, &MainWindow::reset);
}

void MainWindow::get() {
    try {
        int value = solver->get(ui->keyBox->value());
        ui->valueBox->setValue(value);
        solver->populateTable();
    } catch (std::invalid_argument e) {
        ui->valueBox->setValue(-1);
    }
}

void MainWindow::remove() {
    solver->remove(ui->keyBox->value());
    solver->populateTable();
}

void MainWindow::insert() {
    solver->insert(ui->keyBox->value(), ui->valueBox->value());
    solver->populateTable();
}

void MainWindow::findMinKey() {
    int min = solver->findMinKey();
    ui->lineEdit->setText(QString::number(min));
}

void MainWindow::reset() {
    if (solver != nullptr) {
        delete solver;
        solver = nullptr;
    }

    solver = new TaskSolver(ui->tableWidget, ui->numElementsBox->value(), ui->mapSizeBox->value());
}