//
// Created by acryoz on 14.2.24.
//

#ifndef UNTITLED_FIGURE_H
#define UNTITLED_FIGURE_H
#include <cmath>
#include <QDebug>
#include <QTimer>
#include <QPainter>
#include <QWidget>
#include <QMouseEvent>


class figure: public QObject {
    Q_OBJECT
public:
    figure();
    virtual void draw(QPainter*);
    virtual void addPoint(QPointF);
    virtual void move();
    void mousePress(QMouseEvent* mouseEvent);
    void mouseMove(QMouseEvent* mouseEvent);
    void mouseRelease(QMouseEvent* mouseEvent);
    double getAngle();
    double getScale();
    QPointF getCentre();
    double getArea();
    double getPerimeter();
    double figure_id = 0;
    double angle = 0;
    double scale = 1;
    QVector<QPointF> vertices;

signals:
    void changed();

public slots:
    virtual void resize(int);
    virtual void rotate(int);
    void setV1x(QString);
    void setV1y(QString);
    void setV2x(QString);
    void setV2y(QString);
    void setV3x(QString);
    void setV3y(QString);
    void setV4x(QString);
    void setV4y(QString);

protected:
    virtual double calculateArea();
    virtual double calculatePerimeter();
    virtual QPointF findCentre();
    QPointF centre;
    QPointF cur_mouse;
    QPointF pressing_mouse;
    QPointF released_mouse;
    double area;
    double perimeter;
    QTimer glob_timer;
};


#endif //UNTITLED_FIGURE_H
