#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::fillTreeWidget(QTreeWidgetItem *item, Tree::Node *node)
{
    if (node == nullptr)
        return;

    item->setText(0, QString::number(node->key) + " " + node->data);

    if (node->left != nullptr) {
        QTreeWidgetItem* leftSon = new QTreeWidgetItem(item);
        fillTreeWidget(leftSon, node->left);
    }

    if (node->right != nullptr) {
        QTreeWidgetItem* rightSon = new QTreeWidgetItem(item);
        fillTreeWidget(rightSon, node->right);
    }
}


void MainWindow::displayTree()
{
    ui->treeWidget->clear();

    if (ST.root == nullptr)
        return;

    QTreeWidgetItem *rootItem = new QTreeWidgetItem(ui->treeWidget);

    fillTreeWidget(rootItem, ST.root);

    ui->treeWidget->addTopLevelItem(rootItem);
}

void MainWindow::on_pushButton_clicked()
{
    ui->textBrowser->clear();
    ST.balanceTree();
    displayTree();
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->textBrowser->clear();
    QString t = ST.find(ui->spinBox->value());
    if(t == "")
    {
        ui->textBrowser->append("element not exist");
    }
    else
    {
        ui->textBrowser->append(t);
    }

}


void MainWindow::on_pushButton_2_clicked()
{
    ui->textBrowser->clear();
    ST.insert(ui->spinBox->value(), ui->lineEdit->text());
    displayTree();
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->textBrowser->clear();
    ST.remove(ui->spinBox->value());
    displayTree();
}


void MainWindow::on_pushButton_8_clicked()
{
  ui->textBrowser->clear();
    ST.removeSubtree(ui->spinBox->value());
   displayTree();
}


void MainWindow::on_pushButton_7_clicked()
{
    ui->textBrowser->clear();
    auto res = ST.preOrderTraversal();
    QString text = "";
    for (auto el : res) {
        text += el + "\n";
    }
    ui->textBrowser->setPlainText(text);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->textBrowser->clear();
    auto res = ST.inOrderTraversal();
    QString text = "";
    for (auto el : res) {
        text += el + "\n";
    }
    ui->textBrowser->setPlainText(text);
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->textBrowser->clear();
    auto res = ST.postOrderTraversal();
    QString text = "";
    for (auto el : res) {
        text += el + "\n";
    }
    ui->textBrowser->setPlainText(text);
}

