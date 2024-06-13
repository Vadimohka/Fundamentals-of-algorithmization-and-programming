#include "botplayer.h"
#include "const_numbers.h"
#include <QDebug>
#include <QRandomGenerator>
BotPlayer::BotPlayer(QString name, int balance) : AbstractPlayer(name, balance)  {

}

int BotPlayer::makeDecision(int current_bet)
{
    double winProbability = calculateWinProbability(cards);

    double lowerBound = -0.05;
    double upperBound = 0.2;
    double randomFactor = QRandomGenerator::global()->generateDouble() * (upperBound - lowerBound) + lowerBound;

    winProbability += randomFactor;

    if (winProbability >= 0.6)
    {
        int bet = money * 0.1;
        if (bet > current_bet)
        {
            raise(bet);
            return bet;
        }
        else
        {
            call(current_bet);
            return current_bet;
        }
    }
    else if (winProbability >= 0.4)
    {
        call(current_bet);
        return current_bet;
    }
    else if(winProbability >= 0.2){
        check();
        return 1;
    }
    else
    {
        fold();
        return 0;
    }
}

int BotPlayer::makeMove(int current_bet)
{
    double winProbability = calculateWinProbability(cards);
    double lowerBound = -0.05;
    double upperBound = 0.2;
    double randomFactor = QRandomGenerator::global()->generateDouble() * (upperBound - lowerBound) + lowerBound;

    winProbability += randomFactor;

    double riskTolerance = 1.0 - (current_bet * 1.0 / money);
    double callThreshold = 0.3 * (1 - riskTolerance);

    if (winProbability > callThreshold && money >= current_bet)
    {
        call(current_bet);
        return current_bet;
    }
    else
    {
        fold();
        return 0;
    }
}

double BotPlayer::calculateWinProbability(QVector<Card> allCards) {

    QVector<int> ranks(RANKS_SIZE, 0);
    QVector<int> suits(SUITS_SIZE, 0);

    for (const Card& card : allCards) {
        ranks[static_cast<int>(card.getValue())]++;
        suits[static_cast<int>(card.getSuit())]++;
    }

    int pair = 0, three = 0, four = 0;
    for (int i = CARD_VALUE_MIN; i <= CARD_VALUE_MAX; i++) {
        if (ranks[i] == 2)
        {
            pair++;
        }
        if (ranks[i] == 3)
        {
            three++;
        }
        if (ranks[i] == 4)
        {
            four++;
        }
    }

    int straight = 0;

    if (ranks[CARD_VALUE_MAX] && ranks[13] && ranks[12] && ranks[11] && ranks[10]) {
        straight = 1;
    }

    else if (ranks[CARD_VALUE_MAX] && ranks[CARD_VALUE_MIN] && ranks[3] && ranks[4] && ranks[5]) {
        straight = 1;
    }
    else {
        for (int i = CARD_VALUE_MIN; i <= 10; i++) {
            if (ranks[i] && ranks[i+1] && ranks[i+2] && ranks[i+3] && ranks[i+4]) {
                straight = 1;
                break;
            }
        }
    }

    int flush = 0;
    for (int i = 0; i < SUITS_SIZE; i++) {
        if (suits[i] >= FLUSH_CARDS_COUNT) {
            flush = 1;
            break;
        }
    }

    QMap<QString, double> handRanks;
    handRanks["four"] = FOUR_OF_A_KIND_PROB;
    handRanks["fullhouse"] = FULL_HOUSE_PROB;
    handRanks["flushstraight"] = FLUSH_STRAIGHT_PROB;
    handRanks["flush"] = FLUSH_PROB;
    handRanks["straight"] = STRAIGHT_PROB;
    handRanks["three"] = THREE_OF_A_KIND_PROB;
    handRanks["twopair"] = TWO_PAIR_PROB;
    handRanks["pair"] = PAIR_PROB;
    handRanks["highcard"] = HIGH_CARD_PROB;

    QString handType = "highcard";

    if (four){
        handType = "four";
    }
    else if (three && pair)
    {
        handType = "fullhouse";
    }
    else if (flush && straight)
    {
        handType = "flushstraight";
    }
    else if (flush)
    {
        handType = "flush";
    }
    else if (straight)
    {
        handType = "straight";
    }
    else if (three) {
        handType = "three";
    }
    else if (pair >= 2)
    {
        handType = "twopair";
    }
    else if (pair)
    {
        handType = "pair";
    }

    return handRanks[handType];
}
