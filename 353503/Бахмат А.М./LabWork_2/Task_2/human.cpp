#include "human.h"

Human::Human() {}

Human::Human(int id, QString name, int age, int height, int weight, QString habits, QString hobby, int minAge, int maxAge, int minHeight, int maxHeight, int minWeight, int maxWeight)
{
    _id = id;
    _name = name;
    _age = age;
    _height = height;
    _weight = weight;
    _habits = habits;
    _hobby = hobby;
    _minAge = minAge;
    _maxAge = maxAge;
    _minHeight = minHeight;
    _maxHeight = maxHeight;
    _minWeight = minWeight;
    _maxWeight = maxWeight;
    _isMatched = false;
}

int Human::getId()
{
    return _id;
}

QString Human::getName()
{
    return _name;
}

int Human::getAge()
{
    return _age;
}

int Human::getHeight()
{
    return _height;
}

int Human::getWeight()
{
    return _weight;
}

QString Human::getHabits()
{
    return _habits;
}

QString Human::getHobby()
{
    return _hobby;
}

int Human::getMinAge()
{
    return _minAge;
}

int Human::getMaxAge()
{
    return _maxAge;
}

int Human::getMinHeight()
{
    return _minHeight;
}

int Human::getMaxHeight()
{
    return _maxHeight;
}

int Human::getMinWeight()
{
    return _minWeight;
}

int Human::getMaxWeight()
{
    return _maxWeight;
}
