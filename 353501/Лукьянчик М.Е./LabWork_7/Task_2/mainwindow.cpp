#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_addButton_clicked() {
    int key = ui->keyLineEdit->text().toInt();
    QString data = ui->dataLineEdit->text();
    bst.insert(data, key);
    QMessageBox::information(this, "Info", "Node added to the tree.");
}

void MainWindow::on_searchButton_clicked() {
    int key = ui->keyLineEdit->text().toInt();
    QString result = bst.search(key);
    QMessageBox::information(this, "Search Result", result.isEmpty() ? "Key not found." : result);
}

void MainWindow::on_deleteButton_clicked() {
    int key = ui->keyLineEdit->text().toInt();
    bst.remove(key);
    QMessageBox::information(this, "Info", "Node removed from the tree.");
}

void MainWindow::on_balanceButton_clicked() {
    bst.balance();
    QMessageBox::information(this, "Info", "Tree balanced.");
}

void MainWindow::on_printInOrderButton_clicked() {
    ui->treeView->clear();
    bst.printInOrder(ui->treeView);
}

void MainWindow::on_printPreOrderButton_clicked() {
    ui->treeView->clear();
    bst.printPreOrder(ui->treeView);
}

void MainWindow::on_printPostOrderButton_clicked() {
    ui->treeView->clear();
    bst.printPostOrder(ui->treeView);
}

void MainWindow::on_NodesWithTwoChildrenButton_clicked()
{
    int count = bst.countNodesWithTwoChildren();
    QMessageBox::information(this, "Info", QString::number(count) + " nodes with two children.");
}

