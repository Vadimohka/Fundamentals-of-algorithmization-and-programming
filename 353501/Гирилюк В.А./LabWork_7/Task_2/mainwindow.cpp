#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tree = new BranchBST();
    tree->setTreeWidget(ui->treeWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int keys[ui->tableWidget->rowCount()];
    QString values[ui->tableWidget->rowCount()];
    for(int i = 0; i < ui->tableWidget->rowCount(); i++){
        keys[i] = ui->tableWidget->item(i, 0)->text().toInt();
        values[i] = ui->tableWidget->item(i, 1)->text();
        tree->put(keys[i], values[i]);
    }
    tree->setTree();
}


void MainWindow::on_pushButton_6_clicked()
{
    if(ui->lineEdit->text().length() > 0){
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        QTableWidgetItem* item = new QTableWidgetItem(QString::number(ui->spinBox->value()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, item);
        item = new QTableWidgetItem(ui->lineEdit->text());
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, item);
    }
    else{
        QMessageBox::critical(this, "No value!", "Please, input some value");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    tree->put(ui->spinBox->value(), ui->lineEdit->text());
    tree->setTree();
}


void MainWindow::on_pushButton_3_clicked()
{
    QString* str = tree->get(ui->spinBox_2->value());
    if(str != nullptr){
        QMessageBox::critical(this, "Successful!", "Value is:" + *str);
    }
    else{
        QMessageBox::critical(this, "Fail", "No Value");
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    QString* str = tree->get(ui->spinBox_3->value());
    if(str != nullptr){
        tree->remove(ui->spinBox_3->value());
        QMessageBox::critical(this, "Successful!", "Element " + *str + " deleted");
    }
    else{
        QMessageBox::critical(this, "Fail", "No Value");
    }
    if(tree->size() > 0){
        tree->setTree();
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    tree->deleteBrunch(ui->spinBox_4->value());
    if(tree->size() > 0){
        tree->setTree();
    }
}

