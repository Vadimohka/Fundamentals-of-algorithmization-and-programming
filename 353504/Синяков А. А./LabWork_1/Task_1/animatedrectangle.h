



// animatedrectangle.h
#ifndef ANIMATEDRECTANGLE_H
#define ANIMATEDRECTANGLE_H


#include <QGraphicsRectItem>
#include <QTimer>

class Rectangle : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Rectangle(qreal x, qreal y, qreal width, qreal height, QObject *parent = nullptr);

public slots:

    void moveUp();
    void moveDown();




private:

    QTimer animationTimer;
    bool liftedAnimationCompleted=true;
    int animationSpeed;
    int currentDirection;
    int targetDistance;
    int currentDistance;
    bool a;
    qreal targetAngle;
    qreal targetRadius;
    qreal  currentAngle ;
   void rotateRectangle();


    void stopAnimation();
};

#endif // ANIMATEDRECTANGLE_H


