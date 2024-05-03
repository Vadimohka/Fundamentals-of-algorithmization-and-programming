#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
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

bool MainWindow::containszero(long long n)
{
    if (n != 0 && n / 10 == 0) {
        return false;
    }
    int lastDigit = n % 10;
    if (lastDigit == 0) {
        return true;
    }
    return containszero(n /= 10);
}

long long MainWindow::reversenum(long long a)
{
    if(a == 0){
        return reverse_num;
    }
    else{
        reverse_num = reverse_num * 10 + a % 10;
        return reversenum(a /= 10);
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->outputlabel->clear();
    QString a = ui->lineEdit->text();
    bool mOk;
    long long b = a.toLongLong(&mOk);
    if (mOk) {
        if(containszero(b)){
            QMessageBox::warning(this, "Warning", "Wrong data");
            return;
        }else{
            ui->outputlabel->setText(QString::number(reversenum(b)));
        }
    } else {
        QMessageBox::warning(this, "Warning", "Wrong data");
        return;
    }
    reverse_num = 0;
}



