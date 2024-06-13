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
    Tree1 = new BinaryTree<QString>();
    Tree2 = new BinaryTree<QString>();
    //QVector<QPair<int, QString>> initial;
    for (int i = 1; i < 10; i++){
        Tree1->insert(i, "0");
        Tree2->insert(i + 10, "0");
    }
    update1();
    update2();

    //grahicsTree1 = new GraphicsTree(ui->Tree_1);
    //grahicsTree2 = new GraphicsTree(ui->Tree_2);

}

MainWindow::~MainWindow()
{
    delete ui;
}

TreeNode *MainWindow::fillTree(BinaryTree<QString>::Node *node)
{
    if (node == nullptr) return nullptr;

    return new TreeNode(node->key, fillTree(node->left), fillTree(node->right));
}

void MainWindow::update1(bool poisk, int value)
{
    if (grahicsTree1 != nullptr)
        delete grahicsTree1;
    grahicsTree1 = new GraphicsTree(ui->Tree_1);
    grahicsTree1->setGeometry(ui->Tree_1->geometry());

    TreeNode* root = fillTree(Tree1->root);

    grahicsTree1->setTree(root, poisk, value);

    //binaryTree->setWindowTitle("Binary Tree Visualization");
    grahicsTree1->show();
    repaint();
}

void MainWindow::update2(bool poisk, int value)
{
    if (grahicsTree2 != nullptr)
        delete grahicsTree2;
    grahicsTree2 = new GraphicsTree(ui->Tree_2);
    grahicsTree2->setGeometry(ui->Tree_1->geometry());

    TreeNode* root = fillTree(Tree2->root);

    grahicsTree2->setTree(root, poisk, value);

    //binaryTree->setWindowTitle("Binary Tree Visualization");
    grahicsTree2->show();
    repaint();
}

void MainWindow::on_insertButton_2_clicked()
{
    if (ui->radioButton->isChecked()){
        Tree1->appendTree(*Tree2);
        update1();
    }

    if (ui->radioButton_2->isChecked()){
        Tree2->appendTree(*Tree1);
        update2();
    }

}


void MainWindow::on_findButton_clicked()
{
    if (!correctKey) return;
    QString value = "";
    if (ui->radioButton->isChecked()){
        findAnimation(Tree1->root, currentKey);
        value = Tree1->get(currentKey);
    }
    else if (ui->radioButton_2->isChecked()){
        findAnimation(Tree2->root, currentKey);
        value = Tree2->get(currentKey);
    }

    if (value == "")
        ui->foundValue->setText("Not found");
    else
        ui->foundValue->setText(QString::number(currentKey) + " : " + value);
}


void MainWindow::on_insertButton_clicked()
{
    if (!correctKey || !correctData) return;
    if (ui->radioButton->isChecked()){
        Tree1->insert(currentKey, currentData);
        Tree1->balance();
        update1();
    }
    if (ui->radioButton_2->isChecked()){
        Tree2->insert(currentKey, currentData);
        Tree2->balance();
        update2();
    }
}


void MainWindow::on_eraseButton_clicked()
{
    if (!correctKey) return;
    if (ui->radioButton->isChecked()){
        Tree1->remove(currentKey);
        Tree1->balance();
        update1();
    }
    if (ui->radioButton_2->isChecked()){
        Tree2->remove(currentKey);
        Tree2->balance();
        update2();
    }
}
void MainWindow::findAnimation(BinaryTree<QString>::Node* node, int key)
{
    if (ui->radioButton->isChecked()){
        if (node == nullptr) update1();
        else if (node->key == key) update1(true, node->key);
        else if (key > node->key) {
            update1(true, node->key);
            repaint();

            QCoreApplication::processEvents();
            findAnimation(node->right, key);
        }
        else {
            update1(true, node->key);
            repaint();
            QCoreApplication::processEvents();
            findAnimation(node->left, key);
        }
    }
    else if (ui->radioButton_2->isChecked()){
        if (node == nullptr) update2();
        else if (node->key == key) update2(true, node->key);
        else if (key > node->key) {
            update2(true, node->key);
            repaint();

            QCoreApplication::processEvents();
            findAnimation(node->right, key);
        }
        else {
            update2(true, node->key);
            repaint();
            QCoreApplication::processEvents();
            findAnimation(node->left, key);
        }
    }
}

