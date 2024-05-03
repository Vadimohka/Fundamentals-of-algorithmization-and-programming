#include "animatedrectangle.h"
#include "qgraphicsscene.h"
#include <QPainter>
#include <QKeyEvent>

Rectangle::Rectangle(qreal x, qreal y, qreal width, qreal height, QObject *parent)
    : QObject(parent), QGraphicsRectItem(x, y, width, height)
{
    setBrush(QColor(0, 0, 128)); // Темно-синий цвет

    currentAngle = 0;
    targetAngle = 90;

    connect(&animationTimer, &QTimer::timeout, this, &Rectangle::rotateRectangle);



}
void Rectangle::moveUp()
{
    if (!animationTimer.isActive()&&  liftedAnimationCompleted==true) {
        animationSpeed = 3;
        targetDistance = 100;
        animationTimer.start(10);
        liftedAnimationCompleted=false;
        scene()->update();

    }
}

void Rectangle::moveDown()
{
    if (!animationTimer.isActive()&& liftedAnimationCompleted==false) {
        animationSpeed = -3;
        targetDistance = 100;
        animationTimer.start(10);
        scene()->update();
        liftedAnimationCompleted=true;
    }
}

void Rectangle::stopAnimation()
{
    animationTimer.stop();
    currentDistance = 0;
    scene()->update();
}
void Rectangle::rotateRectangle()
{
    if (currentAngle < targetAngle &&  pos().y() >= 0 && pos().x() <= 0 ) {
        qreal currentX = pos().x();
        qreal currentY = pos().y();

        // Устанавливаем новые координаты, чтобы точка (-300, 0) стала центром
        setTransformOriginPoint(QPointF(-300, 0));

        // Используем отрицательное значение для вращения против часовой стрелки
        setRotation(rotation() - animationSpeed);
        currentAngle += qAbs(animationSpeed);

        // Возвращаем прямоугольник обратно на его предыдущее местоположение
        setPos(currentX, currentY);
    } else {
        stopAnimation();
        currentAngle = 0;
    }
}



