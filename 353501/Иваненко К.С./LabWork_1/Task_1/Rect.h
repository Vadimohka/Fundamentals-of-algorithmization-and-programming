#pragma once

#include <QGraphicsObject>

class Rect: public QGraphicsObject {

    public:
        int x;
        int y;
        bool ifLeft;
        bool ifRight;
        Rect();
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
        void turnLeft();
        void turnRight();
        void setLeft();
        void setRight();

    private:
        int left;
        int right;
        int rotate_right;
        int rotate_left;
        QTimer *timer;
};  