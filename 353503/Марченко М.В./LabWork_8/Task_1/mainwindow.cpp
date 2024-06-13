#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->setHeaderLabels({"Key", "String"});
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::addNode);
    connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::searchNode);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::removeNode);
    connect(ui->preorderButton, &QPushButton::clicked, this, &MainWindow::printPreorder1);
    connect(ui->inorderButton, &QPushButton::clicked, this, &MainWindow::printInorder1);
    connect(ui->postorderButton, &QPushButton::clicked, this, &MainWindow::printPostorder1);
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::clearTree);
    connect(ui->balanceButton, &QPushButton::clicked, this, &MainWindow::balanceTree);
    connect(ui->taskButton, &QPushButton::clicked, this, &MainWindow::task);
    connect(ui->addNewButton, &QPushButton::clicked, this, &MainWindow::addNewNode);
    connect(ui->addTreeButton, &QPushButton::clicked, this, &MainWindow::addTree);
    connect(ui->removeTreeButton, &QPushButton::clicked, this, &MainWindow::removeTree);
    connect(ui->ancButton, &QPushButton::clicked, this, &MainWindow::findAnc);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addNode()
{
    int key = ui->keyLineEdit->text().toInt();
    QString string = ui->stringLineEdit->text();
    Data data ;
    data.key = key;
    data.string = string;
    m_root = m_bst.add(m_root, data);
    updateTreeWidget();
    ui->keyLineEdit->clear();
    ui->stringLineEdit->clear();

}

void MainWindow::addNewNode()
{
    int key = ui->keyLineEdit3->text().toInt();
    QString string = ui->stringLineEdit3->text();
    Data data;
    data.key = key;
    data.string = string;

    new_root = new_bst.add(new_root, data);
    updateTreeWidget1();

    ui->keyLineEdit3->clear();
    ui->stringLineEdit3->clear();
}

void MainWindow::addTree()
{

    m_bst.insertSubtree(m_root, new_root);
    updateTreeWidget();
    ui->treeWidget1->clear();

    new_bst.clear(new_root);
    new_root = nullptr;

}



void MainWindow::searchNode()
{
    int key = ui->keyLineEdit1->text().toInt();
    Node* found = m_bst.search(m_root, key);
    if (found) {
        ui->resultTextEdit->setText(QString("Ключ = %1, Строка = %2").arg(found->data.key).arg(found->data.string));
    } else {
        ui->resultTextEdit->setText("Ключ не найден");
    }
}

void MainWindow::removeNode()
{
    int key = ui->keyLineEdit1->text().toInt();
    m_root = m_bst.remove(m_root, key);
    updateTreeWidget();
}

void MainWindow::printPreorder1()
{
    ui->resultTextEdit->clear();
    m_bst.printPreorder(m_root, *ui->resultTextEdit);
}

void MainWindow::printInorder1()
{
    ui->resultTextEdit->clear();
    m_bst.printInorder(m_root, *ui->resultTextEdit);
}

void MainWindow::printPostorder1()
{
    ui->resultTextEdit->clear();
    m_bst.printPostorder(m_root, *ui->resultTextEdit);
}

void MainWindow::updateTreeWidget(){
    ui->treeWidget->clear();
    updateTreeWidgetRecursive(m_root);
}

void MainWindow::updateTreeWidget1(){
    ui->treeWidget1->clear();
    updateTreeWidgetRecursive1(new_root);
}

void MainWindow::updateTreeWidgetRecursive(Node* node, QTreeWidgetItem* parentItem){
    if (node == nullptr) {
        return;
    }

    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0, QString::number(node->data.key));
    item->setText(1, node->data.string);

    if (parentItem == nullptr) {
        ui->treeWidget->addTopLevelItem(item);
    } else {
        parentItem->addChild(item);
    }

    updateTreeWidgetRecursive(node->left, item);
    updateTreeWidgetRecursive(node->right, item);
}

void MainWindow::updateTreeWidgetRecursive1(Node* node, QTreeWidgetItem* parentItem){
    if (node == nullptr) {
        return;
    }

    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0, QString::number(node->data.key));
    item->setText(1, node->data.string);

    if (parentItem == nullptr) {
        ui->treeWidget1->addTopLevelItem(item);
    } else {
        parentItem->addChild(item);
    }

    updateTreeWidgetRecursive(node->left, item);
    updateTreeWidgetRecursive(node->right, item);
}

void MainWindow::clearTree()
{
    m_bst.clear(m_root);
    ui->treeWidget->clear();
    m_root = nullptr;

}

void MainWindow::balanceTree()
{
    m_root = m_bst.balance(m_root);
    updateTreeWidget();
}

void MainWindow::removeTree()
{
    m_bst.removeSubtree(m_root, new_root);
    updateTreeWidget();
    ui->treeWidget1->clear();

    new_bst.clear(new_root);
    new_root = nullptr;
}

void MainWindow::task()
{

    int key = ui->keyLineEdit2->text().toInt();
    m_root = m_bst.removeBrunch(m_root, key);
    updateTreeWidget();

}

void MainWindow::findAnc()
{
    int key1 = ui->keyLineEdit4->text().toInt();
    int key2 = ui->keyLineEdit5->text().toInt();
    Node* result = m_bst.findAncestor(m_root, key1, key2);
    if (result) {
       ui->resultTextEdit1->setText(QString::number(result->data.key));
    } else {
        ui->resultTextEdit1->setText("Такой предок не найден");
    }

}
