#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStandardItem>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUi();
}

MainWindow::~MainWindow() {}

void MainWindow::setupUi() {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QHBoxLayout *inputLayout = new QHBoxLayout();
    keyLineEdit = new QLineEdit();
    dataLineEdit = new QLineEdit();
    inputLayout->addWidget(keyLineEdit);
    inputLayout->addWidget(dataLineEdit);

    QPushButton *insertButton = new QPushButton("Insert");
    QPushButton *searchButton = new QPushButton("Search");
    QPushButton *removeButton = new QPushButton("Remove");
    QPushButton *printInOrderButton = new QPushButton("Print In Order");
    QPushButton *printPreOrderButton = new QPushButton("Print Pre Order");
    QPushButton *printPostOrderButton = new QPushButton("Print Post Order");
    QPushButton *countLeftNodesButton = new QPushButton("Count Left Nodes");

    connect(insertButton, &QPushButton::clicked, this, &MainWindow::onInsertButtonClicked);
    connect(searchButton, &QPushButton::clicked, this, &MainWindow::onSearchButtonClicked);
    connect(removeButton, &QPushButton::clicked, this, &MainWindow::onRemoveButtonClicked);
    connect(printInOrderButton, &QPushButton::clicked, this, &MainWindow::onPrintInOrderButtonClicked);
    connect(printPreOrderButton, &QPushButton::clicked, this, &MainWindow::onPrintPreOrderButtonClicked);
    connect(printPostOrderButton, &QPushButton::clicked, this, &MainWindow::onPrintPostOrderButtonClicked);
    connect(countLeftNodesButton, &QPushButton::clicked, this, &MainWindow::onCountLeftNodesButtonClicked);

    inputLayout->addWidget(insertButton);
    inputLayout->addWidget(searchButton);
    inputLayout->addWidget(removeButton);
    inputLayout->addWidget(printInOrderButton);
    inputLayout->addWidget(printPreOrderButton);
    inputLayout->addWidget(printPostOrderButton);
    inputLayout->addWidget(countLeftNodesButton);

    mainLayout->addLayout(inputLayout);

    outputTextEdit = new QTextEdit();
    mainLayout->addWidget(outputTextEdit);

    treeView = new QTreeView();
    treeModel = new QStandardItemModel();
    treeView->setModel(treeModel);
    mainLayout->addWidget(treeView);
}

void MainWindow::onInsertButtonClicked() {
    int key = keyLineEdit->text().toInt();
    QString data = dataLineEdit->text();
    tree.insert(data, key);
    updateTreeView();
}

void MainWindow::onSearchButtonClicked() {
    int key = keyLineEdit->text().toInt();
    BinarySearchTree::Node* result = tree.search(key);
    if (result) {
        outputTextEdit->setText(QString("Found: %1").arg(result->data));
    } else {
        outputTextEdit->setText("Not found");
    }
}

void MainWindow::onRemoveButtonClicked() {
    int key = keyLineEdit->text().toInt();
    tree.remove(key);
    updateTreeView();
}

void MainWindow::onPrintInOrderButtonClicked() {
    QString result;
    QTextStream out(&result);
    tree.printInOrder(out);
    outputTextEdit->setText(result);
}

void MainWindow::onPrintPreOrderButtonClicked() {
    QString result;
    QTextStream out(&result);
    tree.printPreOrder(out);
    outputTextEdit->setText(result);
}

void MainWindow::onPrintPostOrderButtonClicked() {
    QString result;
    QTextStream out(&result);
    tree.printPostOrder(out);
    outputTextEdit->setText(result);
}

void MainWindow::onCountLeftNodesButtonClicked() {
    int count = tree.countLeftSubtreeNodes();
    outputTextEdit->setText(QString("Left subtree node count: %1").arg(count));
}

void MainWindow::updateTreeView() {
    treeModel->clear();

    QStandardItem *rootItem = new QStandardItem("Root");
    treeModel->appendRow(rootItem);

    addNodeToModel(rootItem, tree.root);

    treeView->expandAll();
}

void MainWindow::addNodeToModel(QStandardItem *parentItem, BinarySearchTree::Node *node) {
    if (!node) return;

    QStandardItem *item = new QStandardItem(QString("%1: %2").arg(node->key).arg(node->data));
    parentItem->appendRow(item);

    if (node->left) {
        addNodeToModel(item, node->left);
    }
    if (node->right) {
        addNodeToModel(item, node->right);
    }
}
