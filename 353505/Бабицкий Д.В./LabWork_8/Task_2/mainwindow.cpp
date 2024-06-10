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

void MainWindow::displayTree(QStandardItem* parentItem, std::shared_ptr<ListNode> node) {
    if (node == nullptr)
        return;

    QStandardItem * child = new QStandardItem(QString::number(node->data));
    parentItem->appendRow(child);

    displayTree(child, node->left);
    displayTree(child, node->right);
}

void MainWindow::on_pushButton_push_clicked()
{
    arr.push(ui->spinBox->value());
    auto vec = arr.toVec();
    QString str;
    for (auto i : vec) {
        str.append(QString::number(i) + " ");
    }
    ui->textEdit->setText(str);
}


void MainWindow::on_pushButton_pop_clicked()
{
    arr.pop();
    auto vec = arr.toVec();
    QString str;
    for (auto i : vec) {
        str.append(QString::number(i) + " ");
    }
    ui->textEdit->setText(str);
}


void MainWindow::on_pushButton_clear_clicked()
{
    arr.clear();
    auto vec = arr.toVec();
    QString str;
    for (auto i : vec) {
        str.append(QString::number(i) + " ");
    }
    ui->textEdit->setText(str);
}


void MainWindow::on_pushButton_push_2_clicked()
{
    list.push(ui->spinBox->value());
    model->clear();
    displayTree(model->invisibleRootItem(), list.getRoot());
    ui->treeView->expandAll();
}


void MainWindow::on_pushButton_pop_2_clicked()
{
    list.pop();
    model->clear();
    displayTree(model->invisibleRootItem(), list.getRoot());
    ui->treeView->expandAll();
}


void MainWindow::on_pushButton_clear_2_clicked()
{
    list.clear();
    model->clear();
    displayTree(model->invisibleRootItem(), list.getRoot());
    ui->treeView->expandAll();
}

