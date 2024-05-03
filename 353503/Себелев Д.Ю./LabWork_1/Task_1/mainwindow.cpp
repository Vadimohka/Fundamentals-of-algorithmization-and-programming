#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);

    truck = new Truck();
    angle = 0;
    //scene->addLine(0, -400, 0, 400);
    //scene->addLine(-400, 0, 400, 0);
    scene->addItem(truck);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->scale(2, 2);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, truck, &Truck::rotate);
    connect(ui->back_up, &QPushButton::pressed, this, &MainWindow::on_back_up_pressed);
    connect(ui->back_up, &QPushButton::released, this, &MainWindow::on_back_up_released);
    connect(ui->back_down, &QPushButton::pressed, this, &MainWindow::on_back_down_pressed);
    connect(ui->back_down, &QPushButton::released, this, &MainWindow::on_back_down_released);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_back_up_pressed()
{
    timer->start(40);
}


void MainWindow::on_back_up_released()
{
    timer->stop();
}


void MainWindow::on_back_down_pressed()
{
    truck->sign = -(truck->sign);
    timer->start(40);
}


void MainWindow::on_back_down_released()
{
    truck->sign = -(truck->sign);
    timer->stop();
}
