#include "mainwindow.h"
#include "pavozka.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();


    ui->graphicsView->setScene(scene);
    pavozka *повозка = new pavozka;
    scene->addItem(повозка);
    connect(ui->pushButtonMoveLeft ,&QPushButton::clicked,повозка,  &object::MoveLeft);
     connect(ui->pushButtonRight ,&QPushButton::clicked,повозка,  &object::MoveRight);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButtonMoveLeft_clicked()
{

}


void MainWindow::on_pushButtonRight_clicked()
{

}

