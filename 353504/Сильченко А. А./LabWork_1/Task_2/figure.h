#ifndef FIGURE_H
#define FIGURE_H

#pragma once
#include <QGraphicsItem>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QKeyEvent>

class Figure : public QGraphicsItem{
private:
    bool setCenter = false;

public:
    double S = 0.0, P = 0.0;
    int centerX = 0, centerY = 0;
    int mouseX, mouseY;

    Figure(QGraphicsItem *parent2 = nullptr);

    virtual void draw(QPainter *painter) = 0;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
        draw(painter);
    }
    QRectF boundingRect() const{
        // Возвращает ограничивающий прямоугольник
        return QRectF(-100, -100, 1000*625, 1000*450);
    }
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event) override;
    void rotate(double angle);

    double getS(){
        return S;
    }
    double getP(){
        return P;
    }

    virtual void findSquare() = 0;
    virtual void findPerimetr() = 0;
};
#endif // FIGURE_H
