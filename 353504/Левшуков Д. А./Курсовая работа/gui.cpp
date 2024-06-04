#include "gui.h"
#include "game.h"
void ShowBlockInfo(std::string info, QGraphicsTextItem* t)
{
    //qDebug()<<t;
    t->show();
    t->setPlainText(QString::fromStdString(info));
    //qDebug()<<info;
}
void HideBlockInfo(QGraphicsTextItem* t)
{
    t->hide();
}
void UpdateTurnInfo(QGraphicsTextItem* t)
{
    std::string col[]={"Red","Blue","Green","Yellow"};
    if(Game::whosTurn%4==0)
        t->setDefaultTextColor(Qt::red);
    if(Game::whosTurn%4==1)
        t->setDefaultTextColor(Qt::blue);
    if(Game::whosTurn%4==2)
        t->setDefaultTextColor(Qt::green);
    if(Game::whosTurn%4==3)
        t->setDefaultTextColor(Qt::yellow);

    t->setPlainText(QString::fromStdString("Turn: Player "+col[Game::whosTurn%4]));

}

void ShowResourceInfo(std::string info,QGraphicsTextItem *t)
{
    t->setPlainText(QString::fromStdString("==Resources amount==\n"+info));
}
