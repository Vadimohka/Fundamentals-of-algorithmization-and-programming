#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->spinBox->setMaximum(100);
    ui->spinBox->setMinimum(0);
    ui->spinBox_2->setMaximum(1000);
    ui->spinBox_2->setMinimum(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    arr.push_back(ui->spinBox->value());
    ui->textBrowser_2->insertPlainText( "   " + QString::number(arr.back()));
}


void MainWindow::on_pushButton_2_clicked()
{
    arr.clear();
    ui->textBrowser_2->clear();
    for(long long i = 0; i < ui->spinBox_2->value(); ++i)
    {
        arr.push_back(QRandomGenerator::global()->bounded(0, 100));
        ui->textBrowser_2->insertPlainText( "   " + QString::number(arr.back()));
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    rez.clear();
    ui->textBrowser->clear();
    for(long long i = 0; i < arr.size(); i+=3)
    {
        if(i + 3 > arr.size())
        {
            long long res = arr[i];
            if(i + 1 < arr.size())
                res = (res + arr[i + 1])/2;
            rez.push_back(res);
            ui->textBrowser->insertPlainText( "   " + QString::number(rez.back()));
            continue;
        }

        int a = arr[i];
        int b = arr[i + 1];
        int c = arr[i + 2];
        int res;
        if ((b >= a && c <= a) || (b <= a && c >= a)) {
            res = a;
        } else if ((a >= b && c <= b) || (a <= b && c >= b)) {
            res = b;
        } else {
            res = c;
        }
        rez.push_back(res);
        ui->textBrowser->insertPlainText( "   " + QString::number(rez.back()));

    }


}

