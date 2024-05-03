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

void MainWindow::on_pushButton_clicked()
{
    ct=new counter;
    QString filep=QFileDialog::getExistingDirectory(this,"Choose directory",QDir::homePath());
    count1=0;
    count2=0;


    ct->count(filep,count1,count2);
    ui->label_3->setText(QString::number(count1));
    ui->label_4->setText(QString::number(count2));

}
