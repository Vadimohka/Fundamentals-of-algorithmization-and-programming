#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    htable = new MyHashTable(14);
    htable->createRandomHashTable(80);
    display();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_create_clicked(){
    htable->clear();
    htable = new MyHashTable(ui->spinBox->value());
    htable->createRandomHashTable(ui->spinBox->value()*100);
    QString find = htable->findMaxKey();
    ui->lineEdit->setText(find);
    display();
}

void MainWindow::display(){
    auto vec = htable->displayHash();
    QString ans;
    for (int j = 0; j < vec.size(); ++j) {
        ans += QString::number(j) + ": ";
        for (auto & i : vec[j]){
            ans += QString::number(i) + " ";
        }
        ans += "\n\n";
    }
    ui->textEdit->setText(ans);
}


void MainWindow::on_pushButton_clicked()
{
    htable->insertItem(ui->spinBox_key->value(), ui->spinBox_data->value());
    display();
}


void MainWindow::on_pushButton_2_clicked()
{
    htable->deleteItem(ui->spinBox_key->value());
    display();
}

