#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <qcontainerfwd.h>
#include <qpushbutton.h>
#include <qtablewidget.h>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);
    table = ui->tableWidget;
    
    deque = new TraversableDeque<int>();

    ui->backwardBtn->setEnabled(false);
    ui->forwardBtn->setEnabled(false);

    connect(ui->pushBackBtn, &QPushButton::pressed, this, &MainWindow::pushBack);
    connect(ui->pushFrontBtn, &QPushButton::pressed, this, &MainWindow::pushFront);
    connect(ui->popBackBtn, &QPushButton::pressed, this, &MainWindow::popBack);
    connect(ui->popFrontBtn, &QPushButton::pressed, this, &MainWindow::popFront);
    connect(ui->CircularBtn, &QPushButton::pressed, this, &MainWindow::convertToRing);
    connect(ui->forwardBtn, &QPushButton::pressed, this, &MainWindow::moveForward);
    connect(ui->backwardBtn, &QPushButton::pressed, this, &MainWindow::moveBackward);

    
    std::srand(std::time(nullptr));
}

void MainWindow::pushFront() {
    deque->pushFront(rand() % MAX_VAL + 1);
    updateTable();
}

void MainWindow::pushBack() {
    deque->pushBack(rand() % MAX_VAL + 1);
    updateTable();
}

void MainWindow::popFront() {
    deque->popFront();
    updateTable();
}

void MainWindow::popBack() {
    deque->popBack();
    updateTable();
}

void MainWindow::convertToRing() {
    deque->convertToRing();

    ui->backwardBtn->setEnabled(true);
    ui->forwardBtn->setEnabled(true);

    ui->pushBackBtn->setEnabled(false);
    ui->pushFrontBtn->setEnabled(false);
    ui->popBackBtn->setEnabled(false);
    ui->popFrontBtn->setEnabled(false);
    ui->CircularBtn->setEnabled(false);
}

void MainWindow::moveForward() {
    deque->moveForward();
    int index = deque->getCurrentIndex();

    ui->indexLabel->setText(QString::number(index));
    ui->valueLabel->setText(QString::number(deque->getCurrent()));
    ui->progressBar->setValue((float)(index + 1) / deque->getSize() * 100);
}

void MainWindow::moveBackward() {
    deque->moveBackward();
    int index = deque->getCurrentIndex();

    ui->indexLabel->setText(QString::number(index));
    ui->valueLabel->setText(QString::number(deque->getCurrent()));
    ui->progressBar->setValue((float)(index + 1) / deque->getSize() * 100);
}

void MainWindow::updateTable() {
    table->clear();
    table->setRowCount(1);

    int columnIndex = 0;
    table->setColumnCount(deque->getSize());
    for (int i = 0; i < deque->getSize(); i++) {
        const auto &item = *(deque->begin() + i);

        QTableWidgetItem* itemWidget = new QTableWidgetItem(QString::number(item));
        table->setHorizontalHeaderItem(columnIndex, new QTableWidgetItem(QString::number(columnIndex)));
        table->setItem(0, columnIndex, itemWidget);
        table->setColumnWidth(columnIndex, 16);
        columnIndex++;
    }
}
