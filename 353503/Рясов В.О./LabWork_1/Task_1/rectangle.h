#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QMainWindow>
#include <QPolygon>
#include <QPainter>

class Rectangle : public QMainWindow
{
    Q_OBJECT
public:
    explicit Rectangle(QMainWindow *parent = nullptr);
protected:
    QPolygon rect;
signals:
};

#endif // RECTANGLE_H
