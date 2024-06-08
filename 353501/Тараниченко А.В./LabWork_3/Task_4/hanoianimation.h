#ifndef HANOIANIMATION_H
#define HANOIANIMATION_H

#include <QPropertyAnimation>
#include <QtWidgets>

class HanoiAnimation
{
public:
    HanoiAnimation(QGraphicsRectItem *ring, char from_rod, char to_rod, int duration)
        : ring(ring)
        , from_rod(from_rod)
        , to_rod(to_rod)
        , duration(duration){};

    void Start();

private:
    QGraphicsRectItem *ring;
    char from_rod;
    char to_rod;
    int duration;
};

#endif // HANOIANIMATION_H
