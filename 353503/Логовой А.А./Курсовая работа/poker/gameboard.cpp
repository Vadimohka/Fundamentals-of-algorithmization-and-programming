#include "gameboard.h"
#include "ui_gameboard.h"
#include<QPainter>
#include<userplayer.h>
#include<botplayer.h>

GameBoard::GameBoard(QWidget *parent)
    : QDialog(parent)
    ,_menu(nullptr)
    , ui(new Ui::GameBoard)
{
    ui->setupUi(this);
    connect(ui->menu_button,&QPushButton::clicked, this,&GameBoard::openMenu);

    setWindowFlags(Qt::Window | Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    showMaximized();

    QFile file("user_money.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QString lastLine;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (!line.isEmpty())
            lastLine = line;
    }

    int balance = lastLine.toInt();
    qDebug() << balance;
    file.close();
    UserPlayer user("User", balance);
    BotPlayer bot1("Ivan", 1100);
    BotPlayer bot2("Nikalay", 1100);
    BotPlayer bot3("Misha", 1110);
    _bots.push_back(bot1);
    _bots.push_back(bot2);
    _bots.push_back(bot3);

    Dealer* dealer = new Dealer(user, _bots, ui);

    while(true){
    dealer->distribution();
    }
}

GameBoard::~GameBoard()
{
    delete ui;
}

void GameBoard::openMenu()
{
    if (!_menu) {
        _menu = new Menu(this);
    }
    _menu->exec();
}

