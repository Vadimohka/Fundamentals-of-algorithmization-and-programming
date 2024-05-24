#ifndef PLAYER_H
#define PLAYER_H
#include <QString>
class Player
{
public:
    Player();
    Player(QString name,int goals_num,int penalty_num,QString club,QString role);
    QString name;
    int goals_num;
    int penalty_num;
    QString club;
    QString role;
    void get_goals(QString);
    void get_penalty(QString);
    QString print_goals();
    QString print_penalty();
};

#endif // PLAYER_H
