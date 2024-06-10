#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (ui->spinPush->hasFocus() && (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)) {
        processKeyPress(ui->spinPush, ui->spinOutput, heap);
    }

    if (ui->spinPush_2->hasFocus() && (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)) {
        processKeyPress(ui->spinPush_2, ui->spinOutput_2, heap2);
    }
}

void MainWindow::processKeyPress(QSpinBox *spinBox, QSpinBox *outputBox, binaryheap_massive<int> &heap)
{
    heap.push(spinBox->value());
    outputBox->setValue(heap.max());
    ui->spinSize->setValue(heap.size());
}

void MainWindow::on_popButton_clicked()
{
    processPopButton(ui->spinOutput, ui->spinSize, heap);
}

void MainWindow::on_popButton_2_clicked()
{
    processPopButton(ui->spinOutput_2, ui->spinSize_2, heap2);
}

void MainWindow::processPopButton(QSpinBox *outputBox, QSpinBox *sizeBox, binaryheap_massive<int> &heap)
{
    if (!heap.empty()) {
        heap.pop();
        sizeBox->setValue(heap.size());
        outputBox->setValue(heap.empty() ? 0 : heap.max());
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1 - ui->stackedWidget->currentIndex());
}

MainWindow::~MainWindow()
{
    delete ui;
}
