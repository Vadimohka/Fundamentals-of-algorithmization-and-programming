#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    hashtable = new HashTableChild<QString>(30);

    hashtable->print(ui->listWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::listUpdate()
{
    hashtable->print(ui->listWidget);
}

void MainWindow::on_insertButton_clicked()
{
    hashtable->insert(ui->insertKey->value(), ui->insertValue->text());
    listUpdate();
}


void MainWindow::on_removeButton_clicked()
{
    hashtable->remove(ui->insertKey->value());
    listUpdate();

    ui->getValue->clear();
}


void MainWindow::on_getButton_clicked()
{
    ui->getValue->setText(hashtable->get(ui->insertKey->value()));
    if(ui->getValue->text() == "error!@#$%^&*()") ui->getValue->setText("Not founded");
}


void MainWindow::on_removeEvenKeys_clicked()
{
    hashtable->deleteAllEvenKeys();
    listUpdate();
}


void MainWindow::on_insertButton_2_clicked()
{
    hashtable->clear();

    for(int i = 0; i < ui->countGenerate->value(); i++)
    {
        int key = rand() % 10000;
        QString str;

        for(int j = 0; j < rand() % 10 + 1; j++)
        {
            str += QChar(rand() % 29 + 97);
        }

        hashtable->insert(key, str);
    }

    listUpdate();
}

