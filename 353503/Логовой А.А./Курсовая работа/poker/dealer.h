#ifndef DEALER_H
#define DEALER_H
#include<deck.h>
#include<userplayer.h>
#include<botplayer.h>
#include<QGraphicsView>
#include<ui_gameboard.h>
#include<QTimer>
#include<QPushButton>
#include <QFile>
#include <QTextStream>

class Dealer : public QObject
{
private:

    UserPlayer user_player;
    QVector<BotPlayer>players;
    Deck deck;
    int smallBlind{};
    int bigBlind{};
    int handCount{};
    int current_bet{};
    int start{};
    int sum{};
    int current_rate{};
    int card_count = 0;
    Ui::GameBoard *ui;
    QGraphicsScene* scene;
    QGraphicsScene* user_hand;
    QGraphicsScene* bot_hand_0;
    QGraphicsScene* bot_hand_1;
    QGraphicsScene* bot_hand_2;
    QVector <QGraphicsScene* > bot_hands;
    QVector <QTextEdit* > bot_nicks;
    QVector <QTextEdit* > bot_balance;

public:

    Dealer(UserPlayer user, QVector<BotPlayer> botsList,  Ui::GameBoard *ui);

    void tableCard();

    void newGame();

    void dealCards();

    void distribution();

    void actionPlayer();

    void determineWinner();

    void hideButtons();

    void showButtons();

    void waitForAction();

    void showCards();

public slots:

    void check();

    int call();

    int raise();

    void fold();

};

#endif // DEALER_H
