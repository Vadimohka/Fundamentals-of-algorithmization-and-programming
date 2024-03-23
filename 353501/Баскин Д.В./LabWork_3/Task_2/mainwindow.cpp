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

void MainWindow::on_pushButton_evaluate_clicked()
{
    int m = ui->spinBox_m->value();
    int n = ui->spinBox_n->value();

    if (m > 4 || (m == 4 && n) || (m == 3 && n > 10) || (m == 2 && n > 10000) || (m == 1 && n > 261114))
    {
        QMessageBox::information(this, tr("Info"), tr("Entered numbers are too big!"), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }

    int output = Akkerman::Evaluate(m, n);
    ui->label_output->setText(QString::number(output));
}

