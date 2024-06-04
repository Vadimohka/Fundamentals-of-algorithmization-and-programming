#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

unsigned long long MainWindow::FuncAkkerman(unsigned long long m, unsigned long long n){
    if(m == 0){
        return n + 1;
    } else if(m > 0 && n == 0){
        return FuncAkkerman(m - 1, 1);
    } else {
        return FuncAkkerman(m - 1, FuncAkkerman(m, n - 1));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    unsigned long long m = 0, n = 0;

    QString s = ui->textEdit->toPlainText();
    n = s.toLongLong();
    s = ui->textEdit_2->toPlainText();
    m = s.toLongLong();

    ui->Result->setText("Result: " + QString::number(FuncAkkerman(m, n)));
}
