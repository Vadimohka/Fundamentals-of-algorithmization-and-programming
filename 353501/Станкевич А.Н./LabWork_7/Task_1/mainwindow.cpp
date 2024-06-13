#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "queue.h"

MainWindow::MainWindow() : ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Queue mainQueue;
    for (int i = 0; i < 100; ++i)
    {
        int value = rand() % 21 - 10;
        Node *newNode = new Node(value);
        mainQueue.enqueue(newNode);
    }

    ui->main->setText(mainQueue.output());
    Queue negativeQueue;
    Queue positiveQueue;
    mainQueue.splitQueue(negativeQueue, positiveQueue);
    ui->negative->setText(negativeQueue.output());
    ui->positive->setText(positiveQueue.output());
}

MainWindow::~MainWindow()
{
}
