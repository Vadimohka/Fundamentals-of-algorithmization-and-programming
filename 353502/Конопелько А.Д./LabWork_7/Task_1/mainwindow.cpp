#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButtonEnqueue_clicked() {
    int value = rand() % 100;
    queue.push_back(value);
    updateDisplay();
}

void MainWindow::on_pushButtonRing_clicked() {
    queue.convertToRing();
    updateDisplay();
}

void MainWindow::on_pushButtonForward_clicked() {
    queue.moveForward();
    updateCurrentPosition();
}

void MainWindow::on_pushButtonBackward_clicked() {
    queue.moveBackward();
    updateCurrentPosition();
}

void MainWindow::on_pushButtonPushBack_clicked() {
    int value = rand() % 100;
    queue.push_back(value);
    updateDisplay();
}

void MainWindow::on_pushButtonPushFront_clicked() {
    int value = rand() % 100;
    queue.push_front(value);
    updateDisplay();
}

void MainWindow::on_pushButtonPopBack_clicked() {
    queue.pop_back();
    updateDisplay();
}

void MainWindow::on_pushButtonPopFront_clicked() {
    queue.pop_front();
    updateDisplay();
}

void MainWindow::updateDisplay() {
    ui->listWidget->clear();
    Node* temp = queue.getHead();
    if (!temp) return;

    //   int totalNodes = queue.getTotalNodes();

    do {
        ui->listWidget->addItem(QString::number(temp->data));
        temp = temp->next;
    } while (temp && temp != queue.getHead());

    //  ui->progressBar->setMaximum(totalNodes);
    updateCurrentPosition();
}

void MainWindow::updateCurrentPosition() {
    int currentValue = queue.getCurrentValue();
    if (currentValue == -1) {
        ui->label->setText("Current: N/A");
        ui->progressBar->setValue(0);
    } else {
        ui->label->setText("Current: " + QString::number(currentValue));

        // Обновляем прогресс-бар
        Node* temp = queue.getHead();
        int position = 0;
        int totalNodes = queue.getTotalNodes();

        do {
            if (temp == queue.current) break;
            temp = temp->next;
            ++position;
        } while (temp && temp != queue.getHead());
        //   qDebug() << position << " " << totalNodes << '\n' << ((totalNodes > 0) ? (position * 100 / totalNodes) : 0);
        ui->progressBar->setValue((totalNodes > 0) ? ((position + 1) * 100 / (totalNodes)) : 0);
    }
}
