#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "wheel.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainScene = new QGraphicsScene();
    ui->graphicsView->setScene(mainScene);

    wheelShape = new wheel;

    mainScene->addItem(wheelShape);

    wheelShape->setCircle(0, 0, 50);

    this->timer = new QTimer();
    time = 0;
    connect(this->timer, SIGNAL(timeout()), this, SLOT(updateWheel()));
    this->timer->start(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateWheel()
{
    this->time++;
    wheelShape->setPosition((500 * (double)(10000 - time)) / 10000, 0);
    mainScene->update();
}

