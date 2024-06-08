#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tower = new HanoiTower();
    ui->graphicsView->setScene(tower);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBoxDisks_valueChanged(int arg1)
{
    ui->listWidget->clear();
    tower->running = false;
    if(tower->movable != nullptr){
        while(tower->movable->timer->isActive()){
            QCoreApplication::processEvents();
        }
    }
    disksCount = arg1;
    tower->clear();
    tower->setHeight(arg1);
    ui->graphicsView->setScene(nullptr);
    ui->graphicsView->setScene(tower);
}


void MainWindow::on_pushButtonStart_clicked()
{
    ui->listWidget->clear();
    tower->running = false;
    if(tower->movable != nullptr){
        while(tower->movable->timer->isActive()){
            QCoreApplication::processEvents();
        }
    }
    tower->clear();
    tower->setHeight(disksCount);
    ui->graphicsView->setScene(nullptr);
    ui->graphicsView->setScene(tower);
    tower->running = true;
    tower->hanoi(disksCount, 'A', 'C', 'B');
    hanoi(disksCount, 'A', 'C', 'B');
}

void MainWindow::hanoi(int diskCount, QChar from, QChar to, QChar temp)
{
    if(tower->running){
        if(diskCount != 0){
            hanoi(diskCount - 1, from, temp, to);
            QString str(from + QString::fromStdString("->") + to);
            ui->listWidget->addItem(str);
            hanoi(diskCount - 1, temp, to, from);
        }
    }
}


void MainWindow::on_pushButtonReset_clicked()
{
    ui->listWidget->clear();
    tower->running = false;
    if(tower->movable != nullptr){
        while(tower->movable->timer->isActive()){
            QCoreApplication::processEvents();
        }
    }
    tower->clear();
    tower->setHeight(disksCount);
    ui->graphicsView->setScene(nullptr);
    ui->graphicsView->setScene(tower);
}

