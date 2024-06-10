#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tree = new QTreeWidget(ui->treeView);

    tree->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    tree->resize(500, 500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addNode()
{
    int data = 0;
    bool ok;
    int id = QInputDialog::getInt(nullptr, "Input", "Enter the Id value: ", 1, -100, 100, 1, &ok);
    if (ok)
    {
        data = id;
    }
    bst.addNodeToTree(data, tree);
}

void MainWindow::on_insert_btn_clicked()
{
    tree->clear();
    addNode();
}


void MainWindow::on_remove_btn_clicked()
{
    int val = QInputDialog::getInt(nullptr, "Input", "Enter the value to remove: ", 1, -100, 100, 1);
    bst.remove(val);
    bst.update(tree);
}


void MainWindow::on_find_btn_clicked()
{
    int val = QInputDialog::getInt(nullptr, "Input", "Enter the value to find: ", 1, -100, 100, 1);
    if (bst.find(val))
    {
        QMessageBox::information(nullptr, "Find", "Value found!");
    }
    else
    {
        QMessageBox::information(nullptr, "Find", "Value not found!");
    }
}


void MainWindow::on_preorder_btn_clicked()
{
    ui->lineEdit->setText(bst.preOrder(bst.getRoot()));
}


void MainWindow::on_inorder_btn_clicked()
{
    ui->lineEdit->setText(bst.inOrder(bst.getRoot()));
}


void MainWindow::on_postorder_btn_clicked()
{
    ui->lineEdit->setText(bst.postOrder(bst.getRoot()));
}


void MainWindow::on_lowAnces_btn_clicked()
{
    int val1 = QInputDialog::getInt(nullptr, "Input", "Enter the first value: ", 1, -100, 100, 1);
    int val2 = QInputDialog::getInt(nullptr, "Input", "Enter the second value: ", 1, -100, 100, 1);
    Node<int>* lca = bst.lowestCommonAncestor(bst.getRoot(), val1, val2);
    if (lca)
    {
        ui->lineEdit->setText("LCA:" + QString::number(lca->data));
    }
    else
    {
        ui->lineEdit->setText("No LCA found!");
    }
}

