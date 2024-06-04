#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qpushbutton.h>
#include <qtablewidget.h>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->table_1, &QTableWidget::cellClicked, this, &MainWindow::table1Clicked);
    connect(ui->table_2, &QTableWidget::cellClicked, this, &MainWindow::table2Clicked);

    connect(ui->pushBackBtn1, &QPushButton::pressed, this, &MainWindow::pushBack1);
    connect(ui->pushBackBtn2, &QPushButton::pressed, this, &MainWindow::pushBack2);
    connect(ui->popBackBtn1, &QPushButton::pressed, this, &MainWindow::popBack1);
    connect(ui->popBackBtn2, &QPushButton::pressed, this, &MainWindow::popBack2);
    connect(ui->eraseBtn1, &QPushButton::pressed, this, &MainWindow::erase1);
    connect(ui->eraseBtn2, &QPushButton::pressed, this, &MainWindow::erase2);
    connect(ui->insertBtn1, &QPushButton::pressed, this, &MainWindow::insert1);
    connect(ui->insertBtn2, &QPushButton::pressed, this, &MainWindow::insert2);
}

void MainWindow::populateTable1(){
    QTableWidget *table = ui->table_1;
    int size = firstVector.size();
    table->clear();
    table->setRowCount(size);
    table->setColumnCount(1);

    for (int i = 0; i < size; i++) {
        int number = firstVector.at(i);
        table->setItem(i, 0, new QTableWidgetItem( QString::number(number)));
    }
}

void MainWindow::populateTable2(){
    QTableWidget *table = ui->table_2;
    int size = secondVector.size();
    table->clear();
    table->setRowCount(secondVector.size());
    table->setColumnCount(2);

    for (int i = 0; i < size; i++) {
        Pair<int, double> numbers = secondVector.at(i);
        table->setItem(i, 0, new QTableWidgetItem( QString::number(numbers.first)));
        table->setItem(i, 1, new QTableWidgetItem( QString::number(numbers.second)));
    }
}

void MainWindow::table1Clicked(int row, int column) {
    selectedRow = row;
    selectedCol = column;
    selectedTable = 1;
    ui->eraseBtn1->setDisabled(false);
    ui->insertBtn1->setDisabled(false);
}

void MainWindow::table2Clicked(int row, int column) {
    selectedRow = row;
    selectedCol = column;
    selectedTable = 2;
    ui->eraseBtn2->setDisabled(false);
    ui->insertBtn2->setDisabled(false);
}

void MainWindow::pushBack1(){
    firstVector.push_back(ui->spinBox1->value());
    populateTable1();
}

void MainWindow::pushBack2(){
    secondVector.push_back({ui->spinBox2_int->value(), ui->spinBox2_double->value()});
    populateTable2();
}

void MainWindow::popBack1(){
    firstVector.pop_back();
    populateTable1();
}

void MainWindow::popBack2(){
    secondVector.pop_back();
    populateTable2();
}

void MainWindow::insert1(){
    try {
        firstVector.insert(firstVector.cbegin() + selectedRow, ui->spinBox1->value());
        selectedRow = -1;
    } catch (...) {
        return;
    }
    populateTable1();
}

void MainWindow::insert2(){
    try {
        secondVector.insert(secondVector.cbegin() + selectedRow, {ui->spinBox2_int->value(), ui->spinBox2_double->value()});
        selectedRow = -1;
    } catch (...) {
        return;
    }
    populateTable2();
}

void MainWindow::erase1(){
    try { 
        firstVector.erase(firstVector.begin() + selectedRow);
        selectedRow = -1;
    } catch (...) {
        return;
    }
    populateTable1();
}

void MainWindow::erase2(){
    try {
        secondVector.erase(secondVector.begin() + selectedRow);
        selectedRow = -1;
    } catch (...) {
        return;
    }
    populateTable2();
}