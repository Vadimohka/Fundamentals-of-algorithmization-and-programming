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
    subModel = new QStandardItemModel(this);
    ui->treeView_2->setModel(subModel);
    ui->treeView_2->header()->hide();
    ui->treeView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::recursiveDisplayTree(QStandardItem *parentItem, TreeNode <QString> *node)
{
    if (node == nullptr)
        return;

    QList<QStandardItem *> rowItems;

    QString data = (node != nullptr) ? node->data : QString("Node not found");
    QStandardItem *item = new QStandardItem(QString::number(node->key) + ": " + data);
    rowItems << item;

    parentItem->appendRow(rowItems);

    recursiveDisplayTree(item, node->left_child);
    recursiveDisplayTree(item, node->right_child);
}

void MainWindow::on_bnt_add_item_clicked()
{
    tree.add(ui->spb_val->value(), ui->lineEditText->text());
    model->clear();
    recursiveDisplayTree(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
}


void MainWindow::on_bnt_remove_clicked()
{
    tree.remove(ui->spb_delValue->value());
    model->clear();
    recursiveDisplayTree(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
}


void MainWindow::on_bnt_search_clicked()
{
    bool data = tree.find(ui->spb_findValue->value());
    QString info = data ? "Такой элемент есть!!!" : "Такого элемента нет!!!";
    QMessageBox::information(this, "Результат поиска                                         ", info);
}


void MainWindow::on_bnt_cnt_of_list_clicked()
{
    bool d1 = tree.find(ui->el_1->value());
    bool d2 = tree.find(ui->el_2->value());
    if (!d1 || !d2) {
        QMessageBox::information(this, "Результат поиска                                         ", "Таких ключей нет");
    }
    else {
        auto key = tree.findLowestCommonAncestor(ui->el_1->value(), ui->el_2->value());
        QMessageBox::information(this, "Ключ наименьшего общего предка                     ", QString::number(key->key));
    }
}


void MainWindow::on_bnt_pre_clicked()
{
    auto vec = tree.preOrderTraverse();
    QString ans;
    for (auto & i : vec) {
        ans += QString::number(i) + "\n";
    }
    QMessageBox::information(this, "Результат обхода (ключи)                     ", ans);
}


void MainWindow::on_bnt_post_clicked()
{
    auto vec = tree.postOrderTraverse();
    QString ans;
    for (auto & i : vec) {
        ans += QString::number(i) + "\n";
    }
    QMessageBox::information(this, "Результат обхода (ключи)                     ", ans);
}


void MainWindow::on_bnt_in_clicked()
{
    auto vec = tree.inOrderTraverse();
    QString ans;
    for (auto & i : vec) {
        ans += QString::number(i) + "\n";
    }
    QMessageBox::information(this, "Результат обхода (ключи)                     ", ans);
}


void MainWindow::on_bnt_add_subtree_clicked()
{
    tree.insertSubtree(subTree.getRoot());
    model->clear();
    recursiveDisplayTree(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
    subModel->clear();
    recursiveDisplayTree(subModel->invisibleRootItem(), subTree.getRoot());
    ui->treeView_2->expandAll();
}


void MainWindow::on_bnt_remove_subtree_clicked()
{
    tree.removeSubtree(subTree.getRoot());
    model->clear();
    recursiveDisplayTree(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
    subModel->clear();
    recursiveDisplayTree(subModel->invisibleRootItem(), subTree.getRoot());
    ui->treeView_2->expandAll();
}


void MainWindow::on_bnt_add_item_2_clicked()
{
    subTree.add(ui->spb_val_2->value(), ui->lineEditText_2->text());
    subModel->clear();
    recursiveDisplayTree(subModel->invisibleRootItem(), subTree.getRoot());
    ui->treeView_2->expandAll();
}

