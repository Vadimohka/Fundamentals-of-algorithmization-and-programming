#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "boat.h"


Boat* boat = new Boat();


MainWindow::MainWindow(QWidget *parent)  : QMainWindow(parent) , ui(new Ui::MainWindow){
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui -> graphicsView -> setScene(scene);
    ui -> graphicsView -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui -> graphicsView -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    QGraphicsRectItem* water = new QGraphicsRectItem(-400,-30,800,300);
    QGraphicsRectItem* sky = new QGraphicsRectItem(-400,-250,800,220);
    QGraphicsEllipseItem* sun = new QGraphicsEllipseItem(- 350, -240, 70, 70);
    QPen pen;


    water -> setZValue(0);
    boat -> Polygon -> setZValue(1);
    boat -> Rect_2 -> setZValue(1);
    boat -> Rect_1 -> setZValue(1);

    water -> stackBefore(boat -> Polygon);
    water -> stackBefore(boat -> Rect_2);
    water -> stackBefore(boat -> Rect_1);

    water -> setBrush(QColor(56, 146, 203));
    sky -> setBrush(QColor(164, 214, 245));
    sun -> setBrush(QColor(238, 255, 73));

    QConicalGradient Sky_Gradient;
    Sky_Gradient.setColorAt(0.0, Qt::blue);
    QGraphicsEffect* Sky_effect = new QGraphicsColorizeEffect();
    Sky_effect -> setEnabled(true);



    boat -> Polygon -> setBrush(QColor(185, 171, 27));
    boat -> Rect_2 -> setBrush(QColor(222, 214, 129));
    boat -> Rect_1 -> setBrush(Qt::white);


    scene -> addItem(boat -> Polygon);
    scene -> addItem(boat -> Rect_2);
    scene -> addItem(boat -> Rect_1);

    pen.setColor(QColor(56, 146, 203));
    water -> setPen(pen);
    scene -> addItem(water);

    pen.setColor(QColor(164, 214, 245));
    sky -> setPen(pen);
    scene -> addItem(sky);

    pen.setColor(QColor(238, 255, 73));
    sun -> setPen(pen);
    scene -> addItem(sun);

    once_clicked = true;

//    QGraphicsPathItem* Wave = new QGraphicsPathItem();
//    QPainterPath Wave_path;

//    Wave_path.moveTo(100, 100);
//    Wave_path.quadTo(117, 60, 150, 75);
//    Wave_path.moveTo(150, 75);
//    Wave_path.quadTo(120, 75, 120, 100);



//    Wave -> setPath(Wave_path);


//    scene -> addItem(Wave);


    ui -> graphicsView -> centerOn(boat -> Rect_2 -> x(),boat -> Rect_2 -> y() - 300);

    ui -> Sail_down -> setCursor(Qt::PointingHandCursor);
    ui -> Sail_up -> setCursor(Qt::PointingHandCursor);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Sail_down_clicked()
{


    ui -> Sail_up -> setEnabled(false);

    if(once_clicked) {
        once_clicked = false;
        if(boat -> Rect_1 -> y() >= 0 && boat -> Rect_1 -> y() <= 60){
            ui -> Sail_down -> setEnabled(false);
            ui -> Sail_up -> setEnabled(false);
        }

        boat -> Move_Down();

        ui -> Sail_down -> setText("Парус опускается");
        ui -> Sail_up -> setText("Парус опускается");
        ui -> Sail_down -> setCursor(Qt::ForbiddenCursor);
        QApplication::setOverrideCursor(Qt::ForbiddenCursor);

        QTimer* timer = new QTimer(this);
        int seconds = 2642;
        timer->setSingleShot(true);

        connect(timer, &QTimer::timeout, this, [=]() {
            QApplication::restoreOverrideCursor();
            ui -> Sail_down -> setText("Парус опустился");
            ui -> Sail_up -> setText("Поднять парус");
            ui -> Sail_up -> setEnabled(true);
            ui -> Sail_down -> setEnabled(false);
            once_clicked = true;

        });

        timer->start(seconds);
    }


}


void MainWindow::on_Sail_up_clicked()
{
    ui -> Sail_down -> setEnabled(false);
    if(once_clicked) {
        once_clicked = false;
        if(boat -> Rect_1 -> y() >= 0 && boat -> Rect_1 -> y() <= 120){
            ui -> Sail_down -> setEnabled(false);
            ui -> Sail_up -> setEnabled(false);
        }
        boat -> Move_Up();
        ui -> Sail_up -> setText("Парус поднимается");
        ui -> Sail_down -> setText("Парус поднимается");
        ui -> Sail_up -> setCursor(Qt::ForbiddenCursor);
        QApplication::setOverrideCursor(Qt::ForbiddenCursor);

        QTimer* timer = new QTimer(this);
        int seconds = 2642;
        timer->setSingleShot(true);

        connect(timer, &QTimer::timeout, this, [=]() {
            QApplication::restoreOverrideCursor();
            ui -> Sail_up -> setText("Парус поднялся");
            ui -> Sail_down -> setText("Опустить парус");
            ui -> Sail_down -> setEnabled(true);
            ui -> Sail_up -> setEnabled(false);
            once_clicked = true;

        });

        timer->start(seconds);
    }

}

void MainWindow::paintEvent(QPaintEvent* event) {
    QPainter painter(this);

//    QPainterPath path;
//    path.moveTo(500, 500);
//    path.arcTo(QRectF(50,50,50,50), 45, 200);

//    painter.drawPath(path);
}
