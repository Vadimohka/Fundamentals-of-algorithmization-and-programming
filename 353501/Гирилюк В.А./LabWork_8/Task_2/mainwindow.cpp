#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    arrHeap.setTreeWidget(ui->treeWidget);
    listHeap.setTreeWidget(ui->treeWidget_2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit->text().length() > 0){
        arrHeap.add(ui->spinBox->value(), ui->lineEdit->text());
        arrHeap.setTree();
        listHeap.add(ui->spinBox->value(), ui->lineEdit->text());
        listHeap.setTree();
    }
    else{
        QMessageBox::critical(this, "No value!", "Please, input some value");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    if(arrHeap.contains()){
        arrHeap.add(ui->spinBox->value(), ui->lineEdit->text());
        arrHeap.setTree();
        listHeap.add(ui->spinBox->value(), ui->lineEdit->text());
        listHeap.setTree();
    }
    else{
        QMessageBox::critical(this, "No value!", "Please, input some value");
    }
}

