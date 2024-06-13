#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(new QStandardItemModel(this))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QStandardItem* MainWindow::createItemForNode(std::shared_ptr<Node> root, const QString &position)
{
    if (!root) {
        return nullptr;
    }

    QString label;
    if (position.isEmpty()) {
        label = QString::number(root->key) + ":" + QString::fromStdString(root->value) + " (root)";
    } else {
        label = QString::number(root->key) + ":" + QString::fromStdString(root->value) + " (" + position + ")";
    }

    QStandardItem* item = new QStandardItem(label);

    if (root->left) {
        QStandardItem* leftChild = createItemForNode(root->left, "left");
        item->appendRow(leftChild);
    }

    if (root->right) {
        QStandardItem* rightChild = createItemForNode(root->right, "right");
        item->appendRow(rightChild);
    }

    return item;
}

void MainWindow::preorderTraversal(std::shared_ptr<Node> node)
{
    if (!node) {
        return;
    }
    ui->textEdit->append(QString("Key: %1, Value: %2").arg(node->key).arg(QString::fromStdString(node->value)));
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void MainWindow::postorderTraversal(std::shared_ptr<Node> node)
{
    if (!node) {
        return;
    }
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    ui->textEdit->append(QString("Key: %1, Value: %2").arg(node->key).arg(QString::fromStdString(node->value)));
}

void MainWindow::inorderTraversal(std::shared_ptr<Node> node)
{
    if (!node) {
        return;
    }
    inorderTraversal(node->left);
    ui->textEdit->append(QString("Key: %1, Value: %2").arg(node->key).arg(QString::fromStdString(node->value)));
    inorderTraversal(node->right);
}

void MainWindow::on_addBtn_clicked()
{
    int key = ui->key->value();
    QString value = ui->value->text();

    root_ = bst.insert(root_, key, value.toStdString());

    QStandardItem* newItem = createItemForNode(root_, QString());
    model->clear();
    model->appendRow(newItem);
    ui->treeView->setModel(model);
}

void MainWindow::on_deleteBtn_clicked()
{
    int key = ui->key->value();
    root_ = bst.remove(root_, key);

    QStandardItem* newRoot = createItemForNode(root_, QString());
    model->clear();
    model->appendRow(newRoot);
    ui->treeView->setModel(model);
}

void MainWindow::on_findBtn_clicked()
{
    int key = ui->key->value();
    std::shared_ptr<Node> foundNode = bst.find(root_, key);

    if (foundNode) {
        ui->valueEdit->setText(QString::fromStdString(foundNode->value));
    } else {
        ui->valueEdit->setText("Node not found");
    }
}

void MainWindow::on_minBtn_clicked()
{
    std::shared_ptr<Node> minNode = bst.getMin(root_);
    if (minNode) {
        ui->valueEdit->setText(QString::fromStdString(minNode->value));
    } else {
        ui->valueEdit->setText("Tree is empty");
    }
}

void MainWindow::on_maxBtn_clicked()
{
    std::shared_ptr<Node> maxNode = bst.getMax(root_);
    if (maxNode) {
        ui->valueEdit->setText(QString::fromStdString(maxNode->value));
    } else {
        ui->valueEdit->setText("Tree is empty");
    }
}

void MainWindow::on_inorderBtn_clicked()
{
    ui->textEdit->clear();
    inorderTraversal(root_);
}

void MainWindow::on_preorderBtn_clicked()
{
    ui->textEdit->clear();
    preorderTraversal(root_);
}

void MainWindow::on_postorderBtn_clicked()
{
    ui->textEdit->clear();
    postorderTraversal(root_);

}

void MainWindow::on_insertSubtreeBtn_clicked()
{
    int position = ui->position->value();
    std::shared_ptr<Node> subtree = Node::newNode(ui->key->value(), ui->value->text().toStdString());
    root_ = bst.insertSubtree(root_, subtree, position);
    updateTreeView();
}

void MainWindow::on_insertBranchBtn_clicked()
{
    int position = ui->position->value();
    std::shared_ptr<Node> branch = Node::newNode(ui->key->value(), ui->value->text().toStdString());
    root_ = bst.insertBranch(root_, branch, position);
    updateTreeView();
}

void MainWindow::on_removeSubtreeBtn_clicked()
{
    int position = ui->position->value();
    root_ = bst.removeSubtree(root_, position);
    updateTreeView();
}

void MainWindow::on_removeBranchBtn_clicked()
{
    int position = ui->position->value();
    root_ = bst.removeBranch(root_, position);
    updateTreeView();
}

void MainWindow::updateTreeView()
{
    QStandardItem* newRoot = createItemForNode(root_, QString());
    model->clear();
    model->appendRow(newRoot);
    ui->treeView->setModel(model);
}
