#ifndef SIZEFITGRAPHICSVIEW_HPP
#define SIZEFITGRAPHICSVIEW_HPP

#include<QGraphicsView>
#include<QMoveEvent>
#include<iostream>
#include<QObject>
#include<QWidget>

class SizeFitGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    SizeFitGraphicsView(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);

signals:
    void graphicsViewClicked(double x);
};

#endif // SIZEFITGRAPHICSVIEW_HPP
