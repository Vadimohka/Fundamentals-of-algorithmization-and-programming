#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    actionGroup = new QActionGroup(this);
    ui->toolBar->setIconSize(QSize(50, 50));
    actionGroup->addAction(ui->actionRect);
    actionGroup->addAction(ui->actionSquare);
    actionGroup->addAction(ui->actionCircle);
    actionGroup->addAction(ui->actionTriangle90);
    actionGroup->addAction(ui->actionTriangle3);
    actionGroup->addAction(ui->actionHexagon);
    actionGroup->addAction(ui->actionRomb);
    actionGroup->addAction(ui->actionStar5);
    actionGroup->addAction(ui->actionStar6);
    actionGroup->addAction(ui->actionStar8);
    actionGroup->addAction(ui->actionEllipse);
    actionGroup->addAction(ui->actionMove);
    actionGroup->addAction(ui->actionDelete);
    actionGroup->addAction(ui->actionBroom);
    actionGroup->addAction(ui->actionRestart);
    actionGroup->addAction(ui->actionScale);
    actionGroup->addAction(ui->actionRotation);
    actionGroup->addAction(ui->actionLine);

    scene = new CustomScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);                // Устанавливаем сглаживание
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключаем скроллы по вертикали
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллы по горизонтали
    scene->setTypeFigure(13);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(100);

    timerInfo = new QTimer(this);
    connect(timerInfo, &QTimer::timeout, this, &MainWindow::setTextLabel);
    timerInfo->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotTimer()
{
    timer->stop();
    scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QMainWindow::resizeEvent(event);
}

void MainWindow::setTextLabel()
{
    ui->label->setText("Center: (" + QString::number(scene->getXCenter()) + ", " +
        QString::number(scene->getYCenter()) + ")               Square: " + QString::number(scene->getSFigure())
            + "               Perimeter:" + QString::number(scene->getPFigure()));
}

void MainWindow::on_actionRect_triggered()
{
    scene->setTypeFigure(0);
}

void MainWindow::on_actionRomb_triggered()
{
    scene->setTypeFigure(1);
}

void MainWindow::on_actionTriangle3_triggered()
{
    scene->setTypeFigure(2);
}


void MainWindow::on_actionEllipse_triggered()
{
   scene->setTypeFigure(3);
}


void MainWindow::on_actionCircle_triggered()
{
    scene->setTypeFigure(4);
}


void MainWindow::on_actionSquare_triggered()
{
    scene->setTypeFigure(5);
}


void MainWindow::on_actionHexagon_triggered()
{
    scene->setTypeFigure(6);
}


void MainWindow::on_actionTriangle90_triggered()
{
    scene->setTypeFigure(7);
}


void MainWindow::on_actionStar5_triggered()
{
    scene->setTypeFigure(8);
}


void MainWindow::on_actionStar6_triggered()
{
    scene->setTypeFigure(9);
}


void MainWindow::on_actionStar8_triggered()
{
    scene->setTypeFigure(10);
}

void MainWindow::on_actionMove_triggered()
{
    scene->setTypeFigure(11);
}

void MainWindow::on_actionDelete_triggered()
{
    scene->setTypeFigure(12);
}

void MainWindow::on_actionBroom_triggered()
{
    scene->setTypeFigure(13);
}

void MainWindow::on_actionRestart_triggered()
{
    scene->setTypeFigure(14);
}

void MainWindow::on_actionScale_triggered()
{
    scene->setTypeFigure(15);
}

void MainWindow::on_actionRotation_triggered()
{
    scene->setTypeFigure(16);
}

void MainWindow::on_actionLine_triggered()
{
    scene->setTypeFigure(17);
}

