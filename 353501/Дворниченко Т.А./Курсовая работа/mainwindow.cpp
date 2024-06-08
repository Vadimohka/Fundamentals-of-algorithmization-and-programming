#include "mainwindow.h"
#include <QKeyEvent>
#include <QScrollBar>
#include <QPropertyAnimation>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "player.h"
#include "coin.h"
#include "backitem.h"
#include "castle.h"
#include "goomba.h"
#include "questbox.h"
#include "turtle.h"
#include "piranha.h"
#include "brickplatform.h"
#include "flag.h"
#include "notebox.h"
#include "coincounter.h"
#include "wallplatform.h"
#include "conveyor.h"
#include "angrymushroom.h"
#include "warptube.h"
#include "stairblock.h"
#include "bomb.h"
#include "redturtle.h"
#include"spiny.h"
#include "score.h"
#include "timer.h"
#include "smallmario.h"
#include "mushroom.h"
#include "gameover.h"
#include "levelcompletewindow.h"

MyScene::MyScene(QScrollBar*s , QObject *parent) :
    QGraphicsScene(0,0,8000,720, parent)
  , m_velocity(7)
  , m_skippedMoving(0)
  , m_groundLevel(0)
  , m_minX(0)
  , m_maxX(0)
  , m_jumpAnimation(new QPropertyAnimation(this))
  , m_jumpHeight(250)
  , m_fieldWidth(8000)//width of the virtual world
  , m_player()
  , m_smallPlayer()
  , m_sky(0)
  , m_Scene(0)
  , m_coins(0)
  , h_castle()


  , m_wallPlatform(0)
  , m_turtle()
  , m_piranha()
  , m_NoteBox(0)
  , m_platform()
  , scroll(s)

{
    initPlayField();

    //Timer to check if player is moving
    m_timer.setInterval(20);
    connect(&m_timer, &QTimer::timeout, this, &MyScene::movePlayer);

    //Timer to controll mario fall speed
    mFallTimer.setInterval(20);
    connect(&mFallTimer, &QTimer::timeout, this, &MyScene::fallPlayer);

    m_jumpAnimation->setTargetObject(this);
    m_jumpAnimation->setPropertyName("jumpFactor");
    m_jumpAnimation->setStartValue(0);
    m_jumpAnimation->setKeyValueAt(0.5, 1);
    m_jumpAnimation->setEndValue(0);
    m_jumpAnimation->setDuration(800);
    m_jumpAnimation->setEasingCurve(QEasingCurve::OutInQuad);
    connect(this, &MyScene::jumpFactorChanged, this, &MyScene::jumpPlayer);
    connect(m_jumpAnimation, &QPropertyAnimation::stateChanged, this, &MyScene::jumpStatusChanged);
    //ARA
    QObject::connect(this, SIGNAL(playSound(QString)),this->parent(),SIGNAL(playSound(QString)));
    emit this->playSound("level1");
}

//Player key movements
void MyScene::keyPressEvent(QKeyEvent *event)
{

    if (event->isAutoRepeat())
            return;

    switch (event->key()) {
    case Qt::Key_D:
        m_player->addDirection(1);
        m_smallPlayer->addDirection(1);
       checkTimer();
        break;
    case Qt::Key_A:
        m_player->addDirection(-1);
        m_smallPlayer->addDirection(-1);
        checkTimer();
        break;
    case Qt::Key_W:
        if (QAbstractAnimation::Stopped == m_jumpAnimation->state()) {
            m_jumpAnimation->start();
            emit this->playSound("mario_jump");
            //m_timer.start();
        }
        break;
    case Qt::Key_Right:
        m_player->addDirection(1);
        m_smallPlayer->addDirection(1);
       checkTimer();
        break;
    case Qt::Key_Left:
        m_player->addDirection(-1);
        m_smallPlayer->addDirection(-1);
        checkTimer();
        break;
    case Qt::Key_Up:
        //qDebug() << "space pressed";
        if (QAbstractAnimation::Stopped == m_jumpAnimation->state()) {
            m_jumpAnimation->start();
            //qDebug() << "space pressed; animation start";

            emit this->playSound("mario_jump");
            //m_timer.start();
        }
        break;
    default:
        break;
    }
}

void MyScene::keyReleaseEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat())
        return;

    switch (event->key()) {
    case Qt::Key_D:
        m_player->addDirection(-1);
        m_smallPlayer->addDirection(-1);
checkTimer();
        break;
    case Qt::Key_A:
        m_player->addDirection(1);
        m_smallPlayer->addDirection(1);
        checkTimer();
        break;
    case Qt::Key_Right:
        m_player->addDirection(-1);
        m_smallPlayer->addDirection(-1);
        checkTimer();
        break;
    case Qt::Key_Left:
        m_player->addDirection(1);
        m_smallPlayer->addDirection(1);
        checkTimer();

               break;
    default:
        break;
    }
}

void MyScene::movePlayer()
{
    checkCollidingCoin();
    handleCollisionWithGoomba();
    checkCollidingTurtle();
    checkCollidingSpiny();
    checkCollidingBomb();
    checkCollidingRedTurtle();
    checkCollidingPiranha();
    checkCollidingWarpTube();
    checkCollidingGiantGoomba();
    checkCollidingFlag();
    checkCollidingMushroom();
checkCollidingStairBlock();
    if(m_player->isFalling()){
            return;
        }

    m_player->nextFrame();
    m_smallPlayer->nextFrame();

    int direction = m_player->direction();
    if (0 == direction)
        return;

    //previously walking on platform, if there is no platform, step down
    if((!(m_platform && m_player->isTouchingPlatform(m_platform))&& m_jumpAnimation->state() == QAbstractAnimation::Stopped)
       ||(!(m_platform && m_smallPlayer->isTouchingPlatform(m_platform))&& m_jumpAnimation->state() == QAbstractAnimation::Stopped)) {
        if(m_platform) {
            m_player->fall();
            m_smallPlayer->fall();
            mFallTimer.start();
        }
    }

    const int dx = direction * m_velocity;

    if (direction > 0) {
        if(m_player->pos().x()>8000){
            m_timer.stop();
         }

        m_player->moveBy(dx, 0);
        int diff = m_player->pos().x() - scroll->value();
        if(scroll->value()> 6700){
                    return;
                }

        if(diff > 800) {
            scroll->setValue(dx + scroll->value());
            m_sky->setPos(dx + m_sky->pos().x(), 0);
            m_Scene->setPos(dx + m_Scene->pos().x(), m_Scene->y());
            m_countLogo->setPos(dx + m_countLogo->pos().x(), m_countLogo->y());
            m_count->setPos(dx + m_count->pos().x(), m_count->y());
            m_score->setPos(dx + m_score->pos().x(), m_score->y());
            m_gameTimer->setPos(dx + m_gameTimer->pos().x(), m_gameTimer->y());
            m_scoreLogo->setPos(dx + m_scoreLogo->pos().x(), m_scoreLogo->y());
            m_timerLogo->setPos(dx + m_timerLogo->pos().x(), m_timerLogo->y());
            gameover->setPos(dx + gameover->pos().x(), gameover->y());
            courseclear->setPos(dx + courseclear->pos().x(), courseclear->y());
        }

    }


    if (direction < 0) {
        if((m_player->pos().x()<2)||(m_smallPlayer->pos().x()<2)){
            return;
      }
        m_player->moveBy(dx, 0);
        int diff = m_player->pos().x() - scroll->value();

        if(diff < 200) {
            scroll->setValue(dx + scroll->value());
            m_sky->setPos(dx + m_sky->pos().x(), 0);
            m_Scene->setPos(dx + m_Scene->pos().x(), m_Scene->y());
            m_countLogo->setPos(dx + m_countLogo->pos().x(), m_countLogo->y());
            m_count->setPos(dx + m_count->pos().x(), m_count->y());
            m_score->setPos(dx + m_score->pos().x(), m_score->y());
            m_gameTimer->setPos(dx + m_gameTimer->pos().x(), m_gameTimer->y());
            m_scoreLogo->setPos(dx + m_scoreLogo->pos().x(), m_scoreLogo->y());
            m_timerLogo->setPos(dx + m_timerLogo->pos().x(), m_timerLogo->y());
            gameover->setPos(dx + gameover->pos().x(), gameover->y());
            courseclear->setPos(dx + courseclear->pos().x(), courseclear->y());
        }

    }

    if (direction > 0) {

        m_smallPlayer->moveBy(dx, 0);
        int diff2 = m_player->pos().x() - scroll->value();

        if(diff2 > 800) {
            scroll->setValue(dx + scroll->value());
            m_sky->setPos(dx + m_sky->pos().x(), 0);
            m_Scene->setPos(dx + m_Scene->pos().x(), m_Scene->y());
            m_countLogo->setPos(dx + m_countLogo->pos().x(), m_countLogo->y());
            m_count->setPos(dx + m_count->pos().x(), m_count->y());
            m_score->setPos(dx + m_score->pos().x(), m_score->y());
            m_gameTimer->setPos(dx + m_gameTimer->pos().x(), m_gameTimer->y());
            m_scoreLogo->setPos(dx + m_scoreLogo->pos().x(), m_scoreLogo->y());
            m_timerLogo->setPos(dx + m_timerLogo->pos().x(), m_timerLogo->y());
            gameover->setPos(dx + gameover->pos().x(), gameover->y());
            courseclear->setPos(dx + courseclear->pos().x(), courseclear->y());
        }

    }

    if (direction < 0) {

        m_smallPlayer->moveBy(dx, 0);
        int diff2 = m_player->pos().x() - scroll->value();

        if(diff2 < 200) {
            scroll->setValue(dx + scroll->value());
            m_sky->setPos(dx + m_sky->pos().x(), 0);
            m_Scene->setPos(dx + m_Scene->pos().x(), m_Scene->y());
            m_countLogo->setPos(dx + m_countLogo->pos().x(), m_countLogo->y());
            m_count->setPos(dx + m_count->pos().x(), m_count->y());
            m_score->setPos(dx + m_score->pos().x(), m_score->y());
            m_gameTimer->setPos(dx + m_gameTimer->pos().x(), m_gameTimer->y());
            m_scoreLogo->setPos(dx + m_scoreLogo->pos().x(), m_scoreLogo->y());
            m_timerLogo->setPos(dx + m_timerLogo->pos().x(), m_timerLogo->y());
            gameover->setPos(dx + gameover->pos().x(), gameover->y());
            courseclear->setPos(dx + courseclear->pos().x(), courseclear->y());
        }
    }
}

void MyScene::jumpStatusChanged(QAbstractAnimation::State newState, QAbstractAnimation::State oldState) {
    if(newState == QAbstractAnimation::Stopped && oldState == QAbstractAnimation::Running) {

    }
}

void MyScene::fallPlayer() {

    m_player->setPos(m_player->pos().x(), m_player->pos().y() + 30);
    m_smallPlayer->setPos(m_smallPlayer->pos().x(), m_smallPlayer->pos().y() + 30);
    QGraphicsItem* item = collidingPlatforms();
    if(item && handleCollisionWithPlatform()) {
        mFallTimer.stop(); 
        m_player->walk();
        m_smallPlayer->walk();

    } else if((m_player->pos().y() + m_player->boundingRect().height() >= m_groundLevel)||(m_smallPlayer->pos().y() + m_smallPlayer->boundingRect().height() >= m_groundLevel)){
        m_player->setPos(m_player->pos().x(), m_groundLevel - m_player->boundingRect().height());
        m_smallPlayer->setPos(m_smallPlayer->pos().x(), m_groundLevel - m_smallPlayer->boundingRect().height());
        mFallTimer.stop();
        m_player->walk();
        m_smallPlayer->walk();
        m_platform = 0;
    }

}

void MyScene::jumpPlayer(){

    if (QAbstractAnimation::Stopped == m_jumpAnimation->state()) {
        m_player->stand();
        return;
    }

    checkCollidingCoin();
    handleCollisionWithGoomba();
    checkCollidingSpiny();
    checkCollidingBomb();
    checkCollidingRedTurtle();
    checkCollidingTurtle();
    checkCollidingPiranha();
    checkCollidingWarpTube();
    checkCollidingGiantGoomba();
    checkCollidingFlag();
    checkCollidingMushroom();
    checkCollidingQuestBox();


    QGraphicsItem* item = collidingPlatforms();
    if(item) {
        if((m_player->isTouchingHead(item))||(m_smallPlayer->isTouchingHead(item))) {

            m_jumpAnimation->stop();

            if(m_platform) {
                m_player->setPos(m_player->pos().x(), m_platform->pos().y() - m_player->boundingRect().height());
                m_smallPlayer->setPos(m_smallPlayer->pos().x(), m_platform->pos().y() - m_smallPlayer->boundingRect().height());
                return;
            }
            if(!m_platform){
                m_player->setPos(m_player->pos().x(), m_groundLevel - m_player->boundingRect().height());
                m_smallPlayer->setPos(m_smallPlayer->pos().x(), m_groundLevel - m_smallPlayer->boundingRect().height());
                return;
            }

        } else {
            if(handleCollisionWithPlatform()) {
                return;
            }
        }
    }

    qreal y = (m_groundLevel - m_player->boundingRect().height()) - m_jumpAnimation->currentValue().toReal() * m_jumpHeight;
    if(m_platform) {
        y = (m_platform->pos().y() - m_player->boundingRect().height()) - m_jumpAnimation->currentValue().toReal() * m_jumpHeight;
        if(!(m_platform && m_player->isTouchingPlatform(m_platform)) && m_jumpFactor < 0.1 ) {
            if(m_player->pos().x() < m_platform->pos().x() || m_player->pos().x() > m_platform->pos().x() + m_platform->boundingRect().width()){
                if(!m_platform){
                m_platform = 0;
                }
                if(m_player->pos().y() < m_groundLevel) {
                    m_player->fall();
                    mFallTimer.start();
                    return;
                }
            }
        }
    }
    m_player->setPos(m_player->pos().x(), y);

    qreal p = (m_groundLevel - m_smallPlayer->boundingRect().height()) - m_jumpAnimation->currentValue().toReal() * m_jumpHeight;
    if(m_platform) {
        p = (m_platform->pos().y() - m_smallPlayer->boundingRect().height()) - m_jumpAnimation->currentValue().toReal() * m_jumpHeight;
        if(!(m_platform && m_smallPlayer->isTouchingPlatform(m_platform)) && m_jumpFactor < 0.1 ) {
            if(m_smallPlayer->pos().x() < m_platform->pos().x() || m_smallPlayer->pos().x() > m_platform->pos().x() + m_platform->boundingRect().width()){
                if(!m_platform){
                m_platform = 0;
                }
                if(m_smallPlayer->pos().y() < m_groundLevel) {
                    m_smallPlayer->fall();
                    mFallTimer.start();
                    return;
                }
            }
        }
    }
    m_smallPlayer->setPos(m_player->pos().x(), p);
}

//Creating the scene and adding items
void MyScene::initPlayField(){

    setSceneRect(0,0,8000,720);

    m_groundLevel = 680;

    //add sky
    m_sky = new BackgroundItem(QPixmap(":images/volcanmario"));
    addItem(m_sky);

    //Game over screen
    gameover = new BackgroundItem(QPixmap(":images/"));

    //Course clear screen
    courseclear = new BackgroundItem(QPixmap(":images/c2"));

    //add ground
    m_ground = new BackgroundItem(QPixmap(":images/ground"));
    addItem(m_ground);
    m_ground->setPos(0, m_groundLevel );

    //add scene image
    m_Scene = new BackgroundItem(QPixmap(":images"));
    m_Scene->setPos(0, m_groundLevel - m_Scene->boundingRect().height());
    addItem(m_Scene);

    //Image for counter
    m_countLogo = new BackgroundItem(QPixmap(":images/count"));
    m_countLogo->setPos(30, m_groundLevel -652 );
    addItem(m_countLogo);

    //Add Score Text
    m_scoreLogo = new BackgroundItem(QPixmap(":images/scoretext"));
    m_scoreLogo->setPos(900, m_groundLevel -647 );
    addItem(m_scoreLogo);

    //Image for game timer
    m_timerLogo = new BackgroundItem(QPixmap(":images/clock"));
    m_timerLogo->setPos(1100, m_groundLevel -654 );
    addItem(m_timerLogo);

    //Add wall structures
    m_wall2 = new BackgroundItem(QPixmap(":images/wallg.png"));
    m_wall2->setPos(2500, m_groundLevel - m_wall2->boundingRect().height());
    addItem(m_wall2);

    m_wall = new BackgroundItem(QPixmap(":images/wallf2.png"));
    m_wall->setPos(2300, m_groundLevel - m_wall->boundingRect().height());
    addItem(m_wall);

    m_wall3 = new BackgroundItem(QPixmap(":images/walli.png"));
    m_wall3->setPos(2750, m_groundLevel - m_wall3->boundingRect().height());
    addItem(m_wall3);

    //Add flag Pole
    m_flag = new BackgroundItem(QPixmap(":images/flag"));
    m_flag->setPos(7234, m_groundLevel - m_flag->boundingRect().height());
    addItem(m_flag);

    //Add Castle
    m_castle = new BackgroundItem(QPixmap(":images/castle"));
    m_castle->setPos(7637, m_groundLevel - m_castle->boundingRect().height());
    addItem(m_castle);

    //Add Coins
    m_coins = new Coin();
    m_coins->setPos(1050, m_groundLevel - m_coins->boundingRect().height()-200);
    addItem(m_coins);
    startTimer( 100 );

    m_coins2 = new Coin();
    m_coins2->setPos(1015, m_groundLevel - m_coins2->boundingRect().height()-250);
    addItem(m_coins2);    

    m_coins3 = new Coin();
    m_coins3->setPos(980, m_groundLevel - m_coins3->boundingRect().height()-300);
    addItem(m_coins3);    

    m_coins4 = new Coin();
    m_coins4->setPos(945, m_groundLevel - m_coins4->boundingRect().height()-350);
    addItem(m_coins4);  

    m_coins5 = new Coin();
    m_coins5->setPos(1155, m_groundLevel - m_coins5->boundingRect().height()-350);
    addItem(m_coins5);    

    m_coins6 = new Coin();
    m_coins6->setPos(1120, m_groundLevel - m_coins6->boundingRect().height()-300);
    addItem(m_coins6);  

    m_coins7 = new Coin();
    m_coins7->setPos(1085, m_groundLevel - m_coins7->boundingRect().height()-250);
    addItem(m_coins7);

    m_coins8 = new Coin();
    m_coins8->setPos(1250, m_groundLevel - m_coins8->boundingRect().height()-200);
    addItem(m_coins8);

    m_coins9 = new Coin();
    m_coins9->setPos(1215, m_groundLevel - m_coins9->boundingRect().height()-250);
    addItem(m_coins9);

    m_coins10 = new Coin();
    m_coins10->setPos(1180, m_groundLevel - m_coins10->boundingRect().height()-300);
    addItem(m_coins10);

    m_coins11 = new Coin();
    m_coins11->setPos(1285, m_groundLevel - m_coins11->boundingRect().height()-250);
    addItem(m_coins11);

    m_coins12 = new Coin();
    m_coins12->setPos(1310, m_groundLevel - m_coins12->boundingRect().height()-300);
    addItem(m_coins12);

    m_coins13 = new Coin();
    m_coins13->setPos(1345, m_groundLevel - m_coins13->boundingRect().height()-350);
    addItem(m_coins13);

    m_coins14 = new Coin();
    m_coins14->setPos(1380, m_groundLevel -  m_coins14->boundingRect().height()-300);
    addItem( m_coins14);

    m_coins15 = new Coin();
    m_coins15->setPos(1415, m_groundLevel - m_coins15->boundingRect().height()-250);
    addItem(m_coins15);

    m_coins16 = new Coin();
    m_coins16->setPos(1450, m_groundLevel - m_coins16->boundingRect().height()-200);
    addItem(m_coins16);

    m_coins17 = new Coin();
    m_coins17->setPos(1485, m_groundLevel - m_coins17->boundingRect().height()-250);
    addItem(m_coins17);

    m_coins18 = new Coin();
    m_coins18->setPos(1510, m_groundLevel - m_coins18->boundingRect().height()-300);
    addItem(m_coins18);

    m_coins19 = new Coin();
    m_coins19->setPos(1545, m_groundLevel - m_coins19->boundingRect().height()-350);
    addItem(m_coins19);



    //first wall structure coins
    m_coins27 = new Coin();
    m_coins27->setPos(2970, m_groundLevel - m_coins27->boundingRect().height()-200);
    addItem(m_coins27);

    m_coins28 = new Coin();
    m_coins28->setPos(3020, m_groundLevel - m_coins28->boundingRect().height()-200);
    addItem(m_coins28);

    m_coins29 = new Coin();
    m_coins29->setPos(3070, m_groundLevel - m_coins29->boundingRect().height()-200);
    addItem(m_coins29);

    m_coins30 = new Coin();
    m_coins30->setPos(2920, m_groundLevel - m_coins30->boundingRect().height()-200);
    addItem(m_coins30);

    //Bottom wall structure coins
    m_coins32 = new Coin();
    m_coins32->setPos(3510, m_groundLevel - m_coins32->boundingRect().height()-150);
    addItem(m_coins32);

    m_coins33 = new Coin();
    m_coins33->setPos(2760, m_groundLevel - m_coins33->boundingRect().height()-150);
    addItem(m_coins33);

    m_coins34 = new Coin();
    m_coins34->setPos(2810, m_groundLevel - m_coins34->boundingRect().height()-150);
    addItem(m_coins34);

    m_coins35 = new Coin();
    m_coins35->setPos(2860, m_groundLevel - m_coins35->boundingRect().height()-150);
    addItem(m_coins35);

    m_coins36 = new Coin();
    m_coins36->setPos(2910, m_groundLevel - m_coins36->boundingRect().height()-150);
    addItem(m_coins36);

    m_coins37 = new Coin();
    m_coins37->setPos(2960, m_groundLevel - m_coins37->boundingRect().height()-150);
    addItem(m_coins37);

    m_coins38 = new Coin();
    m_coins38->setPos(3010, m_groundLevel - m_coins38->boundingRect().height()-150);
    addItem(m_coins38);

    m_coins39 = new Coin();
    m_coins39->setPos(3060, m_groundLevel - m_coins39->boundingRect().height()-150);
    addItem(m_coins39);

    m_coins40 = new Coin();
    m_coins40->setPos(3110, m_groundLevel - m_coins40->boundingRect().height()-150);
    addItem(m_coins40);

    m_coins41 = new Coin();
    m_coins41->setPos(3160, m_groundLevel - m_coins41->boundingRect().height()-150);
    addItem(m_coins41);

    m_coins42 = new Coin();
    m_coins42->setPos(3210, m_groundLevel - m_coins42->boundingRect().height()-150);
    addItem(m_coins42);

    m_coins43 = new Coin();
    m_coins43->setPos(3260, m_groundLevel - m_coins43->boundingRect().height()-150);
    addItem(m_coins43);

    m_coins44 = new Coin();
    m_coins44->setPos(3310, m_groundLevel - m_coins44->boundingRect().height()-150);
    addItem(m_coins44);

    m_coins45 = new Coin();
    m_coins45->setPos(3360, m_groundLevel - m_coins45->boundingRect().height()-150);
    addItem(m_coins45);

    m_coins46 = new Coin();
    m_coins46->setPos(3410, m_groundLevel - m_coins46->boundingRect().height()-150);
    addItem(m_coins46);

    m_coins47 = new Coin();
    m_coins47->setPos(3460, m_groundLevel - m_coins47->boundingRect().height()-150);
    addItem(m_coins47);

    //Notebox coins
    m_coins48 = new Coin();
    m_coins48->setPos(3995, m_groundLevel - m_coins48->boundingRect().height()-370);
    addItem(m_coins48);

    m_coins49 = new Coin();
    m_coins49->setPos(4030, m_groundLevel - m_coins49->boundingRect().height()-440);
    addItem(m_coins49);

    m_coins50 = new Coin();
    m_coins50->setPos(4108, m_groundLevel - m_coins50->boundingRect().height()-495);
    addItem(m_coins50);

    m_coins51 = new Coin();
    m_coins51->setPos(4190, m_groundLevel - m_coins51->boundingRect().height()-450);
    addItem(m_coins51);

    m_coins52 = new Coin();
    m_coins52->setPos(4240, m_groundLevel - m_coins52->boundingRect().height()-390);
    addItem(m_coins52);

    m_coins53 = new Coin();
    m_coins53->setPos(4290, m_groundLevel - m_coins53->boundingRect().height()-465);
    addItem(m_coins53);

    m_coins54 = new Coin();
    m_coins54->setPos(4360, m_groundLevel - m_coins54->boundingRect().height()-520);
    addItem(m_coins54);

    m_coins55 = new Coin();
    m_coins55->setPos(4435, m_groundLevel - m_coins55->boundingRect().height()-465);
    addItem(m_coins55);

    m_coins56 = new Coin();
    m_coins56->setPos(4490, m_groundLevel - m_coins56->boundingRect().height()-410);
    addItem(m_coins56);

    m_coins57 = new Coin();
    m_coins57->setPos(4540, m_groundLevel - m_coins57->boundingRect().height()-490);
    addItem(m_coins57);

    m_coins58 = new Coin();
    m_coins58->setPos(4610, m_groundLevel - m_coins58->boundingRect().height()-540);
    addItem(m_coins58);

    m_coins59 = new Coin();
    m_coins59->setPos(4680, m_groundLevel - m_coins59->boundingRect().height()-500);
    addItem(m_coins59);

    m_coins60 = new Coin();
    m_coins60->setPos(4730, m_groundLevel - m_coins60->boundingRect().height()-440);
    addItem(m_coins60);

    m_coins61 = new Coin();
    m_coins61->setPos(520, m_groundLevel - m_coins61->boundingRect().height()-315);
    addItem(m_coins61);

    m_coins62 = new Coin();
    m_coins62->setPos(2300, m_groundLevel - m_coins62->boundingRect().height()-300);
    addItem(m_coins62);

    m_coins64 = new Coin();
    m_coins64->setPos(2355, m_groundLevel - m_coins64->boundingRect().height()-300);
    addItem(m_coins64);

    m_coins65 = new Coin();
    m_coins65->setPos(2410, m_groundLevel - m_coins65->boundingRect().height()-300);
    addItem(m_coins65);

    m_coins66 = new Coin();
    m_coins66->setPos(2465, m_groundLevel - m_coins66->boundingRect().height()-300);
    addItem(m_coins66);

    m_coins67 = new Coin();
    m_coins67->setPos(2520, m_groundLevel - m_coins67->boundingRect().height()-300);
    addItem(m_coins67);

    m_coins68 = new Coin();
    m_coins68->setPos(2575, m_groundLevel - m_coins68->boundingRect().height()-300);
    addItem(m_coins68);

    //End Level coins
    m_coins69 = new Coin();
    m_coins69->setPos(5300, m_groundLevel - m_coins69->boundingRect().height()-250);
    addItem(m_coins69);

    m_coins70 = new Coin();
    m_coins70->setPos(5300, m_groundLevel - m_coins70->boundingRect().height()-300);
    addItem(m_coins70);

    m_coins71 = new Coin();
    m_coins71->setPos(5300, m_groundLevel - m_coins71->boundingRect().height()-350);
    addItem(m_coins71);

    m_coins72 = new Coin();
    m_coins72->setPos(5250, m_groundLevel - m_coins72->boundingRect().height()-250);
    addItem(m_coins72);

    m_coins73 = new Coin();
    m_coins73->setPos(5250, m_groundLevel - m_coins73->boundingRect().height()-300);
    addItem(m_coins73);

    m_coins74 = new Coin();
    m_coins74->setPos(5250, m_groundLevel - m_coins74->boundingRect().height()-350);
    addItem(m_coins74);

    m_coins75 = new Coin();
    m_coins75->setPos(5200, m_groundLevel - m_coins75->boundingRect().height()-250);
    addItem(m_coins75);

    m_coins76 = new Coin();
    m_coins76->setPos(5200, m_groundLevel - m_coins76->boundingRect().height()-300);
    addItem(m_coins76);

    m_coins77 = new Coin();
    m_coins77->setPos(5200, m_groundLevel - m_coins77->boundingRect().height()-350);
    addItem(m_coins77);

    m_coins78 = new Coin();
    m_coins78->setPos(5150, m_groundLevel - m_coins78->boundingRect().height()-250);
    addItem(m_coins78);

    m_coins79 = new Coin();
    m_coins79->setPos(5150, m_groundLevel - m_coins79->boundingRect().height()-300);
    addItem(m_coins79);

    m_coins80 = new Coin();
    m_coins80->setPos(5150, m_groundLevel - m_coins80->boundingRect().height()-350);
    addItem(m_coins80);

    m_coins81 = new Coin();
    m_coins81->setPos(5100, m_groundLevel - m_coins81->boundingRect().height()-250);
    addItem(m_coins81);

    m_coins82 = new Coin();
    m_coins82->setPos(5100, m_groundLevel - m_coins82->boundingRect().height()-300);
    addItem(m_coins82);

    m_coins83 = new Coin();
    m_coins83->setPos(5100, m_groundLevel - m_coins83->boundingRect().height()-350);
    addItem(m_coins83);

    m_coins84 = new Coin();
    m_coins84->setPos(5050, m_groundLevel - m_coins84->boundingRect().height()-250);
    addItem(m_coins84);

    m_coins85 = new Coin();
    m_coins85->setPos(5050, m_groundLevel - m_coins85->boundingRect().height()-300);
    addItem(m_coins85);

    m_coins86 = new Coin();
    m_coins86->setPos(5050, m_groundLevel - m_coins86->boundingRect().height()-350);
    addItem(m_coins86);

    m_coins87 = new Coin();
    m_coins87->setPos(5700, m_groundLevel - m_coins87->boundingRect().height()-350);
    addItem(m_coins87);

    m_coins88 = new Coin();
    m_coins88->setPos(5750, m_groundLevel - m_coins88->boundingRect().height()-350);
    addItem(m_coins88);

    m_coins89 = new Coin();
    m_coins89->setPos(5800, m_groundLevel - m_coins89->boundingRect().height()-350);
    addItem(m_coins89);

    m_coins90 = new Coin();
    m_coins90->setPos(5850, m_groundLevel - m_coins90->boundingRect().height()-350);
    addItem(m_coins90);

    m_coins91 = new Coin();
    m_coins91->setPos(5900, m_groundLevel - m_coins91->boundingRect().height()-350);
    addItem(m_coins91);

    m_coins92 = new Coin();
    m_coins92->setPos(5950, m_groundLevel - m_coins92->boundingRect().height()-350);
    addItem(m_coins92);

    m_coins93 = new Coin();
    m_coins93->setPos(6000, m_groundLevel - m_coins93->boundingRect().height()-350);
    addItem(m_coins93);

    m_coins94 = new Coin();
    m_coins94->setPos(6050, m_groundLevel - m_coins94->boundingRect().height()-350);
    addItem(m_coins94);

    m_coins95 = new Coin();
    m_coins95->setPos(6100, m_groundLevel - m_coins95->boundingRect().height()-350);
    addItem(m_coins95);

    m_coins96 = new Coin();
    m_coins96->setPos(6140, m_groundLevel - m_coins96->boundingRect().height()-350);
    addItem(m_coins96);

    m_coins97 = new Coin();
    m_coins97->setPos(6105, m_groundLevel - m_coins97->boundingRect().height()-300);
    addItem(m_coins97);

    m_coins98 = new Coin();
    m_coins98->setPos(6060, m_groundLevel - m_coins98->boundingRect().height()-250);
    addItem(m_coins98);

    m_coins99 = new Coin();
    m_coins99->setPos(6105, m_groundLevel - m_coins99->boundingRect().height()-400);
    addItem(m_coins99);

    m_coins100 = new Coin();
    m_coins100->setPos(6060, m_groundLevel - m_coins100->boundingRect().height()-450);
    addItem(m_coins100);



    m_questbox2 = new QuestBox(1);
    m_questbox2->setPos(2155, m_groundLevel - m_questbox2->boundingRect().height()-150);
    addItem(m_questbox2);

    m_questbox3 = new QuestBox(1);
    m_questbox3->setPos(2058, m_groundLevel - m_questbox3->boundingRect().height()-100);
    addItem(m_questbox3);

    //Wall scructure questbox
    m_questbox4 = new QuestBox(1);
    m_questbox4->setPos(2650, m_groundLevel - m_questbox4->boundingRect().height()-450);
    addItem(m_questbox4);

    m_questbox5 = new QuestBox(1);
    m_questbox5->setPos(3250, m_groundLevel - m_questbox5->boundingRect().height()-250);
    addItem(m_questbox5);

    //Rcc Coin area Questbox
    m_questbox6 = new QuestBox(1);
    m_questbox6->setPos(1445, m_groundLevel - m_questbox6->boundingRect().height()-130);
    addItem(m_questbox6);

    m_questbox7 = new QuestBox(1);
    m_questbox7->setPos(1245, m_groundLevel - m_questbox7->boundingRect().height()-130);
    addItem(m_questbox7);

    m_questbox8 = new QuestBox(1);
    m_questbox8->setPos(1045, m_groundLevel - m_questbox8->boundingRect().height()-130);
    addItem(m_questbox8);

    m_questbox9 = new QuestBox(1);
    m_questbox9->setPos(6240, m_groundLevel - m_questbox9->boundingRect().height()-350);
    addItem(m_questbox9);

    m_questbox10 = new QuestBox(1);
    m_questbox10->setPos(5600, m_groundLevel - m_questbox10->boundingRect().height()-350);
    addItem(m_questbox10);

    m_questbox11 = new QuestBox(1);
    m_questbox11->setPos(5153, m_groundLevel - m_questbox11->boundingRect().height()-200);
    addItem(m_questbox11);

    m_questbox12 = new QuestBox(1);
    m_questbox12->setPos(7200, m_groundLevel - m_questbox11->boundingRect().height()-100);
    addItem(m_questbox12);

    //Add brick platforms


    mBrickPlatform2 = new BrickPlatform(1);
    mBrickPlatform2->setPos(348, m_groundLevel - mBrickPlatform2->boundingRect().height()-150);
    addItem(mBrickPlatform2);

    mBrickPlatform3 = new BrickPlatform(1);
    mBrickPlatform3->setPos(510, m_groundLevel - mBrickPlatform3->boundingRect().height()-270);
    addItem(mBrickPlatform3);

    mBrickPlatform4 = new BrickPlatform(5);
    mBrickPlatform4->setPos(700, m_groundLevel - mBrickPlatform4->boundingRect().height()-200);
    addItem(mBrickPlatform4);

    mBrickPlatform5 = new BrickPlatform(5);
    mBrickPlatform5->setPos(5500, m_groundLevel - mBrickPlatform5->boundingRect().height()-150);
    addItem(mBrickPlatform5);

    mBrickPlatform6 = new BrickPlatform(5);
    mBrickPlatform6->setPos(5050, m_groundLevel - mBrickPlatform6->boundingRect().height()-200);
    addItem(mBrickPlatform6);

    mBrickPlatform7 = new BrickPlatform(1);
    mBrickPlatform7->setPos(5900, m_groundLevel - mBrickPlatform7->boundingRect().height()-150);
    addItem(mBrickPlatform7);

    mBrickPlatform8 = new BrickPlatform(7);
    mBrickPlatform8->setPos(6100, m_groundLevel - mBrickPlatform8->boundingRect().height()-150);
    addItem(mBrickPlatform8);

    //Add wall platform
    m_wallPlatform = new WallPlatform(6);
    m_wallPlatform->setPos(2310, m_groundLevel - m_wallPlatform->boundingRect().height()-240);
    addItem(m_wallPlatform);

    m_wallPlatform2  = new WallPlatform(8);
    m_wallPlatform2->setPos(2515, m_groundLevel - m_wallPlatform2->boundingRect().height()-300);
    addItem(m_wallPlatform2);

    m_wallPlatform3 = new WallPlatform(16);
    m_wallPlatform3->setPos(2770, m_groundLevel - m_wallPlatform3->boundingRect().height()-103);
    addItem(m_wallPlatform3);

    m_wallPlatform4 = new WallPlatform(20);
    m_wallPlatform4->setPos(5000, m_groundLevel );
    addItem(m_wallPlatform4);

    m_wallPlatform4_1 = new WallPlatform(20);
    m_wallPlatform4_1->setPos(3910, m_groundLevel );
    addItem(m_wallPlatform4_1);


    m_wallPlatform5 = new WallPlatform(10);
    m_wallPlatform5->setPos(1045, m_groundLevel );
    addItem(m_wallPlatform5);

    m_wallPlatform6 = new WallPlatform(3);
    m_wallPlatform6->setPos(404, m_groundLevel );
    addItem(m_wallPlatform6);


    m_wallPlatform7 = new WallPlatform(3);
    m_wallPlatform7->setPos(730, m_groundLevel );
    addItem(m_wallPlatform7);

    m_wallPlatform8 = new WallPlatform(4);
    m_wallPlatform8->setPos(2515, m_groundLevel );
    addItem(m_wallPlatform8);

    m_wallPlatform9 = new WallPlatform(3);
    m_wallPlatform9->setPos(4390, m_groundLevel );
    addItem(m_wallPlatform9);

    m_wallPlatform12 = new WallPlatform(3);
    m_wallPlatform12->setPos(5000, m_groundLevel );
    addItem(m_wallPlatform12);

    m_wallPlatform10 = new WallPlatform(3);
    m_wallPlatform10->setPos(6100, m_groundLevel );
    addItem(m_wallPlatform10);

    m_wallPlatform11 = new WallPlatform(3);
    m_wallPlatform11->setPos(1700, m_groundLevel- m_wallPlatform11->boundingRect().height()-280 );
    addItem(m_wallPlatform11);

   //Add Notebox
    m_NoteBox = new NoteBox(5);
    m_NoteBox->setPos(1700, m_groundLevel - m_NoteBox->boundingRect().height()-250);
    addItem(m_NoteBox);

    m_NoteBox2 = new NoteBox(1);
    m_NoteBox2->setPos(3580, m_groundLevel - m_NoteBox2->boundingRect().height()-150);
    addItem(m_NoteBox2);

    m_NoteBox3 = new NoteBox(1);
    m_NoteBox3->setPos(3690, m_groundLevel - m_NoteBox3->boundingRect().height()-310);
    addItem(m_NoteBox3);

    m_NoteBox4 = new NoteBox(1);
    m_NoteBox4->setPos(3980, m_groundLevel - m_NoteBox4->boundingRect().height()-150);
    addItem(m_NoteBox4);

    m_NoteBox5 = new NoteBox(1);
    m_NoteBox5->setPos(4120, m_groundLevel - m_NoteBox5->boundingRect().height()-315);
    addItem(m_NoteBox5);

    m_NoteBox6 = new NoteBox(5);
    m_NoteBox6->setPos(4390, m_groundLevel - m_NoteBox6->boundingRect().height()-400);
    addItem(m_NoteBox6);

    //Add Goomba

    //Add Turtle
    m_goomba = new Goomba(QRectF(m_wallPlatform7->pos(), m_wallPlatform7->boundingRect().size()), -1);
    m_goomba->setPos(745, m_groundLevel - m_goomba->boundingRect().height()-250);
    addItem(m_goomba);

    m_turtle2 = new Turtle(QRectF(m_wallPlatform8->pos(), m_wallPlatform8->boundingRect().size()), -1);
    m_turtle2->setPos(2550, m_groundLevel - m_turtle2->boundingRect().height()-345);
    addItem(m_turtle2);

    //Add piranha plant
    m_piranha = new Piranha();
    m_piranha->setPos(473, m_groundLevel - m_piranha->boundingRect().height()-95);
    addItem(m_piranha);

    m_piranha2 = new Piranha();
    m_piranha2->setPos(2225, m_groundLevel - m_piranha2->boundingRect().height()-95);
    addItem(m_piranha2);

    m_piranha3= new Piranha();
    m_piranha3->setPos(4690, m_groundLevel - m_piranha2->boundingRect().height()-95);
    addItem(m_piranha3);

    //Add Flag Animation
    m_flag2 = new Flag();
    m_flag2->setPos(7320, m_groundLevel - m_flag2->boundingRect().height()-285);
    addItem(m_flag2);

    //Add coin counter
    m_count = new CoinCounter();
    m_count->setPos(65, m_groundLevel - m_count->boundingRect().height()-602);
    addItem(m_count);

    //Add Score counter
    m_score = new Score();
    m_score->setPos(980, m_groundLevel - m_score->boundingRect().height()-610);
    addItem(m_score);

    //Add Game Timer
    m_gameTimer = new Timer();
    m_gameTimer->setPos(1140, m_groundLevel - m_gameTimer->boundingRect().height()-610);
    addItem(m_gameTimer);

    //Add conveyor
    m_conveyor = new Conveyor();
    m_conveyor->setPos(3660, m_groundLevel - m_conveyor->boundingRect().height()-160);
    addItem(m_conveyor);

    m_conveyor2 = new Conveyor();
    m_conveyor2->setPos(3870, m_groundLevel - m_conveyor2->boundingRect().height()-350);
    addItem(m_conveyor2);

    m_conveyor3 = new Conveyor();
    m_conveyor3->setPos(4180, m_groundLevel - m_conveyor3->boundingRect().height()-100);
    addItem(m_conveyor3);

    //Add giant goomba
    m_giantgoomba = new GiantGoomba();
    m_giantgoomba->setPos(3700, m_groundLevel - m_giantgoomba->boundingRect().height()-210);
    addItem(m_giantgoomba);

    m_giantgoomba2 = new GiantGoomba();
    m_giantgoomba2->setPos(3910, m_groundLevel - m_giantgoomba2->boundingRect().height()-400);
    addItem(m_giantgoomba2);

    m_giantgoomba3 = new GiantGoomba();
    m_giantgoomba3->setPos(4230, m_groundLevel - m_giantgoomba3->boundingRect().height()-150);
    addItem(m_giantgoomba3);

    //Add warp tube
    m_warpTube1 = new WarpTube();
    m_warpTube1->setPos(500, m_groundLevel - m_warpTube1->boundingRect().height());
    addItem(m_warpTube1);

    m_warpTube2 = new WarpTube();
    m_warpTube2->setPos(2250, m_groundLevel - m_warpTube2->boundingRect().height());
    addItem(m_warpTube2);

    m_warpTube3 = new WarpTube();
    m_warpTube3->setPos(4720, m_groundLevel - m_warpTube3->boundingRect().height());
    addItem(m_warpTube3);

    //Add Stair blocks
    m_stairBlock = new StairBlock(9);
    m_stairBlock->setPos(6750, m_groundLevel - m_stairBlock->boundingRect().height());
    addItem(m_stairBlock);

    m_stairBlock2 = new StairBlock(8);
    m_stairBlock2->setPos(6798, m_groundLevel - m_stairBlock2->boundingRect().height()-48);
    addItem(m_stairBlock2);

    m_stairBlock3 = new StairBlock(7);
    m_stairBlock3->setPos(6846, m_groundLevel - m_stairBlock3->boundingRect().height()-96);
    addItem(m_stairBlock3);

    m_stairBlock4 = new StairBlock(6);
    m_stairBlock4->setPos(6894, m_groundLevel - m_stairBlock4->boundingRect().height()-144);
    addItem(m_stairBlock4);

    m_stairBlock5 = new StairBlock(5);
    m_stairBlock5->setPos(6942, m_groundLevel - m_stairBlock5->boundingRect().height()-192);
    addItem(m_stairBlock5);

    m_stairBlock6 = new StairBlock(4);
    m_stairBlock6->setPos(6990, m_groundLevel - m_stairBlock6->boundingRect().height()-240);
    addItem(m_stairBlock6);

    m_stairBlock7 = new StairBlock(3);
    m_stairBlock7->setPos(7038, m_groundLevel - m_stairBlock7->boundingRect().height()-288);
    addItem(m_stairBlock7);

    m_stairBlock8 = new StairBlock(2);
    m_stairBlock8->setPos(7086, m_groundLevel - m_stairBlock8->boundingRect().height()-336);
    addItem(m_stairBlock8);

    //Add goomba
    m_turtle = new Turtle(QRectF(m_wallPlatform12->pos(), m_wallPlatform12->boundingRect().size()), -1);
    m_turtle->setPos(5000, m_groundLevel - m_turtle->boundingRect().height()-250);
    addItem(m_turtle);

    m_goomba2 = new Goomba(QRectF(m_wallPlatform9->pos(), m_wallPlatform9->boundingRect().size()), -1);
    m_goomba2->setPos(4390, m_groundLevel - m_goomba2->boundingRect().height()-465);
    addItem(m_goomba2);

    //Add bomb
    m_bomb2 = new Bomb(QRectF(m_wallPlatform10->pos(), m_wallPlatform10->boundingRect().size()), -1);
    m_bomb2->setPos(6100, m_groundLevel - m_bomb2->boundingRect().height()-190);
    addItem(m_bomb2);

    //Add Red Turtle
    m_redTurtle = new RedTurtle(QRectF(m_wallPlatform4->pos(), m_wallPlatform4->boundingRect().size()), -1);
    m_redTurtle->setPos(5100, m_groundLevel - m_redTurtle->boundingRect().height()+4);
    addItem(m_redTurtle);

    m_redTurtle2 = new RedTurtle(QRectF(m_wallPlatform4_1->pos(), m_wallPlatform4_1->boundingRect().size()), -1);
    m_redTurtle2->setPos(3910, m_groundLevel - m_redTurtle2->boundingRect().height()+4);
    addItem(m_redTurtle2);

    //Add Spiny
    m_spiny = new Spiny(QRectF(m_wallPlatform5->pos(), m_wallPlatform5->boundingRect().size()), -1);
    m_spiny->setPos(1045, m_groundLevel - m_spiny->boundingRect().height()+4);
    addItem(m_spiny);

    m_mushroom = new Mushroom(QRectF(m_wallPlatform11->pos(), m_wallPlatform11->boundingRect().size()), -1);
    m_mushroom->setPos(1700, m_groundLevel - m_mushroom->boundingRect().height()-310);
    addItem(m_mushroom);

    //add player
    m_player = new Player();
    m_minX = m_player->boundingRect().width()/2 ;
    m_maxX = m_fieldWidth - m_player->boundingRect().width() * 1.5;
    m_player->setPos(m_minX, m_groundLevel - m_player->boundingRect().height() );
    m_realPos = m_minX;
    addItem(m_player);

    m_smallPlayer = new SmallMario();

    //Add half castle to make it look like mario can walk inside of castle
    h_castle = new Castle();
    h_castle->setPos(7637, m_groundLevel - h_castle->boundingRect().height());
    addItem(h_castle);
}

//Timer event for animations
void MyScene::timerEvent(QTimerEvent *){
    m_coins->nextFrame2();
    m_coins2->nextFrame2();
    m_coins3->nextFrame2();
    m_coins4->nextFrame2();
    m_coins5->nextFrame2();
    m_coins6->nextFrame2();
    m_coins7->nextFrame2();
    m_coins8->nextFrame2();
    m_coins9->nextFrame2();
    m_coins10->nextFrame2();
    m_coins11->nextFrame2();
    m_coins12->nextFrame2();
    m_coins13->nextFrame2();
    m_coins14->nextFrame2();
    m_coins15->nextFrame2();
    m_coins16->nextFrame2();
    m_coins17->nextFrame2();
    m_coins18->nextFrame2();
    m_coins19->nextFrame2();


    m_coins27->nextFrame2();
    m_coins28->nextFrame2();
    m_coins29->nextFrame2();
    m_coins30->nextFrame2();

    m_coins32->nextFrame2();
    m_coins33->nextFrame2();
    m_coins34->nextFrame2();
    m_coins35->nextFrame2();
    m_coins36->nextFrame2();

    m_coins37->nextFrame2();
    m_coins38->nextFrame2();
    m_coins39->nextFrame2();
    m_coins40->nextFrame2();
    m_coins41->nextFrame2();
    m_coins42->nextFrame2();
    m_coins43->nextFrame2();
    m_coins44->nextFrame2();
    m_coins45->nextFrame2();
    m_coins46->nextFrame2();
    m_coins47->nextFrame2();

    m_coins48->nextFrame2();
    m_coins49->nextFrame2();
    m_coins50->nextFrame2();
    m_coins51->nextFrame2();
    m_coins52->nextFrame2();

    m_coins53->nextFrame2();
    m_coins54->nextFrame2();
    m_coins55->nextFrame2();
    m_coins56->nextFrame2();

    m_coins57->nextFrame2();
    m_coins58->nextFrame2();
    m_coins59->nextFrame2();
    m_coins60->nextFrame2();

    m_coins61->nextFrame2();
    m_coins62->nextFrame2();
    m_coins64->nextFrame2();
    m_coins65->nextFrame2();
    m_coins66->nextFrame2();
    m_coins67->nextFrame2();
    m_coins68->nextFrame2();

    m_coins69->nextFrame2();
    m_coins70->nextFrame2();
    m_coins71->nextFrame2();

    m_coins72->nextFrame2();
    m_coins73->nextFrame2();
    m_coins74->nextFrame2();

    m_coins75->nextFrame2();
    m_coins76->nextFrame2();
    m_coins77->nextFrame2();
    m_coins78->nextFrame2();
    m_coins79->nextFrame2();
    m_coins80->nextFrame2();

    m_coins81->nextFrame2();
    m_coins82->nextFrame2();
    m_coins83->nextFrame2();
    m_coins84->nextFrame2();
    m_coins85->nextFrame2();
    m_coins86->nextFrame2();

    m_coins87->nextFrame2();
    m_coins88->nextFrame2();
    m_coins89->nextFrame2();
    m_coins90->nextFrame2();
    m_coins91->nextFrame2();
    m_coins92->nextFrame2();
    m_coins93->nextFrame2();
    m_coins94->nextFrame2();
    m_coins95->nextFrame2();
    m_coins96->nextFrame2();
    m_coins97->nextFrame2();
    m_coins98->nextFrame2();
    m_coins99->nextFrame2();
    m_coins100->nextFrame2();




    m_questbox2->nextFrame4();
    m_questbox3->nextFrame4();
    m_questbox4->nextFrame4();
    m_questbox5->nextFrame4();
    m_questbox6->nextFrame4();
    m_questbox7->nextFrame4();
    m_questbox8->nextFrame4();
    m_questbox9->nextFrame4();
    m_questbox10->nextFrame4();
    m_questbox11->nextFrame4();
    m_questbox12->nextFrame4();

    m_turtle->nextFrame6();
    m_turtle2->nextFrame6();

    m_piranha->nextFrame();
    m_piranha2->nextFrame();
    m_piranha3->nextFrame();


    mBrickPlatform2->nextFrame();
    mBrickPlatform3->nextFrame();
    mBrickPlatform4->nextFrame();
    mBrickPlatform5->nextFrame();
    mBrickPlatform6->nextFrame();
    mBrickPlatform7->nextFrame();
    mBrickPlatform8->nextFrame();

    m_NoteBox->nextFrame();
    m_NoteBox2->nextFrame();
    m_NoteBox3->nextFrame();
    m_NoteBox4->nextFrame();
    m_NoteBox5->nextFrame();
    m_NoteBox6->nextFrame();

    m_flag2->nextFrame();

    m_conveyor->nextFrame11();
    m_conveyor2->nextFrame11();
    m_conveyor3->nextFrame11();

    m_giantgoomba->nextFrame12();
    m_giantgoomba2->nextFrame12();
    m_giantgoomba3->nextFrame12();

    m_goomba2->nextFrame3();
    m_goomba->nextFrame3();

    m_bomb2->nextFrame();

    m_redTurtle->nextFrame();
    m_redTurtle2->nextFrame();


    m_spiny->nextFrame();
    m_mushroom->nextFrame();
}

qreal MyScene::jumpFactor() const{
    return m_jumpFactor;
}

void MyScene::setJumpFactor(const qreal &jumpFactor){
    if (m_jumpFactor == jumpFactor)
        return;

    m_jumpFactor = jumpFactor;
    emit jumpFactorChanged(m_jumpFactor);
}

//Check timer and change player to standing position if timer stopped
void MyScene::checkTimer(){
    if (0 == m_player->direction()) {
        m_player->stand();
        m_smallPlayer->stand();
        m_timer.stop();
    }

    else if (!m_timer.isActive()) {
        m_timer.start();
        m_player->walk();
        m_smallPlayer->walk();
    }
}

//COLLISION DETECTION

QGraphicsItem* MyScene::collidingPlatforms() {
    QList<QGraphicsItem*> items =  collidingItems(m_player);
    foreach(QGraphicsItem *item, items) {
        if(BrickPlatform *brickplatform = qgraphicsitem_cast<BrickPlatform *>(item)) {
            return brickplatform;
        }
        if(QuestBox *questbox = qgraphicsitem_cast<QuestBox *>(item)) {
            return questbox;
        }
        if(NoteBox *notebox = qgraphicsitem_cast<NoteBox *>(item)) {
            return notebox;
        }
        if(WallPlatform *wallplatform = qgraphicsitem_cast<WallPlatform *>(item)) {
            return wallplatform;
        }
        if(StairBlock *stairblock = qgraphicsitem_cast<StairBlock *>(item)) {
            return stairblock;
        }

    }
    return 0;
}

//Platform collision detection
bool MyScene::handleCollisionWithPlatform() {
    QGraphicsItem* platform =  collidingPlatforms();
    if(platform) {
        QPointF platformPos = platform->pos();     
        if((m_player->isTouchingFoot(platform))||(m_smallPlayer->isTouchingFoot(platform))) {
            m_player->setPos(m_player->pos().x(), platformPos.y() - m_player->boundingRect().height());
            m_smallPlayer->setPos(m_smallPlayer->pos().x(), platformPos.y() - m_smallPlayer->boundingRect().height());
            m_platform = platform;
            m_jumpAnimation->stop();           
            return true;
        }
    }
    else {
        m_platform = 0;
    }
    return false;
}

//Goomba Collision
void MyScene::handleCollisionWithGoomba() {
    QList<QGraphicsItem*> items = collidingItems(m_player);
    foreach (QGraphicsItem* item, items) {
        Goomba* c = qgraphicsitem_cast<Goomba*>(item);
        if(c){
            removeItem(c);
            emit this->playSound("shrink");
            removeItem(m_player);
            addItem(m_smallPlayer);
            m_smallPlayer->setPos(m_player->pos().x(),m_player->pos().y());
            m_smallPlayer->fall();
            mFallTimer.start();
        }
    }
}


//Coin collision
void MyScene::checkCollidingCoin() {
    QList<QGraphicsItem*> items = collidingItems(m_player);
    foreach (QGraphicsItem* item, items) {
        Coin* c = qgraphicsitem_cast<Coin*>(item);
        if(c){

            removeItem(c);
            emit this->playSound("coin");
            m_count->increase();
            m_score->increase();          
        }
    }
}


//Question box collision for mario head coin count
void MyScene::checkCollidingQuestBox(){
    QList<QGraphicsItem*> items = collidingItems(m_player);
    foreach (QGraphicsItem* item, items) {
        QuestBox* q = qgraphicsitem_cast<QuestBox*>(item);
        if(q){
            if(m_player->isTouchingHead(q)){

                emit this->playSound("coin");
                m_count->increase();
                m_score->increase();
            }
        }
    }
}

//Stairblock Collision
void MyScene::checkCollidingStairBlock(){
    QList<QGraphicsItem*> items = collidingItems(m_player);
    foreach (QGraphicsItem* item, items) {
        StairBlock* x = qgraphicsitem_cast<StairBlock*>(item);
        if(x){

            if(x->pos().x()){
                if(m_player->pos().x() < x->pos().x())
                    m_player->setPos(x->pos().x()- m_player->boundingRect().width()+5,m_player->pos().y());
                    m_smallPlayer->setPos(x->pos().x()- m_smallPlayer->boundingRect().width()+5,m_smallPlayer->pos().y());
                if(m_player->pos().x() > x->pos().x()){
                    m_player->setPos(x->pos().x() + m_player->boundingRect().width()+370,m_player->pos().y());
                    m_smallPlayer->setPos(x->pos().x() + m_smallPlayer->boundingRect().width()+370,m_smallPlayer->pos().y());
                }
            }

            if(x->pos().y()) {
                if((m_player->pos().y() <= x->pos().y())||(m_smallPlayer->pos().y() <= x->pos().y()))
                    m_player->setPos(m_player->pos().x(),x->pos().y() - m_player->boundingRect().height());
                    m_smallPlayer->setPos(m_smallPlayer->pos().x(),x->pos().y() - m_smallPlayer->boundingRect().height());
            }
            if(!x->pos().y()){
                x=0;
            }
            if((m_player->pos().y() < m_groundLevel)||(m_smallPlayer->pos().y() < m_groundLevel)) {

                m_player->fall();
                m_smallPlayer->fall();
                mFallTimer.start();
                return;
            }
            m_player->setPos(m_player->pos().x(), m_player->pos().y());
            m_smallPlayer->setPos(m_smallPlayer->pos().x(), m_smallPlayer->pos().y());

        }
    }
}

//Piranha plant collision
void MyScene::checkCollidingPiranha() {
    QList<QGraphicsItem*> items = collidingItems(m_player);
    foreach (QGraphicsItem* item, items) {

        Piranha* p = qgraphicsitem_cast<Piranha*>(item);
        if(p){

            removeItem(p);
            emit playSound("mario_death");
            addItem(gameover);
            removeItem(m_player);
            m_gameTimer->stop();

            currentTime = m_gameTimer->getTime(); // Получаем текущее время с таймера
            // Дальнейшая обработка значения времени...

            gameOverWindow = new GameOverWindow();
            gameOverWindow->setFixedSize(650,400);
            gameOverWindow->setWindowFlags(((gameOverWindow->windowFlags() | Qt::CustomizeWindowHint)& ~Qt::WindowCloseButtonHint) );
            gameOverWindow->exec();

        }
    }
}

//Turtle Collision
void MyScene::checkCollidingTurtle() {
    QList<QGraphicsItem*> items = collidingItems(m_player);
    foreach (QGraphicsItem* item, items) {

        Turtle* t = qgraphicsitem_cast<Turtle*>(item);
        if(t){

            removeItem(t);
            emit playSound("mario_death");
            addItem(gameover);
            removeItem(m_player);
            m_gameTimer->stop();
            gameOverWindow = new GameOverWindow();
            gameOverWindow->setFixedSize(650,400);
            gameOverWindow->setWindowFlags(((gameOverWindow->windowFlags() | Qt::CustomizeWindowHint)& ~Qt::WindowCloseButtonHint) );
            gameOverWindow->exec();

        }
    }
}

//Mushroom collision
void MyScene::checkCollidingMushroom(){

    QList<QGraphicsItem*> items = collidingItems(m_smallPlayer);
    foreach (QGraphicsItem* item, items) {

        Mushroom* m = qgraphicsitem_cast<Mushroom*>(item);
        if(m){

            removeItem(m);
            emit playSound("powerup");
            removeItem(m_smallPlayer);
            addItem(m_player);
            m_player->setPos(m_smallPlayer->pos().x(),m_smallPlayer->pos().y());
            m_player->fall();
            mFallTimer.start();

        }
    }
}

//Giant Goomba collision
void MyScene::checkCollidingGiantGoomba() {
    QList<QGraphicsItem*> items = collidingItems(m_player);
    foreach (QGraphicsItem* item, items) {

        GiantGoomba* G = qgraphicsitem_cast<GiantGoomba*>(item);
        if(G){

            removeItem(G);
            emit playSound("mario_death");
            addItem(gameover);
            removeItem(m_player);
            m_gameTimer->stop();
            gameOverWindow = new GameOverWindow();
            gameOverWindow->setFixedSize(650,400);
            gameOverWindow->setWindowFlags(((gameOverWindow->windowFlags() | Qt::CustomizeWindowHint)& ~Qt::WindowCloseButtonHint) );
            gameOverWindow->exec();
        }
    }
}

//Stretch Collision


//Flag Collision
void MyScene::checkCollidingFlag() {
    QList<QGraphicsItem*> items = collidingItems(m_player);
    foreach (QGraphicsItem* item, items) {

        Flag* f = qgraphicsitem_cast<Flag*>(item);
        if(f){

             removeItem(f);
             addItem(courseclear);
             emit playSound("level_clear");         
             removeItem(m_player);
             m_gameTimer->stop();
             levelCompleteWindow = new LevelCompleteWindow();
             levelCompleteWindow->setFixedSize(650,400);
             levelCompleteWindow->setWindowFlags(((levelCompleteWindow ->windowFlags() | Qt::CustomizeWindowHint)& ~Qt::WindowCloseButtonHint) );
             levelCompleteWindow->exec();          
        }
    }
}

//WarpTube Collision
void MyScene::checkCollidingWarpTube() {
    QList<QGraphicsItem*> items = collidingItems(m_player);
    foreach (QGraphicsItem* item, items) {

        WarpTube* w = qgraphicsitem_cast<WarpTube*>(item);
        if(w){

            if(w->pos().x()){
                if(m_player->pos().x() < w->pos().x())
                    m_player->setPos(w->pos().x()- m_player->boundingRect().width(),m_player->pos().y());
                    m_smallPlayer->setPos(w->pos().x()- m_smallPlayer->boundingRect().width(),m_smallPlayer->pos().y());
                if(m_player->pos().x() > w->pos().x()){
                    m_player->setPos(w->pos().x() + m_player->boundingRect().width()+25,m_player->pos().y());
                    m_smallPlayer->setPos(w->pos().x() + m_smallPlayer->boundingRect().width()+25,m_smallPlayer->pos().y());
                }

            }
        }
    }
}

//Spiny Collision
void MyScene::checkCollidingSpiny() {
    QList<QGraphicsItem*> items = collidingItems(m_player);
    foreach (QGraphicsItem* item, items) {

        Spiny* s = qgraphicsitem_cast<Spiny*>(item);
        if(s){

            removeItem(s);
            emit playSound("mario_death");
            addItem(gameover);          
            removeItem(m_player);       
            gameOverWindow = new GameOverWindow();
            gameOverWindow->setFixedSize(650,400);
            gameOverWindow->setWindowFlags(((gameOverWindow->windowFlags() | Qt::CustomizeWindowHint)& ~Qt::WindowCloseButtonHint) );
            gameOverWindow->exec();
        }
    }
}

//Red turtle Collision
void MyScene::checkCollidingRedTurtle() {
    QList<QGraphicsItem*> items = collidingItems(m_player);
    foreach (QGraphicsItem* item, items) {

        RedTurtle* r = qgraphicsitem_cast<RedTurtle*>(item);
        if(r){

            removeItem(r);
            emit playSound("mario_death");
            addItem(gameover);          
            removeItem(m_player);           
            gameOverWindow = new GameOverWindow();
            gameOverWindow->setFixedSize(650,400);
            gameOverWindow->setWindowFlags(((gameOverWindow->windowFlags() | Qt::CustomizeWindowHint)& ~Qt::WindowCloseButtonHint) );
            gameOverWindow->exec();
        }
    }
}

//Bomb Collision
void MyScene::checkCollidingBomb() {
    QList<QGraphicsItem*> items = collidingItems(m_player);
    foreach (QGraphicsItem* item, items) {

        Bomb* b = qgraphicsitem_cast<Bomb*>(item);
        if(b){

            removeItem(b);
            emit playSound("mario_death");
            addItem(gameover);        
            removeItem(m_player);          
            gameOverWindow = new GameOverWindow();
            gameOverWindow->setFixedSize(650,400);
            gameOverWindow->setWindowFlags(((gameOverWindow->windowFlags() | Qt::CustomizeWindowHint)& ~Qt::WindowCloseButtonHint) );
            gameOverWindow->exec();
        }
    }
}







