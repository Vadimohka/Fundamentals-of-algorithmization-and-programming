#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::click);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::click(){
    long long ans = 0;
    ui->label_2->setText(QString::number(reverse(ui->spinBox->value(), ans)));
}

long long MainWindow::reverse(long long n, long long ans){

    ans = ans*10 + n%10;
    n = n/10;

    if (n > 0){
        return reverse(n, ans);
    }
    else {
        return ans;
    }
}
