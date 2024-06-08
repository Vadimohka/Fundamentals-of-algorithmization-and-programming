#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_deleteButton_clicked()
{
    tree.remove(ui->deleteKey->value());
    tree.buildTreeWidget(ui->treeWidget);
    ui->insertKey->setValue(1);
}

void MainWindow::on_insertButton_clicked()
{
    tree.insert(ui->insertKey->value(), ui->insertValue->text());
    tree.buildTreeWidget(ui->treeWidget);
    ui->insertKey->setValue(1);
    ui->insertValue->clear();
}

void MainWindow::on_directButton_clicked()
{
    QPair<QVector<int>, QVector<QString>> pair;
    tree.directPrint(pair);
    ui->tableWidget->setColumnCount(pair.first.size());
    for (int i = 0; i < pair.first.size(); i++) {
        ui->tableWidget->setItem(0, i, new QTableWidgetItem(QString::number(pair.first[i])));
        ui->tableWidget->setItem(1, i, new QTableWidgetItem(pair.second[i]));
    }
}

void MainWindow::on_reverseButton_clicked()
{
    QPair<QVector<int>, QVector<QString>> pair;
    tree.reversePrint(pair);
    ui->tableWidget->setColumnCount(pair.first.size());
    for (int i = 0; i < pair.first.size(); i++) {
        ui->tableWidget->setItem(0, i, new QTableWidgetItem(QString::number(pair.first[i])));
        ui->tableWidget->setItem(1, i, new QTableWidgetItem(pair.second[i]));
    }
}

void MainWindow::on_printButton_clicked()
{
    QPair<QVector<int>, QVector<QString>> pair;
    tree.printTree(pair);
    ui->tableWidget->setColumnCount(pair.first.size());
    for (int i = 0; i < pair.first.size(); i++) {
        ui->tableWidget->setItem(0, i, new QTableWidgetItem(QString::number(pair.first[i])));
        ui->tableWidget->setItem(1, i, new QTableWidgetItem(pair.second[i]));
    }
}

void MainWindow::on_searchButton_clicked()
{
    ui->searchValue->setText(tree.search(ui->searchKey->value()));
    ui->searchKey->setValue(1);
}

void MainWindow::on_taskButton_clicked()
{
    ui->taskValue->setText(tree.findMiddleKeyValue());
}

void MainWindow::on_balanceButton_clicked()
{
    tree.balance();
    tree.buildTreeWidget(ui->treeWidget);
}
