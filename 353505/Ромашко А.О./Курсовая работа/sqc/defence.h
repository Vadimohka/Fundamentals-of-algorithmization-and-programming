#ifndef DEFENCE_H
#define DEFENCE_H

#include <QObject>
#include "CardCharHDDE.h"

class Defence : public QObject
{
    Q_OBJECT
public:
    explicit Defence(QObject *parent = nullptr);
    void takeDamage(int damage);
    void takeDamage(Damage *damage){takeDamage(damage->damage());}
    void addDef(int def);
    void addDef(Defence *def){defence += def->setDef();}
    void doNull(){this->defence=0;}


    int setDef();
private:
    int defence=0;
};

#endif // DEFENCE_H
