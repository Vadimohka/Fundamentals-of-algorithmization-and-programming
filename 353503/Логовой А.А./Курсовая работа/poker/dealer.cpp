#include "dealer.h"
#include<QGraphicsPixmapItem>
#include<timer.h>
#include <QTimer>
#include <QEventLoop>

Dealer::Dealer(UserPlayer user, QVector<BotPlayer> botsList, Ui::GameBoard *ui) : user_player(user), players(botsList),  ui(ui), scene (new QGraphicsScene()) ,
    user_hand(new QGraphicsScene()), bot_hand_0(new QGraphicsScene()), bot_hand_1(new QGraphicsScene()), bot_hand_2(new QGraphicsScene())
{
    ui->graphicsView->setScene(scene);
    ui->player_hand_view->setScene(user_hand);
    ui->bot_player_hand_view->setScene(bot_hand_0);
    ui->bot1_player_hand_view->setScene(bot_hand_1);
    ui->bot2_player_hand_view->setScene(bot_hand_2);

    bot_hands.push_back(bot_hand_0);
    bot_hands.push_back(bot_hand_1);
    bot_hands.push_back(bot_hand_2);

    bot_nicks.push_back(ui->bot_player_nick);
    bot_nicks.push_back(ui->bot1_player_nick);
    bot_nicks.push_back(ui->bot2_player_nick);

    bot_balance.push_back(ui->bot_player_balance);
    bot_balance.push_back(ui->bot1_player_balance);
    bot_balance.push_back(ui->bot2_player_balance);
    ui->raisie_slider->setMaximum(user_player.getBalance());
    hideButtons();

    for(int i{}; i < players.size(); ++i){
        bot_nicks[i]->setText(players[i].getName());
    }
    ui->user_player_nick->setText(user_player.getName());

    for(int i{}; i < players.size(); ++i){
        bot_balance[i]->setText(QString::number(players[i].getBalance()));
    }
    ui->user_player_balance->setText(QString::number(user_player.getBalance()));

    connect(ui->check_btn, &QPushButton::clicked, this,&Dealer::check);
    connect(ui->fold_btn, &QPushButton::clicked, this,&Dealer::fold);
    connect(ui->raise_btn, &QPushButton::clicked, this,&Dealer::raise);
    connect(ui->call_btn, &QPushButton::clicked, this,&Dealer::call);

    deck.initializeCards();
    deck.shuffleCards();
    bigBlind = 10;
    smallBlind = 5;
    start = 0;
    current_bet = bigBlind;
    players[0].call(bigBlind);
    players[1].call(smallBlind);
}

void Dealer::tableCard()
{
    int cardSpacing = 120;
    int initialPosition = 20;
    Card card = deck.currentCard();

    for(int i{}; i < players.size(); ++i){
        stop();
        players[i].addCard(card);
    }

    QGraphicsPixmapItem* card_image = new QGraphicsPixmapItem(card.getImage());
    card_image->setPos(initialPosition + card_count * cardSpacing, 0);
    scene->addItem(card_image);

    user_player.addCard(card);

    ++card_count;
}

void Dealer::newGame()
{
    for(int i{}; i < players.size(); ++i){
        players[i].newGame();
        bot_hands[i]->clear();
    }
    user_player.newGame();
    user_hand->clear();
    scene->clear();
    card_count = 0;
    sum = 0;
    deck.shuffleCards();

    if(start != players.size())
    {
        start++;
    }

    else
    {
        bigBlind *= 2;
        smallBlind *= 2;
        start = 0;
    }

    int pos_small{};
    int pos_big{};
    pos_small = (start + 3)%(players.size() + 1);
    pos_big = (start + 2)%(players.size() + 1);

    if(pos_big > players.size())
    {
        user_player.raise(bigBlind);
        players[pos_small].raise(smallBlind);
    }

    else if(pos_big == players.size())
    {
        user_player.raise(smallBlind);
        players[pos_small].raise(pos_small);
    }

    current_bet = bigBlind;
    ui->raisie_slider->setMaximum(user_player.getBalance());
    ui->total_sum->clear();
    ui->total_sum->setText("0");
}

void Dealer::dealCards()
{
    int cardSpacing = 120;
    int initialPosition = 20;

    QPixmap image;
    image.load("/home/blaugranas/poker_qt/card_images/back_card.png");
    QPixmap scaledImage = image.scaled(QSize(PICTURE_SIZE, PICTURE_SIZE), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    for (int i = start; i < players.size(); ++i){
        stop();
        Card card = deck.currentCard();
        players[i].addCard(card);

        QGraphicsPixmapItem* back_image = new QGraphicsPixmapItem(scaledImage);
        back_image->setPos(initialPosition + card_count * cardSpacing, 0);
        bot_hands[i]->addItem(back_image);
    }
    stop();
    Card userCard = deck.currentCard();
    user_player.addCard(userCard);

    QGraphicsPixmapItem* card_image = new QGraphicsPixmapItem(userCard.getImage());
    card_image->setPos(initialPosition + card_count * cardSpacing, 0);
    user_hand->addItem(card_image);

    for(int i = 0; i < start; ++i){
        stop();
        Card card = deck.currentCard();
        players[i].addCard(card);

        QGraphicsPixmapItem* back_image = new QGraphicsPixmapItem(scaledImage);
        back_image->setPos(initialPosition + card_count * cardSpacing, 0);
        bot_hands[i]->addItem(back_image);
    }
    ++card_count;
}



void Dealer::distribution()
{
    dealCards();
    dealCards();
    actionPlayer();
    for(int i{}; i < 3; ++i){
        tableCard();
    }
    actionPlayer();
    for(int i{}; i < 2; ++i){
        tableCard();
        actionPlayer();
    }

    determineWinner();
    newGame();
}


void Dealer::actionPlayer()
{

    int current_player_index = start;
    int moves = players.size()  + 1;

    for(int  i{}; i < moves; ++i)
    {
        ui->raisie_slider->setMaximum(user_player.getBalance());
        ui->total_sum->clear();
        ui->total_sum->setText(QString::number(sum));

        if(current_player_index == players.size())
        {
            if(user_player.isPlayed() &&  user_player.getBalance() > 0)
            {
            showButtons();
            ui->call_btn->setText("CALL" + QString::number(current_bet - user_player.getCurrentBet()));
            ui->user_player_nick->clear();
            ui->user_player_nick->setTextColor(Qt::green);
            ui->user_player_nick->setText(user_player.getName());

            waitForAction();
            ui->user_player_nick->clear();
            ui->user_player_nick->setTextColor(Qt::red);
            ui->user_player_nick->setText(user_player.getName());
            }

            current_player_index = -1;
            hideButtons();
            ui->user_player_balance->clear();
            ui->user_player_balance->setText(QString::number(user_player.getBalance()));
        }

        else
        {
            if (players[current_player_index].isPlayed() && players[current_player_index].getBalance() > 0 )
            {

                bot_nicks[current_player_index]->clear();
                bot_nicks[current_player_index]->setTextColor(Qt::green);
                bot_nicks[current_player_index]->setText(players[current_player_index].getName());
                bot_nicks[current_player_index]->setTextColor(Qt::red);
                stop();
                stop();
                int player_action = players[current_player_index].makeDecision(current_bet);

                sum += player_action;

                // if (player_action == 0 && current_bet != 0)
                // {
                //     players[current_player_index].fold();
                // }

                ui->raisie_slider->setMinimumWidth(current_bet);
                stop();
                bot_balance[current_player_index]->clear();
                bot_balance[current_player_index]->setText(QString::number(players[current_player_index].getBalance()));
                bot_nicks[current_player_index]->clear();
                bot_nicks[current_player_index]->setText(players[current_player_index].getName());
            }

            if(players[current_player_index].isPlayed() == false)
            {
                bot_hands[current_player_index]->clear();
                players[current_player_index].fold();
            }
        }

        ui->total_sum->clear();
        ui->total_sum->setText(QString::number(sum));
        current_player_index++;
    }


    for(int i{}; i < moves; ++i ){
        ui->total_sum->clear();
        ui->total_sum->setText(QString::number(sum));
        if(current_player_index == players.size())
        {
            ui->raisie_slider->setMaximum(user_player.getBalance());
            if(user_player.isPlayed() && user_player.getCurrentBet() != current_bet && user_player.getBalance() > 0)
            {
                ui->call_btn->show();
                ui->call_btn->setEnabled(true);
                ui->call_btn->setText("CALL" + QString::number(current_bet));
                ui->fold_btn->show();
                ui->fold_btn->setEnabled(true);
                waitForAction();
                ui->user_player_balance->clear();
                ui->user_player_balance->setText(QString::number(user_player.getBalance()));
            }
            current_player_index = -1;
            hideButtons();
        }

        else
        {
            if(players[current_player_index].isPlayed() && players[current_player_index].getCurrentBet() <  current_bet)
            {

                sum += players[current_player_index].makeMove(current_bet);
            }

            else if(players[current_player_index].isPlayed())
            {
                players[current_player_index].check();
            }

            bot_balance[current_player_index]->clear();
            bot_balance[current_player_index]->setText(QString::number(players[current_player_index].getBalance()));
        }
        ui->total_sum->clear();
        ui->total_sum->setText(QString::number(sum));
        current_player_index++;
    }

    for(int i{}; i < players.size(); ++i){
        players[i].setCurrentBet(0);
    }

    user_player.setCurrentBet(0);
    current_bet = 0;
}

void Dealer::determineWinner() {
    int highest_rank = -1;
    int best_bot = -1;
    QFile file("winners.txt");
    QFile file_money("user_money.txt");
    showCards();
    stop(3000);
    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        return;
    }

    else
    {
    QTextStream out(&file);

    for (int i = 0; i < players.size(); i++)
    {
        if(players[i].isPlayed())
        {
            int botRank = players[i].getHandRank();

            if(botRank == highest_rank && best_bot != - 1)
            {
                best_bot = (players[best_bot].getHighPairCard() >= players[i].getHighPairCard()) ? best_bot : i;
            }

            else if (botRank > highest_rank)
            {
                highest_rank = botRank;
                best_bot = i;
            }
        }
    }

    int userRank = -1;

    if(user_player.isPlayed())
    {
     userRank = user_player.getHandRank();
    }

    if (userRank > highest_rank)
    {
        out << "Победитель: " << user_player.getName() << " с рангом руки: " << userRank << " сумма выигрыша : " << sum << "\n";
        user_player.win(sum);
        ui->user_player_nick->clear();
        ui->user_player_nick->setTextColor(Qt::green);
        ui->user_player_nick->setText("WInner");
        stop(3000);
        ui->user_player_nick->setTextColor(Qt::red);
        ui->user_player_nick->clear();
        ui->user_player_nick->setText(user_player.getName());

    }
    else if(userRank == highest_rank && user_player.getHighPairCard() > players[best_bot].getHighPairCard())
    {
        out << "Победитель: " << user_player.getName() << " с рангом руки: " << userRank << " сумма выигрыша : " << sum << "\n";
        user_player.win(sum);
        ui->user_player_nick->clear();
        ui->user_player_nick->setTextColor(Qt::green);
        ui->user_player_nick->setText("WInner");
        stop(3000);
        ui->user_player_nick->setTextColor(Qt::red);
        ui->user_player_nick->clear();
        ui->user_player_nick->setText(user_player.getName());
    }

    else
    {
        bot_nicks[best_bot]->clear();
        bot_nicks[best_bot]->setTextColor(Qt::green);
        bot_nicks[best_bot]->setText("Winner");
        bot_nicks[best_bot]->setTextColor(Qt::red);
        stop(3000);
        bot_nicks[best_bot]->clear();
        bot_nicks[best_bot]->setText(players[best_bot].getName());

        players[best_bot].win(sum);
        out << "Победитель: " << players[best_bot].getName() << " с рангом руки: " << highest_rank << " сумма выигрыша : " << sum << "\n";
    }

    file.close();
    }

    if (!file_money.open(QIODevice::Append | QIODevice::Text))
    {
        return;
    }

    else
    {
        QTextStream outs(&file_money);

        outs << user_player.getBalance() << "\n";

        file_money.close();
    }

    ui->total_sum->clear();
}

void Dealer::hideButtons()
{
    ui->call_btn->hide();
    ui->call_btn->setEnabled(false);
    ui->check_btn->hide();
    ui->check_btn->setEnabled(true);
    ui->raise_btn->hide();
    ui->raise_btn->setEnabled(false);
    ui->fold_btn->hide();
    ui->fold_btn->setEnabled(false);
    ui->raisie_slider->hide();
    ui->raisie_slider->setEnabled(false);
}
#include <QDebug>
void Dealer::showButtons()
{
    ui->call_btn->show();
    ui->call_btn->setEnabled(true);
    ui->check_btn->show();
    ui->check_btn->setEnabled(true);
    ui->fold_btn->show();
    ui->fold_btn->setEnabled(true);
    ui->raise_btn->show();
    ui->raise_btn->setEnabled(true);
    ui->raisie_slider->show();
    ui->raisie_slider->setEnabled(true);
}

void Dealer::waitForAction()
{
    QTimer timer;
    QEventLoop loop;
    timer.setSingleShot(true);

    QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    QObject::connect(ui->call_btn, &QPushButton::clicked, &loop, &QEventLoop::quit);
    QObject::connect(ui->check_btn, &QPushButton::clicked, &loop, &QEventLoop::quit);
    QObject::connect(ui->raise_btn, &QPushButton::clicked, &loop, &QEventLoop::quit);
    QObject::connect(ui->fold_btn, &QPushButton::clicked, &loop, &QEventLoop::quit);

    timer.start(5000);

    loop.exec();

    if(timer.isActive())
    {
        timer.stop();
    }
    else
    {
        fold();
    }

    QObject::disconnect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    QObject::disconnect(ui->call_btn, &QPushButton::clicked, &loop, &QEventLoop::quit);
    QObject::disconnect(ui->check_btn, &QPushButton::clicked, &loop, &QEventLoop::quit);
    QObject::disconnect(ui->raise_btn, &QPushButton::clicked, &loop, &QEventLoop::quit);
    QObject::disconnect(ui->fold_btn, &QPushButton::clicked, &loop, &QEventLoop::quit);
}

void Dealer::showCards()
{
    for(int i{}; i < players.size(); ++i){
        if(players[i].isPlayed()){
            bot_hands[i]->clear();
            QGraphicsPixmapItem* fisrt_card_image = new QGraphicsPixmapItem(players[i].getFisrtCard());
            QGraphicsPixmapItem* second_card_image = new QGraphicsPixmapItem(players[i].getSecondCard());
            bot_hands[i]->addItem(fisrt_card_image);
            second_card_image->setPos(fisrt_card_image->x() + fisrt_card_image->boundingRect().width() + 20, 0);
            bot_hands[i]->addItem(second_card_image);
        }
    }
}


void Dealer::check()
{
    user_player.check();
}

int Dealer::call()
{
    user_player.call(current_bet);
    sum += current_bet;
    return current_bet;
}

int Dealer::raise()
{
    int raise = ui->raisie_slider->value();
    current_bet = raise >  current_bet ? raise : current_bet;
    user_player.raise(raise);
    sum += raise;
    return raise;
}

void Dealer::fold()
{
    user_player.fold();
    user_hand->clear();
}



