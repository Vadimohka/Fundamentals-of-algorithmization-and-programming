#ifndef SHAPE_H
#define SHAPE_H
#include <QGraphicsObject>
#include <QPainter>
#include <QVector>

class Shape : public QGraphicsObject
{
    Q_OBJECT
protected:
    double radius = 50;
    double centerX;
    double centerY;
    QVector<QPointF> points;
    QVector<double> pointsX;
    QVector<double> pointsY;

public:
    double rotateCenterX = 0;
    double rotateCenterY = 0;
    double rotateAngle = 0;
    double X = 0;
    double Y = 0;
    double size = 1;
    bool centerConnected = true;

    QPointF move = {X,Y};
    Shape() = default;
    QRectF boundingRect() const override;

    virtual void paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    virtual void changerad(double spinrad);
    virtual qreal calculateArea();
    virtual qreal calculatePerimeter();
    virtual void calculatePoints();
    virtual void number_apexes(int number);
    virtual void centerset();

    void rotate(double spinangle);
    void moveX(double spinX);
    void moveY(double spinY);
    void changesize(double spinsize);
    void changerotateCenterX(double spincoord);
    void changerotateCenterY(double spincoord);
};

#endif // SHAPE_H
