//
// Created by volodya-petarda on 3/10/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_window.h" resolved

#include <QDebug>
#include "main_window.h"
#include "ui_main_window.h"
#include "paintScene.h"
#include "figures/npolygon.h"
#include "figures/nstar.h"
#include <QTimer>


main_window::main_window(QWidget *parent) :
QWidget(parent), ui(new Ui::main_window) {
    figure = new npolygon(8);
    figure->setScaled(0, 0);
//    auto scene2 = new QGraphicsScene(this);
    scene = new paintScene(this, this);
    ui->setupUi(this);
    scene->setParentWindow(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    scene->addItem(figure);

    auto *timer = new QTimer(this);
    timer->setInterval(10);
    connect(timer, SIGNAL(timeout()), this, SLOT(setPerimentr()));
    timer->start();
    connect(ui->squareButton, SIGNAL(clicked()), this, SLOT(setSquare()));
    connect(ui->circleButton, SIGNAL(clicked()), this, SLOT(setCircle()));
    connect(ui->fivePolygonButton, SIGNAL(clicked()), this, SLOT(set5polygon()));
    connect(ui->sixPolygonButton, SIGNAL(clicked()), this, SLOT(set6polygon()));
    connect(ui->eightPolygonButton, SIGNAL(clicked()), this, SLOT(set8polygon()));
    connect(ui->rhombusButton, SIGNAL(clicked()), this, SLOT(setRhombus()));
    connect(ui->triangleButton, SIGNAL(clicked()), this, SLOT(setTriangle()));
    connect(ui->fiveStarButton, SIGNAL(clicked()), this, SLOT(set5Star()));
    connect(ui->eightStarButton, SIGNAL(clicked()), this, SLOT(set8Star()));
    connect(ui->multiStarButton, SIGNAL(clicked()), this, SLOT(setMultiStar()));
}

main_window::~main_window() {
    delete ui;
}

void main_window::setSizes(qreal x1, qreal y1, qreal x2, qreal y2) {
    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2;
}

void main_window::draw() {
    figure->setFigurePos(x1, y1);
    figure->setScaled(x2 - x1, y2 - y1);
    figure->update();
}

void main_window::setSquare() {
    figure = new npolygon(4);
    scene->addItem(figure);
    scene->reset();
}

void main_window::setCircle() {
    figure = new npolygon(256);
    scene->addItem(figure);
    scene->reset();
}

void main_window::set5polygon() {
    figure = new npolygon(5);
    scene->addItem(figure);
    scene->reset();
}

void main_window::set6polygon() {
    figure = new npolygon(6);
    scene->addItem(figure);
    scene->reset();
}

void main_window::set8polygon() {
    figure = new npolygon(8);
    scene->addItem(figure);
    scene->reset();
}

void main_window::setRhombus() {
    figure = new nstar(2);
    scene->addItem(figure);
    scene->reset();
}

void main_window::setTriangle() {
    figure = new npolygon(3);
    scene->addItem(figure);
    scene->reset();
}

void main_window::set5Star() {
    figure = new nstar(5);
    scene->addItem(figure);
    scene->reset();
}

void main_window::set8Star() {
    figure = new nstar(8);
    scene->addItem(figure);
    scene->reset();
}

void main_window::setMultiStar() {
    figure = new nstar(256);
    scene->addItem(figure);
    scene->reset();
}

void main_window::moveLeft() {
    figure->moveLeft();
}

void main_window::moveRight() {
    figure->moveRight();
}

void main_window::moveDown() {
    figure->moveDown();
}

void main_window::moveUp() {
    figure->moveUp();
}

void main_window::rotateLeft() {
    figure->rotateLeft();
}

void main_window::rotateRight() {
    figure->rotateRight();
}

void main_window::setPerimentr() {
    QString s;
    s = QString::number(figure->getPerimetr());
    this->ui->perimetr->setText(s);
    ui->perimetr->update();
    s = QString::number(figure->getS());
    this->ui->square->setText(s);
    ui->square->update();
    figure->update();
}


