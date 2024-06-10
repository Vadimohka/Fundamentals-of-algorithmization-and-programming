//
// Created by zgdarya on 5/29/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
        , widget(new Widget(this))
{
    ui->setupUi(this);

    treeNode = nullptr;

    updateTreeView();

    widget->setGeometry(10, 50, 780, 540); // Задаем размер и расположение виджета
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_insertButton_clicked()
{
    bool ok;
    int key = ui->keyInput->text().toInt(&ok);
    if (ok) {
        treeNode = AVLTree::insert(treeNode, key);
        updateTreeView();
    } else {
        QMessageBox::warning(this, "Input Error", "Please enter a valid integer key.");
    }
}

void MainWindow::on_removeButton_clicked()
{
    bool ok;
    int key = ui->keyInput->text().toInt(&ok);
    if (ok) {
        treeNode = AVLTree::deleteNode(treeNode, key);
        updateTreeView();
    } else {
        QMessageBox::warning(this, "Input Error", "Please enter a valid integer key.");
    }
}

void MainWindow::updateTreeView()
{
    widget->setAVLTree(treeNode);
}

void MainWindow::on_createButton_clicked() {
    std::map<long, std::string> database {
            {3, "a"},
            {0, "b"},
            {7, "c"},
            {11, "d"},
            {5, "e"},
            {90, "f"},
            {-12, "g"}
    };
    treeNode = AVLTree::createAVLTree(database);
    updateTreeView();
}

void MainWindow::on_containButton_clicked() {
    bool ok;
    int key = ui->keyInput->text().toInt(&ok);
    if (ok) {
        ok = AVLTree::contains(treeNode, key);
        ui->keyInput->setText(ok ? "true" : "false");
    } else {
        QMessageBox::warning(this, "Input Error", "Please enter a valid integer key.");
    }
}

void MainWindow::on_postButton_clicked() {
    AVLTree::postorderWalk(treeNode);
}

void MainWindow::on_preButton_clicked() {
    AVLTree::preorderWalk(treeNode);
}

void MainWindow::on_increaseButton_clicked() {
    std::vector<int> increase;
    AVLTree::increaseOrder(treeNode, increase);

    for(auto value: increase) {
        qDebug() << value;
    }
}
