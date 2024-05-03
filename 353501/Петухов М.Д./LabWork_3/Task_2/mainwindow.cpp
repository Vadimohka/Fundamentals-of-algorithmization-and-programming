#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::calculate_clicked);
}

void MainWindow::calculate_clicked()
{
    long long m = ui->spinBox_m->value();
    long long n = ui->spinBox_n->value();

    if (m > 4 || (m == 4 && n > 1) || (m == 3 && n > 13) || (m == 2 && n > 10100) || (m == 1 && n > 170000))
    {
        QMessageBox::information(this, tr("Info"), tr("Введенные числа слишком большие!"), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }

    int output = Ackerman::func(m, n);
    ui->label_ankerman->setText(QString::number(output));
}