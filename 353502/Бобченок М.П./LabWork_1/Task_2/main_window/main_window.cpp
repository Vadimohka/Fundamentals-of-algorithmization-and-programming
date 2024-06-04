//
// Created by u on 10.03.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_window.h" resolved

#include <iostream>
#include "main_window.h"
#include "ui_main_window.h"



void main_window::setStar() const
{
    QString s;
    s = ui->numOfCorners->text();

    int numOfCorners = std::max(2, s.toInt());
    scene->setFigure(numOfCorners, false);
}

void main_window::setPolygon() const
{
    QString s;
    s = ui->numOfCorners->text();

    int numOfCorners = std::max(2, s.toInt());

    scene->setFigure(numOfCorners, true);
}

void main_window::quit()
{
    exit(0);
}

void main_window::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_W)
    {
        scene->moveFigure(0);
    }
    else if (e->key() == Qt::Key_S)
    {
        scene->moveFigure(1);
    }
    else if (e->key() == Qt::Key_A)
    {
        scene->moveFigure(2);
    }
    else if (e->key() == Qt::Key_D)
    {
        scene->moveFigure(3);
    }
    else if (e->key() == Qt::Key_Q)
    {
        scene->rotateFigure(0);
    }
    else if (e->key() == Qt::Key_E)
    {
        scene->rotateFigure(1);
    }
    else if (e->key() == Qt::Key_Minus)
    {
        scene->changeFigureSize(0);
    }
    else if (e->key() == Qt::Key_Plus)
    {
        scene->changeFigureSize(1);
    }

    scene->setPS();
}

main_window::main_window(QWidget *parent) : QWidget(parent), ui(new Ui::main_window), scene(new paintScene(this))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(this->scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    scene->setP(ui->perimetr);
    scene->setSquare(ui->square);

    connect(ui->triangle, SIGNAL(clicked(bool)), scene, SLOT(setTriangle()));
    connect(ui->circle, SIGNAL(clicked(bool)), scene, SLOT(setCircle()));
    connect(ui->rect, SIGNAL(clicked(bool)), scene, SLOT(setRect()));
    connect(ui->rhombus, SIGNAL(clicked(bool)), scene, SLOT(setRhombus()));
    connect(ui->drawing, SIGNAL(clicked(bool)), scene, SLOT(setDrawing()));
    connect(ui->star, SIGNAL(clicked(bool)), this, SLOT(setStar()));
    connect(ui->hecsaedr, SIGNAL(clicked(bool)), this, SLOT(setPolygon()));
    connect(ui->exit, SIGNAL(clicked(bool)), this, SLOT(quit()));
}

main_window::~main_window()
{
    delete ui;
}
