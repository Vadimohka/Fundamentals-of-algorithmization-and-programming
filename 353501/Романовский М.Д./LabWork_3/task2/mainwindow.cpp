#include "mainwindow.h"
#include "Ackermann.h"
#include "ui_mainwindow.h"
#include <qspinbox.h>

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->inputM, &QSpinBox::valueChanged, this, &MainWindow::onUpdate);
  connect(ui->inputN, &QSpinBox::valueChanged, this, &MainWindow::onUpdate);
  onUpdate();
}

const long long LIMITS[] = {
    16777216, 261144, 2048, 9, 0,
};

void MainWindow::onUpdate() {
  int m = ui->inputM->value();
  ui->inputN->setMaximum(LIMITS[m]);

  int n = ui->inputN->value();
  int value = Ackermann::ComputeAckermann(m, n);

  ui->output->setText(QString::number(value));
}