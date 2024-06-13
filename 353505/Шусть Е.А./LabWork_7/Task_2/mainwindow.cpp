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

void MainWindow::on_add_clicked()
{
    _tree.add(ui->key->value(), ui->inputValue->text());
    rebuildTree();
}


void MainWindow::on_erase_clicked()
{
    _tree.erase(ui->key->value());
    rebuildTree();
}


void MainWindow::on_find_clicked()
{
    QString* str;
    if (str = _tree.find(ui->key->value())) {
        ui->returnValue->setText(*str);
    } else {
        ui->returnValue->setText("Unlucky that time");
    }
}

void MainWindow::rebuildTree()
{
    ui->tree->clear();
    if (_tree._root) {
        QTreeWidgetItem *root = new QTreeWidgetItem(ui->tree);
        root->setText(0, QString::number(_tree._root->key) + ": " + _tree._root->value);
        ui->tree->addTopLevelItem(root);
        addTreeNodes(ui->tree->topLevelItem(0), _tree._root->left.get());
        addTreeNodes(ui->tree->topLevelItem(0), _tree._root->right.get());
    }
    ui->size->setValue(_tree.size());
    ui->leaves->clear();
    for (size_t leaves : _tree.leaves()) {
        ui->leaves->setText(ui->leaves->text() + " " + QString::number(leaves));
    }
}

void MainWindow::addTreeNodes(QTreeWidgetItem *parentItem, TaskTree::Node *node)
{
    if (node == nullptr) {
        return;
    }

    QTreeWidgetItem *treeItem = new QTreeWidgetItem();

    treeItem->setText(0, QString::number(node->key) + ": " + node->value);

    parentItem->addChild(treeItem);

    addTreeNodes(treeItem, node->left.get());
    addTreeNodes(treeItem, node->right.get());
}

