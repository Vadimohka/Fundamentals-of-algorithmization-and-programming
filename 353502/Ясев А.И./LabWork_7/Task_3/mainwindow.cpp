#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hashtable = new HashTable(101);
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
    QVector<QVector<Pair>> vec = hashtable->toVector();
    QString str;

    foreach(QVector<Pair> colliding, vec){
        if(!colliding.isEmpty()){
            str += QString::number(colliding[0].key) + ": ";
            foreach(Pair i, colliding)
            {
                str += QString::number(i.value) + " ";
            }
            str += "\n\n";
        }
    }
    ui->listWidget->addItem(str);

    QPair<HashTable*, HashTable*> division = hashtable->divide();
    auto vecN = division.first->toVector();
    auto vecP = division.second->toVector();
    QString strN;
    foreach(QVector<Pair> colliding, vecN){
        if(!colliding.isEmpty()){
            strN += QString::number(colliding[0].key) + ": ";
            foreach(Pair i, colliding)
            {
                strN += QString::number(i.value) + " ";
            }
            strN += "\n\n";
        }
    }
    ui->listWidget_2->addItem(strN);
    QString strP;
    foreach(QVector<Pair> colliding, vecP){
        if(!colliding.isEmpty()){
            strP += QString::number(colliding[0].key) + ": ";
            foreach(Pair i, colliding)
            {
                strP += QString::number(i.value) + " ";
            }
            strP += "\n\n";
        }
    }
    ui->listWidget_3->addItem(strP);
}

void MainWindow::on_pushButton_create_clicked()
{
    hashtable->clear();
    hashtable = new HashTable(101);
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

