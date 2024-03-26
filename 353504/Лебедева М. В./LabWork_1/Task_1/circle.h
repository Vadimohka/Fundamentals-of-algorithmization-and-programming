#ifndef CIRCLE_H
#define CIRCLE_H

#include <QObject>
#include <QtWidgets>


class Circle : public QObject,  public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Circle();

    void left();
    void right();

};

#endif // CIRCLE_H
