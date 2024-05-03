#include "player.h"

Player::Player() = default;

void Player::setAmplua(QString _amplua)
{
    amplua = _amplua;
}

void Player::setName(QString _name)
{
    name = _name;
}

void Player::setSurname(QString _surname)
{
    surname = _surname;
}

void Player::setName2(QString _name2)
{
    name2 = _name2;
}

void Player::setClub(QString _club)
{
    club = _club;
}

void Player::setBalls(qint64 _balls)
{
    balls = _balls;
}

void Player::setPoints(qint64 _points)
{
    points = _points;
}

QString Player::getName()
{
    return name;
}

QString Player::getName2()
{
    return name2;
}

QString Player::getSurname()
{
    return surname;
}

QString Player::getAmplua()
{
    return amplua;
}

QString Player::getClub()
{
    return club;
}

qint64 Player::getBalls()
{
    return balls;
}

qint64 Player::getPoints()
{
    return points;
}

void Player::init(QString _surname,
                  QString _name,
                  QString _name2,
                  QString _club,
                  QString _amplua,
                  qint64 _balls,
                  qint64 _points)
{
    name = _name;
    surname = _surname;
    name2 = _name2;
    amplua = _amplua;
    club = _club;
    balls = _balls;
    points = _points;
}

void Player::sortBalls(Player *arr, int count)
{
    Player maxVal, temp;
    int index = 0;
    for (int i = 0; i < count; i++) {
        maxVal = arr[i];
        index = i;
        for (int j = i; j < count; j++) {
            if (maxVal.balls < arr[j].balls) {
                maxVal = arr[j];
                index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
}
