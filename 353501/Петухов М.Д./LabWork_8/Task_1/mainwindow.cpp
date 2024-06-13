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

void MainWindow::on_deleteRightBranch_clicked(){
    if(tree.getRoot() != nullptr){    
        BinarySearchTree<QString>::Node* nodeToDelete = tree.search(tree.getRoot(), ui->spinBox_4->value());
        tree.destroyRightBranch(nodeToDelete);
    }
    on_displayTreeButton_clicked();
}

void MainWindow::on_deleteLeftBranch_clicked(){
    if(tree.getRoot() != nullptr){    
        BinarySearchTree<QString>::Node* nodeToDelete = tree.search(tree.getRoot(), ui->spinBox_5->value());
        tree.destroyLeftBranch(nodeToDelete);
    }
    on_displayTreeButton_clicked();
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
        tree.destroyTree(tree.root);
    }
    tree.root = nullptr;
    on_displayTreeButton_clicked();
}

void MainWindow::on_destroySubTree_clicked(){
    BinarySearchTree<QString>::Node* nodeToDelete = tree.search(tree.getRoot(), ui->spinBox_6->value());
    if(tree.getRoot() != nullptr){
        tree.destroySubTree(nodeToDelete);
    }
    nodeToDelete = nullptr;
    on_displayTreeButton_clicked();
}

void MainWindow::on_findCommonKey_clicked(){
    if(tree.getRoot() != nullptr){
        BinarySearchTree<QString>::Node* node1 = tree.search(tree.getRoot(), ui->spinBox_7->value());
        BinarySearchTree<QString>::Node* node2 = tree.search(tree.getRoot(), ui->spinBox_8->value());
        BinarySearchTree<QString>::Node* foundNode = tree.findCommonKey(tree.root, node1, node2);
        ui->label->setText(QString::number(foundNode->key));
    }
    on_displayTreeButton_clicked();
}