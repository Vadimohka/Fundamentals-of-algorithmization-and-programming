#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    qDebug()<<"PAINTEVENT";
    t->draw(&p);
}

void MainWindow::keyPressEvent(QKeyEvent *ke)
{
    //qDebug()<<ke->key()<<" "<<(int)Qt::LeftArrow;
    if (ke->key()== 16777234&&!Right)
    {
        qDebug()<<"Left press";
        Left=true;
        connect(timer,SIGNAL(timeout()),this,SLOT(move_left()));
        timer->start(5);

    }
    if (ke->key()== 16777236&&!Left)
    {
        qDebug()<<"Right press";
        Right=true;
        connect(timer,SIGNAL(timeout()),this,SLOT(move_right()));
        timer->start(5);

    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *ke)
{
    if (!(ke->modifiers() & Qt::LeftArrow))
    {
        qDebug()<<"Left realese";
        disconnect(timer,SIGNAL(timeout()),this,SLOT(move_left()));
        timer->stop();
        Left=false;
    }
    if (!(ke->modifiers() & Qt::RightArrow))
    {
        qDebug()<<"Right realese";
        disconnect(timer,SIGNAL(timeout()),this,SLOT(move_right()));
        timer->stop();
        Right=false;
    }
}

/*
void MainWindow::on_pushButton_pressed()
{
    connect(timer,SIGNAL(timeout()),this,SLOT(movee()));
    timer->start(5);
}


void MainWindow::on_pushButton_released()
{
    disconnect(timer,SIGNAL(timeout()),this,SLOT(movee()));
    timer->stop();
}

void MainWindow::movee()
{
    t->drive();
    update();
}
*/
void MainWindow::move_left()
{
    t->drive(-1);
    update();
}

void MainWindow::move_right()
{
    t->drive(+1);
    update();
}

