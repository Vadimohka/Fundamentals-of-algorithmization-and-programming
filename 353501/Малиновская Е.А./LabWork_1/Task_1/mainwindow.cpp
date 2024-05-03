#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "telezhka.h"
#include <QGraphicsScene>
#pragma ones

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui -> graphicsView -> setScene(scene);
    rectangle = new telezhka(0, 0, 300, 200);
    scene -> addItem(rectangle);
    ui -> graphicsView -> setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    connect(ui -> pushButton, &QPushButton :: clicked, rectangle, &telezhka :: move_right);
    connect(ui -> pushButton_2, &QPushButton :: clicked, rectangle, &telezhka :: move_left);
}

MainWindow::~MainWindow()
{
    delete ui;
}
