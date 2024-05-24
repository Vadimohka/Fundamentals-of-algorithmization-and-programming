#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qgraphicsscene.h>

#include <QTimer>
#include <QEvent>
#include <iostream>


mainwindow::mainwindow(): ui(new Ui::mainwindow), scene (new QGraphicsScene(this)){

    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    scene->addItem(background);

    auto *left_tick = new QTimer(this);
    auto *right_tick = new QTimer(this);
    auto *up_tick = new QTimer(this);
    auto *down_tick = new QTimer(this);

    left_tick->setInterval(20);
    right_tick->setInterval(20);
    up_tick->setInterval(20);
    down_tick->setInterval(20);

  //  left_tick->


    connect(ui->leftButton, SIGNAL(pressed()), left_tick, SLOT(start()));
    connect(ui->rightButton, SIGNAL(pressed()), right_tick, SLOT(start()));
    connect(ui->upButton, SIGNAL(pressed()), up_tick, SLOT(start()));
    connect(ui->downButton, SIGNAL(pressed()), down_tick, SLOT(start()));

    connect(ui->leftButton, SIGNAL(released()), left_tick, SLOT(stop()));
    connect(ui->rightButton, SIGNAL(released()), right_tick, SLOT(stop()));
    connect(ui->upButton, SIGNAL(released()), up_tick, SLOT(stop()));
    connect(ui->downButton, SIGNAL(released()), down_tick, SLOT(stop()));

    connect(left_tick, SIGNAL(timeout()), this, SLOT(on_leftButton_clicked()));
    connect(right_tick, SIGNAL(timeout()), this, SLOT(on_rightButton_clicked()));
    connect(up_tick, SIGNAL(timeout()), this, SLOT(on_upButton_clicked()));
    connect(down_tick, SIGNAL(timeout()), this, SLOT(on_downButton_clicked()));


    connect(ui->boomButton, SIGNAL(clicked()), this, SLOT(on_boomButton_clicked()));
    connect(ui->closeButton, SIGNAL(clicked()), this, SLOT(on_closeButton_clicked()));

    scene->addItem(Baloon);
}

void mainwindow::on_boomButton_clicked()
{
    Baloon->remove();
}

void mainwindow::on_closeButton_clicked()
{
    close();
}

void mainwindow::on_upButton_clicked()
{
    Baloon->move(0, -2);

}

void mainwindow::on_downButton_clicked()
{
    Baloon->move(0, 2);
}

void mainwindow::on_leftButton_clicked()
{
    Baloon->move(-2, 0);
}

void mainwindow::on_rightButton_clicked()
{
    Baloon->move(2, 0);
}