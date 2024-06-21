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
    ui->label->setText("");
    ui->label_2->setText("");
    ui->textBrowser->clear();
    h1.insert(ui->spinBox->value());
    h2.insert(ui->spinBox->value());
    ui->textBrowser->append(h1.print());
}


void MainWindow::on_pushButton_2_clicked()
{
    int hh1;
    int hh2;
    ui->textBrowser->clear();
    hh1 = h1.extractMax();
    hh2 = h2.extractMax();
    ui->label->setText(QString::number(hh1));
    ui->label_2->setText(QString::number(hh2));

    ui->textBrowser->append(h1.print());

}

