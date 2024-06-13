#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow() : ui(new Ui::MainWindow), mybintree(new MyBinTree) {
    ui->setupUi(this);

    update();
}

void MainWindow::update() {
    mybintree->fillEnties(ui->tree);
    ui->totlen->setText(QString::number(mybintree->findTotalLen()));
}

void MainWindow::on_randBtn_clicked()
{

    mybintree->randomize();
    update();

}


void MainWindow::on_clearBtn_clicked()
{

    mybintree->clear();
    update();

}


void MainWindow::on_getBtn_clicked()
{

    int key = ui->key->value();
    QString val = "NOT_FOUND";
    if (mybintree->contains(key))
        val = mybintree->get(key);
    ui->value->setText(val);

}


void MainWindow::on_setBtn_clicked()
{

    int key = ui->key->value();
    QString val = ui->value->text();
    mybintree->insert(key, val);
    update();

}


void MainWindow::on_delBtn_clicked()
{

    int key = ui->key->value();
    QString val = "NOT_FOUND";
    if (mybintree->contains(key))
        val = mybintree->get(key);
    ui->value->setText(val);
    mybintree->remove(key);
    update();

}


void MainWindow::on_balanceBtn_clicked()
{

    mybintree->balance();
    update();

}

