#ifndef MOVEPLANE_H
#define MOVEPLANE_H

#include <QWidget>
class QRect;
class MovePlane : public QWidget
{
    Q_OBJECT
public:
    void stop();
    void moveplane();
    void straight();
    int dx;
    float dy;
    QRect rect;
public:
    explicit MovePlane(QWidget *parent = nullptr);

signals:
};

#endif // MOVEPLANE_H
