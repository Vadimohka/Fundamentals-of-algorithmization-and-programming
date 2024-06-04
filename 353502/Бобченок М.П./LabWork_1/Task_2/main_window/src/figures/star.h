//
// Created by u on 10.03.24.
//

#ifndef PAINTDEGRODATED_STAR_H
#define PAINTDEGRODATED_STAR_H

#include <QGraphicsObject>
#include <QGraphicsView>
#include <QPainter>
#include <cmath>

class star : public QGraphicsObject
{
    Q_OBJECT
private:
    const float pi = acosf(-1);
    int corners = 4;
    float x_centre, y_centre, angle;
    float R, r, p;
    bool isConvex;

public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    [[nodiscard]] QRectF boundingRect() const override;

    [[nodiscard]] float getR() const;
    [[nodiscard]] float getAngle() const;
    void move(float deltaX, float deltaY);
    void rotate(float deltaAngle);
    void changeR(float delta);

    star(float _x_centre, float _y_centre, float _angle, float _radius, int _numOfCorners, bool _isConvex = false);
};


#endif //PAINTDEGRODATED_STAR_H
