#include "world.h"
#include "game.h"

Block * World::choosed_block=nullptr;
std::pair<int,int> **World::map=nullptr;
QVector<QVector<int>>World::owners;
QList<QList<Block*>>World::blocks;
QVector<int> World::resource_amount={0,0,0,0,0};
World::World(QGraphicsScene*& scene, QWidget* w, QGraphicsPolygonItem *& select,
             QGraphicsPolygonItem *& select_unit,QGraphicsTextItem *& block_info,
             QVector<Player*> &players_, QObject*parent):players(players_), QObject(parent)
{

    choosed_block=nullptr;
    map=nullptr;
    owners.clear();
    blocks.clear();
    resource_amount={0,0,0,0,0};


    action_button=new Button("⚒️",160,50);
    action_button->setPos(-32,-32);
    QObject::connect(action_button,SIGNAL(clicked()),this,SLOT(action()));
    scene->addItem(action_button);
    this->scene=scene;
    this->select_unit=select_unit;
    this->select=select;
    //qDebug()<<scene;
    widget=w;
    gen.seed(time(0));

    blocks.resize(1440/32);
    owners.resize(1440/32);
    for(int i=0;i<1440/32;i++)
    {
        blocks[i].resize(896/32);
        owners[i].resize(896/32);
        for(int j=0;j<896/32;j++)
            owners[i][j]=-1;
    }
    this->block_info=block_info;
    placeBlocks();
    normalise_world();

    //qDebug()<<select;
    scene->addItem(select);
    scene->addItem(select_unit);
    contenent_distribution();

    //this->players=players;
    for(int i=0;i<4;i++){
        players[i]=new Player(scene,getUnitstay(), getMap(),select_unit,select,action_button,i);
        //qDebug()<<players_[i]<<" "<<this->players[i];
    }


    set_player(this->players[0]);


}

void World::placeBlocks()
{
    unitstay=new int*[1440/32];
    map = new std::pair<int,int>*[1440/32];
    height_map=new int*[1440/32];

    for(int i=0;i<1440/32;i++)
    {
        unitstay[i]=new int[896/32];
        for(int j=0;j<896/32;j++)
            unitstay[i][j]=false;
    }
    for(int i=0;i<1440/32;i++)
    {

        map[i]=new std::pair<int,int>[896/32];
        height_map[i]=new int[896/32];

        for(int j=0;j<896/32;j++)
        {
            short id=generate_block(),res=gen_res(id);
            if(i==0||i==1440/32-1||j==0||j==896/32-1)
                id=0,res=gen_res(id);
            map[i][j]={id,res};

            Block* block=new Block(id,res, widget,scene,select,select_unit, height_map, block_info);

            height_map[i][j]=block->getHeight();

            block->setPos(32*i,32*j);

            blocks[i][j]=block;
            //qDebug()<<block;
            scene->addItem(block);
            block->building_pos(QPointF(32*i,32*j));
        }

    }
}

short World::generate_block()
{

    //Water gen
    short g=gen()%8;

    if(g<1)
    {
        return 0;
    }

    //Other block type gen
    g=gen()%10;

    if(g>0)
        return 1;
    return 2;
}

short World::gen_res(short id)
{
    short res;
    //0 - nothing 1 - wheat 2 - stone 3 - iron 4 - fish
    if(id==0)
    {
        res=gen()%10;

        if(res!=4)
            return 0;

        return 4;

    }
    if(id==1)
    {
        res=gen()%6;

        if(res==0)
        {
            res=gen()%10;

            if(res<6)
                return 1;

            if(res<8)
                return 2;

                return 3;
        }

        return 0;
    }
    if(id==2)
    {
        res=gen()%3;

        if(res==0)
        {
            res=gen()%10;

            if(res<6)
                return 2;

            return 3;
        }

        return 0;
    }
}

void World::normalise_world()
{

    add_log("Normalise world started");
    for(int i=1;i<1440/32-1;i++)
        for(int j=1;j<896/32-1;j++)
        {

            if(height_map[i][j]==2)
            if(i+1<1440/32&&abs(height_map[i][j]-height_map[i+1][j])>1)
            {
                if(i-1>=0&&abs(height_map[i][j]-height_map[i-1][j])>1)
                {
                    if(j-1>=0&&abs(height_map[i][j]-height_map[i][j-1])>1)
                    {
                        if(j+1<896/32&&abs(height_map[i][j]-height_map[i][j+1])>1)
                        {
                            getBlock(i*32,j*32)->change(1);
                            add_log("Normalise: "+std::to_string(i)+" "+std::to_string(j));
                        }
                    }
                }
            }

        }


    for(int i=1;i<1440/32-1;i++)
        for(int j=1;j<896/32-1;j++)
            visited[i][j]=0;

    int c=1;
    for(int i=1;i<1440/32-1;i++)
        for(int j=1;j<896/32-1;j++)
        {

            if(visited[i][j]==0)
            {
            kol[c]=0;
            dfs(i,j,c);
            c++;
            }
        }

    while(c!=0)
    {
        if(kol[c]<3)
        {
            for(int i=1;i<1440/32-1;i++)
                for(int j=1;j<896/32-1;j++)
                {
                    if(visited[i][j]==c)
                    {
                        getBlock(i*32,j*32)->change(0);
                    }
                }
        }
        c--;
    }

    //Bridges

    timer=0;
    for(int i=0;i<1440/32;i++)
        for(int j=0;j<896/32;j++)
            visited[i][j]=0,fup[i][j]=tin[i][j]=30000;

    for(int i=1;i<1440/32-1;i++)
        for(int j=1;j<896/32-1;j++)
        {

            if(visited[i][j]==0)
            {
                dfs2(i,j);
            }
        }

    //qDebug()<<bridges.size();

    for(auto& i:bridges)
    {
        getBlock(i.first,i.second)->change(0);
    }
    add_log("Normalise world ended");

}

void World::contenent_name_creator()
{
    for(int i=0;i<35;i++)
        for(int j=i,n=35;n!=0;n--,j++)
        {
            contenent_name[i*35+35-n]=s1[j]+s2[i];
        }
}

void World::contenent_distribution()
{
    contenent_name_creator();

    bool **used=new bool*[1440/32];
    for(int i=0;i<1440/32;i++)
    {

        used[i]=new bool[896/32];
        for(int j=0;j<896/32;j++)
        {

            used[i][j]=false;
        }

    }

    int num=-1;
    for(int i=1;i<1440/32;i++)
    {
        for(int j=1;j<896/32;j++)
        {

            if(!used[i][j]&&map[i][j].first!=0)
            {
                num++;
                std::queue<std::pair<int,int>>q;
                q.push({i,j});
                used[i][j]=true;
                while(!q.empty())
                {
                    std::pair<int,int>pos=q.front();
                    q.pop();

                    //qDebug()<<"------------------------------";
                    getBlock(pos.first*32,pos.second*32)->setContinent(contenent_name[num]);
                    //qDebug()<<pos<<" "<<num<<" "<<getBlock(pos.first*32,pos.second*32);
                    //qDebug()<<"==============================";
                    if(map[pos.first-1][pos.second].first>0&&!used[pos.first-1][pos.second])
                    {
                        used[pos.first-1][pos.second]=true;
                        q.push({pos.first-1,pos.second});
                    }
                    if(map[pos.first+1][pos.second].first>0&&!used[pos.first+1][pos.second])
                    {
                        used[pos.first+1][pos.second]=true;
                        q.push({pos.first+1,pos.second});
                    }
                    if(map[pos.first][pos.second+1].first>0&&!used[pos.first][pos.second+1])
                    {
                        used[pos.first][pos.second+1]=true;
                        q.push({pos.first,pos.second+1});
                    }
                    if(map[pos.first][pos.second-1].first>0&&!used[pos.first][pos.second-1])
                    {
                        used[pos.first][pos.second-1]=true;
                        q.push({pos.first,pos.second-1});
                    }
                }
            }
        }

    }

    for(int i=0;i<1440/32;i++)
        delete[] used[i],used[i]=nullptr;
    delete[] used;
    used=nullptr;
}

void World::set_player(Player *pl)
{
    for(auto& i:blocks)
    {
        for(auto& j:i)
            j->setPlayer(pl);
    }

    select->setPos(-32,-32);
    select_unit->setPos(-32,-32);
    Block::hideButtons();

    for(auto i:pl->getUnits())
        i->setMoves(1);

    resource_amount=pl->resource_amount;
    //Game::houses=pl->getHouses();
}

void World::update_resource()
{
    players[Game::whosTurn%4]->resource_amount=resource_amount;
}

bool  World::try_spawn(double x, double y, int id)
{
    //qDebug()<<x<<" "<<y<<" "<<id<<" Try";
    if(id==-1)return false;
    x=(int)(x/32);
    y=(int)(y/32);
    x*=32;
    y*=32;
    x+=+11/2;
    y+=+11/2;

    return players[Game::whosTurn%4]->Spawn(x,y,id);
}

void World::dfs(short x, short y, short c)
{
    //qDebug()<<x<<" "<<y;
    visited[x][y]=c;
    kol[c]++;
    //We have bound rect created from water
    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++)
        {
            if(i!=0&&j!=0)
            {
                continue;
            }

            if(!visited[x+i][y+j]&&getBlock((x+i)*32,(y+j)*32)->getId()!=0)
                dfs(x+i,y+j,c);
        }
}

void World::dfs2(short x1, short y1, short x2, short y2)
{
    visited[x1][y1] = true;
    tin[x1][y1] = fup[x1][y1] = timer++;

    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++)
        {
            if((i!=0&&j!=0)||(x1+i==x2&&y1+j==y2)||(!(i!=0&&j!=0)&&getBlock((x1+i)*32,(y1+j)*32)->getId()==0))
            {
                continue;
            }

            if(visited[x1+i][y1+j])
                fup[x1+i][y1+j]=std::min (fup[x1][y1], tin[x1+i][y1+j]);
            else
            {
                dfs2(x1+i,y1+j,x1,y1);
                fup[x1][y1] = std::min (fup[x1][y1], fup[x1+i][y1+i]);
                if(fup[x1+i][y1+i]>tin[x1][y1])
                {
                    bridges.push_back({x1,y1});
                    //bridges.push_back({x2,y2});
                }
            }
        }
}

Block *World::getBlock(int x, int y)
{
    //qDebug()<<"!"<<x<<" "<<y;
    x/=32;
    y/=32;
    return blocks[x][y];
}

int** World::getUnitstay()
{
    return unitstay;
}

std::pair<int, int> **World::getMap()
{
    return map;
}

void World::turn_update()
{
    for(auto& i:blocks)
    {
        for(auto& j:i)
        {
            if(j->getOwner()==Game::whosTurn%4)
            {
                if(try_spawn(j->pos().x(),j->pos().y(),j->tick()))
                {
                    j->stop_build();
                    //qDebug()<<"%"<<scene->items().front();
                    //scene->items().pop_back();
                }
            }
        }
    }
    action_button->setPos(-1900,-100);

    for(auto& i:players[Game::whosTurn%4]->getUnits())
    {
        i->setMoves(1);
    }

    update_resource();
}

void World::action()//Todo
{
    //qDebug()<<"WORLD"<<scene;
    QPointF  position= players[Game::whosTurn%4]->getUnit(select_unit->pos())->pos();

    choosed_block=getBlock(((int)position.x()/32)*32,((int)position.y()/32)*32);
    players[Game::whosTurn%4]->getUnit(select_unit->pos())->action();
/*
    for(auto& i:players[Game::whosTurn%4]->getUnits())
    {
         qDebug()<<i;
    }
*/
  int ind=0;
    for(auto& i:players[Game::whosTurn%4]->getUnits())
    {
        if(i->pos()==position&&i->getActions()==0)
        {
            //qDebug()<<i;
            scene->removeItem(i);
            players[Game::whosTurn%4]->del_unit(ind);
            //for(auto& j:)
            //qDebug()<<"Remove unit";
            select_unit->setPos(-32,-32);
            return;
        }
        ind++;
    }

//    qDebug()<<"///////////";

}
