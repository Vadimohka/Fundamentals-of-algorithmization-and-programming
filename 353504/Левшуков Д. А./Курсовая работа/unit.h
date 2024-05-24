#ifndef UNIT_H
#define UNIT_H
#include <QGraphicsPixmapItem>
#include <ctime>
#include <random>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "button.h"

#pragma once

class Unit : public QGraphicsPixmapItem
{
//    Q_OBJECT
public:
    Unit(QGraphicsScene*&, int**, std::pair<int,int>** map, QGraphicsPolygonItem *&,QGraphicsPolygonItem *&,Button *&,int);
    void Spawn(int);
    void Spawn(int,double x,double y);
    void drawUnit();
    void SetAttributes();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hide_select();
    int getMoves() const;
    void kill();

    void setMoves(int newMoves);

    void action();

    int getActions() const;

    int getId() const;

    int getAttack() const;

    int getOwner() const;

private:
    int id;
    int attack;
    int hp;
    int actions;
    int moves;
    int owner;
    //int moves;
    QGraphicsScene* scene;
    int **used;
    std::pair<int,int> **map;
    QGraphicsPolygonItem * select;
    QGraphicsPolygonItem * select_block;

    Button * action_button;
};

#endif // UNIT_H
