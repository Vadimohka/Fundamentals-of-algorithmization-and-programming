#include "gamesceneview.h"
#include "montecarlo.h"
GameSceneView::GameSceneView(QObject *parent)
    : QGraphicsScene{parent}
{
    p = new QPixmap(":/new/prefix1/prefix1/DEFAULT.png");
    p1= new QPixmap(":/new/prefix1/prefix1/BOSSIMAGE.png");
    p3= new QPixmap(":/new/prefix1/prefix1/Koster.png");
    p4= new QPixmap(":/new/prefix1/prefix1/HARD.png");
}

GameSceneView::~GameSceneView()
{

    delete this;
}

void GameSceneView::getPlayer(Player *p){
    this->player = p;
}

void GameSceneView::GenerateEnemy(int num)
{

        switch (num) {
            case StartT:{
            qDebug() << "startt in VIEW";

                QPixmap pixmap(":/new/prefix1/prefix1/START.webp");
                QPixmap scaledPixmap = pixmap.scaled(1600, 1284, Qt::KeepAspectRatio);
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(scaledPixmap);
                this->addItem(pixmapItem);
                enemy = new Enemy(100,7,10,DEFAULTET);
                enemy->getPixmap(p);
                break;
            }
            case BossT:{
                QPixmap pixmap(":/prefix1/BOSSSCENE3.jpeg");
                QPixmap scaledPixmap = pixmap.scaled(1600, 1284, Qt::KeepAspectRatio);
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(scaledPixmap);
                this->addItem(pixmapItem);
                enemy = new Enemy(300,15,20,BOSSET);
                // pixmapItem->setPos(0, 0);
                enemy->getPixmap(p1);
                break;
            }
            case RestT:{
                QPixmap pixmap(":/new/prefix1/prefix1/ForRestRRR.jpeg");
                QPixmap scaledPixmap = pixmap.scaled(1600, 1084, Qt::KeepAspectRatio);
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(scaledPixmap);
                this->addItem(pixmapItem);
                enemy = new Enemy(0,0,0,NOT);
                // pixmapItem->setPos(0, 0);
                enemy->getPixmap(p3);
                break;
            }
            case RandT:{
                int a = MonteCarlo::monteCarlo(0,2);
                switch (a) {
                case 0:
                {
                    enemy = new Enemy(120,12,0,HARDET);
                }
                    break;
                case 1:
                {
                    enemy = new Enemy(0,0,0,NOT);
                }
                    break;
                case 2:
                {
                    enemy = new Enemy(0,0,0,NOT);
                }
                    break;
                }

                break;
            }
            case DefaultT:{
                QPixmap pixmap(":/prefix1/HARDSCENE1.jpeg");
                QPixmap scaledPixmap = pixmap.scaled(1500, 1084, Qt::KeepAspectRatio);
                QGraphicsPixmapItem *pixmapItem = new QGraphicsPixmapItem(scaledPixmap);
                pixmapItem->setPos(0, 0);
                this->addItem(pixmapItem);
                enemy = new Enemy(150,10,20,HARDET);

                enemy->getPixmap(p4);
                break;
            }
            case FreebieT:{
                 enemy = new Enemy(0,0,0,NOT);
                break;
            }
            default:
                enemy = new Enemy(0,0,0,NOT);
                break;
        }
        connect(player,&Player::attack,enemy,&Enemy::takeAttack);
        connect(enemy,&Enemy::attack,player,&Player::takeAttack);
        connect(player,&Player::updateView,this,&GameSceneView::updateSlot);
        connect(enemy,&Enemy::updateView,this,&GameSceneView::updateSlot);
        //connect(player,&Player::enemyMove,enemy,&Enemy::Attack);
        enemy->getCoordinate(1160,400,200,400);
}

void GameSceneView::updateSlot()
{
    this->update();
}

void GameSceneView::takeEnemyNum(int num)
{
    GenerateEnemy(num);
}

void GameSceneView::addPlayerAndEnemyToScene()
{
    this->addItem(player);
    this->addItem(enemy);
}

