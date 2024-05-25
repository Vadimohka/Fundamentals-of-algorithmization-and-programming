#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_On_insert_clicked()
{
    int val = ui->inBox->value();
    HT.insert(val);
}


void MainWindow::on_On_remove_clicked()
{
    int val = ui->inBox->value();
    HT.remove(val);
}

void MainWindow::on_On_search_clicked()
{
    int val = ui->inBox->value();
    bool Is = HT.search(val);
    QString expr = "The key was" + QString(Is ? " " : " not ") + "found";
    ui->lineEdit->setText(expr);
}

void MainWindow::on_On_print_clicked()
{
    QString expr = QString::fromStdString(HT.toString());
    ui->lineEdit->setText(expr);
}

void MainWindow::on_On_LoadFactor_clicked()
{
    QString expr = "Load Factor is : ";
    expr += QString::number(HT.getLoadFactor());
    ui->lineEdit->setText(expr);
    if(HT.getLoadFactor() > 1.0)
    {
         ui->progressBar->setValue(100);
         return;
    }
    ui->progressBar->setValue(HT.getLoadFactor()*100);
}

void MainWindow::on_On_clear_clicked()
{
    ui->lineEdit->clear();
}


void MainWindow::on_On_search_min_clicked()
{
    QString str = "Min key is : ";
    int val = HT.findMinKey();
    str += QString::number(val);
    ui->lineEdit->setText(str);
}


void MainWindow::on_On_Fill_clicked()
{
    for (int i = 0; i < static_cast<int>(HT.getSize()); ++i)
    {
        int val = QRandomGenerator::global()->bounded(100);;
        HT.insert(val);
    }

}

