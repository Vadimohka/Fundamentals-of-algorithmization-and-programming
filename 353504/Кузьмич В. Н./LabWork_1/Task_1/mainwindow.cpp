#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    object = new rectangle;
    object2 = new truck;
    scene->addItem(object);
    scene->addItem(object2);
    timer = new QTimer(this);
    ui->graphicsView->viewport()->update();
}

void MainWindow::on_pushButton_2_clicked()
{
    close();
}


void MainWindow::on_per_left_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(fun_left()));
    timer->stop();
}


void MainWindow::on_per_left_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(fun_left()));
    timer->start(8);
}


void MainWindow::on_per_rigth_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(fun_right()));
    timer->stop();
}


void MainWindow::on_per_rigth_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(fun_right()));
    timer->start(8);
}

void MainWindow::fun_left(){
    object -> per_left();
    object2 -> per_left();
    ui->graphicsView->viewport()->update();
    if (object -> is_left()){
        ui -> label -> setText("НЕЛЬЗЯ сдвинуть влево!!!");
    }
    else if (!(object -> is_left()) && !(object -> is_right())){
        ui -> label -> setText("");
    }
}

void MainWindow::fun_right(){
    object -> per_right();
    object2 -> per_right();
    ui->graphicsView->viewport()->update();
    if (object -> is_right()){
        ui -> label -> setText("НЕЛЬЗЯ сдвинуть вправо!!!");
    }
    else if (!(object -> is_left()) && !(object -> is_right())){
        ui -> label -> setText("");
    }
}

