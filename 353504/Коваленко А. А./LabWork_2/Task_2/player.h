#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player
{
public:
    Player();
    void setName(QString);
    void setSurname(QString);
    void setName2(QString);
    void setClub(QString);
    void setAmplua(QString);
    void setBalls(qint64);
    void setPoints(qint64);

    QString getName();
    QString getSurname();
    QString getName2();
    QString getClub();
    QString getAmplua();
    qint64 getBalls();
    qint64 getPoints();

    void init(QString, QString, QString, QString, QString, qint64, qint64);
    static void sortBalls(Player *, int);

private:
    QString surname;
    QString name;
    QString name2;
    QString club;
    QString amplua;
    qint64 balls;
    qint64 points;
};

#endif // PLAYER_H
