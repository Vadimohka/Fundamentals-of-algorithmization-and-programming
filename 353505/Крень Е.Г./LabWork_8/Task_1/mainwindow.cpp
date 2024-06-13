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

void MainWindow::recursiveDisplayTree(QStandardItem *parentItem, BinSearchTree<int>::node* node)
{
    if (node == nullptr)
        return;

    QList<QStandardItem *> rowItems;

    QStandardItem *item = new QStandardItem(QString::number(node->data));
    rowItems << item;

    parentItem->appendRow(rowItems);

    recursiveDisplayTree(item, node->left);
    recursiveDisplayTree(item, node->right);
}

void MainWindow::on_add1_push_button_clicked()
{
    tree.add(ui->add1_spinBox->value());
    model->clear();
    recursiveDisplayTree(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
}


void MainWindow::on_delete_push_button_clicked()
{
    tree.remove(ui->delete_spinBox->value());
    model->clear();
    recursiveDisplayTree(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
}


void MainWindow::on_find_push_button_clicked()
{
    bool data = tree.find(ui->find_spinBox->value());
    ui->answer_label->setText(data ? "Элемент не найден" : "Элемент найден");
}


void MainWindow::on_find_root_push_button_clicked()
{
    bool d1 = tree.find(ui->spinBox_5->value());
    bool d2 = tree.find(ui->spinBox_6->value());
    if (!d1 || !d2) {
        ui->answer_label->setText("Таких ключей нет");
    }
    else {
        auto key = tree.findRoot(ui->spinBox_5->value(), ui->spinBox_5->value());
         ui->answer_label->setText(QString::number(key->data));
    }
}

void MainWindow::on_traverse_button_clicked()
{
    QVector<int> vec = tree.traverse();
    QString ans = "Результат обхода: ";
    for (auto & i : vec) {
        ans += QString::number(i) + "\n";
    }
    ui->answer_label->setText(ans);
}


void MainWindow::on_add_subtree_push_button_clicked()
{
    tree.insertTree(subTree.getRoot());
    model->clear();
    recursiveDisplayTree(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
    subModel->clear();
    recursiveDisplayTree(subModel->invisibleRootItem(), subTree.getRoot());
    ui->treeView_2->expandAll();
}


void MainWindow::on_delete_subtree_push_button_clicked()
{
    tree.removeTree(subTree.getRoot());
    model->clear();
    recursiveDisplayTree(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
    subModel->clear();
    recursiveDisplayTree(subModel->invisibleRootItem(), subTree.getRoot());
    ui->treeView_2->expandAll();
}


void MainWindow::on_add2_push_button_clicked()
{
    subTree.add(ui->add2_spinBox->value());
    subModel->clear();
    recursiveDisplayTree(subModel->invisibleRootItem(), subTree.getRoot());
    ui->treeView_2->expandAll();
}

