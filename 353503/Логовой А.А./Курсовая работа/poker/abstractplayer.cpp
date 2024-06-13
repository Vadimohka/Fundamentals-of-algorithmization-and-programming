#include "abstractplayer.h"

AbstractPlayer::AbstractPlayer(QString name, int balance):  money(balance), name(name), played{true} {}

bool AbstractPlayer::isPlayed()
{
    return played;
}

void AbstractPlayer::addCard(Card card)
{
    cards.push_back(card);
}


void AbstractPlayer::check()
{
    played = true;
}

int AbstractPlayer::call(int _money)
{
    played = true;
    money -= _money - getCurrentBet();
    setCurrentBet(_money);
    return _money;
}

void AbstractPlayer::fold()
{
    played = false;
}

int AbstractPlayer::raise(int _money)
{
    money -= _money - getCurrentBet();
    setCurrentBet(_money);
    return _money;
}

void AbstractPlayer::win(int prise)
{
    played = true;
    money += prise;
}

void AbstractPlayer::newGame()
{
    played = true;
    cards.clear();
}

int AbstractPlayer::getBalance()
{
    return money;
}

QString AbstractPlayer::getName()
{
    return name;
}

int AbstractPlayer::getHandRank() const {
    QVector<int> cardCounts(15, 0);
    QVector<int> suitCounts(4, 0);

    for (const Card& card : cards) {
        cardCounts[static_cast<int>(card.getValue())]++;
        suitCounts[static_cast<int>(card.getSuit())]++;
    }

    QVector<int> pairs;
    bool hasThreeOfAKind = false;

    for (int i = CARD_VALUE_MIN; i <= CARD_VALUE_MAX; i++) {
        if (cardCounts[i] == 2)
        {
            pairs.push_back(i);
        }
        else if (cardCounts[i] == 3)
        {
            hasThreeOfAKind = true;
        }
        else if (cardCounts[i] == 4)
        {
            return HAND_RANK_FOUR_OF_A_KIND;
        }
    }

    if (pairs.size() >= 2) {
        return HAND_RANK_FULL_HOUSE;
    }

    if (hasThreeOfAKind && !pairs.empty()) {
        return HAND_RANK_FULL_HOUSE;
    }

    if (cardCounts[CARD_VALUE_MAX] && cardCounts[2] && cardCounts[3] && cardCounts[4] && cardCounts[5]) {
        return HAND_RANK_STRAIGHT;
    }

    for (int i = CARD_VALUE_MIN; i <= CARD_VALUE_MAX - 4; i++) {
        if (cardCounts[i] && cardCounts[i+1] && cardCounts[i+2] && cardCounts[i+3] && cardCounts[i+4]) {
            return HAND_RANK_STRAIGHT;
        }
    }

    for (int i = 0; i < SUIT_COUNT; i++) {
        if (suitCounts[i] >= 5) {
            return HAND_RANK_FLUSH;
        }
    }

    if (hasThreeOfAKind) {
        return HAND_RANK_THREE_OF_A_KIND;
    }

    if (!pairs.empty()) {
        return HAND_RANK_PAIR;
    }

    return HAND_RANK_HIGH_CARD;
}

void AbstractPlayer::setStatusBet(bool value)
{
    has_bet = value;
}

bool AbstractPlayer::getStatusBet() const
{
    return has_bet;
}

int AbstractPlayer::getBalance() const
{
    return money;
}

int AbstractPlayer::getCurrentBet() const
{
    return currnet_bet;
}

void AbstractPlayer::setCurrentBet(int value)
{
    currnet_bet = value;
}

int AbstractPlayer::getHighPairCard() const {
    QVector<int> cardCounts(15, 0);

    for (const Card& card : cards) {
        cardCounts[static_cast<int>(card.getValue())]++;
    }

    int highPairCard = 0;
    for (int i = 2; i <= 14; i++) {
        if (cardCounts[i] == 2 && i > highPairCard) {
            highPairCard = i;
        }
    }

    return highPairCard;
}

QPixmap AbstractPlayer::getFisrtCard() const
{
    return cards[0].getImage();
}

QPixmap AbstractPlayer::getSecondCard() const
{
    return cards[1].getImage();
}


