//
// Created by acryoz on 15.2.24.
//

#pragma once

#ifndef UNTITLED_CANVAS_H
#define UNTITLED_CANVAS_H

#include <QDebug>
#include <QFrame>
#include <QPainter>
#include "figure.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"
#include "Hexagon.h"
#include "Rhombus.h"
#include "Pentagram.h"
#include "Hexagram.h"
#include "Octagram.h"
#include "Pentagon.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Canvas; }
QT_END_NAMESPACE

class Canvas : public QFrame {
Q_OBJECT

public:
    Canvas(QWidget *parent = nullptr);
    QVector<figure*> figures;
    int selected_id = 0;
    int cur_figure = 0;
    ~Canvas() override;

public slots:
    void newFigure();
    void tick();

protected:
    void mousePressEvent(QMouseEvent* mouseEvent);
    void mouseMoveEvent(QMouseEvent* mouseEvent);
    void mouseReleaseEvent(QMouseEvent* mouseEvent);

private:
    QTimer glob_timer;
    void paintEvent(QPaintEvent*);
    Ui::Canvas *ui;
};


#endif //UNTITLED_CANVAS_H
