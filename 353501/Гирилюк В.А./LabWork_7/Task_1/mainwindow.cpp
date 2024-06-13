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

void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->clear();
    ui->listWidget->addItem("Queue");
    Queue<int> queue;
    int min = 100;
    int max = 0;
    int minPos = 0;
    int maxPos = 0;
    for(int i = 0; i < 10; i++){
        int randomValue = QRandomGenerator::global()->bounded(1, 100);
        if(randomValue > max){
            max = randomValue;
            maxPos = i;
        }
        else if(randomValue < min){
            min = randomValue;
            minPos = i;
        }
        queue.enqueue(randomValue);
        ui->listWidget->addItem(QString::number(randomValue));
    }

    ui->listWidget->addItem("Queue (cut)");
    int size = queue.size();
    for(int i = 0; i < size; i++){
        if(i > qMin(maxPos, minPos) && i < qMax(maxPos, minPos)){
            queue.dequeue();
            continue;
        }
        ui->listWidget->addItem(QString::number(queue.dequeue()));
    }
}

