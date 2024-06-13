#ifndef FOOTBALLER_H
#define FOOTBALLER_H

#include<QString>

class Footballer{

public:
    Footballer(QString name, QString club, QString position, short goals, short penalty_points);
    ~Footballer();

    void setName(QString name);

    void setClub(QString club);

    void setPosition(QString position);

    void setGoals(short goals);

    void setPenaltyPoints(short points);

    QString getName() const;

    QString getClub() const;

    QString getPosition() const;

    QString toString() const;

    short getGoals() const;

    short getPenaltyPoints() const;

private:
    QString name;
    QString club;
    QString position;
    short goals;
    short penalty_points;
};

#endif // FOOTBALLER_H
