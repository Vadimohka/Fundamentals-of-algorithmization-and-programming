#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QRegularExpression rx("^([1-9]|[1-9][0-9])$");
    ui->lineEdit->setValidator(new QRegularExpressionValidator(rx));
    ui->v1->setValidator(new QRegularExpressionValidator(rx));
    ui->v2->setValidator(new QRegularExpressionValidator(rx));

    tree.add(50);
    for (int i = 0; i < 5; ++i)
    {
        tree.add(QRandomGenerator::global()->bounded(100));
    }
    toQTreeWidget(ui->treeWidget, tree.root);
    ui->treeWidget->expandAll();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::toQTreeWidget(QTreeWidget *treeWidget, Node *node, QTreeWidgetItem *parentItem)
{
    if (node == nullptr)
    {
        return;
    }

    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0, QString::number(node->key));

    if (parentItem == nullptr)
    {
        treeWidget->addTopLevelItem(item);
    }
    else
    {
        parentItem->addChild(item);
    }

    toQTreeWidget(treeWidget, node->left, item);
    toQTreeWidget(treeWidget, node->right, item);
}

void MainWindow::on_add_clicked()
{
    ui->treeWidget->clear();
    tree.add(QRandomGenerator::global()->bounded(1, 100));
    toQTreeWidget(ui->treeWidget, tree.root);
    ui->treeWidget->expandAll();
}


void MainWindow::on_pushButton_2_clicked()
{
    int num = ui->lineEdit->text().toInt();
    tree.remove(num);
    ui->treeWidget->clear();
    toQTreeWidget(ui->treeWidget, tree.root);
    ui->treeWidget->expandAll();
}


void MainWindow::on_removetree_clicked()
{
    int num = ui->lineEdit->text().toInt();
    tree.removeSubTree(num);
    ui->treeWidget->clear();
    toQTreeWidget(ui->treeWidget, tree.root);
    ui->treeWidget->expandAll();
}


void MainWindow::on_find_clicked()
{
    if(ui->v1->text().isEmpty() || ui->v2->text().isEmpty())
    {
        ui->minnode->setText("Неверный ввод");
        return;
    }
    int v1 = ui->v1->text().toInt();
    int v2 = ui->v2->text().toInt();
    Node *node = tree.lca(v1, v2);
    ui->minnode->setText(QString::number(node->key));
}
