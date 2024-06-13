#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setCentralWidget(ui->gridLayoutWidget);
    setWindowTitle("Двусторонняя очередь");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushbackButton_clicked()
{
    deq.push_back(ui->spinBox->value());
    printDeq();
}


void MainWindow::on_popbackButton_2_clicked()
{
    deq.pop_back();
    printDeq();
}


void MainWindow::on_pushfrontButton_clicked()
{
    deq.push_front(ui->spinBox->value());
    printDeq();
}


void MainWindow::on_popfrontButton_clicked()
{
    deq.pop_front();
    printDeq();
}


void MainWindow::on_clearButton_clicked()
{
    deq.clear();
    printDeq();
}

void MainWindow::printDeq()
{
    ui->label->clear();
    for (auto el : deq) {
        ui->label->setText(ui->label->text() + " " + QString::number(el));
    }
}

