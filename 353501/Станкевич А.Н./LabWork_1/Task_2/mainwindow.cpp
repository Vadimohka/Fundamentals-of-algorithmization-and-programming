#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsRectItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);


    m_menu = new QMenu(ui->menuButton);
    m_menu->addAction("Circle");
    m_menu->addAction("Square");
    m_menu->addAction("Triangle");
    m_menu->addAction("Rhombus");
    m_menu->addAction("Rectangle");
    m_menu->addAction("Hexagon");
    m_menu->addAction("Star5x");
    m_menu->addAction("Star6x");
    m_menu->addAction("Star8x");
    m_menu->addAction("Cross");

   ui->menuButton->setMenu(m_menu);



   connect(m_menu->actions()[0], &QAction::triggered, this, &MainWindow::handleCircleAction);
   connect(m_menu->actions()[1], &QAction::triggered, this, &MainWindow::handleSquareAction);
   connect(m_menu->actions()[2], &QAction::triggered, this, &MainWindow::handleTriangleAction);
   connect(m_menu->actions()[3], &QAction::triggered, this, &MainWindow::handleRhombusAction);
   connect(m_menu->actions()[4], &QAction::triggered, this, &MainWindow::handleRectangleAction);
   connect(m_menu->actions()[5], &QAction::triggered, this, &MainWindow::handleHexagonAction);
   connect(m_menu->actions()[6], &QAction::triggered, this, &MainWindow::handleStar5xAction);
   connect(m_menu->actions()[7], &QAction::triggered, this, &MainWindow::handleStar6xAction);
   connect(m_menu->actions()[8], &QAction::triggered, this, &MainWindow::handleStar8xAction);
   connect(m_menu->actions()[9], &QAction::triggered, this, &MainWindow::handleCrossAction);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_menuButton_clicked()
{

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);

    QPainter painter(this);
    rotation->setAxis(QVector3D(0, 0, 1));
    rotation->setAngle(rotationAngle);


    scene->clear();
    if (shouldDrawCircle == 1) {
        QGraphicsItem* item = scene->addEllipse(0 + xCoordinate,0 + yCoordinate, 100, 100);
        double rotationAngleDegrees = rotationAngle; // Например, поворот на 45 градусов
        item->setRotation(rotationAngleDegrees);

    } else if (shouldDrawCircle == 2) {
        QGraphicsRectItem* rectItem = scene->addRect(-50 + xCoordinate,50 + yCoordinate, 100, 100);
        double rotationAngleDegrees = rotationAngle;
        rectItem->setRotation(rotationAngleDegrees);


    }
    else if (shouldDrawCircle == 3) {
        // Рисование треугольника
        QPolygon pol;
        pol << QPoint(0,0) << QPoint(50,100) << QPoint(-65, 90);
        QGraphicsItem* item = scene->addPolygon(pol);
        double rotationAngleDegrees = rotationAngle;
        item->setRotation(rotationAngleDegrees);

    }
    else if (shouldDrawCircle == 4) {


        // Рисование ромб
        QPolygon rhombus;
        rhombus << QPoint(-40 + xCoordinate, 0+ yCoordinate) << QPoint(0+ xCoordinate, 60+ yCoordinate) << QPoint(40+ xCoordinate, 0+ yCoordinate) << QPoint(0+ xCoordinate, -60+ yCoordinate);
        QGraphicsItem* item = scene->addPolygon(rhombus);
        double rotationAngleDegrees = rotationAngle;
        item->setRotation(rotationAngleDegrees);


    }
    else if (shouldDrawCircle == 5) {
        // Рисование прямоугольник
        QPolygon rect;
        rect << QPoint(-40+ xCoordinate, -20+ yCoordinate) << QPoint(40+ xCoordinate, -20+ yCoordinate) << QPoint(40+ xCoordinate, 20+ yCoordinate) << QPoint(-40+ xCoordinate, 20+ yCoordinate);
        QGraphicsItem* item = scene->addPolygon(rect);
        double rotationAngleDegrees = rotationAngle;
        item->setRotation(rotationAngleDegrees);


    }
    else if (shouldDrawCircle == 6) {
        QPolygon rect;
        rect << QPoint(-25+ xCoordinate, 40+ yCoordinate) << QPoint(25+ xCoordinate, 40+ yCoordinate) << QPoint(50+ xCoordinate, 0+ yCoordinate)
             << QPoint(25+ xCoordinate, -40+ yCoordinate) << QPoint(-25+ xCoordinate, -40+ yCoordinate) << QPoint(-50+ xCoordinate, 0+ yCoordinate);
        QGraphicsItem* item = scene->addPolygon(rect);
        double rotationAngleDegrees = rotationAngle;
        item->setRotation(rotationAngleDegrees);


    }
    else if (shouldDrawCircle == 7) {
        QPolygon rect;
        rect << QPoint(-20+ xCoordinate, 30+ yCoordinate) << QPoint(0+ xCoordinate, 15+ yCoordinate) << QPoint(20+ xCoordinate, 30+ yCoordinate)
             << QPoint(10+ xCoordinate, 5+ yCoordinate) << QPoint(40+ xCoordinate, -10+ yCoordinate) << QPoint(7+ xCoordinate, -10+ yCoordinate)
            << QPoint(0+ xCoordinate, -25+ yCoordinate) << QPoint(-7+ xCoordinate, -10+ yCoordinate) << QPoint(-40+ xCoordinate, -10+ yCoordinate)
             << QPoint(-10+ xCoordinate, 5+ yCoordinate)<< QPoint(-20+ xCoordinate, 30+ yCoordinate);



        painter.drawPolygon(rect);
        QGraphicsItem* item = scene->addPolygon(rect);
        double rotationAngleDegrees = rotationAngle;
        item->setRotation(rotationAngleDegrees);

    }
    else if (shouldDrawCircle == 8) {
        // Рисование не знаю
        QPolygon rect;
        rect << QPoint(-20 + xCoordinate, 30 + yCoordinate)
<< QPoint(0 + xCoordinate, 15 + yCoordinate)
<< QPoint(20 + xCoordinate, 30 + yCoordinate)
<< QPoint(10 + xCoordinate, 5 + yCoordinate)
<< QPoint(40 + xCoordinate, -10 + yCoordinate)
<< QPoint(10+ xCoordinate, -5 + yCoordinate)
<< QPoint(20 + xCoordinate, -30 + yCoordinate)
            << QPoint(0 + xCoordinate, -15 + yCoordinate)
<< QPoint(-20 + xCoordinate, -30 + yCoordinate)
<< QPoint(-10+ xCoordinate, -5 + yCoordinate)
<< QPoint(-40 + xCoordinate, -10 + yCoordinate)
<< QPoint(-10 + xCoordinate, 5 + yCoordinate)
<< QPoint(-20 + xCoordinate, 30 + yCoordinate)
            ;

        QGraphicsItem* item = scene->addPolygon(rect);
        double rotationAngleDegrees = rotationAngle;
        item->setRotation(rotationAngleDegrees);

    }
    else if (shouldDrawCircle == 9) {
        // Рисование не знаю
        QPolygon rect;
        rect << QPoint(-20 + xCoordinate, 30 + yCoordinate)
             << QPoint(0 + xCoordinate, 15 + yCoordinate)
             << QPoint(20 + xCoordinate, 30 + yCoordinate)

            << QPoint(15 + xCoordinate, 15 + yCoordinate)
            << QPoint(35 + xCoordinate, 10 + yCoordinate)


             << QPoint(10 + xCoordinate, 5 + yCoordinate)
             << QPoint(40 + xCoordinate, -10 + yCoordinate)


             << QPoint(10+ xCoordinate, -5 + yCoordinate)
             << QPoint(20 + xCoordinate, -30 + yCoordinate)
             << QPoint(0 + xCoordinate, -15 + yCoordinate)


             << QPoint(-20 + xCoordinate, -30 + yCoordinate)
             << QPoint(-10+ xCoordinate, -5 + yCoordinate)
             << QPoint(-40 + xCoordinate, -10 + yCoordinate)
             << QPoint(-10 + xCoordinate, 5 + yCoordinate)
                         << QPoint(-35 + xCoordinate, 10 + yCoordinate)
                                    << QPoint(-15 + xCoordinate, 15 + yCoordinate)

             << QPoint(-20 + xCoordinate, 30 + yCoordinate)
            ;
        QGraphicsItem* item = scene->addPolygon(rect);
        double rotationAngleDegrees = rotationAngle;
        item->setRotation(rotationAngleDegrees);

    }
    else if (shouldDrawCircle == 10) {
        // Рисование не знаю
        QPolygon rect;
        rect << QPoint(-40+ xCoordinate, -20+ yCoordinate) << QPoint(40+ xCoordinate, 20+ yCoordinate);
        rect     << QPoint(40+ xCoordinate,-20+ yCoordinate) << QPoint(-40+ xCoordinate, 20+ yCoordinate);
        QGraphicsItem* item = scene->addPolygon(rect);
        double rotationAngleDegrees = rotationAngle;
        item->setRotation(rotationAngleDegrees);

    }


}

void MainWindow::handleCircleAction()
{

    ui->menuButton->setText("Circle");
    shouldDrawCircle = 1;
    perimetr = 2*3.14*50;
        QString p = QString::number(perimetr);
        ui->label_13->setText(p);

        Area = 7850;
    QString s = QString::number(Area);
        ui->label_14->setText(s);
    update();
}

void MainWindow::handleSquareAction()
{
    ui->menuButton->setText("Square");
    shouldDrawCircle = 2;
    perimetr = 300;
    QString p = QString::number(perimetr);
            ui->label_13->setText(p);
    Area = 5625;
    QString s = QString::number(Area);
    ui->label_14->setText(s);
    update();

}
void MainWindow::handleTriangleAction()
{
    ui->menuButton->setText("Triangle");
    shouldDrawCircle = 3;
    perimetr = 263.4;
    QString p = QString::number(perimetr);
            ui->label_13->setText(p);
    Area = 3277;
    QString s = QString::number(Area);
    ui->label_14->setText(s);
    update();

}

void MainWindow::handleRhombusAction()
{
ui->menuButton->setText("Rhombus");
    shouldDrawCircle = 4;
perimetr = 305;
QString p = QString::number(perimetr);
            ui->label_13->setText(p);
Area = 4355;
QString s = QString::number(Area);
ui->label_14->setText(s);
    update();
}

void MainWindow::handleRectangleAction()
{
ui->menuButton->setText("Rectangle");
    shouldDrawCircle = 5;
perimetr = 240;
QString p = QString::number(perimetr);
        ui->label_13->setText(p);
Area = 3200;
QString s = QString::number(Area);
ui->label_14->setText(s);
    update();
}
void MainWindow::handleHexagonAction()
{
ui->menuButton->setText("Hexagon");
    shouldDrawCircle = 6;
perimetr = 304.22;
QString p = QString::number(perimetr);
        ui->label_13->setText(p);
Area = 4863.3;
QString s = QString::number(Area);
ui->label_14->setText(s);
    update();
}
void MainWindow::handleStar5xAction()
{
ui->menuButton->setText("Star5x");
    shouldDrawCircle = 7;
perimetr = 178.7;
QString p = QString::number(perimetr);
        ui->label_13->setText(p);
Area = 2084.1;
QString s = QString::number(Area);
ui->label_14->setText(s);
    update();
}
void MainWindow::handleStar6xAction()
{
    ui->menuButton->setText("Star6x");
    shouldDrawCircle = 8;
    perimetr = 184.5;
    QString p = QString::number(perimetr);
            ui->label_13->setText(p);
    Area = 2478.8;
    QString s = QString::number(Area);
    ui->label_14->setText(s);
    update();
}
void MainWindow::handleStar8xAction()
{
    ui->menuButton->setText("Star8x");
    shouldDrawCircle = 9;
    perimetr = 207.3;
    QString p = QString::number(perimetr);
            ui->label_13->setText(p);
    Area = 2663;
    QString s = QString::number(Area);
    ui->label_14->setText(s);
    update();
}
void MainWindow::handleCrossAction()
{
ui->menuButton->setText("Cross");
    shouldDrawCircle = 10;
perimetr = 2*56.56+2*40;
QString p = QString::number(perimetr);
        ui->label_13->setText(p);
Area = 2478.8;
QString s = QString::number(Area);
ui->label_14->setText(s);
    update();
}


void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    xCoordinate = arg1;
    update();
}


void MainWindow::on_doubleSpinBox_2_valueChanged(double argY)
{
    yCoordinate = argY;
    update();

}



void MainWindow::on_doubleSpinBox_3_valueChanged(double arg)
{
    rotationAngle = arg;
    update();
}

void MainWindow::updateLabel() {
    QString labelText = QString("%1, %2").arg(CentralX).arg(CentralY);
    ui->label_12->setText(labelText);
}

void MainWindow::on_spinBox_2_valueChanged(int centery) {
    CentralY = centery;
    updateLabel();
    update();
}


void MainWindow::on_spinBox_valueChanged(int centerx) {
    CentralX = centerx;
    updateLabel();
    update();
}

