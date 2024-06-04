#include "entity.h"

Entity::Entity(QString name,
               QString race,
               int health,
               int str,
               int dex,
               int con,
               int intel,
               int wis,
               int cha,
               int danger,
               int defence,
               int damage)
    : strength(str)
    , dexterity(dex)
    , constitution(con)
    , intellegence(intel)
    , wisdom(wis)
    , charisma(cha)
    , name(name)
    , race(race)
    , danger(danger)
    , health(health)
    , maxHealth(health)
    , defence(defence)
    , damage(damage)
{}

void Entity::setup(Entity *other)
{
    strength = other->strength;
    dexterity = other->dexterity;
    constitution = other->constitution;
    intellegence = other->intellegence;
    wisdom = other->wisdom;
    charisma = other->charisma;
    name = other->name;
    race = other->race;
    health = other->health;
    maxHealth = health;
    defence = other->defence;
    damage = other->damage;
    danger = other->danger;
}

void Entity::setup(QString name,
                   QString race,
                   int health,
                   int str,
                   int dex,
                   int con,
                   int intel,
                   int wis,
                   int cha,
                   int danger,
                   int defence,
                   int damage)
{
    strength = str;
    dexterity = dex;
    constitution = con;
    intellegence = intel;
    wisdom = wis;
    charisma = cha;
    this->name = name;
    this->race = race;
    this->health = health;
    maxHealth = health;
    this->danger = danger;
    this->defence = defence;
    this->damage = damage;
}

void Entity::setDefence(int def)
{
    defence = def;
}

int Entity::getDefence()
{
    return defence;
}

void Entity::setDamage(int dam)
{
    damage = dam;
}

int Entity::getDamage()
{
    return damage;
}

void Entity::setMod(int mod, int value)
{
    switch (mod) {
    case STRENGTH:
        strength = value;
        break;
    case DEXTERITY:
        dexterity = value;
        break;
    case CONSTITUTION:
        constitution = value;
        break;
    case INTELLEGENCE:
        intellegence = value;
        break;
    case WISDOM:
        wisdom = value;
        break;
    case CHARISMA:
        charisma = value;
        break;
    default:
        break;
    }
}

int Entity::getMod(int mod)
{
    switch (mod) {
    case STRENGTH:
        return strength;
        break;
    case DEXTERITY:
        return dexterity;
        break;
    case CONSTITUTION:
        return constitution;
        break;
    case INTELLEGENCE:
        return intellegence;
        break;
    case WISDOM:
        return wisdom;
        break;
    case CHARISMA:
        return charisma;
        break;
    default:
        return INT_MAX;
        break;
    }
}

QString Entity::getName()
{
    return name;
}

void Entity::setName(QString name)
{
    this->name = name;
}

QString Entity::getRace()
{
    return race;
}

void Entity::setRace(QString race)
{
    this->race = race;
}

int Entity::getHealth()
{
    return health;
}

void Entity::setHealth(int newHealth)
{
    health = newHealth;
}

int Entity::getDanger()
{
    return danger;
}

void Entity::setDanger(int dan)
{
    danger = dan;
}

bool Entity::isAlive()
{
    return health != 0;
}

void Entity::getHeart(int count)
{
    if (count > health) {
        health = 0;
    } else if (count >= 0) {
        health -= count;
    }
}
