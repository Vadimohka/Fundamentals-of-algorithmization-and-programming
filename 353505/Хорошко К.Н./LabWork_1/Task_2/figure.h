#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include <QPainter>
#include <QtMath>
#include <QColor>
#include <QRandomGenerator>


class Figure : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Figure(QPointF point, QObject *parent = nullptr);
    ~Figure();

    int a = 40;
    double b = 0;

    QPointF startPoint() const;

    void setStartPoint(const QPointF point);

    double S = 0;
    double P = 0;
    double X = 0;
    double Y = 0;

    double grad = 0;

    QRectF boundingRect()const;
    QPainterPath shape() const;

    QPainterPath m_shape;
        QColor randomColor();

private:
    QPointF m_startPoint;

};

#endif // FIGURE_H
