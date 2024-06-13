#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(800, 620);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayQueue(QListWidget *listWidget, const Queue &queue)
{
    listWidget->clear();
    for (int i = 0; i < queue.getSize(); ++i) {
        int num = queue.peek(i);
        listWidget->addItem(QString::number(num));
    }
}

void MainWindow::on_bnt_generation_clicked()
{
    mainQueue.clear();
    negativeQueue.clear();
    positiveQueue.clear();
    mainQueue.fillMainQueueRandomly(ui->spinBox->value());
    displayQueue(ui->mainListWidget, mainQueue);
}


void MainWindow::on_bnt_split_clicked()
{
    mainQueue.splitQueue(negativeQueue, positiveQueue);
    displayQueue(ui->listWidgetNegative, negativeQueue);
    displayQueue(ui->listWidgetPositive, positiveQueue);
}

