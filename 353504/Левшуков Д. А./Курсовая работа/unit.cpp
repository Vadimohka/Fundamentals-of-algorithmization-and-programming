#include "unit.h"

#include "game.h"
#include "world.h"
//extern long long Game::whosTurn;

Unit::Unit(QGraphicsScene*& scene,int ** used,  std::pair<int,int>** map, QGraphicsPolygonItem *& select,QGraphicsPolygonItem *& select_block, Button *& action_button,int n) {
    this->scene=scene;
    owner=n;
    this->used=used;
    this->select_block=select_block;
    this->map=map;
    this->select=select;

    this->action_button=action_button;
    moves=1;

}

void Unit::Spawn(int id)
{
    this->id=id;
    SetAttributes();
    std::mt19937_64 gen(time(0));
    int x1,y1;
    do{
        x1=gen()%(1440/32);
        y1=gen()%(896/32);
    }while(used[x1][y1]||map[x1][y1].first==0);
    setPos(x1*32+11/2,y1*32+11/2);
    used[x1][y1]=owner;
    drawUnit();
}

void Unit::Spawn(int id, double x, double y)
{
    this->id=id;
    qDebug()<<"id"<<id;
    if(id==1)
        id=3;
    else
        if(id==2)
    {
        id=1;
    }
    else if(id==3)
    {
        id=2;
    }
    SetAttributes();
    setPos(x,y);
    used[(int)(x-11/2)/32][(int)(y-11/2)/32]=owner;
    drawUnit();
    //qDebug()<<scene();
}

void Unit::drawUnit()
{/*
    if(map[(int)(x()/32)][(int)(y()/32)].first==0)
        return setPixmap(QPixmap(":game/resource/ship.png"));
*/
    switch(id)
    {
    case 0:
        switch(owner)
        {
        case 1:
            setPixmap(QPixmap(":game/resource/builder.png"));
            break;
        case 2:
            setPixmap(QPixmap(":game/resource/builder2.png"));
            break;
        case 3:
            setPixmap(QPixmap(":game/resource/builder3.png"));
            break;
        case 4:
            setPixmap(QPixmap(":game/resource/builder4.png"));
            break;
        }
        break;
    case 1:
        switch(owner)
        {
        case 1:
            setPixmap(QPixmap(":game/resource/knight.png"));
            break;
        case 2:
            setPixmap(QPixmap(":game/resource/knight2.png"));
            break;
        case 3:
            setPixmap(QPixmap(":game/resource/knight3.png"));
            break;
        case 4:
            setPixmap(QPixmap(":game/resource/knight4.png"));
            break;
        }
        break;
    case 2:
        switch(owner)
        {
        case 1:
            setPixmap(QPixmap(":game/resource/knight_2.png"));
            break;
        case 2:
            setPixmap(QPixmap(":game/resource/knight_22.png"));
            break;
        case 3:
            setPixmap(QPixmap(":game/resource/knight_23.png"));
            break;
        case 4:
            setPixmap(QPixmap(":game/resource/knight_24.png"));
            break;
        }
        break;
    case 3:
        switch(owner)
        {
        case 1:
            setPixmap(QPixmap(":game/resource/settler.png"));
            break;
        case 2:
            setPixmap(QPixmap(":game/resource/settler2.png"));
            break;
        case 3:
            setPixmap(QPixmap(":game/resource/settler3.png"));
            break;
        case 4:
            setPixmap(QPixmap(":game/resource/settler4.png"));
            break;
        }
        break;
    }
}

void Unit::SetAttributes()
{
    switch(id)
    {
    case 0:
        attack=0,hp=10,actions=3;
        break;
    case 1:
        attack=15,hp=10,actions=-1;
        break;
    case 2:
        attack=20,hp=15,actions=-1;
        break;
    case 3:
        attack=0,hp=10,actions=1;
        break;
    }
}

void Unit::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)//Select unit
    {
        //<<select;
        qDebug()<<pos();
        select->setPos(pos());

        //qDebug()<<(Game::whosTurn)%4+1<<" "<<owner;
        if((Game::whosTurn)%4+1==owner&&id!=1&&id!=2)
            action_button->setPos(1441,730);
        else
            action_button->setPos(-32,-32);
        select_block->setPos(-32,-32);

    }
    if(event->buttons() & Qt::RightButton)//Unselect unit
    {
        select->setPos(-32,-32);
        action_button->setPos(-32,-32);

    }
}


void Unit::hide_select()
{
    select->setPos(x(),y());
}

int Unit::getMoves() const
{
    return moves;
}

void Unit::kill()
{
    qDebug()<<scene;
    scene->removeItem(this);
}

void Unit::setMoves(int newMoves)
{
    moves = newMoves;
}

void Unit::action()
{
    //qDebug()<<"unit:"<<this->scene();
    switch(id)
    {
    case 0:
        if(World::choosed_block->getResource()==0)
        {
            QMessageBox::warning(0,"Error","This field haven't resource to collect");
            return;
        }
        if(World::choosed_block->getOwner()!=Game::whosTurn%4)
        {
            QMessageBox::warning(0,"Error","You can't place building these. You should be owner of this field");
            return;
        }
        if(!((World::choosed_block->getBuilding()<=3&&World::choosed_block->isCity())||(World::choosed_block->getBuilding()==0&&!World::choosed_block->isCity())))
        {
            QMessageBox::warning(0,"Error","You build this yet. Find another place");
            return;
        }
        actions--;

        //qDebug()<<(World::choosed_block);
        World::choosed_block->create_building();
        select->setPos(-32,-32);
        action_button->setPos(-32,-32);
        break;
    case 3:
        if(World::choosed_block->isCity())
        {
            QMessageBox::warning(0,"Error","You can't place city these");
            return;
        }
        actions--;
        World::choosed_block->build_city();
        select->setPos(-32,-32);
        action_button->setPos(-32,-32);
        break;

    default:
        break;

    }
}

int Unit::getActions() const
{
    return actions;
}

int Unit::getId() const
{
    return id;
}

int Unit::getAttack() const
{
    return attack;
}

int Unit::getOwner() const
{
    return owner;
}
