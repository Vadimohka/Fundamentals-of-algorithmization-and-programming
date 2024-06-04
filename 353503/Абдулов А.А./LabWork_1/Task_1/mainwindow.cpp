#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "movingcircle.h"

#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QPainter>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    circle = new RotatableCircle();
    ui->setupUi(this);
    scene = new QGraphicsScene();
    scene->setBackgroundBrush(Qt::white);
    ui->graphicsView->setScene(scene);
    scene->addItem(circle);

    connect(ui->pushButton_1, &QPushButton::clicked, circle, &RotatableCircle::moveLeft);
    connect(ui->pushButton_2, &QPushButton::clicked, circle, &RotatableCircle::moveRight);
    connect(ui->pushButton_3, &QPushButton::clicked, circle, &RotatableCircle::moveDown);
    connect(ui->pushButton_4, &QPushButton::clicked, circle, &RotatableCircle::moveUp);
    //connect(ui->pushButton_5, &QPushButton::clicked, circle, &RotatableCircle::rotate);


}

MainWindow::~MainWindow(){
    delete ui;
}





void MainWindow::on_pushButton_1_clicked(){

}


void MainWindow::on_pushButton_2_clicked(){

}


void MainWindow::on_pushButton_3_clicked(){
}


void MainWindow::on_pushButton_4_clicked(){

}


void MainWindow::on_pushButton_5_clicked(){
    circle->rotate();
}



