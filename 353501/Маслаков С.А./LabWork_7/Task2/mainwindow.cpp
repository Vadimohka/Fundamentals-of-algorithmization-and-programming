#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <random>
MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);
    //ui->treeWidget->setColumnCount(2);
    ui->treeWidget->setHeaderLabel("Tree");
    QString inOreder;
   /*
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> keyDist(0, 100);
    //std::uniform_int_distribution<> valueDist(0, 100);
    for (int i = 0; i < fioList.size(); ++i) {
        int key = keyDist(gen);
        QString value = fioList[i];
        tree.insert(key, value);
    }*/
    //tree.balanceTree();
    //addBSTToTreeWidget(tree.getRoot());
    tree.visualizer(ui->treeWidget);
    ui->preOrderEdit->setReadOnly(true);
    ui->postOrderEdit->setReadOnly(true);
    ui->inOrderEdit->setReadOnly(true);
    connect(ui->insertBut,&QPushButton::clicked,this,&MainWindow::isertButSlot);
    connect(ui->removeBut,&QPushButton::clicked,this,&MainWindow::removeButSlot);
    connect(ui->FindMinBut,&QPushButton::clicked,this,&MainWindow::findMinButSlot);
    connect(ui->FindMaxBut,&QPushButton::clicked,this,&MainWindow::findMaxButSlot);
    connect(ui->BalanceBut,&QPushButton::clicked,this,&MainWindow::balanceButSlot);
    connect(ui->FindBut,&QPushButton::clicked,this,&MainWindow::findButSlot);
    connect(ui->FindAverageBut,&QPushButton::clicked,this,&MainWindow::findAverageButSlot);
    connect(ui->printPreOrderBut,&QPushButton::clicked,this,&MainWindow::printPreOrder);
    connect(ui->printPostOrderBut,&QPushButton::clicked,this,&MainWindow::printPostOrder);
    connect(ui->printInOrderBut,&QPushButton::clicked,this,&MainWindow::printInOrder);
    connect(ui->clearBut,&QPushButton::clicked,this,&MainWindow::clearButSlot);
}
void MainWindow::isertButSlot(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> keyDist(0, 100);
    int key = keyDist(gen);
    QString value = fioList[rand() % 20];
    tree.insert(key, value);
    tree.visualizer(ui->treeWidget);
}
void MainWindow::removeButSlot() {
    int num = ui->removespin->value();
    tree.remove(num);
    tree.visualizer(ui->treeWidget);
}
void MainWindow::findMinButSlot() {
    Node<int,QString>* min = tree.findMin();
    QString output = QString::number(min->key) + " " + min->value;
    ui->findMinLabel->setText(output);
}
void MainWindow::findMaxButSlot(){
    Node<int,QString>* max = tree.findMax();
    QString output = QString::number(max->key) + " " + max->value;
    ui->findMaxLabel->setText(output);
}
void MainWindow::balanceButSlot(){
    tree.balanceTree();
    tree.visualizer(ui->treeWidget);
}
void MainWindow::findButSlot() {
    int num = ui->findSpin->value();
    Node<int,QString>* tmp = tree.find(num);
    if(!tmp){
        ui->findLabel->setText("No such element");
        return;
    }
    QString output = QString::number(tmp->key) + " " + tmp->value;
    ui->findLabel->setText(output);
}
void MainWindow::findAverageButSlot() {
    Node<int,QString>* averageNode = tree.findNearestNode();
    QString output = QString::number(averageNode->key) + " " + averageNode->value;
    ui->findAverage->setText(output);
}
void MainWindow::printPreOrder() {
    QString preOrder;
    tree.printPreOrder(preOrder);
    ui->preOrderEdit->setText(preOrder);
}
void MainWindow::printPostOrder(){
    QString postOrder;
    tree.printPostOrder(postOrder);
    ui->postOrderEdit->setText(postOrder);
}
void MainWindow::printInOrder(){
    QString inOrder;
    tree.printInorderTree(inOrder);
    ui->inOrderEdit->setText(inOrder);
}

void MainWindow::clearButSlot() {
    tree.clearTree();
    tree.visualizer(ui->treeWidget);
}