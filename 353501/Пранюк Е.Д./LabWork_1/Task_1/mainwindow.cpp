#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    rect = new Rect();
    scene->addItem(rect);

    ship=new Ship();
    scene->addItem(ship);

    auto *buttonUp = new QPushButton("Up ↑", this);
    connect(buttonUp, &QPushButton::clicked, rect, &Rect::moveUp);
    buttonUp->setGeometry(50,40,100,50);

    auto *button = new QPushButton("Down ↓", this);
    connect(button, &QPushButton::clicked, rect, &Rect::moveDown);
    button->setGeometry(50,100,100,50);

    auto *buttonClose = new QPushButton("Close ✞", this);
    connect(buttonClose, SIGNAL(clicked(bool)), SLOT(closed()));
    buttonClose->setGeometry(50,160,100,50);

    this->setFixedSize(750, 600);
    setWindowTitle("Lab 1 Task 1");
}

void MainWindow::closed() {
    close();
}

MainWindow::~MainWindow()
{
    delete rect;
}
