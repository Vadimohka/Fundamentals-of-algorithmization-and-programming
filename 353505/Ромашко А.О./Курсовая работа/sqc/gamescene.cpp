#include "gamescene.h"
#include "ui_gamescene.h"
#include <QString>
#include "montecarlo.h"

GameScene::GameScene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameScene)
{
    ui->setupUi(this);
    //

    graphicsView =  new QGraphicsView();
    deck = new QGraphicsView();
    wm = new DialogWinMenu();
    connect(this,&GameScene::openWNMenu,this->wm,&DialogWinMenu::open);
    setWindowTitle("Пути назад нет, закончи битву");
    this->update();
}

GameScene::~GameScene()
{
    wm->~DialogWinMenu();
    delete ui;
}

//void GameScene::getLevelNum(int l) {this->level = l; GameScene::windowTitleChanged(QString::number(level));}

void GameScene::openSlot()//слот открытия игровой сцены
{
    deck->setEnabled(1);
    emit playerDeckUpdate();
    qDebug() << "GameScene opened";
    this->showFullScreen();
}

void GameScene::loser()
{
    emit lose();
    this->close();
    this->~GameScene();
}

void GameScene::WinSlot()
{
    int num = MonteCarlo::monteCarlo(0,5);
    if(num == 4 )
        num=2;

    Card *temp = new Card(new QImage(),new Damage(),new Defence(), new Health(), new Energy());
    QImage *i = new QImage();
    Damage *dam = new Damage();
    Defence *def =  new Defence();
    Health *hp = new Health();
    Energy *en = new Energy();
    Energy *enCost = new Energy();
    switch (num)
    {
    case AttackT:{
        dam->upDamage(20);
        temp->getType(AttackT);

        en->upEnergy(0);
        enCost->upEnergy(2);
        break;
    }
    case DefenceT:{
        def->addDef(20);
        temp->getType(DefenceT);

        en->upEnergy(0);
        enCost->upEnergy(2);
        break;
    }
    case HealtPointT:{
        temp->getType(HealtPointT);
        hp->addHP(20);

        en->upEnergy(0);
        enCost->upEnergy(2);
        break;
    }
    case EnergyT:{
        temp->getType(EnergyT);

        en->upEnergy(2);
        enCost->upEnergy(0);
        break;
    }
    case EffectT:{
        dam->upDamage(7);
        hp->addHP(7);
        def->addDef(3);
        temp->getType(EffectT);

        en->upEnergy(0);
        enCost->upEnergy(2);
        break;
    }
    case CombinationT:{
        dam->upDamage(10);
        hp->addHP(10);
        def->addDef(10);
        temp->getType(CombinationT);

        en->upEnergy(0);
        enCost->upEnergy(0);
        break;
    }
    }
    temp->getDamage(dam);
    temp->getImage(i);
    temp->getDefence(def);
    temp->getEnergy(en);
    temp->getHp(hp);
    temp->getEnergyCost(enCost);
    //temp->getPlayerEnergy(player->setDeck()->getPlayerEnergy(en));
    player->setDeck()->addCard(temp);
    deck->setEnabled(0);
    player->upHp(15);
    player->money+=50*(levelType+1);
    qDebug() << player->money << "player money ";
    wm->takeInfoMONEYCARDHP(50*(levelType+1),temp,15);
    ui->pushButton_Move->setEnabled(0);
    ui->pushButton_Back->setEnabled(1);
    emit openWNMenu();
}


void GameScene::on_pushButton_Back_clicked()
{
    emit goBack();
    this->update();
    this->~GameScene();
}

void GameScene::generateGraphicsView()
{
    gameSceneView =  new GameSceneView();
    gameSceneView->getPlayer(player);
    ui->pushButton_Move->setEnabled(1);
    switch(levelType){
        case StartT:{
        qDebug() << "startT";
            gameSceneView->GenerateEnemy(StartT);
            break;
        }
        case BossT:{
            gameSceneView->GenerateEnemy(BossT);
            break;
        }
        case RestT:{
            gameSceneView->GenerateEnemy(RestT);
            break;
        }
        case RandT:{
            gameSceneView->GenerateEnemy(RandT);
            break;
        }
        case DefaultT:{
            gameSceneView->GenerateEnemy(DefaultT);
            break;
        }
        case FreebieT:{
            gameSceneView->GenerateEnemy(FreebieT);
            break;
        }
    }
    dl = new DialogLOSE();
    deckP = player->setDeck();
    player->getCoordinate(35,400,200,400);

    ui->deck->setRenderHint(QPainter::Antialiasing);
    ui->deck->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->deck->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->deck->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    connect(this,&GameScene::toMoveEnemy,this->gameSceneView->getEnemy(),&Enemy::Attack);
    connect(this,&GameScene::playerDeckUpdate,this->deckP,&Deck::PlayerDeckUpdateSlot);
    connect(player,&Player::GameOver,dl,&DialogLOSE::open);
    connect(dl,&DialogLOSE::openMainMenu,this,&GameScene::loser);
    gameSceneView->addPlayerAndEnemyToScene();
    ui->deck->setScene(deckP);
    ui->graphicsView->setScene(gameSceneView);
    ui->graphicsView->update();
    connect(gameSceneView->getEnemy(),&Enemy::Win,this,&GameScene::WinSlot);

    ui->pushButton_Back->setEnabled(0);
    deckP->setEnabled(1);

    this->update();
}

void GameScene::getPlayer(Player *p){
    this->player= p;
}


void GameScene::on_pushButton_Move_clicked()
{
    this->player->setEnergy()->doNull();
    this->player->setEnergy()->upEnergy(3);
    this->deckP->setEnabled(1);
    this->deck->setEnabled(1);
    this->deckP->update();
    this->deck->update();
    this->gameSceneView->update();
    emit toMoveEnemy();
    emit playerDeckUpdate();
    this->update();
}

