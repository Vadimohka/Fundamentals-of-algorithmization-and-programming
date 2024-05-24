#include "mainwindow.h"
#include "./ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Функция переворота числа");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    val = arg1;
}


void MainWindow::on_label_linkActivated(const QString &link)
{

}


void MainWindow::on_pushButton_clicked()
{


    val = reverse(val, 0);
    ui->label->setText(QString::number(val));
}

int MainWindow::reverse(int num, int res = 0)
{

    if (num == 0) return res;
    return reverse(num / 10, res * 10 + num % 10);
}



