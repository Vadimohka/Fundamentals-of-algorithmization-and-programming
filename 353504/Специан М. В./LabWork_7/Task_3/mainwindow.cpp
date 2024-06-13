#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hashtable = new HashTableExtension(101);
    hashtable->createRandomHashTable();
    UpdateTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateTable()
{
    ui->listWidget->clear();
    ui->listWidget_2->clear();
    ui->listWidget_3->clear();
    auto vec = hashtable->toVector();
    QString str;
    for (int i = 0; i < vec.size(); ++i)
    {
        str += QString::number(i) + ": ";
        for (auto & i : vec[i])
        {
            str += QString::number(i) + " ";
        }
        str += "\n\n";
    }
    ui->listWidget->addItem(str);

    QPair<HashTableExtension*, HashTableExtension*> division = hashtable->divide();
    auto vecN = division.first->toVector();
    auto vecP = division.second->toVector();
    QString strN;
    for (int i = 0; i < vecN.size(); ++i)
    {
        strN += QString::number(i) + ": ";
        for (auto & i : vecN[i])
        {
            strN += QString::number(i) + " ";
        }
        strN += "\n\n";
    }
    ui->listWidget_2->addItem(strN);
    QString strP;
    for (int i = 0; i < vecP.size(); ++i)
    {
        strP += QString::number(i) + ": ";
        for (auto & i : vecP[i])
        {
            strP += QString::number(i) + " ";
        }
        strP += "\n\n";
    }
    ui->listWidget_3->addItem(strP);
}

void MainWindow::on_pushButton_create_clicked()
{
    hashtable->clear();
    hashtable = new HashTableExtension(101);
    hashtable->createRandomHashTable();
    UpdateTable();
}


void MainWindow::on_pushButton_add_clicked()
{
    hashtable->addItem(QInputDialog::getInt(nullptr, tr("User Input"), "Enter Key:", 0, -50, 50), QInputDialog::getInt(nullptr, tr("User Input"), "Enter Value"));
    UpdateTable();
}


void MainWindow::on_pushButton_remove_clicked()
{
    hashtable->removeItem(QInputDialog::getInt(nullptr, tr("User Input"), "Enter Key:", 0, -50, 50));
    UpdateTable();
}

