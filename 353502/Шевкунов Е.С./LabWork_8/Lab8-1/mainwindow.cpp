#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    output(new QTextEdit(this)),
    inputData(new QLineEdit(this)),
    inputKey(new QLineEdit(this)),
    inputKey2(new QLineEdit(this)),
    inputParentKey(new QLineEdit(this))
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QHBoxLayout *inputLayout = new QHBoxLayout;
    inputLayout->addWidget(new QLabel("Data:", this));
    inputLayout->addWidget(inputData);
    inputLayout->addWidget(new QLabel("Key:", this));
    inputLayout->addWidget(inputKey);
    inputLayout->addWidget(new QLabel("Parent Key:", this));
    inputLayout->addWidget(inputParentKey);
    mainLayout->addLayout(inputLayout);

    QHBoxLayout *buttonLayout = new QHBoxLayout;

    QPushButton *addButton = new QPushButton("Add Node", this);
    connect(addButton, &QPushButton::clicked, this, &MainWindow::addNode);
    buttonLayout->addWidget(addButton);

    QPushButton *removeButton = new QPushButton("Remove Node", this);
    connect(removeButton, &QPushButton::clicked, this, &MainWindow::removeNode);
    buttonLayout->addWidget(removeButton);

    QPushButton *findButton = new QPushButton("Find Node", this);
    connect(findButton, &QPushButton::clicked, this, &MainWindow::findNode);
    buttonLayout->addWidget(findButton);

    QPushButton *traverseButton = new QPushButton("Traverse Tree", this);
    connect(traverseButton, &QPushButton::clicked, this, &MainWindow::traverseTree);
    buttonLayout->addWidget(traverseButton);

    QPushButton *insertSubtreeButton = new QPushButton("Insert Subtree", this);
    connect(insertSubtreeButton, &QPushButton::clicked, this, &MainWindow::insertSubtree);
    buttonLayout->addWidget(insertSubtreeButton);

    QPushButton *removeSubtreeButton = new QPushButton("Remove Subtree", this);
    connect(removeSubtreeButton, &QPushButton::clicked, this, &MainWindow::removeSubtree);
    buttonLayout->addWidget(removeSubtreeButton);

    QPushButton *insertBranchButton = new QPushButton("Insert Branch", this);
    connect(insertBranchButton, &QPushButton::clicked, this, &MainWindow::insertBranch);
    buttonLayout->addWidget(insertBranchButton);

    QPushButton *removeBranchButton = new QPushButton("Remove Branch", this);
    connect(removeBranchButton, &QPushButton::clicked, this, &MainWindow::removeBranch);
    buttonLayout->addWidget(removeBranchButton);

    QPushButton *findLCAButton = new QPushButton("Find LCA", this);
    connect(findLCAButton, &QPushButton::clicked, this, &MainWindow::findLCA);
    buttonLayout->addWidget(findLCAButton);

    mainLayout->addLayout(buttonLayout);

    mainLayout->addWidget(output);

    output->setReadOnly(true);
}

MainWindow::~MainWindow() {}

void MainWindow::updateOutput(const QString &message) {
    output->append(message);
}

void MainWindow::addNode() {
    QString data = inputData->text();
    int key = inputKey->text().toInt();
    tree.add(data, key);
    updateOutput(QString("Added node with key %1 and data '%2'").arg(key).arg(data));
}

void MainWindow::removeNode() {
    int key = inputKey->text().toInt();
    tree.remove(key);
    updateOutput(QString("Removed node with key %1").arg(key));
}

void MainWindow::findNode() {
    int key = inputKey->text().toInt();
    BinaryTree::Node* node = tree.find(key);
    if (node) {
        updateOutput(QString("Found node with key %1 and data '%2'").arg(key).arg(node->data));
    } else {
        updateOutput(QString("Node with key %1 not found").arg(key));
    }
}

void MainWindow::traverseTree() {
    output->clear();
    output->append("Tree elements in order:");
    tree.traverseInOrder([this](BinaryTree::Node* node) {
        output->append(QString("Key: %1, Data: %2").arg(node->key).arg(node->data));
    });
}

void MainWindow::insertSubtree() {
    int parentKey = inputParentKey->text().toInt();
    // Example of creating a subtree
    BinaryTree::Node* subtree = new BinaryTree::Node("Subtree Root", 999);
    subtree->left = new BinaryTree::Node("Subtree Left", 998);
    subtree->right = new BinaryTree::Node("Subtree Right", 997);
    tree.insertSubtree(subtree, parentKey);
    updateOutput(QString("Inserted subtree under parent with key %1").arg(parentKey));
}

void MainWindow::removeSubtree() {
    int key = inputKey->text().toInt();
    tree.removeSubtree(key);
    updateOutput(QString("Removed subtree with root key %1").arg(key));
}

void MainWindow::insertBranch() {
    QString data = inputData->text();
    int key = inputKey->text().toInt();
    int parentKey = inputParentKey->text().toInt();
    tree.insertBranch(data, key, parentKey);
    updateOutput(QString("Inserted branch with key %1 and data '%2' under parent with key %3").arg(key).arg(data).arg(parentKey));
}

void MainWindow::removeBranch() {
    int key = inputKey->text().toInt();
    tree.removeBranch(key);
    updateOutput(QString("Removed branch with key %1").arg(key));
}

void MainWindow::findLCA() {
    int key1 = inputKey->text().toInt();
    int key2 = inputKey2->text().toInt();
    BinaryTree::Node* lca = tree.findLowestCommonAncestor(key1, key2);
    if (lca) {
        updateOutput(QString("LCA of nodes with keys %1 and %2 is node with key %3 and data '%4'")
                         .arg(key1).arg(key2).arg(lca->key).arg(lca->data));
    } else {
        updateOutput(QString("No common ancestor found for nodes with keys %1 and %2").arg(key1).arg(key2));
    }
}
