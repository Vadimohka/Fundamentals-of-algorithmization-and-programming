#include "mainwindow.h"
#include "./ui_mainwindow.h"


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

void MainWindow::on_pushButton_ack_clicked()
{
    short m = ui->spinBox_m->value();
    short n = ui->spinBox_n->value();
    if ((m==4 && n>=1) || m>4 || (m==3 && n>12)) {
        ui->label_answer->setText("Ackermann function value is too high");
    } else {
        ui->label_answer->setText(QString::number(ack_func.ack(m,n)));
    }
}

