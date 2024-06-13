#include "mainwindow.h"
#include "./ui_mainwindow.h"

const int Limit = 10000;

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



int MainWindow::GenerateRandomNumber()
{
    return QRandomGenerator::global()->bounded(Limit);
}

void MainWindow::FillTable(HashTable<int> &table, int size)
{
    int r = QRandomGenerator::global()->bounded(size);

    for(int i = 0; i < r; ++i){
        table.insert(GenerateRandomNumber());
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->clear();

    Table16 = new HashTable<int>(16);

    FillTable(*Table16, 16);
    currTable = 16;
    ui->listWidget->addItem(Table16->print());
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->listWidget->clear();

    Table64 = new HashTable<int>(64);

    FillTable(*Table64, 64);
    currTable = 64;

    ui->listWidget->addItem(Table64->print());
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->listWidget->clear();

    Table128 = new HashTable<int>(128);

    FillTable(*Table128, 128);
    currTable = 128;
    ui->listWidget->addItem(Table128->print());
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->listWidget->clear();

    Table2048 = new HashTable<int>(2048);

    FillTable(*Table2048, 2048);
    currTable = 2048;
    ui->listWidget->addItem(Table2048->print());
}


void MainWindow::on_pushButton_5_clicked()
{
    int keyToFind = ui->lineEdit->text().toInt();
    int pos = 0;;
    switch(currTable){
    case 16:{
        pos = Table16->find(keyToFind);
        break;
    }
    case 64:{
        pos = Table64->find(keyToFind);
        break;
    }
    case 128:{
        pos = Table128->find(keyToFind);
        break;
    }
    case 2048:{
        pos = Table2048->find(keyToFind);
        break;
    }
    default: break;
    }

    ui->label_3->setNum(pos);

}


