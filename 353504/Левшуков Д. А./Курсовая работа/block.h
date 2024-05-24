#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QMessageBox>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsPolygonItem>
#include <queue>
#include <stack>
#include <QTimer>
#include <QObject>
#include <QMainWindow>

#include "log.h"
#include "player.h"
#include "gui.h"
#include "city.h"
#include "button.h"

#pragma once

class Block : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    //Constructors
    Block(short,short,  QWidget*, QGraphicsScene*&,QGraphicsPolygonItem *,QGraphicsPolygonItem *,
          int** height_map,QGraphicsTextItem *, QGraphicsPixmapItem * parent=nullptr, QObject * parent2=nullptr);

    //Methods
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void getInfo();
    void selectBlock();
    void updateTexture();
    void change(int id);
    void build_city();
    bool isCity();
    void create_building();
    short tick();
    void stop_build();
    void building_pos(QPointF pos);
    void attack(short);
    //getters
    std::string get_square_info();
    short getHeight() const;

    //setters
    void setContinent(std::string newContinent);
    void setOwner(short newOwner);
    void setPlayer(Player *newPlayer);

    short getOwner() const;

    static void hideButtons();
    short getBuilding() const;

    short getResource() const;

    short getId() const;

public slots:
    // void HideError();
    // void ShowError();
    void create_builder();
    void create_settler();
    void create_knight();
    void create_knight2();
private:
    QWidget *widget;
    QGraphicsScene *scene;
    QGraphicsPolygonItem *select;
    QGraphicsPolygonItem *unit;
    QGraphicsTextItem * block_info;

    QGraphicsPixmapItem * building_texture;

    Player* player;

    std::string continent="";
    short int height;
    short int owner=-1;
    //short int building;
    short int id;
    short int resource;//4
    int** height_map;

    city * City=nullptr;


    short building=0;
    //Buttons
    static Button * unit1_button;
    static Button * unit2_button;
    static Button * unit3_button;
    static Button * unit4_button;
};

#endif // BLOCK_H
