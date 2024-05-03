#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "car.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    block=false;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    C->drawCar(&painter);
    C->drawDoors(&painter);
    C->drawLight(&painter);
}

void MainWindow::on_pushButton_clicked()
{
    C->ride();
}

void MainWindow::on_pushButton_3_clicked()
{
    //C->open();
    //ui->pushButton_3->setDisabled(true);
    //ui->pushButton_3->setHidden(true);
    ui->pushButton_3->setEnabled(false);
    //qDebug()<<"Button pushed "<<block;
    change_door_status();
    /*
    if(block)
        return;

    ui->pushButton_3->setDisabled(true);
    ui->pushButton_3->
    block=true;
    ui->pushButton_3->repaint();



    //qDebug()<<C->get_mov();
    //C->open();
*/
    //timer->stop();
    //ui->pushButton_3->setHidden(false);
    ui->pushButton_3->repaint();
    ui->pushButton_3->setEnabled(true);
}


void MainWindow::on_pushButton_2_pressed()
{
    C->light();
    repaint();
}

void MainWindow::change_door_status()
{
    while(C->door())
    {
        //timer->start(100000);
        repaint();
        //update();
        MyTimer();
        //timer->stop();
    }
    C->opened=!C->opened;
    if(C->changed)
        ui->pushButton_3->setText("Open doors");
    else
        ui->pushButton_3->setText("Close doors");
    C->changed=!C->changed;
    block=false;
}

void MainWindow::MyTimer()
{
    bool fl=false;
    if(fl)
    {
        fl=false;
    }
    else
        fl=true;
    for(int i=0;i<(int)1e6;i++)
        ;
}



