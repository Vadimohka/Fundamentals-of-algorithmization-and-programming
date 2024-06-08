#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    for(int i = 0;i < 20;++i){
        int a = rand() % 100;
        int b = rand() % 100;
        para.pushBack({a,b});
        vect += QString::number(rand() % 100) + " " + QString::number(rand() % 100) + "|";
    }
    ui->textEdit->setText(vect);
    ui->erasespin->hide();
    ui->insert_size->hide();
    ui->insert_spin->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int a = rand() % 100;
    int b = rand() % 100;
    para.pushBack({a,b});
    vect += QString::number(rand() % 100) + " " + QString::number(rand() % 100) + "|";
    ui->textEdit->setText(vect);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->erasespin->cleanText();
    ui->erasespin->show();
    ui->erasespin->setMaximum(para.Size());
}


void MainWindow::on_erasespin_valueChanged(int arg1)
{
    if (arg1 >= 0 && arg1 < para.Size())
    {
        para.erase(para.begin() + arg1);
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->insert_size->show();
    //ui->insert_spin->show();
    ui->insert_size->setMaximum(para.Size());
}


void MainWindow::on_insert_size_valueChanged(int arg1)
{
   ui->insert_spin->show();
   ind
}

