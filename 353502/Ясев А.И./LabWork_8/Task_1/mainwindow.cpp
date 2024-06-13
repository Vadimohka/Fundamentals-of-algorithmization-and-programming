#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel(this);
    ui->treeView->setModel(model);
    ui->treeView->header()->hide();
    ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    tree = new BinarySearchTree();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tree;
}

void MainWindow::showTree(QStandardItem* parent, Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    QStandardItem* child = new QStandardItem(QString::number(node->key) + ": " + node->value);
    parent->appendRow(child);

    showTree(child, node->left);
    showTree(child, node->right);
}

void MainWindow::on_pushButton_add_clicked()
{
    tree->insert(QInputDialog::getInt(nullptr, tr("User Input"), "Enter key:"), QInputDialog::getText(nullptr, tr("User Input"), "Enter Value:"));
    model->clear();
    showTree(model->invisibleRootItem(), tree->getRoot());
    ui->treeView->expandAll();
}

void MainWindow::on_pushButton_delete_clicked()
{
    tree->remove(QInputDialog::getInt(nullptr, tr("User Input"), "Enter key:"));
    model->clear();
    showTree(model->invisibleRootItem(), tree->getRoot());
    ui->treeView->expandAll();
}

void MainWindow::on_pushButton_find_clicked()
{
    QMessageBox::information(nullptr, tr("Search"), tree->search(QInputDialog::getInt(nullptr, tr("User Input"), "Enter Key:")));
}

void MainWindow::on_pushButton_order_clicked()
{
    auto vec = tree->traverseInOrder();
    QString str;
    for (auto& e : vec)
    {
        str += QString::number(e.first) + " - " + e.second + "\n";
    }
    ui->textBrowser->setText(str);
}

void MainWindow::on_pushButton_reverse_clicked()
{
    auto vec = tree->traversePostOrder();
    QString str;
    for (auto& e : vec)
    {
        str += QString::number(e.first) + " - " + e.second + "\n";
    }
    ui->textBrowser->setText(str);
}

void MainWindow::on_pushButton_byValue_clicked()
{
    auto vec = tree->traverseByValue();
    QString str;
    for (auto& e : vec)
    {
        str += QString::number(e.first) + " - " + e.second + "\n";
    }
    ui->textBrowser->setText(str);
}

void MainWindow::on_pushButton_balance_clicked()
{
    tree->balance();
    model->clear();
    showTree(model->invisibleRootItem(), tree->getRoot());
    ui->treeView->expandAll();
}
