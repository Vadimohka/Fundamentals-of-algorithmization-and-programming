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
    rbTree = new RBTree<int, QString>;
    for (int i = 1; i <= 1; i++)
        rbTree->insert(i, "0");
    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update()
{
    if (binaryTree != nullptr)
        delete binaryTree;
    binaryTree = new GraphicsTree(ui->frame);
    binaryTree->setGeometry(ui->frame->geometry());

    TreeNode* root = fillTree(rbTree->root);

    binaryTree->setTree(root);

    //binaryTree->setWindowTitle("Binary Tree Visualization");
    binaryTree->show();
    repaint();
}

TreeNode *MainWindow::fillTree(RBTree<int, QString>::Node *node)
{
    if (node == nullptr) return nullptr;

    return new TreeNode(node->key, fillTree(node->left), fillTree(node->right), node->color);
}

void MainWindow::on_insertButton_clicked()
{
    if (!correctKey || !correctData) return;

    rbTree->insert(currentKey, currentData);
    //avl_tree->balance();
    update();
}


void MainWindow::on_eraseButton_clicked()
{
    if (!correctKey) return;

    rbTree->erase(currentKey);
    //rbTree->balance();
    update();
}


void MainWindow::on_findButton_clicked()
{
    if (!correctKey) return;
    //findAnimation(rbTree->root, currentKey);
    QString value = rbTree->get(currentKey);

    if (value == "")
        ui->foundValue->setText("Not found");
    else
        ui->foundValue->setText(QString::number(currentKey) + " : " + value);
}

