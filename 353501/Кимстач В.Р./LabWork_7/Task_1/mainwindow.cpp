#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
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

void MainWindow::on_enqueue_clicked()
{
    bool ok;
    int value = QInputDialog::getInt(this, "Enqueue", "Enter a value:", 0, -2147483648, 2147483647, 1, &ok);
    if (ok) {
        queue.enqueue(value);
        updateListWidget();
    }
}

void MainWindow::on_dequeue_clicked()
{
    if (!queue.isEmpty()) {
        int value = queue.dequeue();
        ui->listWidget->addItem(QString("Dequeued: %1").arg(value));
        updateListWidget();
    }
}

void MainWindow::on_makeMinFirst_clicked()
{
    queue.makeMinFirst();
    updateListWidget();
}

void MainWindow::on_fillRandomQueue_clicked()
{
    bool ok;
    int size = QInputDialog::getInt(this, "Fill Random Queue", "Enter the size:", 10, 1, 1000, 1, &ok);
    if (ok) {
        queue.fillRandomQueue(size);
        updateListWidget();
    }
}

void MainWindow::updateListWidget()
{
    ui->listWidget->clear();
    Queue::Node* current = queue.getNodeAt(0);
    while (current != nullptr) {
        ui->listWidget->addItem(QString::number(current->data));
        current = current->next;
    }
}
void MainWindow::on_size_clicked()
{
    int size = queue.getSize();
    QMessageBox::information(this, "Size", QString("Size: %1").arg(size));
}

void MainWindow::on_peek_clicked()
{
    if (!queue.isEmpty()) {
        int front = queue.peek();
        QMessageBox::information(this, "Front Element", QString("Front element: %1").arg(front));
    } else {
        QMessageBox::warning(this, "Queue is Empty", "Cannot peek, the queue is empty.");
    }
}

void MainWindow::on_isEmpty_clicked()
{
    bool isEmpty = queue.isEmpty();
    QMessageBox::information(this, "Is Empty?", QString("Queue is empty: %1").arg(isEmpty ? "true" : "false"));
}
