#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <random>
#include <QDebug>
MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->treeWidget->setHeaderLabel("tree");
    tree.visualizer(ui->treeWidget);
    ui->preOrderEdit->setReadOnly(true);
    ui->postOrderEdit->setReadOnly(true);
    ui->inOrderEdit->setReadOnly(true);
    ui->subTreeRight->setChecked(true);
    ui->frame->hide();
}
void MainWindow::on_addSubTreeBut_clicked(){
    //secTree = BSTui();
    ui->frame->show();
    ui->secondtreeWidget->setHeaderLabel("second tree");
    secTree.visualizer(ui->secondtreeWidget);
}
void MainWindow::on_confirmBut_clicked(){
    insertTreeIntoTree(secTree.root,tree);
    tree.visualizer(ui->treeWidget);
    secTree.clearFullTree();
    ui->frame->hide();
}
void MainWindow::insertTreeIntoTree(Node<int, QString>* srcRoot, BSTui& destTree) {
    if (srcRoot == nullptr) {
        return;
    }
    destTree.insert(srcRoot->key, srcRoot->value);
    insertTreeIntoTree(srcRoot->left, destTree);
    insertTreeIntoTree(srcRoot->right, destTree);
}
void MainWindow::on_insertBut_2_clicked(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> keyDist(0, 100);
    int key = keyDist(gen);
    QString value = BSTui::generateRandomString(5);
    secTree.insert(key, value);
    secTree.visualizer(ui->secondtreeWidget);
}
void MainWindow::on_removeBut_2_clicked(){
    int num = ui->removespin_2->value();
    secTree.remove(num);
    secTree.visualizer(ui->secondtreeWidget);
}
void MainWindow::on_subTreeLeft_toggled(bool checked) {
    if (checked) {
        ui->subTreeRight->setChecked(false);
    }
}
void MainWindow::on_balanceBut_clicked(){
    tree.balanceTree();
    tree.visualizer(ui->treeWidget);
}
void MainWindow::on_clearBut_clicked(){
    tree.clearFullTree();
    tree.visualizer(ui->treeWidget);
}
void MainWindow::on_subTreeRight_toggled(bool checked) {
    if (checked) {
        ui->subTreeLeft->setChecked(false);
    }
}
void MainWindow::on_insertBut_clicked(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> keyDist(0, 100);
    int key = keyDist(gen);
    QString value = BSTui::generateRandomString(5);
    tree.insert(key, value);
    tree.visualizer(ui->treeWidget);
}
void MainWindow::on_removeBut_clicked() {
    int num = ui->removespin->value();
    tree.remove(num);
    tree.visualizer(ui->treeWidget);
}

void MainWindow::on_findBut_clicked() {
    int num = ui->findSpin->value();
    Node<int,QString>* tmp = tree.find(num);
    if(!tmp){
        ui->findLabel->setText("No such element");
        return;
    }
    QString output = QString::number(tmp->key) + " " + tmp->value;
    ui->findLabel->setText(output);
}
void MainWindow::on_printPreOrderBut_clicked() {
    QString preOrder;
    tree.printPreOrder(preOrder);
    ui->preOrderEdit->setText(preOrder);
}
void MainWindow::on_printPostOrderBut_clicked(){
    QString postOrder;
    tree.printPostOrder(postOrder);
    ui->postOrderEdit->setText(postOrder);
}
void MainWindow::on_printInOrderBut_clicked(){
    QString inOrder;
    tree.printInorderTree(inOrder);
    ui->inOrderEdit->setText(inOrder);
}
void MainWindow::on_removeSubTreeBut_clicked() {
    int num = ui->removeSubTreeSpin->value();
    Node<int, QString>* tmp = tree.find(num);
    if (tmp == nullptr) {
        return;
    }
    QString direction;
    if (ui->subTreeLeft->isChecked() && !ui->subTreeRight->isChecked()) {
        direction = "l";
    } else if (!ui->subTreeLeft->isChecked() && ui->subTreeRight->isChecked()) {
        direction = "r";
    } else {
        return;
    }
    tree.removeSubTree(tmp, direction);
    tree.visualizer(ui->treeWidget);
}
