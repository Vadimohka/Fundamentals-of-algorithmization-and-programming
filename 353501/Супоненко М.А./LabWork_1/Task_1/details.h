#pragma once

#include <QGraphicsObject>
#include "Rect.h" 

class details : public Rect {
public:
    details();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

private slots:
    void onTimer();

private: 
    int x;
    QTimer *timer;
};