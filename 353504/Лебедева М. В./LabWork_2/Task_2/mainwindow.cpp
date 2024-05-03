include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Wheel *wheel = new Wheel();
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->addItem(wheel);

    connect(ui->pushButton, &QPushButton::clicked, wheel, &Wheel::right);
    connect(ui->pushButton_2, &QPushButton::clicked, wheel, &Wheel::left);
    connect(ui->pushButton_3, &QPushButton::clicked, wheel, &Wheel::rotateRight);
    connect(ui->pushButton_4, &QPushButton::clicked, wheel, &Wheel::rotateLeft);

}
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Wheel *wheel = new Wheel();
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->addItem(wheel);

    connect(ui->pushButton, &QPushButton::clicked, wheel, &Wheel::right);
    connect(ui->pushButton_2, &QPushButton::clicked, wheel, &Wheel::left);
    connect(ui->pushButton_3, &QPushButton::clicked, wheel, &Wheel::rotateRight);
    connect(ui->pushButton_4, &QPushButton::clicked, wheel, &Wheel::rotateLeft);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}


void MainWindow::on_pushButton_2_clicked()
{

}


void MainWindow::on_pushButton_3_clicked()
{

}


void MainWindow::on_pushButton_4_clicked()
{

}
