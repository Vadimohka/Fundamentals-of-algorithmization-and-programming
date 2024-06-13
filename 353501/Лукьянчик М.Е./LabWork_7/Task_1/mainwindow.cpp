#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <ctime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::srand(std::time(nullptr));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_enqueueButton_clicked()
{
    QString valueStr = ui->valueLineEdit->text();
    if (!valueStr.isEmpty()) {
        int value = valueStr.toInt();
        m_queue.enqueue(value);
        ui->queueListWidget->addItem(QString::number(value));
        ui->valueLineEdit->clear();
        ui->messageLabel->setText(QString("Enqueued: %1").arg(value));
    }
    else ui->messageLabel->setText("No value entered");
}

void MainWindow::on_dequeueButton_clicked()
{
    try {
        int value = m_queue.dequeue();
        ui->queueListWidget->takeItem(0);
        ui->messageLabel->setText(QString("Dequeued: %1").arg(value));
    } catch (const std::runtime_error& e) {
        ui->messageLabel->setText(e.what());
    }
}

void MainWindow::on_findMaxAndMoveButton_clicked()
{
    try {
        m_queue.findMax();
        ui->queueListWidget->clear();
        for (int value : m_queue) {
            ui->queueListWidget->addItem(QString::number(value));
        }
        ui->messageLabel->setText(QString("Second queue added after Max element."));
    } catch (const std::runtime_error& e) {
        ui->messageLabel->setText(e.what());
    }
}

void MainWindow::on_fillRandomButton_clicked()
{
    int numRandomValues = 10;
    int minValue = 1;
    int maxValue = 100;
    m_queue.clear();
    ui->queueListWidget->clear();
    for (int i = 0; i < numRandomValues; ++i) {
        int randomValue = minValue + std::rand() % (maxValue - minValue + 1);
       m_queue.enqueue(randomValue);
       ui->queueListWidget->addItem(QString::number(randomValue));
    }

    ui->messageLabel->setText(QString("Queue filled with %1 random values.").arg(numRandomValues));
}

void MainWindow::on_fillRandomButton_2_clicked()
{
    int numRandomValues = 10;
    int minValue = 1;
    int maxValue = 100;
    ui->queueListWidget_2->clear();
        m_queue.clear2();
    for (int i = 0; i < numRandomValues; ++i) {
        int randomValue = minValue + std::rand() % (maxValue - minValue + 1);
        m_queue.enqueue2(randomValue);
        ui->queueListWidget_2->addItem(QString::number(randomValue));
    }

    ui->messageLabel->setText(QString("Queue filled with %1 random values.").arg(numRandomValues));
}

