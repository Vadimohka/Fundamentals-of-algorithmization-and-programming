//
// Created by u on 09.03.24.
//

#ifndef TASK_MOVING_RECT_H
#define TASK_MOVING_RECT_H


#include <QGraphicsObject>
#include <QPainter>
#include <iostream>

class moving_rect : public QGraphicsObject
{
Q_OBJECT
public slots:
    void move(int speedX, int speedY, int posX, int posY);

protected:
    int x_pos{}, y_pos{}, w{}, h{};
    int color{};


public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    [[nodiscard]] QRectF boundingRect() const override;

    void move(int x, int y);
    void swap(moving_rect &r2);

    int getX();
    int getY();
    int getW();
    int getH();
    int getColor();

    void setX(int x);
    void setY(int y);
    void setColor(int c);

    moving_rect();

    moving_rect(moving_rect&& other);

    moving_rect(int x, int y, int w, int h, int color);
};


#endif //TELEGA_MOVING_RECT_H
