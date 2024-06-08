#include "mainwindow.h"
#include "solution.h"
#include "ui_mainwindow.h"
#include <climits>

MainWindow::MainWindow() : ui(new Ui::MainWindow), solve(new Solution) {
  ui->setupUi(this);

  connect(ui->clearBtn, &QPushButton::clicked, this, &MainWindow::clearClicked);
  connect(ui->randBtn, &QPushButton::clicked, this, &MainWindow::randClicked);
  connect(ui->getBtn, &QPushButton::clicked, this, &MainWindow::getClicked);
  connect(ui->setBtn, &QPushButton::clicked, this, &MainWindow::setClicked);
  connect(ui->delBtn, &QPushButton::clicked, this, &MainWindow::delClicked);

  //update();
}

void MainWindow::update() {
  solve->fillEnties(ui->entries);
  long smalles = solve->findTotalLen();
  ui->smalles->setText(smalles == LONG_MAX
                           ? "EMPTY TABLE"
                           : QString::number(solve->findTotalLen()));
}

void MainWindow::clearClicked() {
  solve->clear();
  update();
}

void MainWindow::randClicked() {
  solve->randomize();
  update();
}

void MainWindow::getClicked() {
  int key = ui->key->value();
  QString val = "(value)";
  if (solve->contains(key))
    val = solve->get(key);
  ui->value->setText(val);
}

void MainWindow::setClicked() {
  int key = ui->key->value();
  QString val = ui->value->text();
  solve->insert(key, val);
  update();
}

void MainWindow::delClicked() {
  int key = ui->key->value();
  QString val = "value";
  if (solve->contains(key))
    val = solve->get(key);
  ui->value->setText(val);
  solve->remove(key);
  update();
}
