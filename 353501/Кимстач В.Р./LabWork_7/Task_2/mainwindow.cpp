#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QStandardItemModel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    QStandardItemModel* model=new QStandardItemModel(this);
    ui->setupUi(this);
   ui->treeView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buildTreeButton_clicked()
{
    bool ok;
    int size = QInputDialog::getInt(this, "Build Tree", "Enter the size of the array:", 10, 1, 1000, 1, &ok);
    if (ok) {
        data.clear();
        keys.clear();
        for (int i = 0; i < size; ++i) {
            QString info = QInputDialog::getText(this, "Build Tree", "Enter the information:");
            int key = QInputDialog::getInt(this, "Build Tree", "Enter the key:");
            data.append(info);
            keys.append(key);
        }
        tree.buildTreeFromArray(data, keys);
        updateTreeView(data);
    }
}

void MainWindow::on_balanceTreeButton_clicked()
{
    tree.balanceTree();
    QStringList treeData;
    tree.printInOrder(treeData);
    updateTreeView(treeData);
}

void MainWindow::on_addNodeButton_clicked()
{
    QString info = QInputDialog::getText(this, "Add Node", "Enter the information:");
    int key = QInputDialog::getInt(this, "Add Node", "Enter the key:");
    tree.addNode(info, key);
    QStringList treeData;
    tree.printInOrder(treeData);
    updateTreeView(treeData);
}

void MainWindow::on_findNodeButton_clicked()
{
    int key = QInputDialog::getInt(this, "Find Node", "Enter the key:");
    Node* node = tree.findNode(key);
    if (node) {
        ui->textEdit->setText(node->info + " (" + QString::number(node->key) + ")");
    } else {
        ui->textEdit->setText("Node not found.");
    }
}

void MainWindow::on_removeNodeButton_clicked()
{
    int key = QInputDialog::getInt(this, "Remove Node", "Enter the key:");
    tree.removeNode(key);
    QStringList treeData;
    tree.printInOrder(treeData);
    updateTreeView(treeData);
}

void MainWindow::on_printOrderButton_clicked()
{
    QStringList inOrderData, preOrderData, postOrderData;
    tree.printInOrder(inOrderData);
    tree.printPreOrder(preOrderData);
    tree.printPostOrder(postOrderData);
    ui->textEdit->clear();
    ui->textEdit->append("In-Order Traversal:");
    ui->textEdit->append(inOrderData.join("\n"));
    ui->textEdit->append("\nPre-Order Traversal:");
    ui->textEdit->append(preOrderData.join("\n"));
    ui->textEdit->append("\nPost-Order Traversal:");
    ui->textEdit->append(postOrderData.join("\n"));
}

void MainWindow::on_swapMaxMinButton_clicked()
{
    tree.swapMaxMinKeys();
    QStringList treeData;
    tree.printInOrder(treeData);
    updateTreeView(treeData);
}

void MainWindow::updateTreeView(const QStringList& treeData)
{
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->treeView->model());
    QStandardItem* rootItem = model->invisibleRootItem();
    rootItem->removeRows(0, rootItem->rowCount());

    for (const QString& data : treeData) {
        QStandardItem* item = new QStandardItem(data);
        rootItem->appendRow(item);
    }
}
