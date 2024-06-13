#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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

void MainWindow::on_arrayInsertButton_clicked() {
    int value = ui->arrayValueInput->text().toInt();
    arrayHeap.insert(value);
    ui->arrayOutput->append("Inserted into array heap: " + QString::number(value));
}

void MainWindow::on_arrayExtractButton_clicked() {
    if (arrayHeap.isEmpty()) {
        QMessageBox::warning(this, "Error", "Array heap is empty");
        return;
    }
    int max = arrayHeap.extractMax();
    ui->arrayOutput->append("Extracted max from array heap: " + QString::number(max));
}

void MainWindow::on_arrayGetMaxButton_clicked() {
    if (arrayHeap.isEmpty()) {
        QMessageBox::warning(this, "Error", "Array heap is empty");
        return;
    }
    int max = arrayHeap.getMax();
    ui->arrayOutput->append("Max in array heap: " + QString::number(max));
}

void MainWindow::on_listInsertButton_clicked() {
    int value = ui->listValueInput->text().toInt();
    listHeap.insert(value);
    ui->listOutput->append("Inserted into list heap: " + QString::number(value));
}

void MainWindow::on_listExtractButton_clicked() {
    if (listHeap.isEmpty()) {
        QMessageBox::warning(this, "Error", "List heap is empty");
        return;
    }
    int max = listHeap.extractMax();
    ui->listOutput->append("Extracted max from list heap: " + QString::number(max));
}

void MainWindow::on_listGetMaxButton_clicked() {
    if (listHeap.isEmpty()) {
        QMessageBox::warning(this, "Error", "List heap is empty");
        return;
    }
    int max = listHeap.getMax();
    ui->listOutput->append("Max in list heap: " + QString::number(max));
}
