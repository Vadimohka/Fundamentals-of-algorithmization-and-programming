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
    tree.add(ui->insertKey->value(), ui->insertValue->value());
    tree.buildTreeWidget(ui->treeWidget);
    ui->insertKey->setValue(1);
    ui->insertValue->clear();
}

void MainWindow::on_searchButton_clicked()
{
    ui->searchValue->setText(QString::number(tree.find(ui->searchKey->value())->value));
    ui->searchKey->setValue(1);
}

void MainWindow::on_preorderButton_clicked()
{
    QVector<Node<int> *> arr = tree.preorderTraverse();
    ui->tableWidget->setColumnCount(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        ui->tableWidget->setItem(0, i, new QTableWidgetItem(QString::number(arr[i]->key)));
        ui->tableWidget->setItem(1, i, new QTableWidgetItem(QString::number(arr[i]->value)));
    }
}

void MainWindow::on_postorderButton_clicked()
{
    QVector<Node<int> *> arr = tree.postorderTraverse();
    ui->tableWidget->setColumnCount(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        ui->tableWidget->setItem(0, i, new QTableWidgetItem(QString::number(arr[i]->key)));
        ui->tableWidget->setItem(1, i, new QTableWidgetItem(QString::number(arr[i]->value)));
    }
}

void MainWindow::on_inorderButton_clicked()
{
    QVector<Node<int> *> arr = tree.inorderTraverse();
    ui->tableWidget->setColumnCount(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        ui->tableWidget->setItem(0, i, new QTableWidgetItem(QString::number(arr[i]->key)));
        ui->tableWidget->setItem(1, i, new QTableWidgetItem(QString::number(arr[i]->value)));
    }
}

void MainWindow::on_parentButton_clicked()
{
    ui->parentValue->setText(
        QString::number(tree.findParent(ui->parentKey1->value(), ui->parentKey2->value())->key));
}

void MainWindow::on_subButton_clicked()
{
    tree.removeSubtree(ui->deleteSubKey->value());
    tree.buildTreeWidget(ui->treeWidget);
}

void MainWindow::on_leftButton_clicked()
{
    tree.removeLeftSubtree(ui->deleteSubKey->value());
    tree.buildTreeWidget(ui->treeWidget);
}

void MainWindow::on_rightButton_clicked()
{
    tree.removeRightSubtree(ui->deleteSubKey->value());
    tree.buildTreeWidget(ui->treeWidget);
}
