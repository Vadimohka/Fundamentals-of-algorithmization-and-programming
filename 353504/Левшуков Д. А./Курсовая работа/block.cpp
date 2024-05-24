#include "block.h"

#include"game.h"
Button * Block::unit1_button=nullptr;
Button * Block::unit2_button=nullptr;
Button * Block::unit3_button=nullptr;
Button * Block::unit4_button=nullptr;
Block::Block(short int id, short int res, QWidget* w,QGraphicsScene *&scene,QGraphicsPolygonItem *select,QGraphicsPolygonItem *unit,
             int** height_map,QGraphicsTextItem*block_info,QGraphicsPixmapItem *parent, QObject *parent2):QGraphicsPixmapItem(parent), QObject(parent2)
{


    unit1_button=nullptr;
    unit2_button=nullptr;
    unit3_button=nullptr;
    unit4_button=nullptr;
    this->block_info=block_info;
    this->height_map=height_map;
    //this->player=pl;
    this->select=select;
    this->unit=unit;
    this->scene=scene;
    widget=w;
    this->id=id;
    this->height=id;
    resource=res;
    City=new city();
    City->setPos(pos().x(),pos().y());
    //qDebug()<<City;
    updateTexture();


    building_texture=new QGraphicsPixmapItem(parent);
    building_texture->setFlag(ItemIsSelectable, false);
    building_texture->setFlag(ItemIsMovable, false);
    building_texture->setPos(pos().x(),pos().y());
    //qDebug()<<building_texture;


    unit1_button=new Button("🔨",35,35);
    unit1_button->setPos(-32,-320);
    connect(unit1_button,SIGNAL(clicked()),this,SLOT(create_builder()));
    scene->addItem(unit1_button);

    unit2_button=new Button("🚩",35,35);
    unit2_button->setPos(-32,-320);
    QObject::connect(unit2_button,SIGNAL(clicked()),this,SLOT(create_settler()));
    scene->addItem(unit2_button);

    unit3_button=new Button("🗡️",35,35);
    unit3_button->setPos(-32,-320);
    QObject::connect(unit3_button,SIGNAL(clicked()),this,SLOT(create_knight()));
    scene->addItem(unit3_button);

    unit4_button=new Button("⚔",35,35);
    unit4_button->setPos(-32,-320);
    QObject::connect(unit4_button,SIGNAL(clicked()),this,SLOT(create_knight2()));
    scene->addItem(unit4_button);

}


void Block::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        selectBlock();
        //HideBlockInfo(block_info);
        getInfo();
    }
    if(event->buttons() & Qt::RightButton)
    {
        selectBlock();
        if(unit->pos()!=QPointF(-32,-32))
        {
            std::queue<std::pair<int,std::pair<int,int>>> q;

            int **d=new int*[1440/32];
            std::pair<int,int>** pred=new std::pair<int,int>*[1440/32];
            for(int i=0;i<1440/32;i++)
            {
                d[i]=new int[896/32];
                pred[i]=new std::pair<int,int>[896/32];
                for(int j=0;j<896/32;j++)
                    d[i][j]=1e6,pred[i][j]={0,0};
            }


            if((int)unit->pos().x()/32==x()/32&&(int)unit->pos().y()/32==y()/32)//Already stay in pos
                return;

            q.push({0,{(int)unit->pos().x()/32,(int)unit->pos().y()/32}});
            d[(int)unit->pos().x()/32][(int)unit->pos().y()/32]=0;

            std::pair<int,int>p;
            while(!q.empty())
            {
                int w=(-1)*q.front().first;
                p=q.front().second;
                q.pop();
                //qDebug()<<p<<" "<<x()/32<<" "<<y()/32;
                if(p.first==x()/32&&p.second==y()/32)
                    break;
                if (w > d[p.first][p.second])  continue;

                for(int i=-1;i<=1;i++)
                {
                    for(int j=-1;j<=1;j++)
                    {
                        if((i!=0&&j!=0)||(i==0&&j==0))continue;
                        int toi=p.first+i,toj=p.second+j;
                        toi%=1440/32;
                        toj%=896/32;

                        if(toi<0)
                            toi+=1440/32;
                        if(toj<0)
                            toj+=896/32;

                        int len = abs(height_map[p.first][p.second]-height_map[toi][toj]);
                        if (d[p.first][p.second] + len < d[toi][toj]) {
                            d[toi][toj] = d[p.first][p.second] + len;
                            pred[toi][toj] = {p.first,p.second};
                            q.push ({-d[toi][toj],{ toi,toj}});
                        }
                    }

                }
            }

            while(!q.empty())
            q.pop();

            //qDebug()<<"Not find";
            if(p.first==x()/32&&p.second==y()/32)
            {
                //qDebug()<<"Find";
            }else return;


            std::pair<int,int>s={(int)unit->pos().x()/32,(int)unit->pos().y()/32},l;
            while(p!=s)
            {
                l=p;
                p=pred[p.first][p.second];
            }
            //qDebug()<<"Try to move: "<<player ;

            if(!player->move_unit(unit->pos(),l.first*32+11/2,l.second*32+11/2))
            {
                //unit_error->setPos(1440/2-50,3);
                QMessageBox::warning(widget,"Error","This unit have no steps on this turn / can't move on this field");
            }
        }
            getInfo();

    }
}

void Block::getInfo()
{
   add_log("Get info "+std::to_string(x()/32)+" "+std::to_string(y()/32));
   //QMessageBox::about(widget,"Square info", QString::fromStdString(get_square_info()));
   //qDebug()<<"Show info for "<<pos();
   ShowBlockInfo(get_square_info(),block_info);

   //qDebug()<<City->getIs_city();
   if(City->getIs_city()&&owner==Game::whosTurn%4)
   {
       unit1_button->setPos(1441, 690-288-32-16);
       unit2_button->setPos(1441 + 35 +6, 690-288-32-16);
       unit3_button->setPos(1441+ 35*2 +6*2, 690-288-32-16);
       unit4_button->setPos(1441+ 35*3 +18, 690-288-32-16);
   }
   else
   {
       //qDebug()<<"MOVE!!!";
       unit1_button->setPos(-32, -100);
       unit2_button->setPos(-32, -100);
       unit3_button->setPos(-32, -100);
       unit4_button->setPos(-32, -100);
   }
}

void Block::selectBlock()
{
    add_log("Select block "+std::to_string(x()/32)+" "+std::to_string(y()/32));
    select->setPos(x(),y());
}

void Block::updateTexture()
{

    //qDebug()<<owner<<" "<<id<<" "<<x()<<" "<<y();
    switch(id)
    {
    case 0:
        if(resource==0)
            switch(owner)
            {
            case 0:
                setPixmap(QPixmap(":game/resource/water1.png"));
                break;
            case 1:
                setPixmap(QPixmap(":game/resource/water2.png"));
                break;
            case 2:
                setPixmap(QPixmap(":game/resource/water3.png"));
                break;
            case 3:
                setPixmap(QPixmap(":game/resource/water4.png"));
                break;
            default:
                setPixmap(QPixmap(":game/resource/water.png"));
                break;
            }


        if(resource==4)
            switch(owner)
            {
            case 0:
                setPixmap(QPixmap(":game/resource/water_fish1.png"));
                break;
            case 1:
                setPixmap(QPixmap(":game/resource/water_fish2.png"));
                break;
            case 2:
                setPixmap(QPixmap(":game/resource/water_fish3.png"));
                break;
            case 3:
                setPixmap(QPixmap(":game/resource/water_fish4.png"));
                break;
            default:
                setPixmap(QPixmap(":game/resource/water_fish.png"));
                break;
            }
        break;
    case 1:
        if(resource==0)
            switch(owner)
            {
            case -1:
                setPixmap(QPixmap(":game/resource/grass.png"));
                break;
            default:
                setPixmap(QPixmap(QString::fromStdString(":game/resource/grass"+std::to_string(owner+1)+".png")));
                break;
            }
        if(resource==1)
            switch(owner)
            {
            case -1:
                setPixmap(QPixmap(":game/resource/grass_wheat.png"));
                break;
            default:
                setPixmap(QPixmap(QString::fromStdString(":game/resource/grass_wheat"+std::to_string(owner+1)+".png")));
                break;
            }
        if(resource==2)
            switch(owner)
            {
            case -1:
                setPixmap(QPixmap(":game/resource/grass_stone.png"));
                break;
            default:
                setPixmap(QPixmap(QString::fromStdString(":game/resource/grass_stone"+std::to_string(owner+1)+".png")));
                break;
            }
        if(resource==3)
            switch(owner)
            {
            case -1:
                setPixmap(QPixmap(":game/resource/grass_iron.png"));
                break;
            default:
                setPixmap(QPixmap(QString::fromStdString(":game/resource/grass_iron"+std::to_string(owner+1)+".png")));
                break;
            }
        break;
    default:
        if(resource==0)
            switch(owner)
            {
            case -1:
                setPixmap(QPixmap(":game/resource/mountain.png"));
                break;
            default:
                setPixmap(QPixmap(QString::fromStdString(":game/resource/mountain"+std::to_string(owner+1)+".png")));
                break;
            }

        if(resource==2)
            switch(owner)
            {
            case -1:
                setPixmap(QPixmap(":game/resource/mountain_stone.png"));
                break;
            default:
                setPixmap(QPixmap(QString::fromStdString(":game/resource/mountain_stone"+std::to_string(owner+1)+".png")));
                break;
            }
        if(resource==3)
            switch(owner)
            {
            case -1:
                setPixmap(QPixmap(":game/resource/mountain_iron.png"));
                break;
            default:
                setPixmap(QPixmap(QString::fromStdString(":game/resource/mountain_iron"+std::to_string(owner+1)+".png")));
                break;
            }
        break;
    }
}

void Block::change(int id)
{
    this->id=height=id;
    updateTexture();
}

void Block::build_city()
{

    scene->removeItem(City);
    City->create(Game::whosTurn%4);
//    qDebug()<<"@"<<pos();
    City->setPos(pos());
    //City->setPs(pos());
    //qDebug()<<City;
    scene->addItem(City);

    owner=Game::whosTurn%4;
    World::owners[x()/32][y()/32]=owner;
    City->setGrow_from(0);
    City->check();
    City->setGrow_from(0);
    City->check();
    City->setGrow_from(0);
    City->check();
    City->setGrow_from(0);
    City->check();
    updateTexture();
}

bool Block::isCity()
{
    return City->getIs_city();
}

void Block::create_building()
{
    building++;
    if(isCity())
    {
        City->addHp();
        return;
    }

    switch(resource)
    {
    case 4:
        building_texture->setPixmap(QPixmap(":game/resource/fishing.png"));
        Game::houses[Game::whosTurn%4]+=1;
        break;
    case 1:
        building_texture->setPixmap(QPixmap(":game/resource/farm.png"));
        Game::houses[Game::whosTurn%4]+=2;
        break;
    default:
        building_texture->setPixmap(QPixmap(":game/resource/mine.png"));
        break;
    }

    //building_texture->setPos(pos());



}

short Block::tick()
{
    if(City->getIs_city())
    {
        City->setGrow_from(std::max(0,City->getGrow_from()-4));
        City->check();

        City->setBuild_finish(std::max(0,City->getBuild_finish()-4));
        return City->try_spawn();
    }
    else
        if(building!=0)
    {
        switch(resource)
        {
        case 1:
            World::resource_amount[3]++;
            break;
        case 2:
            World::resource_amount[1]++;
            break;
        case 3:
            World::resource_amount[2]++;
            break;
        case 4:
            World::resource_amount[4]++;
            break;
        }
    }
    return -1;
}

void Block::stop_build()
{
                         City->setBuild_finish(0);
    City->setBuild_id(4);
}

void Block::building_pos(QPointF pos)
{
    building_texture->setPos(pos);
    scene->addItem(building_texture);
}

void Block::attack(short dmg)
{
    City->attack(dmg);
}

std::string Block::get_square_info()
{
    std::string res="=====Block info=====\n";

    res+="Type: ";
    switch (id)
    {
    case 0:
        res+="Water";
        break;

    case 1:
        res+="Grass";
        break;

    case 2:
        res+="Mountain";
        break;
    }

    res+="\n";

    res+="Resource: ";
    switch(this->resource)
    {
    case 0:
        res+="None";
        break;
    case 1:
        res+="Wheat";
        break;
    case 2:
        res+="Stone";
        break;
    case 3:
        res+="Iron";
        break;
    case 4:
        res+="Fish";
        break;
    }

    res+="\n";

    res+="Owner: ";
    if(owner==-1)
        res+="Neutral";
    else
    {
        res+="Player ";
        res+=std::to_string(owner);
    }
    res+="\n";

    switch (id)
    {
    case 1:
        res+="Continent: "+continent;
        break;

    case 2:
        res+="Continent: "+continent;
        break;
    }

    //qDebug()<<City->getIs_city();
    if(City->getIs_city())
    {
        res+="\n\n=====City  Info=====\nLevel: ";
        res+=std::to_string(City->getLevel())+"\n";
        res+="Grow from: "+std::to_string(City->getGrow_from())+"\n Walls LVL:"+std::to_string(building)+"\nHP"+std::to_string(City->getHp());
        //<<"="<<City;
        if(owner==Game::whosTurn%4&&City->getBuild_id()!=4)
        {
            res+="\nBuild: ";
            switch(City->getBuild_id())
            {
            case 0:
                res+="Builder\n";
                break;
            case 1:
                res+="Settler\n";
                break;
            case 2:
                res+="Knight\n";
                break;
            case 3:
                res+="Knight (grade 2)\n";
                break;
            }
            res+="Will ready by "+std::to_string(City->getBuild_finish())+" turns";
        }
    }
    return res;
}

void Block::setOwner(short newOwner)
{
    owner = newOwner;
    World::owners[x()/32][y()/32]=owner;
    //City->setOwner(owner);
    updateTexture();
}

void Block::setPlayer(Player *newPlayer)
{
    player = newPlayer;
}

void Block::create_builder()
{

    if(select->pos()!=pos())
    {
    World::blocks[(int)select->pos().x()/32][(int)select->pos().y()/32]->create_builder();
        return;
    }
    City->build(0);
    //<<"!"<<City->getBuild_id();
    getInfo();
}

void Block::create_settler()
{

    if(select->pos()!=pos()){
        World::blocks[(int)select->pos().x()/32][(int)select->pos().y()/32]->create_settler();
    return;
}
    City->build(1);
    getInfo();
}

void Block::create_knight()
{

    if(select->pos()!=pos()){
        World::blocks[(int)select->pos().x()/32][(int)select->pos().y()/32]->create_knight();
        return;
    }
    City->build(2);
    getInfo();
}

void Block::create_knight2()
{

    if(select->pos()!=pos()){
        World::blocks[(int)select->pos().x()/32][(int)select->pos().y()/32]->create_knight2();
        return;
    }
    City->build(3);
    getInfo();
}

short Block::getId() const
{
    return id;
}

short Block::getResource() const
{
    return resource;
}

short Block::getBuilding() const
{
    return building;
}

short Block::getOwner() const
{
    return owner;
}

void Block::hideButtons()
{
    unit1_button->setPos(-32, -100);
    unit2_button->setPos(-32, -100);
    unit3_button->setPos(-32, -100);
    unit4_button->setPos(-32, -100);
}

short Block::getHeight() const
{
    return height;
}

void Block::setContinent(std::string newContinent)
{
    continent = newContinent;
}
