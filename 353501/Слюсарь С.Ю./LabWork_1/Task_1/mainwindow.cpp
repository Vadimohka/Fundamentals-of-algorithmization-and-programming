#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    car = new Car;
    scene->addItem(car);
    animationTimer = new QTimer(this);
    animationTimerBack = new QTimer(this);
    RightButton = new QPushButton("To Right", this);
    RightButton->setGeometry(200, 50, 100, 50);
    LeftButton = new QPushButton("To Left", this);
    LeftButton->setGeometry(100, 50, 100, 50);
    Lights = new QPushButton("Lights", this);
    Lights->setGeometry(300, 50, 100, 50);
    DoorOpen = new QPushButton("Door", this);
    DoorOpen->setGeometry(400, 50, 100, 50);
    connect(RightButton, &QPushButton::clicked, this, &MainWindow::RightButton_clicked);
    connect(LeftButton, &QPushButton::clicked, this, &MainWindow::LeftButton_clicked);
    connect(Lights, &QPushButton::clicked, car, &Car::lightsOnOff);
    connect(DoorOpen, &QPushButton::clicked, car, &Car::openDoor);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::RightButton_clicked()
{
    animationTimerBack->stop();
    animationTimer->start(1000/60);
    disconnect(animationTimer, &QTimer::timeout, car, &Car::move);
    connect(animationTimer, &QTimer::timeout, car, &Car::move);
}

void MainWindow::LeftButton_clicked()
{
    animationTimer->stop();
    animationTimerBack->start(1000/60);
    disconnect(animationTimerBack, &QTimer::timeout, car, &Car::moveBack);
    connect(animationTimerBack, &QTimer::timeout, car, &Car::moveBack);
}
