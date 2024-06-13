#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    subTree = new BinarySearchTree;

    tree.add(50, "50");
    tree.add(35, "35");
    tree.add(65, "65");
    tree.add(23, "23");
    tree.add(2, "2");
    tree.add(1, "1");
    tree.add(7, "7");
    tree.add(78, "78");
    tree.add(56, "56");

    subTree->add(1, "One");
    subTree->add(2, "Two");
    subTree->add(3, "Three");
    tree.insertSubtree(subTree);

    qDebug() << "Tree after inserting subtree:" << '\n';
    tree.symmetricalTraverse();

    tree.removeSubtree(subTree);

    tree.insertBranch(subTree, true);
    tree.removeBranch(subTree, true);

    qDebug() << "Tree after removing subtree:" << '\n';
    tree.symmetricalTraverse();

    printTree(&tree, ui->treeWidget);
    printTree(subTree, ui->treeWidget_2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printTree(BinarySearchTree *tree, QTreeWidget* treeWidget)
{
    treeWidget->clear();

    QTreeWidgetItem *beginItem = new QTreeWidgetItem(treeWidget);
    beginItem->setText(0, " ");
    tree->fillTreeWidget(beginItem, tree->root);

    treeWidget->expandAll();
}

void MainWindow::on_addButton1_clicked()
{
    tree.add(ui->spinKey1->value(), ui->lineValue1->text());
    printTree(&tree, ui->treeWidget);
}

void MainWindow::on_removeButton1_clicked()
{
    tree.remove(ui->spinKey1->value());
    printTree(&tree, ui->treeWidget);
}

void MainWindow::on_findButton1_clicked()
{
    ui->treeWidget->clearSelection();
    Node* node = tree.find(ui->spinKey1->value());

    if(node)
    {
        QList<QTreeWidgetItem*> items = ui->treeWidget->findItems(QString::number(node->key) + '(' + node->value + ')', Qt::MatchExactly | Qt::MatchRecursive);
        items[0]->setSelected(true);
    }
}

void MainWindow::on_addButton2_clicked()
{
    subTree->add(ui->spinKey2->value(), ui->lineValue2->text());
    printTree(subTree, ui->treeWidget_2);
}

void MainWindow::on_removeButton2_clicked()
{
    subTree->remove(ui->spinKey2->value());
    printTree(subTree, ui->treeWidget_2);
}

void MainWindow::on_insertSubtreeButton_clicked()
{
    tree.insertSubtree(subTree);

    printTree(&tree, ui->treeWidget);
}

void MainWindow::on_removeSubtreeButton_clicked()
{
    tree.removeSubtree(subTree);

    printTree(&tree, ui->treeWidget);
}

void MainWindow::on_insertLBranchButton_clicked()
{
    tree.insertBranch(subTree, true);

    printTree(&tree, ui->treeWidget);
}

void MainWindow::on_insertRBranchButton_clicked()
{
    tree.insertBranch(subTree, false);

    printTree(&tree, ui->treeWidget);
}

void MainWindow::on_removeLBranchButton_clicked()
{
    tree.removeBranch(subTree, true);

    printTree(&tree, ui->treeWidget);
}

void MainWindow::on_removeRBranchButton_clicked()
{
    tree.removeBranch(subTree, false);

    printTree(&tree, ui->treeWidget);
}

void MainWindow::on_lowestCommonAncestorButton_clicked()
{
    ui->treeWidget->clearSelection();
    Node *node = tree.find(
        tree.lowestCommonAncestor(ui->spin1->value(), ui->spin2->value()));

    if (node)
    {
        QList<QTreeWidgetItem *> items = ui->treeWidget->findItems(QString::number(node->key) + '('
                                                                       + node->value + ')',
                                                                   Qt::MatchExactly
                                                                       | Qt::MatchRecursive);
        items[0]->setSelected(true);
    }
}