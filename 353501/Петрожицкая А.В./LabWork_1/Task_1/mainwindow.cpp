#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <qgraphicsscene.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), scene(new QGraphicsScene(this))
{
    ui->setupUi(this);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    this->setFixedSize(855,754);

    rect = new Rect();
    scene->addItem(rect);

    auto *buttonToFirst = new QPushButton("1", this);
    connect(buttonToFirst, &QPushButton::clicked, rect, &Rect::moveToFirst);
    buttonToFirst->setGeometry(720, 120, 51, 31);

    auto *buttonToSecond = new QPushButton("2", this);
    connect(buttonToSecond, &QPushButton::clicked, rect, &Rect::moveToSecond);
    buttonToSecond->setGeometry(720, 80, 51, 31);

    auto *buttonToThird = new QPushButton("3", this);
    connect(buttonToThird, &QPushButton::clicked, rect, &Rect::moveToThird);
    buttonToThird->setGeometry(720, 40, 51, 31);
}

MainWindow::~MainWindow()
{
    delete rect;
}
