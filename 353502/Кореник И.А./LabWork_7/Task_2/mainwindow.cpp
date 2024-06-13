#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->keyEdit, &QLineEdit::textChanged, this, [&](){
        currentKey = ui->keyEdit->text().toInt(&correctKey);
    });
    QObject::connect(ui->dataEdit, &QLineEdit::textChanged, this, [&](){
        currentData = ui->dataEdit->text();
        correctData = (currentData.size() != 0);
    });
    QVector<QPair<int, QString>> initial;
    for (int i = 1; i < 1234; i++){
        initial.push_back({i, "0"});
    }

    avl_tree = new AVL_Tree(initial);

    update();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_insertButton_clicked()
{
    if (!correctKey || !correctData) return;

    avl_tree->insert(currentKey, currentData);
    //avl_tree->balance();
    update();
}

void MainWindow::update(bool poisk, int value)
{
    if (binaryTree != nullptr)
    delete binaryTree;
    binaryTree = new GraphicsTree(ui->frame);
    binaryTree->setGeometry(ui->frame->geometry());

    TreeNode* root = fillTree(avl_tree->root);

    binaryTree->setTree(root, poisk, value);

    //binaryTree->setWindowTitle("Binary Tree Visualization");
    binaryTree->show();
    repaint();
}

TreeNode* MainWindow::fillTree(Node *node)
{
    if (node == nullptr) return nullptr;

    return new TreeNode(node->key, fillTree(node->leftSon), fillTree(node->rightSon));

}

void MainWindow::findAnimation(Node* node, int key)
{

    if (node == nullptr) update();
    else if (node->key == key) update(true, node->key);
    else if (key > node->key) {
        update(true, node->key);
        repaint();

        QCoreApplication::processEvents();
        findAnimation(node->rightSon, key);
    }
    else {
        update(true, node->key);
        repaint();
        QCoreApplication::processEvents();
        findAnimation(node->leftSon, key);
    }
}


void MainWindow::on_eraseButton_clicked()
{
    if (!correctKey) return;

    avl_tree->erase(currentKey);
    avl_tree->balance();
    update();
}


void MainWindow::on_findButton_clicked()
{
    if (!correctKey) return;
    findAnimation(avl_tree->root, currentKey);
    QString value = avl_tree->find(currentKey);

    if (value == "")
        ui->foundValue->setText("Not found");
    else
        ui->foundValue->setText(QString::number(currentKey) + " : " + value);
}


void MainWindow::on_balanceButton_clicked()
{
    while(!avl_tree->isBalanced(avl_tree->root)){
        avl_tree->balance();
        update();
    }
}

