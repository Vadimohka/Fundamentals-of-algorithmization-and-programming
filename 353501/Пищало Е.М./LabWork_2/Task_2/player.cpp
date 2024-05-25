#include "player.h"

Player::Player() {}
void Player::get_goals(QString goal){
    goals_num = goal.toInt();
}
void Player::get_penalty(QString penalty){
    penalty_num = penalty.toInt();
}
QString Player::print_goals(){
    QString goal = QString::number(goals_num);
    return goal;
}
QString Player::print_penalty(){
    QString pen = QString::number(penalty_num);
    return pen;
}
Player::Player(QString nam,int goals_nu,int penalty_nu,QString clu,QString rol){
    goals_num = goals_nu;
    name = nam;
    club = clu;
    role = rol;
    penalty_num = penalty_nu;
}
