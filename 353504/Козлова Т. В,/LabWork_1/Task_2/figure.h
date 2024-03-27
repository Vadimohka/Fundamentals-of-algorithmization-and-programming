#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QtMath>

#define PI 3.1415926535897932


class Figure : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF startPoint
                   READ startPoint WRITE setStartPoint
                       NOTIFY pointChanged)
    Q_PROPERTY(QPointF endPoint
                   READ endPoint WRITE setEndPoint
                       NOTIFY pointChanged)
public:
    explicit Figure(QPointF point, QObject *parent = nullptr);
    ~Figure();

    QPointF startPoint() const;
    QPointF endPoint() const;
    QPointF centerPoint() const;

    qreal angle() const;
    virtual qreal square();
    virtual qreal perimeter();

    void setStartPoint(const QPointF point);
    void setEndPoint(const QPointF point);
    void setAngle(qreal angle);

    void changePoints(QPointF deltaStart, QPointF deltaEnd);
    void scale(int sign);


    virtual void setVertexCount(int vertexCount);
    virtual void setRadiusA(qreal a);
    virtual void setRadiusB(qreal b);

    QRectF boundingRect() const;

protected:
    virtual void setCenterPoint();

    QPointF m_centerPoint;

signals:
    void pointChanged();

private:
    QPointF m_startPoint;
    QPointF m_endPoint;
    qreal m_angle;

public slots:
    void updateRomb();
};

#endif // FIGURE_H
