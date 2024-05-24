#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QPushButton>
#include <button.h>
#include <QFont>
#include "world.h"
#include "log.h"
#include "player.h"

#pragma once



class Game : public QGraphicsView
{
    Q_OBJECT
public:
    //Costructors
    Game(QWidget* parent=NULL);

    //Methods
    void turn_update();
    //Attributes

    //Fields
    static long long whosTurn;
    static long long houses[];
    static QVector<Player *>players;
    //Slots
public slots:
    void next_turn();
    void giveUp();
    void openMain();
signals:
    void mainWindow();
private:
    QGraphicsScene* scene;
    QGraphicsPolygonItem* select_block;
    QGraphicsPolygonItem* select_unit;
    QGraphicsTextItem *block_info;
    QGraphicsTextItem *turn_info;
    QGraphicsTextItem *res_info;

    Button *skip_button;
    Button *give_up;

    World* map;

    int alive=4;

};

#endif // GAME_H
