#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), scene(new QGraphicsScene(this)), towerOfHanoi(new towers())
{
    ui->setupUi(this);
    towerOfHanoi = new towers();
    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(QColor(255, 194, 215));
    scene->addItem(towerOfHanoi);
    ui->restart->hide();

    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    connect(ui->start, &QPushButton::clicked, this, &MainWindow::startClicked);
    connect(ui->restart, &QPushButton::clicked, this, &MainWindow::RestartButClicked);
    //connect(ui->speed, &QSpinBox::valueChanged, this, &MainWindow::ValueOfSpin);
    ui->restart->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete towerOfHanoi;
}

void MainWindow::startClicked()
{
    towerOfHanoi->change = false;
    towerOfHanoi->lastPositionA -= towerOfHanoi->posN[towerOfHanoi->getN() - 1];
    towerOfHanoi->lastPositionB -= towerOfHanoi->posN[towerOfHanoi->getN() - 1];
    towerOfHanoi->lastPositionC -= towerOfHanoi->posN[towerOfHanoi->getN() - 1];
    ui->start->hide();
    ui->label->hide();
    ui->speed->hide();
    // ui->restart->show();

    start(towerOfHanoi->getN(), 0, 1, 2);
    if(!towerOfHanoi->change){
        ui->restart->show();
    }
}

void MainWindow::onSpinBoxValueChanged(int arg1)
{
    towerOfHanoi->changeNumberOfRings(arg1);
}

void MainWindow::RestartButClicked()
{
    if(!towerOfHanoi->change){
        towerOfHanoi->change = true;
    }
    delete towerOfHanoi;
    scene->clear();

    towerOfHanoi = new towers();

    scene->addItem(towerOfHanoi);
    ui->label->show();
    ui->restart->hide();
    ui->start->show();
    ui->speed->show();
    ui->speed->setValue(3);
}

void MainWindow::start(int n, int source, int auxiliary, int target)
{
    QThread::msleep(150);
    if (n == 1)
    {
        moveDisc(n, source, target);
    }
    else
    {
        start(n - 1, source, target, auxiliary);
        moveDisc(n, source, target);
        start(n - 1, auxiliary, source, target);
    }
}


void MainWindow::moveDisc(int number, int source, int target)
{
    // Start the animation timer
    towerOfHanoi->finished = false;
    while(!towerOfHanoi->finished){
        towerOfHanoi->animate(10 - number,source,target);
        QCoreApplication::processEvents();
    }


    if (source == 0) towerOfHanoi->lastPositionA += 20;
    if (source == 1) towerOfHanoi->lastPositionB += 20;
    if (source == 2) towerOfHanoi->lastPositionC += 20;
    update();
}

void MainWindow::ValueOfSpin(int arg){
    N  = arg;
    towerOfHanoi->getn(N);
    QCoreApplication::processEvents();
    update();
}

void MainWindow::on_speed_valueChanged(int arg1)
{
    ValueOfSpin(arg1);
}

