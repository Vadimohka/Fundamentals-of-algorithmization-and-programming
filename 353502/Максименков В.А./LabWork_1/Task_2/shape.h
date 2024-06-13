#ifndef SHAPE_H
#define SHAPE_H
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <cmath>
#include <QDebug>

class Shape : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    static int sostoyanie;
    static QString shapeNow;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void rotatingFunction(QPointF now);

protected:
    QPointF centerOfShape = QPointF(0.0, 0.0);
    QPointF previous = QPointF(0.0, 0.0);
    qreal defaultDistance = 0.0;

    virtual QRectF boundingRect() const = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;

    virtual void resizeShape(QPointF now) = 0;
    virtual void setDefaultDistanceForTriangle();
    virtual void setCenterOfShapeNow(QPointF center);
    virtual void setPositionOfTheShape(QPointF pos);
    virtual QPointF getScenePosition();
    virtual qreal squareOfShape() = 0;
    virtual qreal perimetrOfShape() = 0;


public:
    Shape();
    virtual ~Shape() = default;

    static void setSostoyanie(int newSostoyanie);
    virtual void reinterpret(qreal parametr1, qreal parametr2);


    static void setShapeNow(const QString &newShapeNow);

    static QString getShapeNow();

    void setDefaultDistance(qreal newDefaultDistance);

signals:
    void newItem(Shape* newShape, QString newShapeForm);
    void deleteItem(Shape* deleteShape);
    void mousePosition(QPointF now);
    void updateShape();
    void centerSignal(QPointF center);
    void squareSignal(qreal square);
    void perimetrSignal(qreal perimetr);
    void mouseHasAlreadyClicked(QPointF point);
};

#endif // SHAPE_H
