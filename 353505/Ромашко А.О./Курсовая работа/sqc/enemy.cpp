#include "enemy.h"
#include "montecarlo.h"

Enemy::Enemy(int hpp,
             int dama,
             int defe,
             int t) {

    hp = new Health();
    picture = new QPixmap() ;
    image = new QImage ();
    damage = new Damage ();
    defence = new Defence ();
    energy =  new Energy ();

    hp->addHP(hpp);
    damage->upDamage(dama);
    defence->addDef(defe);
    type = t;

    qDebug() << "enemy created";
}

QRectF Enemy::boundingRect() const
{
    return QRectF(x,y,w,h);
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->drawRect(x,y,w,h);
    QString str = "HP ";
    str+=QString::number(hp->setHP());
    painter->setPen(Qt::red);
    painter->drawText(QPointF(x-100,80+(y+h)/2),str);
    painter->drawPixmap(x-200,y,w+400,h,*picture);
    str = "Defence ";
    painter->setPen(Qt::blue);
    str += QString::number(defence->setDef());
    painter->drawText(QPointF(x-100,100+(y+h)/2),str);

}

void Enemy::getCoordinate(int x, int y, int w, int h)
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
}

Enemy::~Enemy()
{

}

void Enemy::takeAttack(Card *c)
{
    qDebug() << "enemy take damage";

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

        break;
    }
    case effectTA:{

        break;
    }

    }
    Died();
    //Attack();
    this->update();
    emit updateView();
}
void Enemy::Died()
{
    if(hp->setHP()<0){
        emit Win();
        this->~Enemy();
    }

}

void Enemy::Attack()
{
    int num = MonteCarlo::monteCarlo(0,1);
    Damage * d=  new Damage();
    d->upDamage(damage->damage());
    Card* card= new Card(new QImage(),d,new Defence(), new Health(), new Energy());

    switch (num) {
    case defaulTA:
    {
        this->hp->addHP(1);
        break;
    }
    case effectTA:{
        this->defence->addDef(this->type*5);
        if(this->type==0)
            this->defence->addDef(40);
        break;
    }
    }
    emit attack(card);
    this->update();
    emit updateView();
}
