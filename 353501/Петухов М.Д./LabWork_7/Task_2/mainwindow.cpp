#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);

    model = new QStandardItemModel();
    ui->treeView->setModel(model);
    // BinarySearchTree<int> tree;

    tree.root = nullptr;
    tree.root = tree.insert(tree.root, 50, "aboba");
    tree.insert(tree.root, 30, "fdfv");
    tree.insert(tree.root, 20, "bebra");
    tree.insert(tree.root, 40, "bebra2");
    tree.insert(tree.root, 70, "bebra3");
    tree.insert(tree.root, 60, "bebra4");
    tree.insert(tree.root, 80, "bebra5");
    tree.insert(tree.root, 90, "bebra5");
    tree.insert(tree.root, 100, "bebra5");
    tree.insert(tree.root, 110, "bebra5");

    displayTree(model->invisibleRootItem(), tree.getRoot());    
    tree.drawTree();
}

void MainWindow::displayTree(QStandardItem* parentItem, BinarySearchTree<QString>::Node* node) {
    if (node == nullptr)
        return;

    QStandardItem * child = new QStandardItem(QString::number(node->key) + ": " + node->value);
    parentItem->appendRow(child);

    displayTree(child, node->left);
    displayTree(child, node->right);
}

void MainWindow::on_displayTreeButton_clicked(){
    model->clear();
    displayTree(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
    tree.drawTree();
}

void MainWindow::on_countRightNodes_clicked(){
    int counterNodes = tree.countRightBranch(tree.getRoot());
    ui->textEdit->setText(QString::number(counterNodes));
}

void MainWindow::on_find_clicked(){
    BinarySearchTree<QString>::Node* foundedNode = tree.search(tree.getRoot(), ui->spinBox->value());
    if(foundedNode != nullptr){
        ui->textEdit->setText(tree.search(tree.getRoot(), ui->spinBox->value())->value);
    }
    else{
        ui->textEdit->setText("not found");
    }

}

void MainWindow::on_insert_clicked(){
    tree.root = tree.insert(tree.getRoot(), ui->spinBox_2->value(), ui->lineEdit->text());
    on_displayTreeButton_clicked();
}

void MainWindow::on_del_clicked()
{
    //удаление корня не работает, поменять сам метод
    tree.root = tree.deleteNode(tree.getRoot(), ui->spinBox_3->value());
    on_displayTreeButton_clicked();
}

void MainWindow::on_pushButton_PostOrder_clicked()
{
    tree.printPostOrder(tree.getRoot(), strToTraversals);
    ui->textEdit->setText(strToTraversals);
    strToTraversals.clear();
}

void MainWindow::on_pushButton_InOrder_clicked()
{
    tree.printInorderTree(tree.getRoot(), strToTraversals);
    ui->textEdit->setText(strToTraversals);
    strToTraversals.clear();
}

void MainWindow::on_pushButton_PreOrder_clicked()
{
    tree.printPreOrder(tree.getRoot(), strToTraversals);
    ui->textEdit->setText(strToTraversals);
    strToTraversals.clear();
}

void MainWindow::on_destroy_clicked(){
    if(tree.getRoot() != nullptr){
        tree.destroyTree(tree.getRoot());
    }
    tree.root = nullptr;
    on_displayTreeButton_clicked();
}