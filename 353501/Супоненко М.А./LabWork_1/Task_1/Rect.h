#pragma once

#include <QGraphicsObject>

class Rect : public QGraphicsObject {
public:
    Rect();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

private slots:
    void onTimer();

private: 
    int x;
    QTimer *timer;
};