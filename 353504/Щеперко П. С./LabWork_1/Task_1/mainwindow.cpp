#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cart = new Cart(this);
    cart->move(725, 450);

    size1 = this->size();

    animationTimer = new QTimer(this);
    animationTimer2 = new QTimer(this);

    animationTimer = new QTimer(this);
    animationTimer2 = new QTimer(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.translate(0, 600);
    painter.drawLine(QPoint(0, 0), QPoint(1920, 0));

}

void MainWindow::on_moveCart_clicked()
{
    disconnect(animationTimer2, &QTimer::timeout, cart, &Cart::moveBackCart);
    disconnect(animationTimer, &QTimer::timeout, cart, &Cart::moveCart);
    animationTimer->start(1000/60);
    connect(animationTimer, &QTimer::timeout, cart, &Cart::moveCart);
}


void MainWindow::on_moveCartBackward_clicked()
{
    disconnect(animationTimer2, &QTimer::timeout, cart, &Cart::moveBackCart);
    disconnect(animationTimer, &QTimer::timeout, cart, &Cart::moveCart);
    animationTimer2->start(1000/60);
    connect(animationTimer2, &QTimer::timeout, cart, &Cart::moveBackCart);
}

