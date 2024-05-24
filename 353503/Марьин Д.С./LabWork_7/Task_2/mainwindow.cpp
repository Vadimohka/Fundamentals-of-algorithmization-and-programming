#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tree = new QTreeWidget(ui->treeView);
    tree->header()->setStretchLastSection(true);
    tree->header()->setMinimumSectionSize(250);
    tree->header()->resizeSection(0 /*column index*/, 250 /*width*/);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addNode()
{
    int key;
    QString val;
    bool ok = false;
    QString name = QInputDialog::getText(nullptr, "Enter Name", "Enter the name: ", QLineEdit::Normal, "", &ok);
    if (ok)
    {
        val = name;
    }
    int id = QInputDialog::getInt(nullptr, "Input", "Enter the Id value: ", 1, -100, 100, 1, &ok);
    if (ok)
    {
        key = id;
    }
    ui->inBox->setValue(id);
    ui->lineEdit->setText(name);
    AVL_tree.addToTree(key,val,tree);
    qDebug() << "root is " << AVL_tree.getRoot()->value;
}

void MainWindow::on_On_insert_clicked()
{
    tree->clear();
    addNode();
}

void MainWindow::on_On_print_forward_clicked()
{
    QString s = AVL_tree.print();
    ui->label->setText(s);
}

void MainWindow::on_On_balance_clicked()
{
    AVL_tree.updateTree(tree);
}

void MainWindow::on_On_find_clicked()
{
    QString str = AVL_tree.find(ui->inBox->value());
    if(str.isEmpty())
    {
        str += "Noting was found!";
    }
    ui->label->setText(str);
}

void MainWindow::on_On_delete_clicked()
{
    AVL_tree.remove(ui->inBox->value());
    AVL_tree.updateTree(tree);
}

void MainWindow::on_On_clear_clicked()
{
    AVL_tree.clear();
    tree->clear();
}

void MainWindow::on_On_print_reverse_clicked()
{
    QString s = AVL_tree.reverse_print();
    ui->label->setText(s);
}

void MainWindow::on_On_MaxDepth_clicked()
{
    QString s = QString::number(AVL_tree.maxDepth());
    ui->label->setText(s);
}

