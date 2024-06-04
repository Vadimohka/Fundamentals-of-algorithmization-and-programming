#include "player.h"
#include <QString>

Player::Player(int hpp,
               int dama,
               int defe
               ) {
    hp = new Health();
    picture = new QPixmap(":/new/prefix1/prefix1/PLAYER.png") ;
    image = new QImage ();
    damage = new Damage ();
    defence = new Defence ();
    energy =  new Energy ();
    hp->addHP(hpp);
    damage->upDamage(dama);
    defence->addDef(defe);
    deck = new Deck();
    //connect(deck,&Deck::forAttack,this,&Player::takeAttackCard); //не только для атаки, там реализовано действие всех карт
    connect(deck,&Deck::dropSignal,this,&Player::takeAttackCard);
    connect(deck,&Deck::forUpdateView,this,&Player::updateViewSlot);
    energy->upEnergy(3);
    deck->getPlayerEnergy(energy);
    this->money=50;
}

Player::~Player()
{
    operator delete(this);
}


void Player::Died()
{
    if(hp->setHP()<0)
        emit GameOver();
}

QRectF Player::boundingRect() const
{
     qDebug() << "player in rect";
    return QRectF(x,y,w,h);

}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QFont font;
    font.setBold(true); // Делаем текст жирным

    painter->setFont(font);
    // Устанавливаем цвет текста

    painter->drawPixmap(x-100,y,w+200,h,*picture);
    painter->setPen(Qt::red);
    QString str = "HP ";
    str+=QString::number(hp->setHP());
    painter->drawText(QPointF(x+200,80+(y+h)/2),str);
    painter->setPen(Qt::blue);
    str = "Defence ";
    str += QString::number(defence->setDef());
    painter->drawText(QPointF(x+200,100+(y+h)/2),str);
    painter->setPen(Qt::yellow);
    str = "Energy ";
    str += QString::number(energy->setEnergy());

    painter->drawText(QPointF(x+200,120+(y+h)/2),str);

    //тут еще нужно эффекты закинуть


    qDebug() << "player in scene";
    Person::paint(painter,option,widget);
}

void Player::getCoordinate(int X, int Y, int W, int H)
{
    this->x=X;
    this->y=Y;
    this->w=W;
    this->h=H;
}

void Player::takeAttack(Card *c)
{


    switch (c->setType()) {
    case defaulTA:
    {
        if(this->defence->setDef()>=0){
            this->defence->takeDamage(c->setDamage());
            if(this->defence->setDef()<=0)
            {
                this->hp->addHP(this->defence->setDef());
                this->defence->doNull();
            }
        }
        else
            this->hp->takeDamage(c->setDamage());
        qDebug() << "player damaged";
        break;
    }
    case effectTA:{

        break;
    }
    break;
    }
    Died();
    this->energy->doNull();
    this->energy->upEnergy(3);
    this->update();
    emit updateView();
}

void Player::takeAttackCard(Card *c) //тут все карты можно юзать
{
    tempAttack = c;
    qDebug() << c->setEnergy()->setEnergy() << " in takeCardAttack in PLAYER";
    if(c->setEnergy()->setEnergy()>=0){
    switch (c->setType())
    {
    case AttackT:{
        //damage->upDamage(c->setDamage());

        break;
    }
    case DefenceT:{
        this->defence->addDef(c->setDefence());
        break;
    }
    case HealtPointT:{
        this->hp->addHP(c->setHp());
        break;
    }
    case EnergyT:{
        this->energy->upEnergy(c->setEnergy());
        break;
    }
    case EffectT:{
        this->hp->addHP(1);

        break;
    }
    case CombinationT:{
        //damage->upDamage(c->setDamage());
        this->hp->addHP(c->setHp());
        this->defence->addDef(c->setDefence());
        this->energy->upEnergy(c->setEnergy());
        break;
    }
    }
    }

    emit attack(c);
    this->update();
    emit updateView();

}

void Player::updateViewSlot()
{
    this->update();
    emit updateView();
}



