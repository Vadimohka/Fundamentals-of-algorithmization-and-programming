#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel(this);
    ui->tree->setModel(model);
    ui->tree->header()->hide();
    ui->tree->setEditTriggers(QAbstractItemView::NoEditTriggers);

    subModel = new QStandardItemModel(this);
    ui->subtree->setModel(subModel);
    ui->subtree->header()->hide();
    ui->subtree->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayTree(QStandardItem *parentItem, Node<QString> *node)
{
    // if (node == nullptr)
    // {
    //     return;
    // }



    // QList<QStandardItem *> rowItems;

    // QString data = (node != nullptr) ? node->data : QString("Node not found");
    // QStandardItem *item = new QStandardItem(QString::number(node->key) + ": " + data);
    // rowItems << item;

    // parentItem->appendRow(rowItems);

    // //displayTree(item, node->left);
    // //displayTree(item, node->right);
    // displayTree(parentItem, node->left);
    // displayTree(parentItem, node->left);

    if (!ptr1)
        ptr1 = tree.getRoot();
    if (!ptr2)
        ptr2 = tree.getRoot();
    if (node == nullptr)
        return;

    QStandardItem * child = new QStandardItem(QString::number(node->key) + ": " + node->data);
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
void MainWindow::on_pushButton_clicked()
{
    tree.add(ui->key->value(), ui->lineEdit->text());
    model->clear();
    displayTree(model->invisibleRootItem(), tree.getRoot());
    ui->tree->expandAll();
}

void MainWindow::on_pushButton_2_clicked()
{
    tree.remove(ui->spinBox->value());
    model->clear();
    displayTree(model->invisibleRootItem(), tree.getRoot());
    ui->tree->expandAll();
}

void MainWindow::on_pushButton_4_clicked()
{
    bool d1 = tree.find(ui->spinBox_3->value());
    bool d2 = tree.find(ui->spinBox_4->value());
    if (!d1 || !d2) {
        QMessageBox::information(this, "Результат поиска                                         ", "Таких ключей нет");
    }
    else {
        auto key = tree.findTheSmallestCommonAncestor(ui->spinBox_3->value(), ui->spinBox_4->value());
        QMessageBox::information(this, "Ключ наименьшего общего предка                     ", QString::number(key->key));
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    bool data = tree.find(ui->spinBox_2->value());
    QString info = data ? "Такой элемент есть!!!" : "Такого элемента нет!!!";
    QMessageBox::information(this, "Результат поиска                                         ", info);
}

void MainWindow::on_pushButton_5_clicked()
{
    auto vec = tree.preOrderTraverse();
    QString ans;
    for (auto & i : vec) {
        ans += QString::number(i) + "\n";
    }
    QMessageBox::information(this, "Результат обхода (ключи)                     ", ans);
}


void MainWindow::on_pushButton_6_clicked()
{
    auto vec = tree.postOrderTraverse();
    QString ans;
    for (auto & i : vec) {
        ans += QString::number(i) + "\n";
    }
    QMessageBox::information(this, "Результат обхода (ключи)                     ", ans);
}

void MainWindow::on_pushButton_7_clicked()
{
    auto vec = tree.inOrderTraverse();
    QString ans;
    for (auto & i : vec) {
        ans += QString::number(i) + "\n";
    }
    QMessageBox::information(this, "Результат обхода (ключи)                     ", ans);
}
void MainWindow::on_pushButton_8_clicked()
{
    tree.insert(subtree.getRoot());
    model->clear();
    displayTree(model->invisibleRootItem(), tree.getRoot());
    ui->tree->expandAll();
    subModel->clear();
    displayTree(subModel->invisibleRootItem(), subtree.getRoot());
    ui->subtree->expandAll();
}


void MainWindow::on_pushButton_9_clicked()
{
    tree.deleteSubtree(subtree.getRoot());
    model->clear();
    displayTree(model->invisibleRootItem(), tree.getRoot());
    ui->tree->expandAll();
    subModel->clear();
    displayTree(subModel->invisibleRootItem(), subtree.getRoot());
    ui->subtree->expandAll();
}


void MainWindow::on_pushButton_10_clicked()
{
    subtree.add(ui->key_2->value(), ui->lineEdit_2->text());
    subModel->clear();
    displayTree(subModel->invisibleRootItem(), subtree.getRoot());
    ui->subtree->expandAll();
}

