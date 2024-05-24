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

void MainWindow::recursiveDisplayTree(QStandardItem *parentItem, TreeNode *node)
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
    tree.insert(qMakePair(ui->spb_val->value(), ui->lineEditText->text()));
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
    QString data = tree.searchStringByKey(ui->spb_findValue->value());
    QMessageBox::information(this, "Результат поиска                                         ", data);
}


void MainWindow::on_bnt_balanse_clicked()
{
    tree.balanceTree();
    model->clear();
    recursiveDisplayTree(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
}


void MainWindow::on_bnt_cnt_of_list_clicked()
{
    QVector<int> vec = tree.getLeavesPerLevel();
    QString ans;
    for (int i = 0; i < vec.size(); ++i) {
        ans += QString::number(i) + ": " + QString::number(vec[i]) + "\n";
    }
    QMessageBox::information(this, "Количество листьев на каждом уровне составило                     ", ans);
}


void MainWindow::on_bnt_pre_clicked()
{
    auto vec = tree.getPreOrder();
    QString ans;
    for (auto & i : vec) {
        ans += QString::number(i.first) + " - " + i.second + "\n";
    }
    QMessageBox::information(this, "Результат обхода                     ", ans);
}


void MainWindow::on_bnt_post_clicked()
{
    auto vec = tree.getPostOrder();
    QString ans;
    for (auto & i : vec) {
        ans += QString::number(i.first) + " - " + i.second + "\n";
    }
    QMessageBox::information(this, "Результат обхода                     ", ans);
}


void MainWindow::on_bnt_in_clicked()
{
    auto vec = tree.getInOrder();
    QString ans;
    for (auto & i : vec) {
        ans += QString::number(i.first) + " - " + i.second + "\n";
    }
    QMessageBox::information(this, "Результат обхода                     ", ans);
}

