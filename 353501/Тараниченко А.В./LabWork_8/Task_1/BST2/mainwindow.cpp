#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVector<QString> a(20);
    for (int i = 0; i < 20; ++i) {
        a[i] = QChar(i + 'A');
    }

    tree = BST<QString>(a);

    displayTree();

    ui->tableWidget->setRowCount(20);
    ui->tableWidget->setColumnCount(1);
    for (int row = 0; row < 20; ++row) {
        QTableWidgetItem *item0 = new QTableWidgetItem();
        ui->tableWidget->setItem(row, 0, item0);
    }

    for (int i = 0; i < 20; ++i) {
        ui->tableWidget->item(i, 0)->setText(a[i]);
    }

    ui->resLAbel->setReadOnly(true);

    ui->tableWidget->verticalHeader()->setVisible(false);

    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    setCentralWidget(ui->gridLayoutWidget);
    setWindowTitle("Дерево поиска");

    tree.balanceTree();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillTreeWidgetFromBST(QTreeWidgetItem *item, BST<QString>::Data *node)
{
    if (node == nullptr)
        return;

    item->setText(0, node->key);

    if (node->leftSon != nullptr) {
        QTreeWidgetItem* leftSon = new QTreeWidgetItem(item);
        fillTreeWidgetFromBST(leftSon, node->leftSon);
    }

    if (node->rightSon != nullptr) {
        QTreeWidgetItem* rightSon = new QTreeWidgetItem(item);
        fillTreeWidgetFromBST(rightSon, node->rightSon);
    }
}

void MainWindow::displayTree()
{
    ui->treeWidget->clear();

    if (tree.root == nullptr)
        return;

    QTreeWidgetItem *rootItem = new QTreeWidgetItem(ui->treeWidget);

    fillTreeWidgetFromBST(rootItem, tree.root);

    ui->treeWidget->addTopLevelItem(rootItem);
}

void MainWindow::on_insertButton_clicked()
{
    tree.insert(ui->infoLineEdit->text());
    displayTree();
}


void MainWindow::on_findButton_clicked()
{
    QString res = tree.find(ui->infoLineEdit->text());
    ui->resLAbel->setPlainText(res == "" ? "Нет такого ключа!" : res);
}

void MainWindow::on_balanceButton_clicked()
{
    tree.balanceTree();
    displayTree();
}


void MainWindow::on_removeButton_clicked()
{
    tree.remove(ui->infoLineEdit->text());
    displayTree();
}

void MainWindow::on_preorderButton_clicked()
{
    auto res = tree.preOrderTraversal();
    QString text = "";
    for (auto el : res) {
        text += el + "\n";
    }
    ui->resLAbel->setPlainText(text);
}


void MainWindow::on_inorderButton_clicked()
{
    auto res = tree.inOrderTraversal();
    QString text = "";
    for (auto el : res) {
        text += el + "\n";
    }
    ui->resLAbel->setPlainText(text);
}


void MainWindow::on_postorderButton_clicked()
{
    auto res = tree.postOrderTraversal();
    QString text = "";
    for (auto el : res) {
        text += el + "\n";
    }
    ui->resLAbel->setPlainText(text);
}



void MainWindow::on_addStringButton_clicked()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
}


void MainWindow::on_removeStringButton_clicked()
{
    ui->tableWidget->setRowCount(std::max(ui->tableWidget->rowCount() - 1, 0));
}


void MainWindow::on_inputButton_clicked()
{
    QVector<QString> a(ui->tableWidget->rowCount());

    for (int i = 0; i < a.size(); ++i) {
        a[i] = ui->tableWidget->item(i, 0)->text();
    }

    tree = BST<QString>(a);

    displayTree();
}

void MainWindow::on_insertSubtreeButton_clicked()
{
    QVector<QString> a(ui->tableWidget->rowCount());

    for (int i = 0; i < a.size(); ++i) {
        a[i] = ui->tableWidget->item(i, 0)->text();
    }

    tree.insertSubtree(BST<QString>(a).root, ui->infoLineEdit->text());
    displayTree();
}


void MainWindow::on_removeSubtreeButton_clicked()
{
    tree.removeSubtree(ui->infoLineEdit->text());
    displayTree();
}


void MainWindow::on_insertElmentButton_clicked()
{
    tree.insertAtPosition(ui->infoLineEdit->text(), tree.findNode(ui->lineEdit->text(), tree.root));
    displayTree();
}

void MainWindow::on_LCAButton_clicked()
{
    ui->resLAbel->setPlainText(tree.findLCA(ui->infoLineEdit->text(), ui->lineEdit->text())->key);
}

