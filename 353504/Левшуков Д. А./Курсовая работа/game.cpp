#include "game.h"

long long Game::whosTurn=0;
long long Game::houses[]={0,0,0,0};
QVector<Player *>Game::players;
Game::Game(QWidget *parent)
{

    whosTurn=0;
    houses[0]=0;
    houses[1]=0;
    houses[2]=0;
    houses[3]=0;
    players.resize(4);

    //set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1600,896);
    setFixedSize(1600,896);
    setScene(scene);

    add_log("Game scene was created");

    QPolygonF p({{0,0},{32,0},{32,32},{0,32}});
    select_block=new QGraphicsPolygonItem(p);
    select_block->setPen(QPen(QColor("yellow")));

    select_block->setPos(-32,-32);

    QPolygonF p1({{0,0},{22,0},{22,22},{0,22}});
    select_unit=new QGraphicsPolygonItem(p1);
    select_unit->setPen(QPen(QColor("red")));
    select_unit->setPos(-32,-32);

    //Make gui
    block_info=new QGraphicsTextItem();
    block_info->setPos(1440,2);
    scene->addItem(block_info);

    res_info=new QGraphicsTextItem();
    res_info->setPos(1440,240);
    scene->addItem(res_info);


    turn_info=new QGraphicsTextItem();
    turn_info->setPos(1440,790);
    QFont fnt;
    fnt.setBold(true);
    fnt.setPixelSize(17);
    turn_info->setFont(fnt);
    scene->addItem(turn_info);

    UpdateTurnInfo(turn_info);

    map = new World(scene,this,select_block,select_unit,block_info, players);
    add_log("Map was generated");

    //QPushButton *skip_button=new QPushButton();

    skip_button=new Button("Skip",160,80);
    skip_button->setPos(1440,816);
    connect(skip_button,SIGNAL(clicked()),this,SLOT(next_turn()));
    scene->addItem(skip_button);

    ShowResourceInfo("Money: "+std::to_string(players[whosTurn%4]->resource_amount[0])+
                         "\nStone: "+std::to_string(players[whosTurn%4]->resource_amount[1])+
                         "\nIron: "+std::to_string(players[whosTurn%4]->resource_amount[2])+
                         "\nWheat: "+std::to_string(players[whosTurn%4]->resource_amount[3])+
                         "\nFish: "+std::to_string(players[whosTurn%4]->resource_amount[4]),res_info);

    give_up=new Button("Give Up",160,50);
    give_up->setPos(1440,616);
    connect(give_up,SIGNAL(clicked()),this,SLOT(giveUp()));
    scene->addItem(give_up);

}

void Game::turn_update()
{
    map->turn_update();
}

void Game::next_turn()
{

    map->update_resource();
    HideBlockInfo(block_info);
    do{
    whosTurn++;
    //qDebug()<<whosTurn;
    map->set_player(players[whosTurn%4]);
    }while(players[whosTurn%4]->getLose());
    QMessageBox::information(this,"Turn","Player "+QString::fromStdString(std::to_string(whosTurn%4+1))+ ", your turn");
    UpdateTurnInfo(turn_info);
    turn_update();
    ShowResourceInfo("Money: "+std::to_string(players[whosTurn%4]->resource_amount[0])+
                     "\nStone: "+std::to_string(players[whosTurn%4]->resource_amount[1])+
                     "\nIron: "+std::to_string(players[whosTurn%4]->resource_amount[2])+
                     "\nWheat: "+std::to_string(players[whosTurn%4]->resource_amount[3])+
                     "\nFish: "+std::to_string(players[whosTurn%4]->resource_amount[4]),res_info);
    update();
    if(alive==1)//Win
    {

        //setScene();
        //hide();
        scene->clear();
        scene->setSceneRect(0,0,800,600);
        setFixedSize(800,600);
        QGraphicsTextItem * info=new QGraphicsTextItem(QString::fromStdString("Player "+std::to_string(whosTurn%4+1)+" WIN!"));
        info->setPos(360,270);
        if(Game::whosTurn%4==0)
            info->setDefaultTextColor(Qt::red);
        if(Game::whosTurn%4==1)
            info->setDefaultTextColor(Qt::blue);
        if(Game::whosTurn%4==2)
            info->setDefaultTextColor(Qt::green);
        if(Game::whosTurn%4==3)
            info->setDefaultTextColor(Qt::yellow);

        scene->addItem(info);
        Button * main=new Button("Go to main menu",800,50);
        //main->setPos(600,200);
        connect(main,SIGNAL(clicked()),this,SLOT(openMain()));
        scene->addItem(main);
        return;
    }

}

void Game::giveUp()
{
    players[whosTurn%4]->setLose(true);
    alive--;
    next_turn();
}

void Game::openMain()
{
    this->close();
    emit mainWindow();
}
