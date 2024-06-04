#ifndef HEALTH_H
#define HEALTH_H

#include <QObject>
#include "CardCharHDDE.h"
class Health : public QObject
{
    Q_OBJECT
public:
    explicit Health(QObject *parent = nullptr);
    void takeDamage(int damage);
    void takeDamage(Damage *damage){takeDamage(damage->damage());}
    void addHP(int HP);
    void addHP(Health *HP){hp+=HP->setHP();}
    int setHP();

private:
    int hp=0;
signals:
};

#endif // HEALTH_H
