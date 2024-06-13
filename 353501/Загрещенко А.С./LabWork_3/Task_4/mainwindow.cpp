#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), scene(new QGraphicsScene(this)), towerOfHanoi(new towers())
{
    ui->setupUi(this);
    towerOfHanoi = new towers();
    ui->graphicsView->setScene(scene);
    scene->addItem(towerOfHanoi);
    ui->restart->hide();
    
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    connect(ui->start, &QPushButton::clicked, this, &MainWindow::startClicked);
    connect(ui->restart, &QPushButton::clicked, this, &MainWindow::RestartClicked);
    connect(ui->speed, &QSpinBox::valueChanged, this, &MainWindow::ValueOfSpin);

 
    //connect(ui->stop, &QPushButton::clicked, this, &MainWindow::stopClicked);
    
    ui->restart->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete towerOfHanoi;
}

void MainWindow::startClicked()
{
    towerOfHanoi->isChanging = false;
    towerOfHanoi->lastEmptyPositionA -= towerOfHanoi->posN[towerOfHanoi->getN() - 1];
    towerOfHanoi->lastEmptyPositionB -= towerOfHanoi->posN[towerOfHanoi->getN() - 1];
    towerOfHanoi->lastEmptyPositionC -= towerOfHanoi->posN[towerOfHanoi->getN() - 1];
    ui->start->hide();
    ui->label->hide();
    ui->speed->hide();
  
    start(towerOfHanoi->getN(), 0, 1, 2);
    if(!towerOfHanoi->isChanging){
        ui->restart->show();
    }
}

void MainWindow::onSpinBoxValueChanged(int arg1)
{
    towerOfHanoi->changeNumberOfRings(arg1);
}

void MainWindow::RestartClicked()
{
    if(!towerOfHanoi->isChanging){
        towerOfHanoi->isChanging = true;
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
  
    towerOfHanoi->finished = false;
    while(!towerOfHanoi->finished){
        towerOfHanoi->animate(10 - number,source,target);
        QCoreApplication::processEvents();
    }
    
  
    if (source == 0) towerOfHanoi->lastEmptyPositionA += 20;
    if (source == 1) towerOfHanoi->lastEmptyPositionB += 20;
    if (source == 2) towerOfHanoi->lastEmptyPositionC += 20;
    update();
}

void MainWindow::ValueOfSpin(int arg){
    N  = arg;
    towerOfHanoi->getn(N);
    QCoreApplication::processEvents();
    update();
}
