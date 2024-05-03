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

long long MainWindow::ReverseNum(long long num, int rev)
{
    if(num == 0)
    {
        return rev;
    }

    return ReverseNum(num / 10,num % 10  + rev * 10);
}

void MainWindow::on_lineEdit_getNum_returnPressed()
{
    bool ConvertionIsGood = true;
    long long n = ui->lineEdit_getNum->text().toLongLong(&ConvertionIsGood);
    if(!ConvertionIsGood)
    {
        QMessageBox::warning(this, "Error!!!", "Please enter number!");
        return;
    }
    ui->lineEdit_RevesedNum->setText(QString::number(ReverseNum(n)));
}

