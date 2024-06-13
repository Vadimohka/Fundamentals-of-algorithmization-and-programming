#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tree = new BST<QString>[2];
    tree[0].setTreeWidget(ui->treeWidget);
    tree[1].setTreeWidget(ui->treeWidget_2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonAdd_clicked()
{
    int index = ui->comboBox->currentIndex();
    if(ui->lineEdit->text().length() > 0){
        tree[index].put(ui->spinBox->value(), ui->lineEdit->text());
        tree[index].setTree();
    }
    else{
        QMessageBox::critical(this, "No value!", "Please, input some value");
    }
}


void MainWindow::on_pushButton_clicked()
{
    int index = ui->comboBox->currentIndex();
    QString* str = tree[index].get(ui->spinBox->value());
    if(str != nullptr){
        QMessageBox::critical(this, "Successful!", "Value is:" + *str);
    }
    else{
        QMessageBox::critical(this, "Fail", "No Value");
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    int index = ui->comboBox->currentIndex();
    QString* str = tree[index].get(ui->spinBox->value());
    if(str != nullptr){
        tree[index].remove(ui->spinBox->value());
        QMessageBox::critical(this, "Successful!", "Element " + *str + " deleted");
    }
    else{
        QMessageBox::critical(this, "Fail", "No Value");
        return;
    }
    tree[index].setTree();
}


void MainWindow::on_pushButton_5_clicked()
{
    if(ui->comboBox->currentIndex() == 0){
        if(tree[1].size() < 1){
            QMessageBox::warning(this, "Tree is empty", "Tree is empty");
            return;
        }
        tree[0].addBranch(&tree[1]);
        tree[0].setTree();
    }
    else{
        if(tree[0].size() < 1){
            QMessageBox::warning(this, "Tree is empty", "Tree is empty");
            return;
        }
        tree[1].addBranch(&tree[0]);
        tree[1].setTree();
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    int index = ui->comboBox->currentIndex();
    QString *traver = tree[index].travers();
    QString result = "";
    if(traver != nullptr){
        for(int i = 0; i < tree[index].size(); i++){
            result += traver[i];
        }
    }
    ui->textEdit->setText(result);
}


void MainWindow::on_pushButton_4_clicked()
{
    int index = ui->comboBox->currentIndex();
    tree[index].deleteBrunch(ui->spinBox->value());
    tree[index].setTree();
}


void MainWindow::on_pushButton_8_clicked()
{
    int index = ui->comboBox->currentIndex();
    int key1 = ui->spinBox_4->value();
    int key2 = ui->spinBox_5->value();
    if(!tree[index].contains(key1) || !tree[index].contains(key2)){
        QMessageBox::warning(this, "Tree key", "Tree haven't this keys");
        return;
    }
    else{
        QMessageBox::information(this, "Tree key", "Ancestor of this nodes is " + QString::number(tree[index].ancestor(key1, key2)));
    }
}

