//
// Created by u on 09.03.24.
//

#ifndef TELEGA_MOVING_RECT_H
#define TELEGA_MOVING_RECT_H


#include <QGraphicsObject>
#include <QPainter>

class moving_rect : public QGraphicsObject
{
    Q_OBJECT
public slots:
    void moveLeft();

    void moveRight();

    void decreaseSpeed();

    void moveRect();

protected:
    int x_pos, y_pos, w, h;
    int cur_speed = 0;

public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    [[nodiscard]] QRectF boundingRect() const override;

    void move(int x, int y);

    moving_rect();

    moving_rect(int x, int y, int w, int h);
};


#endif //TELEGA_MOVING_RECT_H
