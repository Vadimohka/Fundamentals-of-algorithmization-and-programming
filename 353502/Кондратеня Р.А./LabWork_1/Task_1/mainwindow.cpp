#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    dump_truck = new Dump_Truck();
    ui -> graphicsView -> setScene(scene);
    ui -> graphicsView -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui -> graphicsView -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene -> addItem(dump_truck);
    scene -> addItem(dump_truck -> Rect_1);
    QColor* color = new QColor(Qt::yellow);
    QBrush brush(*color);
    dump_truck -> Rect_1 -> setBrush(brush);


        QPen pen;

        dump_truck -> road -> setZValue(0);
        dump_truck -> sky -> setZValue(0);
        dump_truck -> sun -> setZValue(1);
        dump_truck -> Rect_1 -> setZValue(3);
        dump_truck -> Rect_2 -> setZValue(1);
        dump_truck -> Rect_3 -> setZValue(1);
        dump_truck -> Disk_1 -> setZValue(2);
        dump_truck -> Disk_2 -> setZValue(2);
        dump_truck -> Light_2 -> setZValue(2);
        dump_truck -> Window -> setZValue(2);
        dump_truck -> Wheel_1 -> setZValue(1);
        dump_truck -> Wheel_2 -> setZValue(1);

        dump_truck -> road -> stackBefore(dump_truck -> Rect_2);
        dump_truck -> road -> stackBefore(dump_truck -> Rect_1);
        dump_truck -> road -> stackBefore(dump_truck -> Rect_3);
        dump_truck -> road -> stackBefore(dump_truck -> Light_2);
        dump_truck -> road -> stackBefore(dump_truck -> Wheel_1);
        dump_truck -> road -> stackBefore(dump_truck -> Wheel_2);
        dump_truck -> road -> stackBefore(dump_truck -> Disk_1);
        dump_truck -> road -> stackBefore(dump_truck -> Disk_2);

        dump_truck -> sky -> stackBefore(dump_truck -> sun);
        dump_truck -> sky -> stackBefore(dump_truck -> Rect_1);
        dump_truck -> sky -> stackBefore(dump_truck -> Rect_3);

        dump_truck -> Rect_2 -> stackBefore(dump_truck -> Wheel_1);
        dump_truck -> Rect_2 -> stackBefore(dump_truck -> Wheel_2);
        dump_truck -> Rect_2 -> stackBefore(dump_truck -> Disk_1);
        dump_truck -> Rect_2 -> stackBefore(dump_truck -> Disk_2);

        dump_truck -> Wheel_1 -> stackBefore(dump_truck -> Disk_1);
        dump_truck -> Wheel_2 -> stackBefore(dump_truck -> Disk_2);

        QPen roadPen(Qt::black);
        QBrush roadBrush(Qt::darkGray);
        dump_truck -> road = scene -> addRect(0, 405, 1571, 406, roadPen, roadBrush);

        QBrush skyBrush(QColor(62, 178, 247));
        dump_truck -> sky = scene -> addRect(0, 0, 1571, 405, roadPen, skyBrush);

        QPen sunPen(Qt::yellow);
        QBrush sunBrush(Qt::yellow);
        dump_truck -> sun = scene -> addEllipse(1350, 50, 100, 100, sunPen, sunBrush);

        QPen Rect_2Pen(Qt::black);
        QBrush Rect_2Brush(QColor(171, 9, 23));
        dump_truck -> Rect_2 = scene -> addRect(960, 255, 130, 225, Rect_2Pen, Rect_2Brush);

        QPen Rect_3Pen(Qt::black);
        QBrush Rect_3Brush(QColor(171, 9, 23));
        dump_truck -> Rect_3 = scene -> addRect(710, 375, 250, 105, Rect_3Pen, Rect_3Brush);

        QPen WindowPen(Qt::black);
        QBrush WindowBrush(QColor(8, 36, 226));
        dump_truck -> Window = scene -> addRect(1030, 275, 60, 50, WindowPen, WindowBrush);

        QPen Light_2Pen(Qt::black);
        QBrush Light_2Brush(QColor(240, 184, 10));
        dump_truck -> Light_2 = scene -> addEllipse(1065, 405, 20, 20, Light_2Pen, Light_2Brush);

        QPen WheelPen(Qt::black);
        QBrush WheelBrush(QColor(0, 0, 0));
        dump_truck -> Wheel_1 = scene -> addEllipse(740, 430, 100, 100, WheelPen, WheelBrush);
        dump_truck -> Wheel_2 = scene -> addEllipse(965, 430, 100, 100, WheelPen, WheelBrush);

        QPen DiskPen(QColor(240, 240, 234));
        QBrush DiskBrush(QColor(240, 240, 234));
        dump_truck -> Disk_1 = scene -> addEllipse(765, 455, 50, 50, DiskPen, DiskBrush);
        dump_truck -> Disk_2 = scene -> addEllipse(990, 455, 50, 50, DiskPen, DiskBrush);

        scene -> addItem(dump_truck -> Rect_1);
        scene -> addItem(dump_truck -> Rect_2);
        scene -> addItem(dump_truck -> Rect_3);
        scene -> addItem(dump_truck -> Window);
        scene -> addItem(dump_truck -> Disk_1);
        scene -> addItem(dump_truck -> Disk_2);
        scene -> addItem(dump_truck -> Light_2);
        scene -> addItem(dump_truck -> Wheel_1);
        scene -> addItem(dump_truck -> Wheel_2);
        scene -> addItem(dump_truck -> sky);
        scene -> addItem(dump_truck -> road);
        scene -> addItem(dump_truck -> sun);

        ui -> Body_down -> setCursor(Qt::PointingHandCursor);
        ui -> Body_up -> setCursor(Qt::PointingHandCursor);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Body_up_clicked()
{
    ui -> Body_down -> setEnabled(false);
        if(once_clicked) {
            once_clicked = false;
            dump_truck->Move_Up();
                ui -> Body_down -> setEnabled(false);
                ui -> Body_up -> setEnabled(false);
        }
            ui -> Body_up -> setText("Кузов поднимается");
            ui -> Body_down -> setText("Кузов поднимается");
            ui -> Body_up -> setCursor(Qt::ForbiddenCursor);
            QApplication::setOverrideCursor(Qt::ForbiddenCursor);

            QTimer* timer = new QTimer(this);
            int seconds = 2460;
            timer -> setSingleShot(true);

            connect(timer, &QTimer::timeout, this, [=]() {
                QApplication::restoreOverrideCursor();
                ui -> Body_up -> setText("Кузов поднялся");
                ui -> Body_down -> setText("Опустить кузов");
                ui -> Body_down -> setEnabled(true);
                ui -> Body_up -> setEnabled(false);
                once_clicked = true;

            });
            timer -> start(seconds);
}


void MainWindow::on_Body_down_clicked()
{
    ui -> Body_up -> setEnabled(false);
        if(once_clicked) {
            once_clicked = false;
            dump_truck -> Move_Down();
                ui -> Body_down -> setEnabled(false);
                ui -> Body_up -> setEnabled(false);
            }

            ui -> Body_up -> setText("Кузов опускается");
            ui -> Body_down -> setText("Кузов опускается");
            ui -> Body_up -> setCursor(Qt::ForbiddenCursor);
            QApplication::setOverrideCursor(Qt::ForbiddenCursor);

            QTimer* timer = new QTimer(this);
            int seconds = 2460;
            timer -> setSingleShot(true);

            connect(timer, &QTimer::timeout, this, [=]() {
                QApplication::restoreOverrideCursor();
                ui -> Body_up -> setText("Поднять кузов");
                ui -> Body_down -> setText("Кузов опустился");
                ui -> Body_down -> setEnabled(false);
                ui -> Body_up -> setEnabled(true);
                once_clicked = true;

            });
            timer -> start(seconds);
}


