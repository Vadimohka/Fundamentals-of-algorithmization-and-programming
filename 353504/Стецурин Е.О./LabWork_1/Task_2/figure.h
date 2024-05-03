#ifndef FIGURE_H
#define FIGURE_H

#include <QGraphicsPolygonItem>
#include <QGraphicsObject>

class Figure : public QGraphicsPolygonItem
{
public:
    Figure(QGraphicsPolygonItem* parent = nullptr) : QGraphicsPolygonItem(parent) {}
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override
    {
        QGraphicsItem::mousePressEvent(event);
    }
};

class FigureDraw : public QGraphicsObject
{
    Q_OBJECT
    // Свойство
    Q_PROPERTY(QPointF startPoint
                   READ startPoint WRITE setStartPoint
                       NOTIFY pointChanged)
    Q_PROPERTY(QPointF endPoint
                   READ endPoint WRITE setEndPoint
                       NOTIFY pointChanged)
public:
    explicit FigureDraw(QPointF point, QGraphicsObject *parent = 0);
    ~FigureDraw();

    QPointF startPoint() const;
    QPointF endPoint() const;

    void setStartPoint(const QPointF point);
    void setEndPoint(const QPointF point);
    QRectF boundingRect() const;

signals:
    void pointChanged();
    void coordinatesChanged(int x, int y);

private:
    QPointF m_startPoint;
    QPointF m_endPoint;


public slots:
    void updateRomb();
};


#endif // FIGURE_H
