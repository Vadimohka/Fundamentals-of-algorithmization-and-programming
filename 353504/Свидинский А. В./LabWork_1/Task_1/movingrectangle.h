#ifndef MOVINGRECTANGLE_H
#define MOVINGRECTANGLE_H

#include <QWidget>
#include <QPoint>

class MovingRectangle : public QWidget
{
    Q_OBJECT
public:
    MovingRectangle(QWidget *parent = nullptr);
    void moveTo(const QPoint &newPosition);
};

#endif // MOVINGRECTANGLE_H
