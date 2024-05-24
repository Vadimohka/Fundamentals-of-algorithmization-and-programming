#include "city.h"
#include "world.h"
#include "game.h"

city::city(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    is_city=false;
    owner=-1;

    setFlag(ItemIsSelectable, false);
    setFlag(ItemIsMovable, false);
}

void city::create(short owner)
{
    is_city=true;
    this->owner=owner;
    level=1;
    switch(owner)
    {
    case 0:
        setPixmap(QPixmap(":game/resource/city.png"));
        break;
    case 1:
        setPixmap(QPixmap(":game/resource/city2.png"));
        break;
    case 2:
        setPixmap(QPixmap(":game/resource/city3.png"));
        break;
    case 3:
        setPixmap(QPixmap(":game/resource/city4.png"));
        break;
    }
    World::owners[x()/32][y()/32]=owner;
    Game::houses[Game::whosTurn%4]+=5;

}



void city::destroy()
{
    is_city=false;
    //Game::houses[Game::whosTurn%4]+=5;
    //setPixmap();
    hide();
    owner=-1;
    level=1;
    hp=100;
    grow_from=10;
    build_id=4;
    build_finish=0;
}

void city::check()
{
    if(grow_from<=0&&Game::houses[Game::whosTurn%4]--)
    {
        bool used[1440/32][896/32];

        for(int i=0;i<1440/32;i++)
            for(int j=0;j<896/32;j++)
                used[i][j]=false;

        used[(int)pos().x()/32][(int)pos().y()/32]=true;

        std::queue<std::pair<int,int>>q;
        q.push({(int)pos().x()/32,(int)pos().y()/32});
        //qDebug()<<pos();
        //qDebug()<<q.front();
        while(!q.empty())
        {
            std::pair<int,int>now1=q.front();
            q.pop();
            if(World::owners[now1.first][now1.second]==-1)
            {
                //qDebug()<<"!"<<now1;
                World::owners[now1.first][now1.second]=owner;
                World::blocks[now1.first][now1.second]->setOwner(owner);
                grow_from=10-16/level;
                level++;
                return;
            }
            for(int i=-1;i<=1;i++)
                for(int j=-1;j<=1;j++)
                {
                    if(i!=0&&j!=0)continue;
                    std::pair<int,int>now=now1;
                    now.first+=i;
                    now.second+=j;
                    if(now.first<0)
                        now.first+=1440/32;
                    if(now.first>=1440/32)
                        now.first-=1440/32;
                    if(now.second<0)
                        now.second+=896/32;
                    if(now.second>=896/32)
                        now.second-=896/32;
                   //qDebug()<<"F"<<now;
                    if(!used[now.first][now.second]&&(World::owners[now.first][now.second]==Game::whosTurn%4||World::owners[now.first][now.second]==-1))
                    {
                        used[now.first][now.second]=true;
                        q.push(now);
                    }
                }

        }

    }
}

void city::build(int id)
{

    if(id==build_id)
    {
        QMessageBox::warning(0,"Warning","Unit already training. Just wait :)");
        return;
    }
    build_id=4;
    if(id==3&&World::resource_amount[2]==0)
    {
        QMessageBox::warning(0,"Warning","You need iron to create this unit");
        return;
    }
    build_id=id;
    switch(build_id)
    {
    case 0:
        build_finish=6;
        break;
    case 1:
        build_finish=12;
        break;
    case 2:
        build_finish=3;
        break;
    case 3:
        build_finish=5;
        break;
    }
    build_finish-=level/10;
}

void city::addHp()
{
    hp+=75;
}

short city::try_spawn()
{
    if(build_finish!=0||build_id==4)return -1;
    return build_id;
}

void city::attack(short dmg)
{
    hp-=dmg;
    if(hp<=0)
        destroy();
}

bool city::getIs_city() const
{
    return is_city;
}
/*
short city::getOwner() const
{
    return owner;
}
*/
int city::getLevel() const
{
    return level;
}

int city::getGrow_from() const
{
    return grow_from;
}


void city::setGrow_from(int newGrow_from)
{
    grow_from = newGrow_from;
}

int city::getBuild_id() const
{
    return build_id;
}

int city::getBuild_finish() const
{
    return build_finish;
}

int city::getHp() const
{
    return hp;
}

void city::setBuild_finish(int newBuild_finish)
{
    build_finish = newBuild_finish;
}

void city::setBuild_id(int newBuild_id)
{
    build_id = newBuild_id;
}
/*
void city::setOwner(short newOwner)
{
    owner = newOwner;
}
*/
