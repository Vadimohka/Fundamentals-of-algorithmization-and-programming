//
// Created by zgdarya on 5/30/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow), elementCounter(0) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_deleteButton_clicked() {
    if (!deque.isEmpty()) {
        deque.pop_front();
        print();
    }
}

void MainWindow::on_addButton_clicked() {
    bool ok;
    int number = ui->lineEdit->text().toUInt(&ok);
    if (ok) {
        deque.push_back(number);
        print();
    }
}

void MainWindow::on_showButton_clicked() {
    print();
}

void MainWindow::on_backButton_clicked() {
    ui->deque_listWidget->clear();
    ui->deque_listWidget->addItem(QString::number(deque.back()));
}

void MainWindow::on_frontButton_clicked() {
    ui->deque_listWidget->clear();
    ui->deque_listWidget->addItem(QString::number(deque.front()));

}

void MainWindow::print() {
    ui->deque_listWidget->clear();
    for (int i = 0; i < deque.size(); ++i) {
        ui->deque_listWidget->addItem(QString::number(deque.front()));
        deque.push_back(deque.front());
        deque.pop_front();
    }
}
