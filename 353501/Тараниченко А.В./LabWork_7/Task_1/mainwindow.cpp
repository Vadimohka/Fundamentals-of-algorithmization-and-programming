#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));

    ui->popQ1->setDisabled(true);
    ui->popQ2->setDisabled(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::print()
{
    q.print(ui->listWidget);

    ui->emptyQ1->setText(q.empty() ? "true" : "false");
    ui->sizeQ1->setText(QString::number(q.size()));
    ui->frontQ1->setText(!q.empty() ? QString::number(q.front()) : "exception");
    ui->backQ1->setText(!q.empty() ? QString::number(q.back()) : "exception");


    q1.print(ui->listWidget2);

    ui->emptyQ2->setText(q1.empty() ? "true" : "false");
    ui->sizeQ2->setText(QString::number(q1.size()));
    ui->frontQ2->setText(!q1.empty() ? QString::number(q1.front()) : "exception");
    ui->backQ2->setText(!q1.empty() ? QString::number(q1.back()) : "exception");
}

void MainWindow::on_pushQ1_clicked()
{
    q.push(ui->spinBox->value());
    print();

    ui->popQ1->setEnabled(true);
}


void MainWindow::on_popQ1_clicked()
{
    q.pop();
    print();

    if(q.empty()) ui->popQ1->setDisabled(true);
}


void MainWindow::on_pushQ2_clicked()
{
    q1.push(ui->spinBox_2->value());
    print();

    ui->popQ2->setEnabled(true);
}


void MainWindow::on_popQ2_clicked()
{
    q1.pop();
    print();

    if(q1.empty()) ui->popQ2->setDisabled(true);
}


void MainWindow::on_genQ1_clicked()
{
    q.clear();
    for(int i = 0; i < rand() % 20 + 1; i++) q.push(rand() % 20000 - 10000);
    ui->popQ1->setEnabled(true);

    print();
}


void MainWindow::on_genQ2_clicked()
{
    q1.clear();
    for(int i = 0; i < rand() % 20 + 1; i++) q1.push(rand() % 20000 - 10000);
    ui->popQ2->setEnabled(true);

    print();
}


void MainWindow::on_insertButton_clicked()
{
    q.insertAfterMax(q1);
    ui->popQ1->setEnabled(true);

    print();
}

