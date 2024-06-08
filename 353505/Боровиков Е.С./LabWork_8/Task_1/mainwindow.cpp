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
    model1 = new QStandardItemModel(this);
    ui->treeView_2->setModel(model1);
    ui->treeView_2->header()->hide();
    ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayTree(QStandardItem* parentItem, Node<int> *node) {
    if (!ptr1)
        ptr1 = tree.getRoot();
    if (!ptr2)
        ptr2 = tree.getRoot();
    if (node == nullptr)
        return;

    QStandardItem * child = new QStandardItem(QString::number(node->data));
    if (node == ptr1 && node == ptr2)
        child->setBackground(QColorConstants::Svg::orange);
    else if (node == ptr2)
        child->setBackground(QColorConstants::Svg::yellow);
    else if (node == ptr1)
        child->setBackground(QColorConstants::Svg::red);
    parentItem->appendRow(child);

    displayTree(child, node->left);
    displayTree(child, node->right);
}

void MainWindow::on_pushButton_add_clicked()
{
    tree.insert(ui->spinBox->value(), ui->spinBox->value());
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
    ui->textEdit_ans->setText(QString::number(tree.find(ui->spinBox->value())));
}


void MainWindow::on_pushButton_add_to_sub_clicked()
{
    subTree.insert(ui->spinBox->value(), ui->spinBox->value());
    model1->clear();
    displayTree(model1->invisibleRootItem(), subTree.getRoot());
    ui->treeView_2->expandAll();
}


void MainWindow::on_pushButton_add_sub_clicked()
{
    tree.appendTree(subTree);
    model->clear();
    displayTree(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
    model1->clear();
    displayTree(model1->invisibleRootItem(), subTree.getRoot());
    ui->treeView_2->expandAll();
}


void MainWindow::on_pushButton_del_sub_clicked()
{
    subTree.remove(ui->spinBox->value());
    model1->clear();
    displayTree(model1->invisibleRootItem(), subTree.getRoot());
    ui->treeView_2->expandAll();
}


void MainWindow::on_pushButton_traverse_clicked()
{
    auto vec = tree.traverse();
    QString ans;
    for (auto & i : vec) {
        ans += QString::number(i) + "\n";
    }
    ui->textEdit_ans->setText(ans);
}

void MainWindow::on_pushButton_1_left_clicked()
{
    if (ptr1->left)
        ptr1 = ptr1->left;
    model->clear();
    displayTree(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
}


void MainWindow::on_pushButton_1_right_clicked()
{
    if (ptr1->right)
        ptr1 = ptr1->right;
    model->clear();
    displayTree(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
}


void MainWindow::on_pushButton_1_root_clicked()
{
    ptr1 = tree.getRoot();
    model->clear();
    displayTree(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
}


void MainWindow::on_pushButton_2_left_clicked()
{
    if (ptr2->left)
        ptr2 = ptr2->left;
    model->clear();
    displayTree(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
}


void MainWindow::on_pushButton_2_right_clicked()
{
    if (ptr2->right)
        ptr2 = ptr2->right;
    model->clear();
    displayTree(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
}


void MainWindow::on_pushButton_2_root_clicked()
{
    ptr2 = tree.getRoot();
    model->clear();
    displayTree(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
}


void MainWindow::on_pushButton_lcr_clicked()
{
    ptr1 = tree.findCommonKey(ptr1, ptr2);
    ptr2 = ptr1;
    model->clear();
    displayTree(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
}


void MainWindow::on_pushButton_rem_sub_clicked()
{
    tree.removeTree(subTree);
    model->clear();
    displayTree(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
    model1->clear();
    displayTree(model1->invisibleRootItem(), subTree.getRoot());
    ui->treeView_2->expandAll();
}

