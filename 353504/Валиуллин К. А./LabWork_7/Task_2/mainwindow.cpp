#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    bst(new deletingBranchBST)
{
    ui->setupUi(this);
    model = new QStandardItemModel(this);
    ui->treeView->setModel(model);
    ui->treeView->header()->hide();
    ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->textEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete bst;
}

void MainWindow::displayTree(QStandardItem* parentItem, BSTNode* node)
{
    if (node == nullptr)
        return;

    QStandardItem *child = new QStandardItem(QString::number(node->key) + ": " + node->data);
    parentItem->appendRow(child);

    displayTree(child, node->left);
    displayTree(child, node->right);
}

void MainWindow::on_addNodeButton_clicked()
{
    bst->insert(ui->lineEdit->text(), ui->spinBox->value());
    model->clear();
    displayTree(model->invisibleRootItem(), bst->getRoot());
    ui->treeView->expandAll();
}

void MainWindow::on_balanceTreeButton_clicked()
{
    bst->balance();
    model->clear();
    displayTree(model->invisibleRootItem(), bst->getRoot());
    ui->treeView->expandAll();
}

void MainWindow::on_findNodeButton_clicked()
{
    QString result = bst->search(ui->spinBox->value());
    ui->textEdit->setText(result.isEmpty() ? "Node not found" : result);
}

void MainWindow::on_deleteNodeButton_clicked()
{
    bst->remove(ui->spinBox->value());
    model->clear();
    displayTree(model->invisibleRootItem(), bst->getRoot());
    ui->treeView->expandAll();
}

void MainWindow::on_directBypassButton_clicked()
{
    QList<QString> result = bst->preOrder();
    QString output;
    for (const QString &item : result)
    {
        output += item + "\n";
    }
    ui->textEdit->setText(output);
}

void MainWindow::on_reverseBypassButton_clicked()
{
    QList<QString> result = bst->postOrder();
    QString output;
    for (const QString &item : result)
    {
        output += item + "\n";
    }
    ui->textEdit->setText(output);
}

void MainWindow::on_ascendingBypassButton_clicked()
{
    QList<QString> result = bst->inOrder();
    QString output;
    for (const QString &item : result)
    {
        output += item + "\n";
    }
    ui->textEdit->setText(output);
}

void MainWindow::on_deleteBranchButton_clicked()
{
    int key = ui->spinBox->value();
    bst->removeSubtree(key);
    model->clear();
    displayTree(model->invisibleRootItem(), bst->getRoot());
    ui->treeView->expandAll();
}
