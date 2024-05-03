#ifndef MOVINGRECT_H
#define MOVINGRECT_H

#include <QWidget>

class QRect;
class MovingRect : public QWidget
{
    Q_OBJECT
public:
    void stop();
    void moveRect();
    int dx;
    float dy;
    QRect rect;
public:
    explicit MovingRect(QWidget *parent = nullptr);

signals:
};

#endif // MOVINGRECT_H
