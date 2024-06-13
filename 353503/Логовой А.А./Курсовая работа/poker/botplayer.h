#ifndef BOTPLAYER_H
#define BOTPLAYER_H

#include "abstractplayer.h"

class BotPlayer : public AbstractPlayer
{
public:
    BotPlayer(QString name, int balance);

    int makeDecision(int current_bet);

    int makeMove(int current_bet);

    double calculateWinProbability(QVector<Card> allCards);
};

#endif // BOTPLAYER_H
