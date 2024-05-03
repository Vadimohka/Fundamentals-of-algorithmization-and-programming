#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowState(windowState() & ~Qt::WindowFullScreen);

}

MainWindow::~MainWindow()
{
    delete ui;
}

unsigned long long MainWindow::akkerman(unsigned long long m, unsigned long long n)
{
    num++;
    ui->label->setText("Calls: " + QString::number(num));
    //qDebug()<<num;
    if (num >= 60'000'000) {
        ui->output->setText("Error: To many calls ");
        return 0;
    }

    if(m == 0){
        return n + 1;
    }
    else
        if(m > 0 && n == 0){
        unsigned long long a = akkerman(m - 1, 1);
        if(a > 1000'000'000)
        {
            ui->output->setText("Too big value ");
            return 0;
        }
        else
            return a;

    }
    else
        if(m > 0 && n > 0){
        unsigned long long a =  akkerman(m - 1, akkerman(m, n - 1));
        if(a > 1000'000'000)
        {
            ui->output->setText("Too big value ");
            return 0;
        }
        else
            return a;
    }
}


void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->hide();
    ui->label->clear();
    ui->output->clear();

    QApplication::processEvents();

    num = 0;
    long long m = ui->lineEditM->text().toLongLong();
    long long n = ui->lineEditN->text().toLongLong();

    QString res = QString::number(akkerman(m, n));
    if(res!="0")
        ui->output->setText(res);
    ui->pushButton->show();

}

