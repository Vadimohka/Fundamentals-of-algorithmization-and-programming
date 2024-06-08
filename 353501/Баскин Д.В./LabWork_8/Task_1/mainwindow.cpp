#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QStandardItemModel(this);
    ui->treeView->setModel(model);
    subModel = new QStandardItemModel(this);
    ui->treeView_2->setModel(subModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::display(QStandardItem* parent, Node<long>* node)
{
    if (!node1)
    {
        node1 = bst.getRoot();
    }
    if (!node2)
    {
        node2 = bst.getRoot();
    }
    if (node == nullptr)
    {
        return;
    }

    QStandardItem * child = new QStandardItem(QString::number(node->value));
    if (node == node1 && node == node2)
    {
        child->setBackground(QColorConstants::Svg::purple);
    }
    else if (node == node2)
    {
        child->setBackground(QColorConstants::Svg::yellow);
    }
    else if (node == node1)
    {
        child->setBackground(QColorConstants::Svg::orange);
    }
    parent->appendRow(child);

    display(child, node->left);
    display(child, node->right);
}

void MainWindow::on_pushButton_add_clicked()
{
    long element = QInputDialog::getInt(nullptr, tr("User Input"), "Enter Element:");
    bst.add(element, element);
    model->clear();
    display(model->invisibleRootItem(), bst.getRoot());
    ui->treeView->expandAll();
}

void MainWindow::on_pushButton_remove_clicked()
{
    bst.remove(QInputDialog::getInt(nullptr, tr("User Input"), "Enter Element:"));
    model->clear();
    display(model->invisibleRootItem(), bst.getRoot());
    ui->treeView->expandAll();
}

void MainWindow::on_pushButton_find_clicked()
{
    try {
        QMessageBox::information(nullptr, tr("Find"), QString::number(bst.find(QInputDialog::getInt(nullptr, tr("User Input"), "Enter Element:"))));
    } catch (std::invalid_argument* ex)
    {
        QMessageBox::information(nullptr, tr("Find"), ex->what());
    }
}

void MainWindow::on_pushButton_traverse_clicked()
{
    auto vec = bst.traverse();
    QString res;
    for (auto& e : vec)
    {
        res += QString::number(e) + "\n";
    }
    QMessageBox::information(nullptr, tr("Traverse"), res);
}

void MainWindow::on_pushButton_commonNode_clicked()
{
    node1 = bst.findCommonNode(node1, node2);
    node2 = node1;
    model->clear();
    display(model->invisibleRootItem(), bst.getRoot());
    ui->treeView->expandAll();
}

void MainWindow::on_pushButton_addSub_clicked()
{
    bst.addTree(sub);
    model->clear();
    display(model->invisibleRootItem(), bst.getRoot());
    ui->treeView->expandAll();
    subModel->clear();
    display(subModel->invisibleRootItem(), sub.getRoot());
    ui->treeView_2->expandAll();
}

void MainWindow::on_pushButton_addToSub_clicked()
{
    long element = QInputDialog::getInt(nullptr, tr("User Input"), "Enter Element:");
    sub.add(element, element);
    subModel->clear();
    display(subModel->invisibleRootItem(), sub.getRoot());
    ui->treeView_2->expandAll();
}

void MainWindow::on_pushButton_removeFromSub_clicked()
{
    sub.remove(QInputDialog::getInt(nullptr, tr("User Input"), "Enter Element:"));
    subModel->clear();
    display(subModel->invisibleRootItem(), sub.getRoot());
    ui->treeView_2->expandAll();
}

void MainWindow::on_pushButton_removeSub_clicked()
{
    bst.removeTree(sub);
    model->clear();
    display(model->invisibleRootItem(), bst.getRoot());
    ui->treeView->expandAll();
    subModel->clear();
    display(subModel->invisibleRootItem(), sub.getRoot());
    ui->treeView_2->expandAll();
}

void MainWindow::on_pushButton_left1_clicked()
{
    if (node1->left)
    {
        node1 = node1->left;
    }
    model->clear();
    display(model->invisibleRootItem(), bst.getRoot());
    ui->treeView->expandAll();
}

void MainWindow::on_pushButton_right1_clicked()
{
    if (node1->right)
    {
        node1 = node1->right;
    }
    model->clear();
    display(model->invisibleRootItem(), bst.getRoot());
    ui->treeView->expandAll();
}

void MainWindow::on_pushButton_root1_clicked()
{
    node1 = bst.getRoot();
    model->clear();
    display(model->invisibleRootItem(), bst.getRoot());
    ui->treeView->expandAll();
}

void MainWindow::on_pushButton_left2_clicked()
{
    if (node2->left)
    {
        node2 = node2->left;
    }
    model->clear();
    display(model->invisibleRootItem(), bst.getRoot());
    ui->treeView->expandAll();
}

void MainWindow::on_pushButton_right2_clicked()
{
    if (node2->right)
    {
        node2 = node2->right;
    }
    model->clear();
    display(model->invisibleRootItem(), bst.getRoot());
    ui->treeView->expandAll();
}

void MainWindow::on_pushButton_root2_clicked()
{
    node2 = bst.getRoot();
    model->clear();
    display(model->invisibleRootItem(), bst.getRoot());
    ui->treeView->expandAll();
}

