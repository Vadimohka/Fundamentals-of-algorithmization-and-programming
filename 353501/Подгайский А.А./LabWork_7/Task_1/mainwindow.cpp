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

void MainWindow::on_pushBtn_clicked() {
  queue.push(ui->itemBox->value());
  refresh();
}
void MainWindow::on_popBtn_clicked() {
  if (queue.size() != 0) {
    queue.pop();
  }
  refresh();
}

void MainWindow::on_sortBtn_clicked() {
  const auto sz = queue.size();
  for (size_t i = 0; i < sz; ++i) {
    for (size_t j = 0; j < sz - i - 1; ++j) {
      if (queue[j] > queue[j + 1]) {
        std::swap(queue[j], queue[j + 1]);
      }
    }
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