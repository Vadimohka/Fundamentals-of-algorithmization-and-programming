#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->treeView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update()
{
    model.clear();
    model.appendRow(createItemForNode(tree->getRoot(), ""));
    ui->treeView->setModel(&model);
    ui->treeView->expandAll();
}

void MainWindow::on_treeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_backButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_createButton_clicked()
{
    if (ui->valueEdit->text() != "") {
        tree = new AVLTree<QString>(ui->keyValue->value(), ui->valueEdit->text());
        update();
    }
}

void MainWindow::on_addButton_clicked()
{
    if (ui->valueEdit->text() != "" && model.rowCount() != 0) {
        tree->insert(ui->keyValue->value(), ui->valueEdit->text());
        update();
    }
}

void MainWindow::on_deleteButton_clicked()
{
    if (model.rowCount() != 0) {
        tree->remove(ui->keyValue->value());
        update();
    }
}

void MainWindow::on_directInputButton_clicked()
{
    if (model.rowCount() != 0) {
        ui->inputWidget->clear();
        directInputVisual(tree->getRoot(), *ui->inputWidget);
    }
}

void MainWindow::on_reverseInputButton_clicked()
{
    if (model.rowCount() != 0) {
        ui->inputWidget->clear();
        reverseInputVisual(tree->getRoot(), *ui->inputWidget);
    }
}

void MainWindow::on_increseKeyButton_clicked()
{
    if (model.rowCount() != 0) {
        ui->inputWidget->clear();
        increaseKeyInputVisual(tree->getRoot(), *ui->inputWidget);
    }
}

void MainWindow::on_findButton_clicked()
{
    if (model.rowCount() != 0) {
        ui->inputWidget->clear();
        findVisual(tree->getRoot(), ui->keyValue->value(), *ui->inputWidget);
    }
}

void MainWindow::on_findMinButton_clicked()
{
    if (model.rowCount() != 0) {
        ui->inputWidget->clear();
        findMinVisual(tree->getRoot(), *ui->inputWidget);
    }
}

void MainWindow::on_findMaxButton_clicked()
{
    if (model.rowCount() != 0) {
        ui->inputWidget->clear();
        findMaxVisual(tree->getRoot(), *ui->inputWidget);
    }
}

void MainWindow::on_findAverageButton_clicked()
{
    if (model.rowCount() != 0) {
        ui->inputWidget->clear();
        findAverageNodeVisual(*tree, *ui->inputWidget);
    }
}
