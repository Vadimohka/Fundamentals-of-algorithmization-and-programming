#include "mainwindow.h"
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->pushButton, &QPushButton::pressed, this,
          &MainWindow::pre_decimal);
  connect(ui->pushButton_2, &QPushButton::pressed, this,
          &MainWindow::pre_accerman);
  connect(ui->pushButton_3, &QPushButton::pressed, this,
          &MainWindow::pre_rotate_number);
  connect(ui->pushButton_4, &QPushButton::pressed, this,
          &MainWindow::pre_hanoi);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::pre_decimal() {
  bool ok = false;
  int n = ui->lineEdit->text().toInt(&ok);
  if (!ok) {
    return;
  }
  ui->label->clear();
  decimal_to_binary(n);
}

void MainWindow::decimal_to_binary(int n) {
  if (n / 2 != 0) {
    decimal_to_binary(n / 2);
  }
  ui->label->setText(ui->label->text() + QString::number(n % 2));
}

void MainWindow::pre_accerman() {
  int n = ui->lineEdit_2->text().toInt();
  int m = ui->lineEdit_3->text().toInt();
  int ans = accerman(m, n);
  ui->label_3->setText(QString::number(ans));
}

int MainWindow::accerman(int m, int n) {
  if (m > 0 and n > 0) {
    return accerman(m - 1, accerman(m, n - 1));
  }
  if (m > 0 and n == 0) {
    return accerman(m - 1, 1);
  }
  if (m == 0) {
    return n + 1;
  }

  return 0;
}

void MainWindow::pre_rotate_number() {
  int64_t number = ui->lineEdit_4->text().toInt();
  ui->label_5->setText(QString::number(rotate_number(number, 0)));
}

int MainWindow::rotate_number(int number, int temp) {
  if (number == 0) {
    return temp;
  }
  temp *= g;
  temp += number % g;
  number /= g;
  return rotate_number(number, temp);
}

void MainWindow::pre_hanoi() {
  QString s = ui->lineEdit_5->text();
  int circles = s.toInt();
  hanoi(circles);
}

void MainWindow::hanoi(int quantity, int from, int to, int buf_peg) {
  if (quantity != 0) {
    hanoi(quantity - 1, from, buf_peg, to);
    QListWidgetItem* item = new QListWidgetItem;
    item->setText(QString::number(from) + " -> " + QString::number(to));
    ui->listWidget->addItem(item);

    hanoi(quantity - 1, buf_peg, to, from);
  }
}
