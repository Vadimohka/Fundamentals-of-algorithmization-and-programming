#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{

    setFixedSize(1500,800);

    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);

    timer2 = new QTimer();

    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    balloon = new Balloon(400,400,125,150);

    scene->addItem(balloon);

    connect(ui->pushToMove, &QPushButton::pressed, balloon, &Balloon::startFly);
    connect(ui->pushToMove, &QPushButton::released, balloon, &Balloon::stopFly);

    connect(ui->burst, &QPushButton::clicked, this, &MainWindow::startBurst);
    connect(balloon, &Balloon::stopTimer2, this, &MainWindow::stopBurst);

    connect(ui->fly_down, &QPushButton::pressed, balloon, &Balloon::startFlyDown);
    connect(ui->fly_down, &QPushButton::released, balloon, &Balloon::stopFlyDown);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startBurst(){
    connect(timer2, &QTimer::timeout, this, &MainWindow::burst);
    connect(timer2, &QTimer::timeout, balloon, &Balloon::burst);
    timer2->start(50);
}

void MainWindow::burst(){;
    ui->graphicsView->viewport()->update();
}

void MainWindow::stopBurst(){
    disconnect(timer2, &QTimer::timeout, this, &MainWindow::burst);
    timer2->stop();
}

