#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow() : ui(new Ui::MainWindow), myhashtable(new MyHashTable) {

    ui->setupUi(this);

    update();

}

void MainWindow::update()
{

    myhashtable->fillEnties(ui->entries);
    long smalles = myhashtable->findTotalLen();
    ui->smalles->setText(smalles == LONG_MAX ? "EMPTY TABLE" : QString::number(myhashtable->findTotalLen()));

}

void MainWindow::on_randBtn_clicked()
{

    myhashtable->randomize();
    update();

}


void MainWindow::on_clearBtn_clicked()
{

    myhashtable->clear();
    update();

}


void MainWindow::on_getBtn_clicked()
{

    int key = ui->key->value();
    QString val = "NOT_FOUND";
    if (myhashtable->contains(key))
        val = myhashtable->get(key);
    ui->value->setText(val);

}


void MainWindow::on_setBtn_clicked()
{

    int key = ui->key->value();
    QString val = ui->value->text();
    myhashtable->insert(key, val);
    update();

}


void MainWindow::on_delBtn_clicked()
{

    int key = ui->key->value();
    QString val = "NOT_FOUND";
    if (myhashtable->contains(key))
        val = myhashtable->get(key);
    ui->value->setText(val);
    myhashtable->remove(key);
    update();

}

