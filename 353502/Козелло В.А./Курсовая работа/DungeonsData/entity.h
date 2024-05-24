#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
#include <QString>
#include <QVector>
#include "armor.h"
#include "constants.h"
#include "weapon.h"

class Entity : public QObject
{
    Q_OBJECT
public:
    Entity() = default;
    Entity(QString, QString, int, int, int, int, int, int, int, int, int, int);

    void setup(Entity *);
    void setup(QString, QString, int, int, int, int, int, int, int, int, int, int);

    void setDefence(int def);
    int getDefence();

    void setDamage(int dam);
    int getDamage();

    void setMod(int, int);
    int getMod(int);

    QString getName();
    void setName(QString name);

    QString getRace();
    void setRace(QString race);

    int getHealth();
    void setHealth(int);

    int getDanger();
    void setDanger(int dan);

    bool isAlive();

    void getHeart(int count);

protected:
    //модификаторы броска
    int strength;
    int dexterity;
    int constitution;
    int intellegence;
    int wisdom;
    int charisma;

    //описание
    QString name;
    QString race;
    int danger;

    //характеристики
    int health;
    int maxHealth;
    int defence = 10;
    int damage = D4;
protected slots:
};

#endif // ENTITY_H
