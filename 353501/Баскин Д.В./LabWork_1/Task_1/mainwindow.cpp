#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer();
    scene = new QGraphicsScene();
    wheel = new RotatingWheel();
    road = new Road();
    scene->addItem(wheel);
    scene->addItem(road);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::moveLeft_slot()
{
    wheel->moveLeft();
}

void MainWindow::moveRight_slot()
{
    wheel->moveRight();
}

void MainWindow::rotateLeft_slot()
{
    wheel->rotateLeft();
}

void MainWindow::rotateRight_slot()
{
    wheel->rotateRight();
}

void MainWindow::on_pushButton_moveLeft_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(moveLeft_slot()));
    connect(timer, SIGNAL(timeout()), this, SLOT(rotateLeft_slot()));
    timer->start(16);
}

void MainWindow::on_pushButton_moveLeft_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveLeft_slot()));
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotateLeft_slot()));
    timer->stop();
}

void MainWindow::on_pushButton_moveRight_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(moveRight_slot()));
    connect(timer, SIGNAL(timeout()), this, SLOT(rotateRight_slot()));
    timer->start(16);
}

void MainWindow::on_pushButton_moveRight_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveRight_slot()));
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotateRight_slot()));
    timer->stop();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_A:
        on_pushButton_moveLeft_pressed();
        break;
    case Qt::Key_D:
        on_pushButton_moveRight_pressed();
        break;
    default:
        break;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_A:
        on_pushButton_moveLeft_released();
        break;
    case Qt::Key_D:
        on_pushButton_moveRight_released();
        break;
    default:
        break;
    }
}
