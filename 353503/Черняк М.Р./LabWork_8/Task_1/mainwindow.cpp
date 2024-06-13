#include "mainwindow.h"
#include "Solver.h"
#include "ui_mainwindow.h"
#include <qpushbutton.h>

MainWindow::MainWindow() : ui(new Ui::MainWindow), solver(new Solver) {
  ui->setupUi(this);

  connect(ui->clearBtn, &QPushButton::clicked, this, &MainWindow::clearClicked);
  connect(ui->randBtn, &QPushButton::clicked, this, &MainWindow::randClicked);
  connect(ui->getBtn, &QPushButton::clicked, this, &MainWindow::getClicked);
  connect(ui->setBtn, &QPushButton::clicked, this, &MainWindow::setClicked);
  connect(ui->delBtn, &QPushButton::clicked, this, &MainWindow::delClicked);
  connect(ui->balanceBtn, &QPushButton::clicked, this, &MainWindow::balanceClicked);
  connect(ui->lcaBtn, &QPushButton::clicked, this, &MainWindow::lcaClicked);
  update();
}

void MainWindow::update() {
  solver->fillEnties(ui->tree);
}

void MainWindow::clearClicked() {
  solver->clear();
  update();
}

void MainWindow::lcaClicked() {
    int nkey1 = ui->key1->value();
    int nkey2 = ui->key2->value();
    int res = solver->findLCA(nkey1, nkey2);
    ui->answ->setText(QString::number(res));
    update();
}

void MainWindow::randClicked() {
  solver->randomize();
  update();
}

void MainWindow::getClicked() {
  int key = ui->key->value();
  QString val = "NOT_FOUND";
  if (solver->contains(key))
    val = solver->get(key);
  ui->value->setText(val);
}

void MainWindow::setClicked() {
  int key = ui->key->value();
  QString val = ui->value->text();
  solver->insert(key, val);
  update();
}

void MainWindow::delClicked() {
  int key = ui->key->value();
  QString val = "NOT_FOUND";
  if (solver->contains(key))
    val = solver->get(key);
  ui->value->setText(val);
  solver->remove(key);
  update();
}

void MainWindow::balanceClicked() {
  solver->balance();
  update();
}
