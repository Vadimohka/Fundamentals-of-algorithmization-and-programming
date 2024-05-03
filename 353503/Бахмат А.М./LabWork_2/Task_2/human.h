#ifndef HUMAN_H
#define HUMAN_H

#include <QString>

class Human
{
public:
    Human();
    Human(int, QString, int, int, int, QString, QString, int, int, int, int, int, int);
    int getId();
    QString getName();
    int getAge();
    int getHeight();
    int getWeight();
    QString getHabits();
    QString getHobby();
    int getMinAge();
    int getMaxAge();
    int getMinHeight();
    int getMaxHeight();
    int getMinWeight();
    int getMaxWeight();
    int _id;
    QString _name;
    int _age;
    int _height;
    int _weight;
    QString _habits;
    QString _hobby;
    int _minAge;
    int _maxAge;
    int _minHeight;
    int _maxHeight;
    int _minWeight;
    int _maxWeight;
    bool _isMatched;
private:

};

#endif // HUMAN_H
