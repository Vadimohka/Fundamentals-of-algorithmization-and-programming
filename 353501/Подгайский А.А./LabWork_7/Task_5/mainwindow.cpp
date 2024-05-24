#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <climits>
#include <qstringliteral.h>

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->itemBox->setRange(INT_MIN, INT_MAX);
  refresh();
}

void MainWindow::updateInfo() {
  ui->emptyLbl->setText(queue.empty() ? "true" : "false");
  ui->sizeLbl->setText(QString::number(queue.size()));
  if (queue.empty()) {
    ui->frontLbl->setText({});
    ui->backLbl->setText({});
  } else {
    ui->frontLbl->setText(QString::number(queue.front()));
    ui->backLbl->setText(QString::number(queue.back()));
  }
}

void MainWindow::on_pushBackBtn_clicked() {
  queue.push_back(ui->itemBox->value());
  refresh();
}
void MainWindow::on_popBackBtn_clicked() {
  if (!queue.empty()) {
    queue.pop_back();
  }
  refresh();
}

void MainWindow::on_pushFrontBtn_clicked() {
  queue.push_front(ui->itemBox->value());
  refresh();
}
void MainWindow::on_popFrontBtn_clicked() {
  if (!queue.empty()) {
    queue.pop_front();
  }
  refresh();
}


void MainWindow::refresh() {
  updateInfo();
  updateList();
}

void MainWindow::updateList() {
  ui->list->clear();
  const auto sz = queue.size();
  for (int i = 0; i < sz; ++i) {
    ui->list->addItem(QString::number(queue[i]));
  }
}