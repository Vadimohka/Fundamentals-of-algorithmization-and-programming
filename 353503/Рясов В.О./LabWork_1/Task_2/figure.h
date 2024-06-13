#ifndef FIGURE_H
#define FIGURE_H
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <QVariant>

class Figure : public QObject, public QGraphicsItem
{
public:

    Figure(QPointF startPoint, QPointF endPoint)
    {

    }

    Q_OBJECT

    Q_PROPERTY(QPointF startPoint READ startPoint WRITE setStartPoint NOTIFY pointChanged)
    Q_PROPERTY(QPointF endPoint READ endPoint WRITE setEndPoint NOTIFY pointChanged)

public:
    explicit Figure(QPointF point, QObject *parent = nullptr);

    QPointF startPoint() const;
    QPointF endPoint() const;

    void setStartPoint(const QPointF point);
    void setEndPoint(const QPointF point);

    QRectF boundingRect() const override;

    QPointF centerPoint() const;

    void setCenterPoint();
signals:
    void pointChanged();

private:
    bool m_resizing;

    const int16_t delta1 = 5, delta2 = 10;

    QPointF m_centerPoint;
    QPointF m_lastMousePos;
    QPointF m_startPoint;
    QPointF m_endPoint;

public slots:
    void updateFigure();
};

#endif // FIGURE_H

