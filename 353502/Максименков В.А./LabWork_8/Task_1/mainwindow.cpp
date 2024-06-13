#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeView->setModel(model);
    ui->treeView->header()->hide();
    ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::add);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::remove);
    connect(ui->findButton, &QPushButton::clicked, this, &MainWindow::find);
    connect(ui->traverseButton, &QPushButton::clicked, this, &MainWindow::traverse);
    connect(ui->insertSubtreeButton, &QPushButton::clicked, this, &MainWindow::insertSubBST);
    connect(ui->removeSubtreeButton, &QPushButton::clicked, this, &MainWindow::removeSubBST);
    connect(ui->commonParentButton, &QPushButton::clicked, this, &MainWindow::findCommonParent);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showBST(QStandardItem *parentItem, BST<int>::Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    QStandardItem* child = new QStandardItem(QString::number(node->value) + ": " + QString::number(node->height));
    parentItem->appendRow(child);

    showBST(child, node->left);
    showBST(child, node->right);
}

void MainWindow::displayBST()
{
    model->clear();
    showBST(model->invisibleRootItem(), bst.getRoot());
    ui->treeView->expandAll();
}

void MainWindow::add()
{
    int value = ui->spinBox->value();
    bst.add(value);
    displayBST();
}

void MainWindow::remove()
{
    int value = ui->spinBox->value();
    bst.remove(value);
    displayBST();
}

void MainWindow::find()
{
    int value = ui->spinBox->value();
    BST<int>::Node *ans = bst.find(value);

    if (ans == nullptr)
    {
        ui->answerBrowser->setText("No such node!");
    }
    else
    {
        ui->answerBrowser->setText(QString::number(ans->value));
    }
}

void MainWindow::traverse()
{
    QVector<BST<int>::Node*> vec = bst.traverse();
    QString ans = "";

    for (int i = 0; i < vec.size(); ++i)
    {
        ans += QString::number(vec[i]->value) + " ";
    }

    ui->answerBrowser->setText(ans);
}

void MainWindow::insertSubBST()
{
    BST<int>* subTree = new BST<int>();
    subTree->add(4);
    subTree->add(7);
    subTree->add(2);
    subTree->add(9);
    subTree->add(8);
    subTree->add(1);
    subTree->add(3);

    bst.insertSubtree(subTree);
    displayBST();
}

void MainWindow::removeSubBST()
{
    int value = ui->spinBox->value();
    bst.deleteSubtree(value);
    displayBST();
}

void MainWindow::findCommonParent()
{
    int value1 = ui->value1SpinBox->value();
    int value2 = ui->value2SpinBox->value();
    BST<int>::Node* node = bst.findTheClosestCommonParent(value1, value2);

    if (node == nullptr)
    {
        ui->answerBrowser->setText("One of these values not exists");
    }
    else
    {
        ui->answerBrowser->setText(QString::number(node->value));
    }
}
