#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    bst = new BinarySearchTree(this);
    connect(bst, &BinarySearchTree::traversalCompleted, this, &MainWindow::updateTraversal);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::on_addButton_clicked);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::on_removeButton_clicked);
    connect(ui->insertBranchButton, &QPushButton::clicked, this, &MainWindow::on_insertBranchButton_clicked);
    connect(ui->deleteBranchButton, &QPushButton::clicked, this, &MainWindow::on_deleteBranchButton_clicked);
    connect(ui->findLCAButton, &QPushButton::clicked, this, &MainWindow::on_findLCAButton_clicked);
    connect(ui->traverseButton, &QPushButton::clicked, this, &MainWindow::on_traverseButton_clicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_addButton_clicked() {
    int value = ui->addLineEdit->text().toInt();
    bst->add(value);
}

void MainWindow::on_removeButton_clicked() {
    int value = ui->removeLineEdit->text().toInt();
    bst->remove(value);
}

void MainWindow::on_insertBranchButton_clicked() {
    int parentValue = ui->insertParentLineEdit->text().toInt();
    int branchValue = ui->insertBranchLineEdit->text().toInt();
    bst->insertBranch(parentValue, branchValue);
}

void MainWindow::on_deleteBranchButton_clicked() {
    int parentValue = ui->deleteParentLineEdit->text().toInt();
    int branchValue = ui->deleteBranchLineEdit->text().toInt();
    bst->deleteBranch(parentValue, branchValue);
}



void MainWindow::on_findLCAButton_clicked() {
    int node1Value = ui->node1LineEdit->text().toInt();
    int node2Value = ui->node2LineEdit->text().toInt();
    Node* lca = bst->findLowestCommonAncestor(node1Value, node2Value);
    if (lca)
        ui->findLCAResultLabel->setText("LCA: " + QString::number(lca->data));
    else
        ui->findLCAResultLabel->setText("LCA not found");
}

void MainWindow::on_traverseButton_clicked() {
    bst->traverse();
}

void MainWindow::updateTraversal(QString traversal) {
    ui->traversalLabel->setText(traversal);
}
