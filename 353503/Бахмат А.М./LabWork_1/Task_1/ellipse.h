#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QObject>

class Ellipse : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Ellipse(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
    Ellipse();
    explicit Ellipse(QObject *object = nullptr);
};

#endif // ELLIPSE_H
