#ifndef FIGURE_H
#define FIGURE_H

#include <QTransform>
#include <QGraphicsItem>
#include <QWidget>
#include <QPainter>
#include <QPoint>
#include <QEvent>
#include <QMouseEvent>
#include "additional_functions.h"

class Figure : public QGraphicsItem
{
    Q_OBJECT

public:
    explicit Figure(QWidget *parent = nullptr);

    void move(QPointF);
    void rotate(QPointF);
    void scale(QPointF);
    void setPreviousParameters();
    void updateParameters();

    QPair<short,short> getID();

    virtual QPointF getCenter() = 0;
    virtual qreal getSquare() = 0;
    virtual qreal getPerimeter() = 0;

    virtual QPair<int, int> getParameter() = 0;
    virtual void setParameter(QPair<int, int>) = 0;

protected:
    QPointF center;
    QVector<QPointF> points;

    QPointF former_pos;
    qreal former_scale;
    qreal former_rotation;

    QColor brush_color;

    bool is_selected;
    QPair<short,short> ID;

signals:
    void myID(QPair<short,short>);

public slots:
    void slotIsSelected();
    void slotNotSelected();
};

#endif // FIGURE_H
