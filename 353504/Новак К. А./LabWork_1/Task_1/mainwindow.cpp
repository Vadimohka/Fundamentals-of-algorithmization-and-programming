#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    x=0;y=0;a=100;b=200;
    down=false;

    timer = new QTimer(this);
    //qDebug() << 1;
    fflag.set(910,300,150,112);
    connect(timer, SIGNAL(timeout()), this, SLOT(Timer_slot()));
    flag=true;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    QBrush brush;
    brush.setColor(Qt::darkRed);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    QPolygon ship;
    ship << QPoint(700,800) << QPoint(1100,800) << QPoint(1300,600) << QPoint(1000,700) << QPoint(800,700) << QPoint(500,600);
    painter.drawPolygon(ship);

    brush.setColor(Qt::black);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    painter.drawRect(910,300,-20,400);

    fflag.draw(painter);
}

void MainWindow::Timer_slot()
{
    if (down) {
        if (fflag.gety()>=550) {
            flag=!flag;
            ui->pushButton_2->setText("start");
            timer->stop();
        } else {
            fflag.movedown();
        }
    } else {
        if (fflag.gety()<=300) {
            flag=!flag;
            ui->pushButton_2->setText("start");
            timer->stop();
        } else {
            fflag.moveup();
        }
    }
    repaint();
}


void MainWindow::on_pushButton_2_clicked()
{
    flag=!flag;
    if (flag) {
        ui->pushButton_2->setText("start");
        timer->stop();
    } else {
        ui->pushButton_2->setText("stop");
        timer->start(10);
    }
}


void MainWindow::on_pushButton_clicked()
{
    down=false;
    flag=false;
    ui->pushButton_2->setText("stop");
    timer->start(10);
}


void MainWindow::on_pushButton_3_clicked()
{
    down=true;
    flag=false;
    ui->pushButton_2->setText("stop");
    timer->start(10);
}

