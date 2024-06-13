#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_enqueueButton_clicked() {
    int value = ui->valueInput->text().toInt();
    mainQueue.enqueue(value);
    updateListBox();
}

void MainWindow::on_dequeueButton_clicked() {
    if (!mainQueue.isEmpty()) {
        mainQueue.dequeue();
        updateListBox();
    }
}

void MainWindow::on_splitButton_clicked() {
    positiveQueue = Queue();
    negativeQueue = Queue();
    mainQueue.splitQueues(positiveQueue, negativeQueue);
    updateListBox();
}

void MainWindow::updateListBox() {
    ui->mainQueueList->clear();
    ui->positiveQueueList->clear();
    ui->negativeQueueList->clear();

    Node* current = mainQueue.getHead();
    while (current) {
        ui->mainQueueList->addItem(QString::number(current->data));
        current = current->next;
    }

    current = positiveQueue.getHead();
    while (current) {
        ui->positiveQueueList->addItem(QString::number(current->data));
        current = current->next;
    }

    current = negativeQueue.getHead();
    while (current) {
        ui->negativeQueueList->addItem(QString::number(current->data));
        current = current->next;
    }
}
