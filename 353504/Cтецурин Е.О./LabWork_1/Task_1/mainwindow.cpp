#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    door = new Door(this);
    door -> move (450,150);
    window1 = new Window(this);
    window1 ->move (150,150);
    window2 = new Window(this);
    window2 -> move (250,150);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::gray);
    painter.drawRect(50, 100, 700, 400);
    // Рисуем крышу
    QPolygon roof;
    roof << QPoint(50, 100) << QPoint(750, 100) << QPoint(400, 0);
    painter.setBrush(Qt::darkGray);
    painter.drawPolygon(roof);
    // дверь и окна
    painter.setPen(Qt::black);
    painter.setBrush(Qt::white);
    painter.drawRect(449, 149, 201, 351);
    painter.drawRect(149, 149, 201, 201);
}


void MainWindow::on_pushButton_clicked()
{
    if (!door->isOpen){
    QPropertyAnimation *animation = new QPropertyAnimation(door, "pos");
    animation->setDuration(1000);
    animation->setStartValue(door->pos());
    animation->setEndValue(QPoint(650, door->y()));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
    } else {
        QPropertyAnimation *animation = new QPropertyAnimation(door, "pos");
        animation->setDuration(1000);
        animation->setStartValue(door->pos());
        animation->setEndValue(QPoint(450, door->y()));
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    }
    door->toggle();
}


void MainWindow::on_pushButton_2_clicked()
{
    if (!window1->isOpenWin){
        QPropertyAnimation *animation = new QPropertyAnimation(window1, "pos");
        animation->setDuration(1000);
        animation->setStartValue(window1->pos());
        animation->setEndValue(QPoint(50, window1->y()));
        animation->start(QAbstractAnimation::DeleteWhenStopped);

        QPropertyAnimation *animation1 = new QPropertyAnimation(window2, "pos");
        animation1->setDuration(1000);
        animation1->setStartValue(window2->pos());
        animation1->setEndValue(QPoint(350, window2->y()));
        animation1->start(QAbstractAnimation::DeleteWhenStopped);
    } else {
        QPropertyAnimation *animation = new QPropertyAnimation(window1, "pos");
        animation->setDuration(1000);
        animation->setStartValue(window1->pos());
        animation->setEndValue(QPoint(150, window1->y()));
        animation->start(QAbstractAnimation::DeleteWhenStopped);

        QPropertyAnimation *animation1 = new QPropertyAnimation(window2, "pos");
        animation1->setDuration(1000);
        animation1->setStartValue(window2->pos());
        animation1->setEndValue(QPoint(250, window2->y()));
        animation1->start(QAbstractAnimation::DeleteWhenStopped);
    }
    window1->togglew();
}

