#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    treeNode = nullptr;

    widget = new Widget(this);
    widget->setGeometry(10, 50, 580, 540);


    label = new QLabel("Value", this);
    label->setGeometry(10, 0, 100, 25);

    keyInput = new QLineEdit(this);
    keyInput->setGeometry(10, 35, 100, 25);

    createButton = new QPushButton(this);
    createButton->setGeometry(10, 70, 100, 25);
    createButton->setText("Create tree");

    addButton = new QPushButton(this);
    addButton->setGeometry(10, 105, 100, 25);
    addButton->setText("Add value");

    addNodeButton = new QPushButton(this);
    addNodeButton->setGeometry(10, 140, 100, 25);
    addNodeButton->setText("Add node");

    findButton = new QPushButton(this);
    findButton->setGeometry(10, 175, 100, 25);
    findButton->setText("Find value");

    removeButton = new QPushButton( "Remove value/node", this);
    removeButton->setGeometry(10, 210, 150, 25);

    preButton = new QPushButton(this);
    preButton->setGeometry(10, 245, 100, 25);
    preButton->setText("Preorder");

    postButton = new QPushButton(this);
    postButton->setGeometry(10, 280, 100, 25);
    postButton->setText("Postorder");

    findCommonParentButton = new QPushButton(this);
    findCommonParentButton->setGeometry(10, 315, 150, 25);
    findCommonParentButton->setText("Find common parent");

    connect(createButton, &QPushButton::clicked, this, &MainWindow::create);
    connect(findButton, &QPushButton::clicked, this, &MainWindow::find);
    connect(findCommonParentButton, &QPushButton::clicked, this, &MainWindow::findCommonParent);
    connect(removeButton, &QPushButton::clicked, this, &MainWindow::remove);
    connect(addButton, &QPushButton::clicked, this, &MainWindow::add);
    connect(addNodeButton, &QPushButton::clicked, this, &MainWindow::addNode);
    connect(postButton, &QPushButton::clicked, this, &MainWindow::post);
    connect(preButton, &QPushButton::clicked, this, &MainWindow::pre);

    updateTreeView();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::add()
{
    bool ok;
    int key = keyInput->text().toInt(&ok);
    if (ok) {
        treeNode = AVLTree::add(treeNode, key);
        updateTreeView();
    } else {
        QMessageBox::warning(this, "Input Error", "Please enter a valid integer key.");
    }
}

void MainWindow::addNode() {
    bool ok;
    QString node = keyInput->text();
    QString value;
    int key;

    for (int i = 0; i <= node.size(); ++i) {
        if (node[i] == " ") {
            key = value.toInt(&ok);

            if (ok) {
                treeNode = AVLTree::add(treeNode, key);
                updateTreeView();
            } else {
                QMessageBox::warning(this, "Input Error", "Please enter a valid integer key.");
            }
            value.clear();
        }
        else {
            value.push_back(node[i]);
            if (i == node.size() - 1) {
                node.push_back(" ");
            }
        }
    }
}

void MainWindow::remove()
{
    bool ok;
    int key = keyInput->text().toInt(&ok);
    if (ok) {
        treeNode = AVLTree::remove(treeNode, key);
        updateTreeView();
    } else {
        QMessageBox::warning(this, "Input Error", "Please enter a valid integer key.");
    }
}

void MainWindow::updateTreeView()
{
    widget->setAVLTree(treeNode);
}

void MainWindow::create() {
    std::map<long, std::string> database {
            {3, "a"},
            {0, "b"},
            {7, "c"},
            {11, "d"},
            {5, "e"},
            {90, "f"},
            {-12, "g"}
    };
    treeNode = AVLTree::createAVLTree(database);
    updateTreeView();
}

void MainWindow::find() {
    bool ok;
    int key = keyInput->text().toInt(&ok);
    if (ok) {
        ok = AVLTree::find(treeNode, key);
        keyInput->setText(ok ? "true" : "false");
    } else {
        QMessageBox::warning(this, "Input Error", "Please enter a valid integer key.");
    }
}

void MainWindow::post() {
    AVLTree::postorderTraverse(treeNode);
}

void MainWindow::pre() {
    AVLTree::preorderTraverse(treeNode);
}

void MainWindow::findCommonParent() {
    bool ok;
    QString node = keyInput->text();
    QString value;
    int key1, key2;
    Node* commonParent = new Node();

    for (int i = 0; i <= node.size(); ++i) {
        if (node[i] == " ") {
            key1 = value.toInt(&ok);
            if (ok) {
                value.clear();
                for (int j = i + 1; j <= node.size() ; ++j) {
                    if (node[j] == " ") {
                        key2 = value.toInt(&ok);
                        if (ok) {
                            commonParent = AVLTree::findCommonParent(treeNode, key1, key2);
                            if (commonParent) {
                                keyInput->setText(QString::number(commonParent->value));
                            }
                            else {
                                keyInput->setText(QString("No common parents"));
                            }
                        }
                        else {
                            QMessageBox::warning(this, "Input Error", "Please enter a valid integer key.");
                        }
                        break;
                    }
                    else {
                        value.push_back(node[j]);
                        if (j == node.size() - 1) {
                            node.push_back(" ");
                        }
                    }
                }
                break;
            } else {
                QMessageBox::warning(this, "Input Error", "Please enter a valid integer key.");
            }
        }
        else {
            value.push_back(node[i]);
        }
    }
}
