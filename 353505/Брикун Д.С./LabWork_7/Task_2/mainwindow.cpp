#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>
#include <QTimer>

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

void MainWindow::displayTree(QStandardItem* parentItem, TreeNode* node) {
    if (node == nullptr)
        return;

    QStandardItem * child = new QStandardItem(QString::number(node->key) + ": " + node->str);
    parentItem->appendRow(child);

    displayTree(child, node->left);
    displayTree(child, node->right);
}

void MainWindow::on_pushButton_add_clicked()
{
    tree.insert(qMakePair(ui->spinBox->value(), ui->lineEdit->text()));
    model->clear();
    displayTree(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
}


void MainWindow::on_pushButton_del_clicked()
{
    tree.remove(ui->spinBox->value());
    model->clear();
    displayTree(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
}

void MainWindow::on_pushButton_find_clicked()
{
    ui->textEdit_ans->setText(tree.searchStringByKey(ui->spinBox->value()));
}


void MainWindow::on_pushButton_InOrder_clicked()
{
    auto vec = tree.inOrderToVec();
    QString ans;
    for (auto & i : vec) {
        ans += QString::number(i.first) + " - " + i.second + "\n";
    }
    ui->textEdit_ans->setText(ans);
}


void MainWindow::on_pushButton_PreOrder_clicked()
{
    auto vec = tree.preOrderToVec();
    QString ans;
    for (auto & i : vec) {
        ans += QString::number(i.first) + " - " + i.second + "\n";
    }
    ui->textEdit_ans->setText(ans);
}


void MainWindow::on_pushButton_PostOrder_clicked()
{
    auto vec = tree.postOrderToVec();
    QString ans;
    for (auto & i : vec) {
        ans += QString::number(i.first) + " - " + i.second + "\n";
    }
    ui->textEdit_ans->setText(ans);
}


void MainWindow::on_pushButton_eachLevel_clicked()
{
    auto vec = tree.nodesPerLevel();
    QString ans;
    for (int i = 0; i < vec.size(); ++i) {
        ans += QString::number(i) + ": " + QString::number(vec[i]) + "\n";
    }
    ui->textEdit_ans->setText(ans);
}


void MainWindow::on_pushButton_balanse_clicked()
{
    tree.balanceTree();
    model->clear();
    displayTree(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
}

