#include "card.h"
#include <QString>
Card::Card(QImage *i,
           Damage *dam,
           Defence *def,
           Health *h,
           Energy *e)
{
    damage = dam;
    image =i;
    defence = def;
    hp = h;
    energy = e;
    energyCost = new Energy();
   // p=new QPixmap("");
   // p1=new QPixmap("");
   // p2=new QPixmap("");
   // p3=new QPixmap("");
    //energyCost->upEnergy(0);
}

Card::~Card()
{
    operator delete(this);
}

Damage *Card::setDamage() {return damage;}

Defence *Card::setDefence(){return defence;}

Health *Card::setHp(){return hp;}

Energy *Card::setEnergy(){return energy;}

Energy *Card::setEnergyCost()
{
    return this->energyCost;
}

void Card::getDamage(Damage *damag) {this->damage= damag;}

void Card::getDefence(Defence *def){this->defence=def;}

void Card::getHp(Health *health){this->hp = health;}

void Card::getEnergy(Energy *en){ this->energy=en;}

void Card::getEnergyCost(Energy *en){this->energyCost = en;}

void Card::getEnergyCost(int en){this->energyCost->upEnergy(en);}

void Card::getImage(QImage *im){this->image=im;}

void Card::getCoordinate(int x, int y, int w, int h)
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
}

void Card::getType(int t){this->type=t;}

int Card::setType(){return this->type;}

void Card::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //image("qrc:/new/prefix1/cardAttack.jpeg");
    QRect rectangle(x,y,w,h);
    //painter->setPen(Qt::black);

    // qDebug() << damage->damage() << defence->setDef() << energy->setEnergy() << energyCost->setEnergy();


    switch(this->type){
    case AttackT:{
        QString a = "Атака ";
        QColor color(235, 10, 10);
        QBrush brush(color);

        painter->setBrush(brush);
        painter->drawRect(rectangle);

        a += QString::number(damage->damage());
        painter->drawText(QPointF(x + 20, -20 + y + h), a);
        break;
    }
    case DefenceT:{
        QString a = "Защита ";
        QColor color(10, 10, 235);
        QBrush brush(color);

        painter->setBrush(brush);
        painter->drawRect(rectangle);

        a += QString::number(defence->setDef());
        painter->drawText(QPointF(x + 20, -20 + y + h), a);
        break;
    }
    case HealtPointT:{
        QString a = "ХП ";
        QColor color(20, 155, 10);
        QBrush brush(color);

        painter->setBrush(brush);
        painter->drawRect(rectangle);

        a += QString::number(hp->setHP());
        painter->drawText(QPointF(x + 20, -20 + y + h), a);
        break;
    }
    case EnergyT:{
        QString a = "Энергия ";
        QColor color(235, 250, 10);
        QBrush brush(color);

        painter->setBrush(brush);
        painter->drawRect(rectangle);

        a += QString::number(energy->setEnergy());
        painter->drawText(QPointF(x + 20, -20 + y + h), a);
        break;
    }
    case CombinationT:{

        QColor color(155, 155, 155);
        QBrush brush(color);

        QString a;
        painter->setBrush(brush);
        painter->drawRect(rectangle);

         a = "Атака ";
        a += QString::number(damage->damage());
        painter->drawText(QPointF(x + 15, -80 + y + h), a);

         a = "Защита ";

        a += QString::number(defence->setDef());
        painter->drawText(QPointF(x + 15, -60 + y + h), a);

         a = "ХП ";
        a += QString::number(hp->setHP());
        painter->drawText(QPointF(x + 15, -40 + y + h), a);

         a = "Комбинация ";
        painter->drawText(QPointF(x + 15, -20 + y + h), a);

        break;
    }
    case EffectT:{

        QColor color(155, 155, 155);
        QBrush brush(color);

        QString a;
        painter->setBrush(brush);
        painter->drawRect(rectangle);

        a = "Атака ";
        a += QString::number(damage->damage());
        painter->drawText(QPointF(x + 15, -80 + y + h), a);

        a = "Защита ";

        a += QString::number(defence->setDef());
        painter->drawText(QPointF(x + 15, -60 + y + h), a);

        a = "ХП ";
        a += QString::number(hp->setHP());
        painter->drawText(QPointF(x + 15, -40 + y + h), a);

        a = "Комбинация ";
        painter->drawText(QPointF(x + 15, -20 + y + h), a);

        break;
        x=0;y=0;w=0;h=0;
    }
    }
    //painter->setBrush(Qt::lightGray);

    QString a = QString::number(energyCost->setEnergy());
    painter->drawEllipse(QPointF(-20+x+w,20+y),15,15);
    painter->drawText(QPointF(-25+x+w,25+y),a);
    //painter->drawText(QPointF(x+20,y+h/4),a);

   // qDebug() << "in func paint";
    //painter->drawImage(recrangle, image);
}

void Card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
   // qDebug() << this->PlayerEnergy->downEnergy(energyCost);
   // qDebug() << damage->damage() << defence->setDef() << energy->setEnergy() << energyCost->setEnergy();
    if(this->PlayerEnergy->setEnergy()>=energyCost->setEnergy())
    {

        this->PlayerEnergy->downEnergy(energyCost);
        qDebug() << this->PlayerEnergy->setEnergy();

        emit signalClickType(this);

        QGraphicsItem::mousePressEvent(event);
    }
    else
    {

        return;
    }
}

QRectF Card::boundingRect() const
{
    return QRectF(x,y,w,h);
}

void Card::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}
