#include "footballer.h"

Footballer::Footballer(QString name, QString club, QString position, short goals, short penalty_points):
    name(name), club(club), position(position), goals(goals), penalty_points(penalty_points){
}

Footballer::~Footballer(){

}

void Footballer::setName(QString name){
    this->name = name;
}

void Footballer::setClub(QString club){
    this->club = club;
}

void Footballer::setPosition(QString position){
    this->position = position;
}

void Footballer::setGoals(short goals){
    this->goals = goals;
}

void Footballer::setPenaltyPoints(short points){
    this->penalty_points = points;
}

QString Footballer::getName() const{
    return name;
}

QString Footballer::getClub() const{
    return club;
}

QString Footballer::getPosition() const{
    return position;
}

short Footballer::getGoals() const{
    return goals;
}

short Footballer::getPenaltyPoints() const{
    return penalty_points;
}

QString Footballer::toString() const {
    return "Name: " + name + "\nClub: "
           + club + "\nPosition: " + position +
           "\nGoals: " + QString::number(goals) + "\nPenalty Points: "
           + QString::number(penalty_points);
}

