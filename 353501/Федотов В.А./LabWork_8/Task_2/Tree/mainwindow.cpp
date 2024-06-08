#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qpushbutton.h>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);

    solver = new TreeHeapSolver();

    connect(ui->addBtn, &QPushButton::pressed, this, &MainWindow::add);
    connect(ui->removeBtn, &QPushButton::pressed, this, &MainWindow::remove);
  
}

void MainWindow::add() {
    solver->insert(ui->spinBox->value());
    solver->visualize(ui->treeWidget);
}

void MainWindow::remove() {
    solver->remove();
    solver->visualize(ui->treeWidget);
}