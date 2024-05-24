#ifndef PLAYER_H
#define PLAYER_H
#include "unit.h"
#include <QList>
#include "button.h"
#pragma once

class Player
{
public:
    Player(QGraphicsScene *&scene, int ** used,  std::pair<int,int>** map, QGraphicsPolygonItem *&select,QGraphicsPolygonItem *&,Button *& action_button,int);
    QList<Unit *> getUnits() const;
    bool move_unit(QPointF pos, int x1,int y1);
    void show_units();
    bool getLose() const;
    Unit* getUnit(QPointF);
    QVector<int>resource_amount={0,0,0,0,0};
    //static void try_to_spawn();
    bool Spawn(double x,double y,int id);

    void del_unit(int);
    void setLose(bool newLose);

private:
    QList<Unit*>units;
    QGraphicsScene *scene;
    int ** used;
    std::pair<int,int>** map;
    QGraphicsPolygonItem * select;
    QGraphicsPolygonItem * select_block;

    int number;
    bool lose=false;

    int houses=0;

    Button * action_button;


};

#endif // PLAYER_H
