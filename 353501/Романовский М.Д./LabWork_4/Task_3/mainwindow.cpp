#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qspinbox.h>
#include <qtablewidget.h>

void swapInts(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->inpCnt, &QSpinBox::valueChanged, this,
          &MainWindow::updateInpTable);
  updateInpTable();
}

void MainWindow::updateInpTable() {
  int inpCnt = ui->inpCnt->value();
  int oldCnt = ui->inpTable->rowCount();
  ui->inpTable->setRowCount(inpCnt);

  for (int i = oldCnt; i < inpCnt; i++) {
    QSpinBox *box = new QSpinBox();
    box->setMinimum(1);
    box->setMaximum(100000000);
    box->setValue(rand() % 900 + 10);
    connect(box, &QSpinBox::valueChanged, this, &MainWindow::updateOut);
    ui->inpTable->setCellWidget(i, 0, box);
  }

  updateOut();
}

QList<int> MainWindow::getInpValues() {
  QList<int> res;
  res.resize(ui->inpTable->rowCount());
  for (int i = 0; i < res.count(); i++) {
    QSpinBox *box = (QSpinBox *)ui->inpTable->cellWidget(i, 0);
    res[i] = box->value();
  }
  return res;
}

QList<int> MainWindow::compute(QList<int> inp) {
  QList<int> res;

  for (int i = 0; i < inp.count(); i += 3) {
    if (i + 2 >= inp.count()) {
      int avg = inp[i];
      if (i + 1 < inp.count()) {
        avg += inp[i + 1];
        avg /= 2;
      }
      res.push_back(avg);
      continue;
    }

    int a = inp[i];
    int b = inp[i + 1];
    int c = inp[i + 2];

    if (a > c)
      swapInts(&a, &c);

    if (a > b)
      swapInts(&a, &b);

    if (b > c)
      swapInts(&b, &c);

    res.push_back(b);
  }
  return res;
};

void MainWindow::updateOut() {
  QList<int> inps = getInpValues();
  QList<int> res = compute(inps);

  ui->outTable->setRowCount(res.count());
  for (int i = 0; i < res.count(); i++) {
    ui->outTable->setItem(i, 0, new QTableWidgetItem(QString::number(res[i])));
  }
}