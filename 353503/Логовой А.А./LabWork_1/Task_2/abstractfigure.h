#ifndef ABSTRACTFIGURE_H
#define ABSTRACTFIGURE_H

#include <QGraphicsObject>
#include <QBrush>
#include <QGraphicsScene>
#include <QColor>
#include <QPainter>
#include <QPen>
#include <QWidget>

class AbstractFigure: public QGraphicsObject
{
public:
    AbstractFigure();
    ~AbstractFigure();

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void drawBorders(QPainter *painter);

    void drawPoints(QPainter *painter);

    void setColor(QColor color1);

    void setShowBorders(bool value);

    void setShowPoint(bool value);

    void setRect(double x1, double y1, double x2, double y2);

protected:
    QColor color;
    QRectF rect;
    QPen pen;
    bool show_point;
    bool show_borders;
    QBrush brush;

    virtual void drawFigure(QPainter *painter);
};

#endif // ABSTRACTFIGURE_H
