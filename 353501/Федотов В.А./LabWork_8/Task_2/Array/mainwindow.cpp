#include "mainwindow.h"
#include "ArrayHeapSolver.h"
#include "ui_mainwindow.h"
#include <qpushbutton.h>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);

    solver = new ArrayHeapSolver();

    connect(ui->addBtn, &QPushButton::pressed, this, &MainWindow::add);
    connect(ui->removeBtn, &QPushButton::pressed, this, &MainWindow::remove);
  
}

void MainWindow::add() {
    solver->insert(ui->spinBox->value());
    solver->printHeap(ui->textEdit);
}

void MainWindow::remove() {
    solver->remove();
    solver->printHeap(ui->textEdit);
}