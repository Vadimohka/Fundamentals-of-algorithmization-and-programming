#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    rectangle = new Rectangle(100,100,50,25);
    scene->addItem(rectangle);
    QBrush brush(Qt::yellow);
    rectangle->setBrush(brush);

    ship = new Ship(100,100,50,25);
    sea = new Sea(0,300,00,00);

    scene->addItem(ship);
scene->addItem(sea);
    connect(ui->pushButton, &QPushButton::clicked, rectangle, &Rectangle::move);
    connect(ui->pushButton_2, &QPushButton::clicked, rectangle, &Rectangle::move_up);
}

MainWindow::~MainWindow()
{
    delete ui;
}



