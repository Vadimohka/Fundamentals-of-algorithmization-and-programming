#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <ostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    subTree = new Tree<int, QString>;

    tree.add(10, "A");
    tree.add(5, "skibididop");
    tree.add(15, "C");
    tree.add(12, "F");
    tree.add(17, "G");

    subTree->add(1, "eshkereeee");
    subTree->add(2, "Y");

    tree.insertSubtree(subTree);

    // Вывод дерева после вставки поддерева
    std::cout << "Tree after inserting subtree:" << std::endl;
    tree.symmetricalTraverse();

    // Удаление поддерева
    tree.removeSubtree(subTree);

    tree.insertBranch(subTree, true);
    tree.removeBranch(subTree, true);

    // Вывод дерева после удаления поддерева
    std::cout << "Tree after removing subtree:" << std::endl;
    tree.symmetricalTraverse();

    std::cout << tree.lowestCommonAncestor(tree.root->right->right, tree.root)->key;

    printTree(&tree, ui->treeWidget);
    printTree(subTree, ui->treeWidget_2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

template<typename T, typename U>
void MainWindow::printTree(Tree<T, U> *tree, QTreeWidget* treeWidget)
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
    Node<int, QString>* node = tree.find(ui->spinKey1->value());

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
    Node<int, QString>* node = tree.find(tree.lowestCommonAncestor(ui->spin1->value(), ui->spin2->value()));

    if(node)
    {
        ui->ancestor->setText(QString::number(node->key) + '(' + node->value + ')');
    }
}

