#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QtWidgets>

class HealthBar : public QGraphicsRectItem
{
public:
    HealthBar();
    void Update(float fracHp);
private:
    float hp;
};

#endif // HEALTHBAR_H
