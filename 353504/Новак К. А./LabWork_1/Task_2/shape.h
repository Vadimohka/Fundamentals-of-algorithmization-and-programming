#ifndef SHAPE_H
#define SHAPE_H

#include <QGraphicsItem>
#include <QPaintEvent>
#include <QPainter>

const double pi = 3.14;

class shape : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit shape(QPointF point, QObject *parent = 0);
    QPointF getStartPoint() const;
    QPointF getFinalPoint() const;
    void setStartPoint(QPointF point);
    void setFinalPoint(QPointF point);
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;
    double getS();
    double getP();
    void setS(double x);
    void setP(double x);
    void incScaleFactor(double delta);
    int length = 0;
    int width = 0;
    QPointF center = QPointF(0,0);
    double getScaleFactor() const;
    void incRotateFactor(int delta);
    int getRotateFactor() const;
    QColor color = Qt::black;
    double square = 0, perim = 0;
    QPointF delta = QPointF(0,0);
protected:
    double scaleFactor = 1;
    int rotateFactor = 0;
    QPointF startPoint = QPointF(0,0);
    QPointF finalPoint = QPointF(0,0);;
};

#endif // SHAPE_H
