#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QRandomGenerator"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);

    ui->RESULT->addItem("");
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_PUSH_clicked()
{
    queue->push(ui->spinBox->value());

    ui->RESULT->clear();
    ui->RESULT->addItem(queue->info);
}

void MainWindow::on_POP_clicked()
{
    if(queue->size() == 0){
        QMessageBox::warning(nullptr, "", "очередь пустая");
    }else{
        int num = queue->pop();
        QMessageBox::information(nullptr, "", "вы достали число:" + QString::number(num));
    }

    ui->RESULT->clear();
    ui->RESULT->addItem(queue->info);
}

void MainWindow::on_FRONT_clicked()
{
    if(queue->size() == 0){
        QMessageBox::warning(nullptr, "", "очередь пустая");
    }else{
        int num = queue->front();
        QMessageBox::information(nullptr, "", "вы достали число:" + QString::number(num));
    }
}

void MainWindow::on_SIZE_clicked()
{
    QMessageBox::information(nullptr, "", "размер очереди:" + QString::number(queue->size()));
}

void MainWindow::on_ISEMPTY_clicked()
{
    QString res = queue->isEmpty() ? "пустая" : "не пустая";
    QMessageBox::information(nullptr, "", res);
}


void MainWindow::on_BACK_clicked()
{
    if(queue->size() == 0){
        QMessageBox::warning(nullptr, "", "очередь пустая");
    }else{
        int num = queue->back();
        QMessageBox::information(nullptr, "", "вы достали число:" + QString::number(num));
    }
}


void MainWindow::on_RANDOMRANDOM_clicked()
{
    delete queue;

    queue = new MyQueue();

    int count = ui->spinBox_2->value();

    for(int i = 0; i < count; i++){
        queue->push(QRandomGenerator::global()->bounded(100));
    }

    ui->RESULT->clear();
    ui->RESULT->addItem(queue->info);
}


void MainWindow::on_FUNCT_clicked()
{
    if(queue->size() == 0){
        QMessageBox::warning(nullptr, "", "очередь пустая");
    }else{
        queue->fnct();
    }

    ui->RESULT->clear();
    ui->RESULT->addItem(queue->info);
}

