#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qpushbutton.h>

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // FIRST TABLE ================
  firstVec.push_back(123);
  firstVec.push_back(256);
  firstVec.push_back(578);

  updateFirstTable();

  connect(ui->firstPush, &QPushButton::clicked, [&]() {
    firstVec.push_back(getFirstNew());
    updateFirstTable();
  });

  connect(ui->firstInsert, &QPushButton::clicked, [&]() {
    firstVec.insert(getFirstRow(), getFirstNew());
    updateFirstTable();
  });

  connect(ui->firstPop, &QPushButton::clicked, [&]() {
    firstVec.pop_back();
    updateFirstTable();
  });

  connect(ui->firstErase, &QPushButton::clicked, [&]() {
    firstVec.erase(getFirstRow());
    updateFirstTable();
  });

  // SECOND TABLE ================
  secondVec.push_back({123, 0.1});
  secondVec.push_back({256, 0.2});
  secondVec.push_back({578, 0.4});

  updateSecondTable();

  connect(ui->secondPush, &QPushButton::clicked, [&]() {
    secondVec.push_back(getSecondNew());
    updateSecondTable();
  });

  connect(ui->secondInsert, &QPushButton::clicked, [&]() {
    secondVec.insert(getSecondRow(), getSecondNew());
    updateSecondTable();
  });

  connect(ui->secondPop, &QPushButton::clicked, [&]() {
    secondVec.pop_back();
    updateSecondTable();
  });

  connect(ui->secondErase, &QPushButton::clicked, [&]() {
    secondVec.erase(getSecondRow());
    updateSecondTable();
  });
}

void MainWindow::updateFirstTable() {
  ui->firstPop->setEnabled(!firstVec.empty());
  ui->firstErase->setEnabled(!firstVec.empty());

  ui->firstTable->setRowCount(firstVec.size());
  int curRow = 0;
  for (auto g : firstVec) {
    ui->firstTable->setItem(curRow++, 0,
                            new QTableWidgetItem(QString::number(g)));
  }
}

int MainWindow::getFirstNew() { return ui->firstInp->value(); }

int MainWindow::getFirstRow() {
  auto s = ui->firstTable->selectedItems();
  if (s.empty())
    return 0;
  return s[0]->row();
}

void MainWindow::updateSecondTable() {
  ui->secondPop->setEnabled(!secondVec.empty());
  ui->secondErase->setEnabled(!secondVec.empty());

  ui->secondTable->setRowCount(secondVec.size());
  int curRow = 0;
  for (auto g : secondVec) {
    qDebug() << g.first << " " << g.second;

    ui->secondTable->setItem(curRow, 0,
                             new QTableWidgetItem(QString::number(g.first)));

    ui->secondTable->setItem(curRow, 1,
                             new QTableWidgetItem(QString::number(g.second)));

    curRow++;
  }
}

Pair<int, double> MainWindow::getSecondNew() {
  return {ui->secondInpA->value(), ui->secondInpB->value()};
}

int MainWindow::getSecondRow() {
  auto s = ui->secondTable->selectedItems();
  if (s.empty())
    return 0;
  return s[0]->row();
}
