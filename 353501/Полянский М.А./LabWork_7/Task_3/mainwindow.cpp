#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), visualMap(new VisualMap) {
  ui->setupUi(this);

  connect(ui->clearBtn, &QPushButton::clicked, this, &MainWindow::clearClicked);
  connect(ui->randBtn, &QPushButton::clicked, this, &MainWindow::randClicked);
  connect(ui->getBtn, &QPushButton::clicked, this, &MainWindow::getClicked);
  connect(ui->setBtn, &QPushButton::clicked, this, &MainWindow::setClicked);
  connect(ui->delBtn, &QPushButton::clicked, this, &MainWindow::delClicked);

  update();
}

MainWindow::~MainWindow() {
  delete ui;
  delete visualMap;
}

void MainWindow::update() {
  visualMap->fillEntries(ui->entries);
  long countAboveAvg = visualMap->countAboveAverage();
  ui->countAboveAvg->setText(QString::number(countAboveAvg));
}

void MainWindow::clearClicked() {
  visualMap->clear();
  update();
}

void MainWindow::randClicked() {
  visualMap->randomize();
  update();
}

void MainWindow::getClicked() {
  bool ok;
  int key = ui->key->text().toInt(&ok);
  if (!ok) {
    QMessageBox::warning(this, "Error", "Invalid key");
    return;
  }
  QString val = "NOT_FOUND";
  if (visualMap->contains(key))
    val = visualMap->get(key);
  ui->value->setText(val);
}

void MainWindow::setClicked() {
  bool ok;
  int key = ui->key->text().toInt(&ok);
  if (!ok) {
    QMessageBox::warning(this, "Error", "Invalid key");
    return;
  }
  QString val = ui->value->text();
  visualMap->insert(key, val);
  update();
}

void MainWindow::delClicked() {
  bool ok;
  int key = ui->key->text().toInt(&ok);
  if (!ok) {
    QMessageBox::warning(this, "Error", "Invalid key");
    return;
  }
  QString val = "NOT_FOUND";
  if (visualMap->contains(key))
    val = visualMap->get(key);
  ui->value->setText(val);
  visualMap->remove(key);
  update();
}