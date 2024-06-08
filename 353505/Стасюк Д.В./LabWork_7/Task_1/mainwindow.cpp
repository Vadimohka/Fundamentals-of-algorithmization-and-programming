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


void MainWindow::displayQueue(QListWidget *QueueListWidget,const Queue &queue) {
    QueueListWidget->clear();
    for (int i = 0; i < queue.GetSize(); ++i) {
        int num = queue.peek(i);
        QueueListWidget->addItem(QString::number(num));
    }
}

void MainWindow::on_pushButton_random_clicked()
{
    mainQueue.clear();
    mainQueue.FillQueueRandomly(ui->spinBox->value());
    displayQueue(ui->newListWidget, mainQueue);
}

void MainWindow::on_pushButton_new_queue_clicked()
{
    mainQueue.moveMinToFront();
    displayQueue(ui->newListWidget, mainQueue);
}

void MainWindow::on_pushButton_front_clicked()
{
    ui->label_2->setText(QString::number(mainQueue.front()));
}

void MainWindow::on_pushButton_back_clicked()
{
    ui->label_2->setText(QString::number(mainQueue.back()));
}

void MainWindow::on_pushButton_pop_clicked()
{
    mainQueue.pop();
    displayQueue(ui->newListWidget, mainQueue);
}

void MainWindow::on_pushButton_push_clicked()
{
    mainQueue.push(ui->spinBox->value());
    displayQueue(ui->newListWidget, mainQueue);
}



