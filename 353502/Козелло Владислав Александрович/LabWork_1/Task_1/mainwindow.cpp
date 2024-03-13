#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Самолет");

    scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, 600,600);
    rectangle = new movingRect();
    plane = new Plane();
    ground = new Ground();

    ui->graphicsView->setScene(scene);

    scene->addItem(ground);
    scene->addItem(plane);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete plane;
    delete rectangle;
    delete scene;
    delete ground;
}


void MainWindow::on_UpButton_clicked()
{
    plane->moveUp();
    if(plane->y() <= 400)
    {
        plane->removeShassi();
    }
    else if(plane->y() <= 0)
    {

    }
}


void MainWindow::on_rightButton_clicked()
{
    plane->moveRight();
    if(plane->x() > 600)
    {
        plane->setPos(-350, plane->y());
    }
}


void MainWindow::on_downButton_clicked()
{
    if(plane->y() <= 400)
    {
        plane->moveDown();
        if(plane->y() >= 400)
        {
            plane->setShassi();
        }
    }
    else if(plane->y() >= 400)
    {
        plane->setShassi();
    }

}


void MainWindow::on_leftButton_clicked()
{
    plane->moveLeft();
    if(plane->x() <= -350)
    {
        plane->setPos(600, plane->y());
    }
}


void MainWindow::on_pushButton_clicked()
{
    close();
}
