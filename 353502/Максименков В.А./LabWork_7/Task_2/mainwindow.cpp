#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel(this);
    ui->treeView->setModel(model);
    ui->treeView->header()->hide();
    ui->delButton->hide();
    ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::add);
    connect(ui->delButton, &QPushButton::clicked, this, &MainWindow::del);
    connect(ui->findButton, &QPushButton::clicked, this, &MainWindow::find);
    connect(ui->balanseButton, &QPushButton::clicked, this, &MainWindow::balanse);
    connect(ui->InOrderButton, &QPushButton::clicked, this, &MainWindow::InOrder);
    connect(ui->PreOrderButton, &QPushButton::clicked, this, &MainWindow::PreOrder);
    connect(ui->PostOrderButton, &QPushButton::clicked, this, &MainWindow::PostOrder);
    connect(ui->subtreeButton, &QPushButton::clicked, this, &MainWindow::subtree);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::displayTree(QStandardItem* parentItem, TreeNode* node) {
    if (node == nullptr)
    {
        return;
    }

    QStandardItem* child = new QStandardItem(QString::number(node->key) + ": " + node->str);
    parentItem->appendRow(child);

    displayTree(child, node->left);
    displayTree(child, node->right);
}


void MainWindow::add()
{
    tree.insert(qMakePair(ui->spinBox->value(), ui->lineEdit->text()));
    model->clear();
    displayTree(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
}


void MainWindow::del()
{
    tree.remove(ui->spinBox->value());
    model->clear();
    displayTree(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
}

void MainWindow::find()
{
    ui->textEdit_ans->setText(tree.searchStringByKey(ui->spinBox->value()));
}


void MainWindow::InOrder()
{
    auto vec = tree.inOrderToVec();
    QString ans;
    for (auto & i : vec)
    {
        ans += QString::number(i.first) + " - " + i.second + "\n";
    }
    ui->textEdit_ans->setText(ans);
}


void MainWindow::PreOrder()
{
    auto vec = tree.preOrderToVec();
    QString ans;
    for (auto & i : vec)
    {
        ans += QString::number(i.first) + " - " + i.second + "\n";
    }
    ui->textEdit_ans->setText(ans);
}


void MainWindow::PostOrder()
{
    auto vec = tree.postOrderToVec();
    QString ans;
    for (auto & i : vec) {
        ans += QString::number(i.first) + " - " + i.second + "\n";
    }
    ui->textEdit_ans->setText(ans);
}


void MainWindow::balanse()
{
    tree.balanceTree();
    model->clear();
    displayTree(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
}


void MainWindow::subtree()
{
    int key = ui->spinBox->value();
    tree.deleteSubtreePerKey(key);

    model->clear();

    displayTree(model->invisibleRootItem(), tree.getRoot());
    qDebug() << "here";
    ui->treeView->expandAll();
}

