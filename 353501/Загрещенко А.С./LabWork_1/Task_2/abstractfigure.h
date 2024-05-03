#ifndef ABSTRACTFIGURE_H
#define ABSTRACTFIGURE_H

#include <QGraphicsObject>
#include "QBrush"
#include "QPainter"
#include "QGraphicsScene"
#include "QColor"

class AbstractFigure : public QGraphicsObject {

public:
    AbstractFigure();

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void drawBorders(QPainter *painter);

    void setShowBorders(bool value);

    void setShowCorrectPoints(bool value);

    void setFillColor(QColor);

    virtual void setRect(double dx1, double dy1, double dx2, double dy2);

    void setSize(double width, double height);

    virtual double getSquare();
    virtual double getPerimetr();


protected:
    QColor selected_fill_color;
    bool is_show_correct_point;
    bool is_show_borders;
    QRectF rect;

    virtual void drawFigure(QPainter *painter);

    void drawCorrectPoint(QPainter *painter);
};

#endif // ABSTRACTFIGURE_H
