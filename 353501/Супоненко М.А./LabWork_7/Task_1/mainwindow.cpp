#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>

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

void MainWindow::on_enqueueButton_clicked()
{
    int value = QRandomGenerator::global()->bounded(10);
    queue.enqueue(value);
    updateListBox();
}

void MainWindow::on_dequeueButton_clicked()
{
    queue.dequeue();
    updateListBox();
}

void MainWindow::on_removeDuplicatesButton_clicked()
{
    queue.removeDuplicates();
    updateListBox();
}

void MainWindow::updateListBox()
{
    ui->listWidget->clear();
    Node* current = queue.getHead();
    while (current) {
        ui->listWidget->addItem(QString::number(current->data));
        current = current->next;
    }
}
