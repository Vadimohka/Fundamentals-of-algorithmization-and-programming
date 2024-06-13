#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>
#include <QTreeView>
#include <memory>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(new QStandardItemModel(this))
{
    ui->setupUi(this);

    QStandardItem* rootItem = createItemForNode(root_);
    model->setItem(0, 0, rootItem);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QStandardItem* MainWindow::createItemForNode(std::shared_ptr<Node> root, const QString &position)
{
    if (!root) {
        return nullptr;
    }

    QString label;
    if (position.isEmpty()) {
        label = QString::number(root->key) + ":" + QString::fromStdString(root->value) + " (root)";
    } else {
        label = QString::number(root->key) + ":" + QString::fromStdString(root->value) + " (" + position + ")";
    }

    QStandardItem* item = new QStandardItem(label);

    if (root->left) {
        QStandardItem* leftChild = createItemForNode(root->left, "left");
        item->appendRow(leftChild);
    }

    if (root->right) {
        QStandardItem* rightChild = createItemForNode(root->right, "right");
        item->appendRow(rightChild);
    }

    return item;
}

void MainWindow::printDirect(std::shared_ptr<Node> node)
{
    if (!node) {
        return;
    }

    ui->printOrder->append(QString("%1: %2").arg(node->key).arg(QString::fromStdString(node->value)));
    printDirect(node->left);
    printDirect(node->right);
}

void MainWindow::printReverse(std::shared_ptr<Node> node)
{
    if (!node) {
        return;
    }

    printReverse(node->left);
    printReverse(node->right);
    ui->printOrder->append(QString("%1: %2").arg(node->key).arg(QString::fromStdString(node->value)));
}

void MainWindow::printIncreaseKey(std::shared_ptr<Node> node)
{
    if (!node) {
        return;
    }

    printIncreaseKey(node->left);
    ui->printOrder->append(QString("%1: %2").arg(node->key).arg(QString::fromStdString(node->value)));
    printIncreaseKey(node->right);
}

void MainWindow::on_addBtn_clicked()
{
    int key = ui->key->value();
    QString value = ui->value->text();

    root_ = AVLTree::insert(root_, key, value.toStdString());

    QStandardItem* newItem = createItemForNode(root_, QString());
    model->clear();
    model->appendRow(newItem);
    ui->treeView->setModel(model);
}

void MainWindow::on_deleteBtn_clicked()
{
    int key = ui->key->value();
    root_ = AVLTree::deleteNode(root_, key);

    QStandardItem* newRoot = createItemForNode(root_, QString());
    model->clear();
    model->appendRow(newRoot);
    ui->treeView->setModel(model);
}

void MainWindow::on_findBtn_clicked()
{
    int key = ui->key->value();
    std::shared_ptr<Node> foundNode = AVLTree::findNode(root_, key);

    if (foundNode) {
        ui->valueEdit->setText(QString::fromStdString(foundNode->value));
    } else {
        ui->valueEdit->setText("Node not found");
    }
}

void MainWindow::on_directBtn_clicked()
{
    ui->printOrder->clear();
    printDirect(root_);
}

void MainWindow::on_reverseBtn_clicked()
{
    ui->printOrder->clear();
    printReverse(root_);
}

void MainWindow::on_IncreaseKeyBtn_clicked()
{
    ui->printOrder->clear();
    printIncreaseKey(root_);
}

void MainWindow::on_countLeftNodesBtn_clicked()
{
    int leftNodeCount = AVLTree::countNodesInLeftSubtree(root_);
    ui->printOrder->append(QString("Number of nodes in the left subtree: %1").arg(leftNodeCount));
}
