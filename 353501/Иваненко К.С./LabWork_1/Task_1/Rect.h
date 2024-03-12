#pragma once

#include <QGraphicsObject>

class Rect: public QGraphicsObject {

    public:
        int x;
        int y;
        Rect();
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
        void turnLeft();
        void turnRight();
    private slots:
        void onTimer();

    private:
        int left;
        int right;
        int rotate_right;
        int rotate_left;
        QTimer *timer;
};  