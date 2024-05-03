#include "mainwindow.h"
#include "Reverse.h"
#include "ui_mainwindow.h"
#include <qspinbox.h>

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->spinBox, &QSpinBox::valueChanged, this, &MainWindow::onUpdate);
  onUpdate(ui->spinBox->value());
}

void MainWindow::onUpdate(int val) {
  long long converted = Reverse::ReverseDigits(val);
  long long digits = Reverse::CountDigits(val);

  ui->output->setText(QString::number(converted).rightJustified(digits, '0'));
}