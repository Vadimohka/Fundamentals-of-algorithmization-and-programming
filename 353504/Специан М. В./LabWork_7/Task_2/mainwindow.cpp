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
}

MainWindow::~MainWindow()
{
    delete ui;
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
    tree.insert(qMakePair(QInputDialog::getInt(nullptr, tr("User Input"), "Enter key:"), QInputDialog::getText(nullptr, tr("User Input"), "Enter Value:")));
    model->clear();
    showTree(model->invisibleRootItem(), tree.GetTreeRoot());
    ui->treeView->expandAll();
}

void MainWindow::on_pushButton_delete_clicked()
{
    tree.remove(QInputDialog::getInt(nullptr, tr("User Input"), "Enter key:"));
    model->clear();
    showTree(model->invisibleRootItem(), tree.GetTreeRoot());
    ui->treeView->expandAll();
}


void MainWindow::on_pushButton_find_clicked()
{
    QMessageBox::information(nullptr, tr("Search"), tree.searchValueByKey(QInputDialog::getInt(nullptr, tr("User Input"), "Enter Key:")));
}


void MainWindow::on_pushButton_order_clicked()
{
    auto vec = tree.toVector();
    QString str;
    for (auto& e : vec)
    {
        str += QString::number(e.first) + " - " + e.second + "\n";
    }
    ui->textBrowser->setText(str);
}


void MainWindow::on_pushButton_reverse_clicked()
{
    auto vec = tree.reverseToVector();
    QString str;
    for (auto& e : vec)
    {
        str += QString::number(e.first) + " - " + e.second + "\n";
    }
    ui->textBrowser->setText(str);
}


void MainWindow::on_pushButton_byValue_clicked()
{
    auto vec = tree.byValueToVector();
    QString str;
    for (auto& e : vec)
    {
        str += QString::number(e.first) + " - " + e.second + "\n";
    }
    ui->textBrowser->setText(str);
}


void MainWindow::on_pushButton_balance_clicked()
{
    tree.makeBalanced();
    model->clear();
    showTree(model->invisibleRootItem(), tree.GetTreeRoot());
    ui->treeView->expandAll();
}


void MainWindow::on_pushButton_minMaxSwap_clicked()
{
    tree.swapMinMax();
    model->clear();
    showTree(model->invisibleRootItem(), tree.GetTreeRoot());
}

