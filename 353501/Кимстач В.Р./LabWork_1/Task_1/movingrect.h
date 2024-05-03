#ifndef MOVINGRECT_H
#define MOVINGRECT_H

#include <QWidget>
class QRect;
class MovingRect : public QWidget
{
    Q_OBJECT
public:
    void stop(int a,int b);
    void moveRect();
    int dx;
    float dy;
    QRect rect;
public:
    explicit MovingRect(QWidget *parent = nullptr);

};

#endif // MOVINGRECT_H
