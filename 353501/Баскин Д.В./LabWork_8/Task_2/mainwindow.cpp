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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::display(QStandardItem* parent, std::shared_ptr<Node<QString>> node)
{
    if (!node)
    {
        return;
    }

    QStandardItem* item = new QStandardItem(node->value);
    parent->appendRow(item);

    display(item, node->left);
    display(item, node->right);
}

void MainWindow::on_pushButton_push_clicked()
{
    listHeap.push(QInputDialog::getText(nullptr, tr("User Input"), "Enter element:"));
    model->clear();
    display(model->invisibleRootItem(), listHeap.getRoot());
    ui->treeView->expandAll();
}

void MainWindow::on_pushButton_pop_clicked()
{
    if (listHeap.empty())
    {
        QMessageBox::information(nullptr, tr("Pop"), "List Heap is empty", QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }
    QMessageBox::information(nullptr, tr("Pop"), "Popped element:" + listHeap.pop(), QMessageBox::Ok | QMessageBox::NoButton);
    model->clear();
    display(model->invisibleRootItem(), listHeap.getRoot());
    ui->treeView->expandAll();
}

void MainWindow::on_pushButton_clear_clicked()
{
    listHeap.clearHeap();
    QMessageBox::information(nullptr, tr("Clear"), "List Heap has been cleared", QMessageBox::Ok | QMessageBox::NoButton);
    model->clear();
    display(model->invisibleRootItem(), listHeap.getRoot());
    ui->treeView->expandAll();
}

void MainWindow::on_pushButton_push_2_clicked()
{
    arrayHeap.push(QInputDialog::getText(nullptr, tr("User Input"), "Enter element:"));
    auto vec = arrayHeap.toVector();
    QString str;
    for (auto e : vec)
    {
        str.append(e + " ");
    }
    ui->textBrowser->setText(str);
}

void MainWindow::on_pushButton_pop_2_clicked()
{
    if (arrayHeap.empty())
    {
        QMessageBox::information(nullptr, tr("Pop"), "Array Heap is empty", QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }
    QMessageBox::information(nullptr, tr("Pop"), "Popped element:" + arrayHeap.pop(), QMessageBox::Ok | QMessageBox::NoButton);
    auto vec = arrayHeap.toVector();
    QString str;
    for (auto e : vec)
    {
        str.append(e + " ");
    }
    ui->textBrowser->setText(str);
}

void MainWindow::on_pushButton_clear_2_clicked()
{
    arrayHeap.clear();
    QMessageBox::information(nullptr, tr("Clear"), "Array Heap has been cleared", QMessageBox::Ok | QMessageBox::NoButton);
    auto vec = arrayHeap.toVector();
    QString str;
    for (auto e : vec)
    {
        str.append(e + " ");
    }
    ui->textBrowser->setText(str);
}
