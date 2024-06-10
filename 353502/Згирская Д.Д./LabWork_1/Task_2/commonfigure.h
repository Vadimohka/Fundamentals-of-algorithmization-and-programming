#ifndef COMMONFIGURE_H
#define COMMONFIGURE_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QMouseEvent>
#include <QtMath>
#include <QPolygon>
#include <QtWidgets>
#include <vector>

class CommonFigure : public QWidget
{
    Q_OBJECT
public:
    explicit CommonFigure(QWidget *parent);

    ~CommonFigure() override;

    virtual void draw(QPainter *painter);

    virtual void drawPressEvent(QMouseEvent *event);

    virtual void drawMoveEvent(QMouseEvent *event);

    QPointF insertionPoint;

    QPointF centerPoint;
/*
    virtual void GetCurrentPoint;

    virtual void SetCentrePoint;
*/
    float width;

    float height;
protected:
    QTimer *timer;

    QPolygonF polygon;

    std::vector<QPointF> points;

};

#endif // COMMONFIGURE_H
