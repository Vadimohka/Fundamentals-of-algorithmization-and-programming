#include "mainwindow.h"
#include "VisualBST.h"
#include "ui_mainwindow.h"
#include <qpushbutton.h>

MainWindow::MainWindow() : ui(new Ui::MainWindow), bst(new VisualBST) {
  ui->setupUi(this);

  connect(ui->clearBtn, &QPushButton::clicked, this, &MainWindow::clearClicked);
  connect(ui->randBtn, &QPushButton::clicked, this, &MainWindow::randClicked);
  connect(ui->getBtn, &QPushButton::clicked, this, &MainWindow::getClicked);
  connect(ui->setBtn, &QPushButton::clicked, this, &MainWindow::setClicked);
  connect(ui->delBtn, &QPushButton::clicked, this, &MainWindow::delClicked);
  connect(ui->balanceBtn, &QPushButton::clicked, this, &MainWindow::balanceClicked);
  update();
}

void MainWindow::update() {
  bst->fillEnties(ui->tree);
}

void MainWindow::clearClicked() {
  bst->clear();
  update();
}

void MainWindow::randClicked() {
  bst->randomize();
  update();
}

void MainWindow::getClicked() {
  int key = ui->key->value();
  QString ans = "not found ";
  if (bst->contains(key))
    ans = bst->get(key);
  ui->value->setText(ans);
}

void MainWindow::setClicked() {
  int key = ui->key->value();
  QString ans = ui->value->text();
  bst->insert(key, ans);
  update();
}

void MainWindow::delClicked() {
  int key = ui->key->value();
  QString ans = "not found";
  if (bst->contains(key))
    ans = bst->get(key);
  ui->value->setText(ans);
  bst->remove(key);
  update();
}

void MainWindow::balanceClicked() {
  bst->balance();
  update();
}