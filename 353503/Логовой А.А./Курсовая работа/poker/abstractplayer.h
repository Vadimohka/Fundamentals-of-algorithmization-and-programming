#ifndef ABSTRACTPLAYER_H
#define ABSTRACTPLAYER_H

#include<cards.h>
#include<const_numbers.h>

class AbstractPlayer {

protected:

    int money {};
    QString name;
    QVector<Card> cards;
    bool played;
    int rank{};
    bool has_bet{};
    int currnet_bet{};

public:

    AbstractPlayer(QString name, int balance);

    bool isPlayed();

    void addCard(Card card);

    void check();

    int call(int _money);

    void fold();

    int raise(int _money);

    void win(int prise);

    void newGame();

    int getBalance();

    QString getName();

    int getHandRank() const;

    void setStatusBet(bool value);

    bool getStatusBet() const;

    int getBalance() const;

    int getCurrentBet() const;

    void setCurrentBet(int value);

    int getHighPairCard() const;

    QPixmap getFisrtCard() const;

    QPixmap getSecondCard() const;
};


#endif // ABSTRACTPLAYER_H
