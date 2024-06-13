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

void MainWindow::on_addButton_clicked() {
    QString data = ui->dataEdit->text();
    int key = ui->keyEdit->text().toInt();
    tree.insert(data, key);
    ui->dataEdit->clear();
    ui->keyEdit->clear();
}

void MainWindow::on_searchButton_clicked() {
    int key = ui->keyEdit->text().toInt();
    Node* result = tree.search(key);
    if (result != nullptr) {
        ui->resultLabel->setText(result->data);
    } else {
        ui->resultLabel->setText("Not found");
    }
}

void MainWindow::on_deleteButton_clicked() {
    int key = ui->keyEdit->text().toInt();
    tree.remove(key);
    ui->keyEdit->clear();
}

void MainWindow::on_balanceButton_clicked() {
    tree.balance();
}

void MainWindow::on_printPreOrderButton_clicked() {
    ui->outputEdit->setText(tree.getPreOrder());
}

void MainWindow::on_printInOrderButton_clicked() {
    ui->outputEdit->setText(tree.getInOrder());
}

void MainWindow::on_printPostOrderButton_clicked() {
    ui->outputEdit->setText(tree.getPostOrder());
}

void MainWindow::on_countLeavesButton_clicked() {
    ui->outputEdit->setText(tree.countLeavesPerLevel());
}
