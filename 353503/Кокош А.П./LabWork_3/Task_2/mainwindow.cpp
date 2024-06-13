#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::akerman(short m, short n)
{
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return akerman(m - 1, 1);
    } else if (m > 0 && n > 0) {
        return akerman(m - 1, akerman(m, n - 1));
    }
}

void MainWindow::on_doPushButton_clicked()
{
    int m = ui->inputMSpinBox->value();
    int n = ui->inputNSpinBox->value();

    ui->outputLabel->setText(QString::number(akerman(m, n)));
}
