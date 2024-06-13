#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height) : Figure()
{
    x_ = x;
    y_ = y;
    width_ = width;
    height_ = height;
}

Rectangle::~Rectangle()
{

}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);

    painter->save();
    painter->translate(x_ + width_ / 2.0, y_ + height_);
    painter->rotate(rotationAngle_);
    painter->setBrush(Qt::blue);
    painter->setPen(Qt::blue);
    painter->drawRect(x_, y_, width_ * scale_, height_ * scale_);
    painter->restore();
}

double Rectangle::area()
{
    return width_ * height_ * scale_;
}

double Rectangle::perimetr()
{
    return (width_ + height_) * 2.0 * scale_;
}

QPointF Rectangle::centerOfMass()
{
    xCenter_ = scale_ * (((x_ + (x_ + width_)) / 2.0) + stop_ + rotateCenterX);
    yCenter_ = scale_ * ((y_ + (y_ + height_)) / 2.0 + rotateCenterY);
    QPointF r;
    r.setX(xCenter_);
    r.setY(yCenter_);
    return r;
}

void Rectangle::move()
{
    if (stop_ <= 100) {
        moveBy(xspeed_, 0);
        stop_ += 2;
    }
}

void Rectangle::moveBack()
{
    if (stop_ >= -100) {
        moveBy(-xspeed_, 0);
        stop_ -= 2;
    }
}

void Rectangle::rotate()
{
    if (rotationAngle_ < 90)
    {
        ++rotationAngle_;
        update();
        rotateCenterX = -width_ / 4.0;
        rotateCenterY = height_ / 2.0;
    }
}
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, 782, 278);
    
    animationTimer = new QTimer(this);
    animationTimerBack = new QTimer(this);
    rotationAnim = new QTimer(this);
    rotationAnimBack = new QTimer(this);
    scaleAnim = new QTimer(this);
    scaleAnimBack = new QTimer(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPointF c = ui->graphicsView->mapToScene(event->pos());
    startX = c.x();
    startY = c.y();
    //scene->addEllipse(startX - 15, startY - 15, 10, 10, QPen(Qt::NoPen), QBrush(Qt::red));
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPointF c = ui->graphicsView->mapToScene(event->pos());
    endX = c.x();
    endY = c.y();
    scene->addLine(startX, startY, endX, endY, QPen(Qt::red, 10, Qt::SolidLine, Qt::RoundCap));
    startX = c.x();
    startY = c.y();
}

void MainWindow::on_toRight_clicked()
{   if(Error_==1){
        if (whoOnScene)
        {
            animationTimer->stop();
            animationTimerBack->start(1000/60);
            
            switch(whoOnScene) {
            case 1:
                disconnect(animationTimerBack, &QTimer::timeout, hex, &Hexagon::moveBack);
                connect(animationTimerBack, &QTimer::timeout, hex, &Hexagon::moveBack);
                break;
            case 2:
                disconnect(animationTimerBack, &QTimer::timeout, rect, &Rectangle::moveBack);
                connect(animationTimerBack, &QTimer::timeout, rect, &Rectangle::moveBack);
                break;
            case 3:
                disconnect(animationTimerBack, &QTimer::timeout, rhomb, &Rhomb::moveBack);
                connect(animationTimerBack, &QTimer::timeout, rhomb, &Rhomb::moveBack);
                break;
            case 4:
                disconnect(animationTimerBack, &QTimer::timeout, round, &Round::moveBack);
                connect(animationTimerBack, &QTimer::timeout, round, &Round::moveBack);
                break;
            case 5:
                disconnect(animationTimerBack, &QTimer::timeout, square, &Square::moveBack);
                connect(animationTimerBack, &QTimer::timeout, square, &Square::moveBack);
                break;
            case 6:
                disconnect(animationTimerBack, &QTimer::timeout, triangle, &Triangle::moveBack);
                connect(animationTimerBack, &QTimer::timeout, triangle, &Triangle::moveBack);
                break;
            case 7:
                disconnect(animationTimerBack, &QTimer::timeout, fivePointedStar, &FivePointedStar::moveBack);
                connect(animationTimerBack, &QTimer::timeout, fivePointedStar, &FivePointedStar::moveBack);
                break;
            case 8:
                disconnect(animationTimerBack, &QTimer::timeout, sixPointedStar, &SixPointedStar::moveBack);
                connect(animationTimerBack, &QTimer::timeout, sixPointedStar, &SixPointedStar::moveBack);
                break;
            case 9:
                disconnect(animationTimerBack, &QTimer::timeout, eightPointedStar, &EightPointedStar::moveBack);
                connect(animationTimerBack, &QTimer::timeout, eightPointedStar, &EightPointedStar::moveBack);
                break;
            }
        }
    }
}

void MainWindow::on_toLeft_clicked()
{if(Error_==1){
        if (whoOnScene)
        {
            animationTimerBack->stop();
            animationTimer->start(1000/60);
            
            switch(whoOnScene) {
            case 1:
                disconnect(animationTimer, &QTimer::timeout, hex, &Hexagon::move);
                connect(animationTimer, &QTimer::timeout, hex, &Hexagon::move);
                break;
            case 2:
                disconnect(animationTimer, &QTimer::timeout, rect, &Rectangle::move);
                connect(animationTimer, &QTimer::timeout, rect, &Rectangle::move);
                break;
            case 3:
                disconnect(animationTimer, &QTimer::timeout, rhomb, &Rhomb::move);
                connect(animationTimer, &QTimer::timeout, rhomb, &Rhomb::move);
                break;
            case 4:
                disconnect(animationTimer, &QTimer::timeout, round, &Round::move);
                connect(animationTimer, &QTimer::timeout, round, &Round::move);
                break;
            case 5:
                disconnect(animationTimer, &QTimer::timeout, square, &Square::move);
                connect(animationTimer, &QTimer::timeout, square, &Square::move);
                break;
            case 6:
                disconnect(animationTimer, &QTimer::timeout, triangle, &Triangle::move);
                connect(animationTimer, &QTimer::timeout, triangle, &Triangle::move);
                break;
            case 7:
                disconnect(animationTimer, &QTimer::timeout, fivePointedStar, &FivePointedStar::move);
                connect(animationTimer, &QTimer::timeout, fivePointedStar, &FivePointedStar::move);
                break;
            case 8:
                disconnect(animationTimer, &QTimer::timeout, sixPointedStar, &SixPointedStar::move);
                connect(animationTimer, &QTimer::timeout, sixPointedStar, &SixPointedStar::move);
                break;
            case 9:
                disconnect(animationTimer, &QTimer::timeout, eightPointedStar, &EightPointedStar::move);
                connect(animationTimer, &QTimer::timeout, eightPointedStar, &EightPointedStar::move);
            }
        }
    }
}

void MainWindow::on_Hexagon_clicked()
{   Error_ = 1;
    hex = new Hexagon;
    scene->clear();
    scene->addItem(hex);
    hex->setPos(QPoint(150, 100));
    whoOnScene = 1;
}


void MainWindow::on_Rectangle_clicked()
{
    Error_ = 1;
    rect = new Rectangle;
    scene->clear();
    rect->setPos(QPoint(150, 100));
    scene->addItem(rect);
    whoOnScene = 2;
}


void MainWindow::on_Rhomb_clicked()
{
    Error_ = 1;
    rhomb = new Rhomb;
    scene->clear();
    rhomb->setPos(QPoint(150, 100));
    scene->addItem(rhomb);
    whoOnScene = 3;
}

void MainWindow::on_Round_clicked()
{
    Error_ = 1;
    round = new Round;
    scene->clear();
    round->setPos(QPoint(150, 100));
    scene->addItem(round);
    whoOnScene = 4;
}

void MainWindow::on_Square_clicked()
{
    Error_ = 1;
    square = new Square;
    scene->clear();
    square->setPos(QPoint(150, 100));
    scene->addItem(square);
    whoOnScene = 5;
}

void MainWindow::on_Triangle_clicked()
{
    Error_ = 1;
    triangle = new Triangle;
    scene->clear();
    triangle->setPos(QPoint(150, 100));
    scene->addItem(triangle);
    whoOnScene = 6;
}

void MainWindow::on_FivePointedStar_clicked()
{
    Error_ = 1;
    fivePointedStar = new FivePointedStar;
    scene->clear();
    fivePointedStar->setPos(QPoint(150, 100));
    scene->addItem(fivePointedStar);
    whoOnScene = 7;
}

void MainWindow::on_SixPointedStar_clicked()
{
    Error_ = 1;
    sixPointedStar = new SixPointedStar;
    scene->clear();
    sixPointedStar->setPos(QPoint(150, 100));
    scene->addItem(sixPointedStar);
    whoOnScene = 8;
}

void MainWindow::on_EightPointedStar_clicked()
{
    Error_ = 1;
    eightPointedStar = new EightPointedStar;
    scene->clear();
    eightPointedStar->setPos(QPoint(150, 100));
    scene->addItem(eightPointedStar);
    whoOnScene = 9;
}

void MainWindow::on_Rotate_clicked()
{ if(Error_==1){
        if (whoOnScene)
        {
            
            rotationAnimBack->stop();
            rotationAnim->start(1000/60);
            switch(whoOnScene) {
            case 1:
                disconnect(rotationAnim, &QTimer::timeout, hex, &Hexagon::rotate);
                connect(rotationAnim, &QTimer::timeout, hex, &Hexagon::rotate);
                break;
            case 2:
                disconnect(rotationAnim, &QTimer::timeout, rect, &Rectangle::rotate);
                connect(rotationAnim, &QTimer::timeout, rect, &Rectangle::rotate);
                break;
            case 3:
                disconnect(rotationAnim, &QTimer::timeout, rhomb, &Rhomb::rotate);
                connect(rotationAnim, &QTimer::timeout, rhomb, &Rhomb::rotate);
                break;
            case 4:
                disconnect(rotationAnim, &QTimer::timeout, round, &Round::rotate);
                connect(rotationAnim, &QTimer::timeout, round, &Round::rotate);
                break;
            case 5:
                disconnect(rotationAnim, &QTimer::timeout, square, &Square::rotate);
                connect(rotationAnim, &QTimer::timeout, square, &Square::rotate);
                break;
            case 6:
                disconnect(rotationAnim, &QTimer::timeout, triangle, &Triangle::rotate);
                connect(rotationAnim, &QTimer::timeout, triangle, &Triangle::rotate);
                break;
            case 7:
                disconnect(rotationAnim, &QTimer::timeout, fivePointedStar, &FivePointedStar::rotate);
                connect(rotationAnim, &QTimer::timeout, fivePointedStar, &FivePointedStar::rotate);
                break;
            case 8:
                disconnect(rotationAnim, &QTimer::timeout, sixPointedStar, &SixPointedStar::rotate);
                connect(rotationAnim, &QTimer::timeout, sixPointedStar, &SixPointedStar::rotate);
                break;
            case 9:
                disconnect(rotationAnim, &QTimer::timeout, eightPointedStar, &EightPointedStar::rotate);
                connect(rotationAnim, &QTimer::timeout, eightPointedStar, &EightPointedStar::rotate);
                break;
                
            }
            
            
        }
    }
    
}


void MainWindow::on_RotateBack_clicked()
{if(Error_==1){
        if (whoOnScene)
        {
            rotationAnim->stop();
            rotationAnimBack->start(1000/60);
            switch(whoOnScene) {
            case 1:
                disconnect(rotationAnimBack, &QTimer::timeout, hex, &Hexagon::rotateBack);
                connect(rotationAnimBack, &QTimer::timeout, hex, &Hexagon::rotateBack);
                break;
            case 2:
                disconnect(rotationAnimBack, &QTimer::timeout, rect, &Rectangle::rotateBack);
                connect(rotationAnimBack, &QTimer::timeout, rect, &Rectangle::rotateBack);
                break;
            case 3:
                disconnect(rotationAnimBack, &QTimer::timeout, rhomb, &Rhomb::rotateBack);
                connect(rotationAnimBack, &QTimer::timeout, rhomb, &Rhomb::rotateBack);
                break;
            case 4:
                disconnect(rotationAnimBack, &QTimer::timeout, round, &Round::rotateBack);
                connect(rotationAnimBack, &QTimer::timeout, round, &Round::rotateBack);
                break;
            case 5:
                disconnect(rotationAnimBack, &QTimer::timeout, square, &Square::rotateBack);
                connect(rotationAnimBack, &QTimer::timeout, square, &Square::rotateBack);
                break;
            case 6:
                disconnect(rotationAnimBack, &QTimer::timeout, triangle, &Triangle::rotateBack);
                connect(rotationAnimBack, &QTimer::timeout, triangle, &Triangle::rotateBack);
                break;
            case 7:
                disconnect(rotationAnimBack, &QTimer::timeout, fivePointedStar, &FivePointedStar::rotateBack);
                connect(rotationAnimBack, &QTimer::timeout, fivePointedStar, &FivePointedStar::rotateBack);
                break;
            case 8:
                disconnect(rotationAnimBack, &QTimer::timeout, sixPointedStar, &SixPointedStar::rotateBack);
                connect(rotationAnimBack, &QTimer::timeout, sixPointedStar, &SixPointedStar::rotateBack);
                break;
            case 9:
                disconnect(rotationAnimBack, &QTimer::timeout, eightPointedStar, &EightPointedStar::rotateBack);
                connect(rotationAnimBack, &QTimer::timeout, eightPointedStar, &EightPointedStar::rotateBack);
            }
        }
    }
}

void MainWindow::on_ScaleChange_clicked()
{if(Error_==1){
        if (whoOnScene)
        {
            scaleAnimBack->stop();
            scaleAnim->start(1000/60);
            switch(whoOnScene) {
            case 1:
                disconnect(scaleAnim, &QTimer::timeout, hex, &Hexagon::scale);
                connect(scaleAnim, &QTimer::timeout, hex, &Hexagon::scale);
                break;
            case 2:
                disconnect(scaleAnim, &QTimer::timeout, rect, &Rectangle::scale);
                connect(scaleAnim, &QTimer::timeout, rect, &Rectangle::scale);
                break;
            case 3:
                disconnect(scaleAnim, &QTimer::timeout, rhomb, &Rhomb::scale);
                connect(scaleAnim, &QTimer::timeout, rhomb, &Rhomb::scale);
                break;
            case 4:
                disconnect(scaleAnim, &QTimer::timeout, round, &Round::scale);
                connect(scaleAnim, &QTimer::timeout, round, &Round::scale);
                break;
            case 5:
                disconnect(scaleAnim, &QTimer::timeout, square, &Square::scale);
                connect(scaleAnim, &QTimer::timeout, square, &Square::scale);
                break;
            case 6:
                disconnect(scaleAnim, &QTimer::timeout, triangle, &Triangle::scale);
                connect(scaleAnim, &QTimer::timeout, triangle, &Triangle::scale);
                break;
            case 7:#include "mainwindow.h"
#include "ui_mainwindow.h"
                    
                    MainWindow::MainWindow(QWidget *parent)
                    : QMainWindow(parent)
                    , ui(new Ui::MainWindow)
                {
                    ui->setupUi(this);
                    scene = new QGraphicsScene;
                    ui->graphicsView->setScene(scene);
                    scene->setSceneRect(0, 0, 782, 278);
                    
                    animationTimer = new QTimer(this);
                    animationTimerBack = new QTimer(this);
                    rotationAnim = new QTimer(this);
                    rotationAnimBack = new QTimer(this);
                    scaleAnim = new QTimer(this);
                    scaleAnimBack = new QTimer(this);
                }
                
                MainWindow::~MainWindow()
                {
                    delete ui;
                }
                
                void MainWindow::mousePressEvent(QMouseEvent *event)
                {
                    QPointF c = ui->graphicsView->mapToScene(event->pos());
                    startX = c.x();
                    startY = c.y();
                    //scene->addEllipse(startX - 15, startY - 15, 10, 10, QPen(Qt::NoPen), QBrush(Qt::red));
                }
                
                void MainWindow::mouseMoveEvent(QMouseEvent *event)
                {
                    QPointF c = ui->graphicsView->mapToScene(event->pos());
                    endX = c.x();
                    endY = c.y();
                    scene->addLine(startX, startY, endX, endY, QPen(Qt::red, 10, Qt::SolidLine, Qt::RoundCap));
                    startX = c.x();
                    startY = c.y();
                }
                
                void MainWindow::on_toRight_clicked()
                {   if(Error_==1){
                        if (whoOnScene)
                        {
                            animationTimer->stop();
                            animationTimerBack->start(1000/60);
                            
                            switch(whoOnScene) {
                            case 1:
                                disconnect(animationTimerBack, &QTimer::timeout, hex, &Hexagon::moveBack);
                                connect(animationTimerBack, &QTimer::timeout, hex, &Hexagon::moveBack);
                                break;
                            case 2:
                                disconnect(animationTimerBack, &QTimer::timeout, rect, &Rectangle::moveBack);
                                connect(animationTimerBack, &QTimer::timeout, rect, &Rectangle::moveBack);
                                break;
                            case 3:
                                disconnect(animationTimerBack, &QTimer::timeout, rhomb, &Rhomb::moveBack);
                                connect(animationTimerBack, &QTimer::timeout, rhomb, &Rhomb::moveBack);
                                break;
                            case 4:
                                disconnect(animationTimerBack, &QTimer::timeout, round, &Round::moveBack);
                                connect(animationTimerBack, &QTimer::timeout, round, &Round::moveBack);
                                break;
                            case 5:
                                disconnect(animationTimerBack, &QTimer::timeout, square, &Square::moveBack);
                                connect(animationTimerBack, &QTimer::timeout, square, &Square::moveBack);
                                break;
                            case 6:
                                disconnect(animationTimerBack, &QTimer::timeout, triangle, &Triangle::moveBack);
                                connect(animationTimerBack, &QTimer::timeout, triangle, &Triangle::moveBack);
                                break;
                            case 7:
                                disconnect(animationTimerBack, &QTimer::timeout, fivePointedStar, &FivePointedStar::moveBack);
                                connect(animationTimerBack, &QTimer::timeout, fivePointedStar, &FivePointedStar::moveBack);
                                break;
                            case 8:
                                disconnect(animationTimerBack, &QTimer::timeout, sixPointedStar, &SixPointedStar::moveBack);
                                connect(animationTimerBack, &QTimer::timeout, sixPointedStar, &SixPointedStar::moveBack);
                                break;
                            case 9:
                                disconnect(animationTimerBack, &QTimer::timeout, eightPointedStar, &EightPointedStar::moveBack);
                                connect(animationTimerBack, &QTimer::timeout, eightPointedStar, &EightPointedStar::moveBack);
                                break;
                            }
                        }
                    }
                }
                
                void MainWindow::on_toLeft_clicked()
                {if(Error_==1){
                        if (whoOnScene)
                        {
                            animationTimerBack->stop();
                            animationTimer->start(1000/60);
                            
                            switch(whoOnScene) {
                            case 1:
                                disconnect(animationTimer, &QTimer::timeout, hex, &Hexagon::move);
                                connect(animationTimer, &QTimer::timeout, hex, &Hexagon::move);
                                break;
                            case 2:
                                disconnect(animationTimer, &QTimer::timeout, rect, &Rectangle::move);
                                connect(animationTimer, &QTimer::timeout, rect, &Rectangle::move);
                                break;
                            case 3:
                                disconnect(animationTimer, &QTimer::timeout, rhomb, &Rhomb::move);
                                connect(animationTimer, &QTimer::timeout, rhomb, &Rhomb::move);
                                break;
                            case 4:
                                disconnect(animationTimer, &QTimer::timeout, round, &Round::move);
                                connect(animationTimer, &QTimer::timeout, round, &Round::move);
                                break;
                            case 5:
                                disconnect(animationTimer, &QTimer::timeout, square, &Square::move);
                                connect(animationTimer, &QTimer::timeout, square, &Square::move);
                                break;
                            case 6:
                                disconnect(animationTimer, &QTimer::timeout, triangle, &Triangle::move);
                                connect(animationTimer, &QTimer::timeout, triangle, &Triangle::move);
                                break;
                            case 7:
                                disconnect(animationTimer, &QTimer::timeout, fivePointedStar, &FivePointedStar::move);
                                connect(animationTimer, &QTimer::timeout, fivePointedStar, &FivePointedStar::move);
                                break;
                            case 8:
                                disconnect(animationTimer, &QTimer::timeout, sixPointedStar, &SixPointedStar::move);
                                connect(animationTimer, &QTimer::timeout, sixPointedStar, &SixPointedStar::move);
                                break;
                            case 9:
                                disconnect(animationTimer, &QTimer::timeout, eightPointedStar, &EightPointedStar::move);
                                connect(animationTimer, &QTimer::timeout, eightPointedStar, &EightPointedStar::move);
                            }
                        }
                    }
                }
                
                void MainWindow::on_Hexagon_clicked()
                {   Error_ = 1;
                    hex = new Hexagon;
                    scene->clear();
                    scene->addItem(hex);
                    hex->setPos(QPoint(150, 100));
                    whoOnScene = 1;
                }
                
                
                void MainWindow::on_Rectangle_clicked()
                {
                    Error_ = 1;
                    rect = new Rectangle;
                    scene->clear();
                    rect->setPos(QPoint(150, 100));
                    scene->addItem(rect);
                    whoOnScene = 2;
                }
                
                
                void MainWindow::on_Rhomb_clicked()
                {
                    Error_ = 1;
                    rhomb = new Rhomb;
                    scene->clear();
                    rhomb->setPos(QPoint(150, 100));
                    scene->addItem(rhomb);
                    whoOnScene = 3;
                }
                
                void MainWindow::on_Round_clicked()
                {
                    Error_ = 1;
                    round = new Round;
                    scene->clear();
                    round->setPos(QPoint(150, 100));
                    scene->addItem(round);
                    whoOnScene = 4;
                }
                
                void MainWindow::on_Square_clicked()
                {
                    Error_ = 1;
                    square = new Square;
                    scene->clear();
                    square->setPos(QPoint(150, 100));
                    scene->addItem(square);
                    whoOnScene = 5;
                }
                
                void MainWindow::on_Triangle_clicked()
                {
                    Error_ = 1;
                    triangle = new Triangle;
                    scene->clear();
                    triangle->setPos(QPoint(150, 100));
                    scene->addItem(triangle);
                    whoOnScene = 6;
                }
                
                void MainWindow::on_FivePointedStar_clicked()
                {
                    Error_ = 1;
                    fivePointedStar = new FivePointedStar;
                    scene->clear();
                    fivePointedStar->setPos(QPoint(150, 100));
                    scene->addItem(fivePointedStar);
                    whoOnScene = 7;
                }
                
                void MainWindow::on_SixPointedStar_clicked()
                {
                    Error_ = 1;
                    sixPointedStar = new SixPointedStar;
                    scene->clear();
                    sixPointedStar->setPos(QPoint(150, 100));
                    scene->addItem(sixPointedStar);
                    whoOnScene = 8;
                }
                
                void MainWindow::on_EightPointedStar_clicked()
                {
                    Error_ = 1;
                    eightPointedStar = new EightPointedStar;
                    scene->clear();
                    eightPointedStar->setPos(QPoint(150, 100));
                    scene->addItem(eightPointedStar);
                    whoOnScene = 9;
                }
                
                void MainWindow::on_Rotate_clicked()
                { if(Error_==1){
                        if (whoOnScene)
                        {
                            
                            rotationAnimBack->stop();
                            rotationAnim->start(1000/60);
                            switch(whoOnScene) {
                            case 1:
                                disconnect(rotationAnim, &QTimer::timeout, hex, &Hexagon::rotate);
                                connect(rotationAnim, &QTimer::timeout, hex, &Hexagon::rotate);
                                break;
                            case 2:
                                disconnect(rotationAnim, &QTimer::timeout, rect, &Rectangle::rotate);
                                connect(rotationAnim, &QTimer::timeout, rect, &Rectangle::rotate);
                                break;
                            case 3:
                                disconnect(rotationAnim, &QTimer::timeout, rhomb, &Rhomb::rotate);
                                connect(rotationAnim, &QTimer::timeout, rhomb, &Rhomb::rotate);
                                break;
                            case 4:
                                disconnect(rotationAnim, &QTimer::timeout, round, &Round::rotate);
                                connect(rotationAnim, &QTimer::timeout, round, &Round::rotate);
                                break;
                            case 5:
                                disconnect(rotationAnim, &QTimer::timeout, square, &Square::rotate);
                                connect(rotationAnim, &QTimer::timeout, square, &Square::rotate);
                                break;
                            case 6:
                                disconnect(rotationAnim, &QTimer::timeout, triangle, &Triangle::rotate);
                                connect(rotationAnim, &QTimer::timeout, triangle, &Triangle::rotate);
                                break;
                            case 7:
                                disconnect(rotationAnim, &QTimer::timeout, fivePointedStar, &FivePointedStar::rotate);
                                connect(rotationAnim, &QTimer::timeout, fivePointedStar, &FivePointedStar::rotate);
                                break;
                            case 8:
                                disconnect(rotationAnim, &QTimer::timeout, sixPointedStar, &SixPointedStar::rotate);
                                connect(rotationAnim, &QTimer::timeout, sixPointedStar, &SixPointedStar::rotate);
                                break;
                            case 9:
                                disconnect(rotationAnim, &QTimer::timeout, eightPointedStar, &EightPointedStar::rotate);
                                connect(rotationAnim, &QTimer::timeout, eightPointedStar, &EightPointedStar::rotate);
                                break;
                                
                            }
                            
                            
                        }
                    }
                    
                }
                
                
                void MainWindow::on_RotateBack_clicked()
                {if(Error_==1){
                        if (whoOnScene)
                        {
                            rotationAnim->stop();
                            rotationAnimBack->start(1000/60);
                            switch(whoOnScene) {
                            case 1:
                                disconnect(rotationAnimBack, &QTimer::timeout, hex, &Hexagon::rotateBack);
                                connect(rotationAnimBack, &QTimer::timeout, hex, &Hexagon::rotateBack);
                                break;
                            case 2:
                                disconnect(rotationAnimBack, &QTimer::timeout, rect, &Rectangle::rotateBack);
                                connect(rotationAnimBack, &QTimer::timeout, rect, &Rectangle::rotateBack);
                                break;
                            case 3:
                                disconnect(rotationAnimBack, &QTimer::timeout, rhomb, &Rhomb::rotateBack);
                                connect(rotationAnimBack, &QTimer::timeout, rhomb, &Rhomb::rotateBack);
                                break;
                            case 4:
                                disconnect(rotationAnimBack, &QTimer::timeout, round, &Round::rotateBack);
                                connect(rotationAnimBack, &QTimer::timeout, round, &Round::rotateBack);
                                break;
                            case 5:
                                disconnect(rotationAnimBack, &QTimer::timeout, square, &Square::rotateBack);
                                connect(rotationAnimBack, &QTimer::timeout, square, &Square::rotateBack);
                                break;
                            case 6:
                                disconnect(rotationAnimBack, &QTimer::timeout, triangle, &Triangle::rotateBack);
                                connect(rotationAnimBack, &QTimer::timeout, triangle, &Triangle::rotateBack);
                                break;
                            case 7:
                                disconnect(rotationAnimBack, &QTimer::timeout, fivePointedStar, &FivePointedStar::rotateBack);
                                connect(rotationAnimBack, &QTimer::timeout, fivePointedStar, &FivePointedStar::rotateBack);
                                break;
                            case 8:
                                disconnect(rotationAnimBack, &QTimer::timeout, sixPointedStar, &SixPointedStar::rotateBack);
                                connect(rotationAnimBack, &QTimer::timeout, sixPointedStar, &SixPointedStar::rotateBack);
                                break;
                            case 9:
                                disconnect(rotationAnimBack, &QTimer::timeout, eightPointedStar, &EightPointedStar::rotateBack);
                                connect(rotationAnimBack, &QTimer::timeout, eightPointedStar, &EightPointedStar::rotateBack);
                            }
                        }
                    }
                }
                
                void MainWindow::on_ScaleChange_clicked()
                {if(Error_==1){
                        if (whoOnScene)
                        {
                            scaleAnimBack->stop();
                            scaleAnim->start(1000/60);
                            switch(whoOnScene) {
                            case 1:
                                disconnect(scaleAnim, &QTimer::timeout, hex, &Hexagon::scale);
                                connect(scaleAnim, &QTimer::timeout, hex, &Hexagon::scale);
                                break;
                            case 2:
                                disconnect(scaleAnim, &QTimer::timeout, rect, &Rectangle::scale);
                                connect(scaleAnim, &QTimer::timeout, rect, &Rectangle::scale);
                                break;
                            case 3:
                                disconnect(scaleAnim, &QTimer::timeout, rhomb, &Rhomb::scale);
                                connect(scaleAnim, &QTimer::timeout, rhomb, &Rhomb::scale);
                                break;
                            case 4:
                                disconnect(scaleAnim, &QTimer::timeout, round, &Round::scale);
                                connect(scaleAnim, &QTimer::timeout, round, &Round::scale);
                                break;
                            case 5:
                                disconnect(scaleAnim, &QTimer::timeout, square, &Square::scale);
                                connect(scaleAnim, &QTimer::timeout, square, &Square::scale);
                                break;
                            case 6:
                                disconnect(scaleAnim, &QTimer::timeout, triangle, &Triangle::scale);
                                connect(scaleAnim, &QTimer::timeout, triangle, &Triangle::scale);
                                break;
                            case 7:
                                disconnect(scaleAnim, &QTimer::timeout, fivePointedStar, &FivePointedStar::scale);
                                connect(scaleAnim, &QTimer::timeout, fivePointedStar, &FivePointedStar::scale);
                                break;
                            case 8:
                                disconnect(scaleAnim, &QTimer::timeout, sixPointedStar, &SixPointedStar::scale);
                                connect(scaleAnim, &QTimer::timeout, sixPointedStar, &SixPointedStar::scale);
                                break;
                            case 9:
                                disconnect(scaleAnim, &QTimer::timeout, eightPointedStar, &EightPointedStar::scale);
                                connect(scaleAnim, &QTimer::timeout, eightPointedStar, &EightPointedStar::scale);
                            }
                        }
                    }
                }
                
                void MainWindow::on_ScaleChangeBack_clicked()
                {if(Error_==1){
                        if (whoOnScene)
                        {
                            scaleAnim->stop();
                            scaleAnimBack->start(1000/60);
                            switch(whoOnScene) {
                            case 1:
                                disconnect(scaleAnimBack, &QTimer::timeout, hex, &Hexagon::scaleBack);
                                connect(scaleAnimBack, &QTimer::timeout, hex, &Hexagon::scaleBack);
                                break;
                            case 2:
                                disconnect(scaleAnimBack, &QTimer::timeout, rect, &Rectangle::scaleBack);
                                connect(scaleAnimBack, &QTimer::timeout, rect, &Rectangle::scaleBack);
                                break;
                            case 3:
                                disconnect(scaleAnimBack, &QTimer::timeout, rhomb, &Rhomb::scaleBack);
                                connect(scaleAnimBack, &QTimer::timeout, rhomb, &Rhomb::scaleBack);
                                break;
                            case 4:
                                disconnect(scaleAnimBack, &QTimer::timeout, round, &Round::scaleBack);
                                connect(scaleAnimBack, &QTimer::timeout, round, &Round::scaleBack);
                                break;
                            case 5:
                                disconnect(scaleAnimBack, &QTimer::timeout, square, &Square::scaleBack);
                                connect(scaleAnimBack, &QTimer::timeout, square, &Square::scaleBack);
                                break;
                            case 6:
                                disconnect(scaleAnimBack, &QTimer::timeout, triangle, &Triangle::scaleBack);
                                connect(scaleAnimBack, &QTimer::timeout, triangle, &Triangle::scaleBack);
                                break;
                            case 7:
                                disconnect(scaleAnimBack, &QTimer::timeout, fivePointedStar, &FivePointedStar::scaleBack);
                                connect(scaleAnimBack, &QTimer::timeout, fivePointedStar, &FivePointedStar::scaleBack);
                                break;
                            case 8:
                                disconnect(scaleAnimBack, &QTimer::timeout, sixPointedStar, &SixPointedStar::scaleBack);
                                connect(scaleAnimBack, &QTimer::timeout, sixPointedStar, &SixPointedStar::scaleBack);
                                break;
                            case 9:
                                disconnect(scaleAnimBack, &QTimer::timeout, eightPointedStar, &EightPointedStar::scaleBack);
                                connect(scaleAnimBack, &QTimer::timeout, eightPointedStar, &EightPointedStar::scaleBack);
                            }
                        }
                    }
                }
                
                
                
                void MainWindow::on_Perimetr_clicked()
                {if(Error_==1){
                        if (whoOnScene)
                        {
                            QString text;
                            double perimetr;
                            switch(whoOnScene)
                            {
                            case 1:
                                perimetr = hex->perimetr();
                                break;
                            case 2:
                                perimetr = rect->perimetr();
                                break;
                            case 3:
                                perimetr = rhomb->perimetr();
                                break;
                            case 4:
                                perimetr = round->perimetr();
                                break;
                            case 5:
                                perimetr = square->perimetr();
                                break;
                            case 6:
                                perimetr = triangle->perimetr();
                                break;
                            case 7:
                                perimetr = fivePointedStar->perimetr();
                                break;
                            case 8:
                                perimetr = sixPointedStar->perimetr();
                                break;
                            case 9:
                                perimetr = eightPointedStar->perimetr();
                                break;
                            }
                            text = "Периметр: " + QString::number(perimetr);
                            ui->label->setText(text);
                        }
                    }
                }
                
                
                void MainWindow::on_Area_clicked()
                {if(Error_==1){
                        if (whoOnScene)
                        {
                            QString text;
                            double area;
                            switch(whoOnScene)
                            {
                            case 1:
                                area = hex->area();
                                break;
                            case 2:
                                area = rect->area();
                                break;
                            case 3:
                                area = rhomb->area();
                                break;
                            case 4:
                                area = round->area();
                                break;
                            case 5:
                                area = square->area();
                                break;
                            case 6:
                                area = triangle->area();
                                break;
                            case 7:
                                area = fivePointedStar->area();
                                break;
                            case 8:
                                area = sixPointedStar->area();
                                break;
                            case 9:
                                area = eightPointedStar->area();
                                break;
                            }
                            text = "Площадь: " + QString::number(area);
                            ui->label_2->setText(text);
                        }
                    }
                }
                
                void MainWindow::on_CenterOfMass_clicked()
                {if(Error_==1){
                        if (whoOnScene)
                        {
                            QPointF center;
                            QString text;
                            switch(whoOnScene)
                            {
                            case 1:
                                center = hex->centerOfMass();
                                break;
                            case 2:
                                center = rect->centerOfMass();
                                break;
                            case 3:
                                center = rhomb->centerOfMass();
                                break;
                            case 4:
                                center = round->centerOfMass();;
                                break;
                            case 5:
                                center = square->centerOfMass();;
                                break;
                            case 6:
                                center = triangle->centerOfMass();;
                                break;
                            case 7:
                                center = fivePointedStar->centerOfMass();;
                                break;
                            case 8:
                                center = sixPointedStar->centerOfMass();;
                                break;
                            case 9:
                                center = eightPointedStar->centerOfMass();;
                                break;
                            }
                            text = "Координаты: (" + QString::number(center.x()) + ", " + QString::number(center.y()) + ")";
                            ui->label_3->setText(text);
                        }
                    }
                }
                
                void MainWindow::on_Clear_clicked()
                {Error_=0;
                    scene->clear();
                }
                disconnect(scaleAnim, &QTimer::timeout, fivePointedStar, &FivePointedStar::scale);
                connect(scaleAnim, &QTimer::timeout, fivePointedStar, &FivePointedStar::scale);
                break;
            case 8:
                disconnect(scaleAnim, &QTimer::timeout, sixPointedStar, &SixPointedStar::scale);
                connect(scaleAnim, &QTimer::timeout, sixPointedStar, &SixPointedStar::scale);
                break;
            case 9:
                disconnect(scaleAnim, &QTimer::timeout, eightPointedStar, &EightPointedStar::scale);
                connect(scaleAnim, &QTimer::timeout, eightPointedStar, &EightPointedStar::scale);
            }
        }
    }
}

void MainWindow::on_ScaleChangeBack_clicked()
{if(Error_==1){
        if (whoOnScene)
        {
            scaleAnim->stop();
            scaleAnimBack->start(1000/60);
            switch(whoOnScene) {
            case 1:
                disconnect(scaleAnimBack, &QTimer::timeout, hex, &Hexagon::scaleBack);
                connect(scaleAnimBack, &QTimer::timeout, hex, &Hexagon::scaleBack);
                break;
            case 2:
                disconnect(scaleAnimBack, &QTimer::timeout, rect, &Rectangle::scaleBack);
                connect(scaleAnimBack, &QTimer::timeout, rect, &Rectangle::scaleBack);
                break;
            case 3:
                disconnect(scaleAnimBack, &QTimer::timeout, rhomb, &Rhomb::scaleBack);
                connect(scaleAnimBack, &QTimer::timeout, rhomb, &Rhomb::scaleBack);
                break;
            case 4:
                disconnect(scaleAnimBack, &QTimer::timeout, round, &Round::scaleBack);
                connect(scaleAnimBack, &QTimer::timeout, round, &Round::scaleBack);
                break;
            case 5:
                disconnect(scaleAnimBack, &QTimer::timeout, square, &Square::scaleBack);
                connect(scaleAnimBack, &QTimer::timeout, square, &Square::scaleBack);
                break;
            case 6:
                disconnect(scaleAnimBack, &QTimer::timeout, triangle, &Triangle::scaleBack);
                connect(scaleAnimBack, &QTimer::timeout, triangle, &Triangle::scaleBack);
                break;
            case 7:
                disconnect(scaleAnimBack, &QTimer::timeout, fivePointedStar, &FivePointedStar::scaleBack);
                connect(scaleAnimBack, &QTimer::timeout, fivePointedStar, &FivePointedStar::scaleBack);
                break;
            case 8:
                disconnect(scaleAnimBack, &QTimer::timeout, sixPointedStar, &SixPointedStar::scaleBack);
                connect(scaleAnimBack, &QTimer::timeout, sixPointedStar, &SixPointedStar::scaleBack);
                break;
            case 9:
                disconnect(scaleAnimBack, &QTimer::timeout, eightPointedStar, &EightPointedStar::scaleBack);
                connect(scaleAnimBack, &QTimer::timeout, eightPointedStar, &EightPointedStar::scaleBack);
            }
        }
    }
}



void MainWindow::on_Perimetr_clicked()
{if(Error_==1){
        if (whoOnScene)
        {
            QString text;
            double perimetr;
            switch(whoOnScene)
            {
            case 1:
                perimetr = hex->perimetr();
                break;
            case 2:
                perimetr = rect->perimetr();
                break;
            case 3:
                perimetr = rhomb->perimetr();
                break;
            case 4:
                perimetr = round->perimetr();
                break;
            case 5:
                perimetr = square->perimetr();
                break;
            case 6:
                perimetr = triangle->perimetr();
                break;
            case 7:
                perimetr = fivePointedStar->perimetr();
                break;
            case 8:
                perimetr = sixPointedStar->perimetr();
                break;
            case 9:
                perimetr = eightPointedStar->perimetr();
                break;
            }
            text = "Периметр: " + QString::number(perimetr);
            ui->label->setText(text);
        }
    }
}


void MainWindow::on_Area_clicked()
{if(Error_==1){
        if (whoOnScene)
        {
            QString text;
            double area;
            switch(whoOnScene)
            {
            case 1:
                area = hex->area();
                break;
            case 2:
                area = rect->area();
                break;
            case 3:
                area = rhomb->area();
                break;
            case 4:
                area = round->area();
                break;
            case 5:
                area = square->area();
                break;
            case 6:
                area = triangle->area();
                break;
            case 7:
                area = fivePointedStar->area();
                break;
            case 8:
                area = sixPointedStar->area();
                break;
            case 9:
                area = eightPointedStar->area();
                break;
            }
            text = "Площадь: " + QString::number(area);
            ui->label_2->setText(text);
        }
    }
}

void MainWindow::on_CenterOfMass_clicked()
{if(Error_==1){
        if (whoOnScene)
        {
            QPointF center;
            QString text;
            switch(whoOnScene)
            {
            case 1:
                center = hex->centerOfMass();
                break;
            case 2:
                center = rect->centerOfMass();
                break;
            case 3:
                center = rhomb->centerOfMass();
                break;
            case 4:
                center = round->centerOfMass();;
                break;
            case 5:
                center = square->centerOfMass();;
                break;
            case 6:
                center = triangle->centerOfMass();;
                break;
            case 7:
                center = fivePointedStar->centerOfMass();;
                break;
            case 8:
                center = sixPointedStar->centerOfMass();;
                break;
            case 9:
                center = eightPointedStar->centerOfMass();;
                break;
            }
            text = "Координаты: (" + QString::number(center.x()) + ", " + QString::number(center.y()) + ")";
            ui->label_3->setText(text);
        }
    }
}

void MainWindow::on_Clear_clicked()
{Error_=0;
    scene->clear();
}
void Rectangle::rotateBack()
{
    if (rotationAngle_ > -90)
    {
        --rotationAngle_;
        update();
        rotateCenterX = width_ / 4.0;
        rotateCenterY = height_ / 2.0;
    }
}

void Rectangle::scale()
{
    if (scale_ < 1.5)
    {
        scale_ += 0.01;
        update();
    }
    if (scale_ == 1.5) width_ *= scale_;
}
void Rectangle::scaleBack()
{
    if (scale_ > 0.5)
    {
        scale_ -= 0.01;
        update();
    }
    if (scale_ == 1.5) width_ *= scale_;
}
