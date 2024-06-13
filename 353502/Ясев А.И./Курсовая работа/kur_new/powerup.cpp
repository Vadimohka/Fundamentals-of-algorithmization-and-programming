#include "powerup.h"

#include <QDateTime>
#include <QRandomGenerator64>

PowerUp::PowerUp(qint8 x, qint8 y, QGraphicsObject *parent) : Square(x, y, parent)
{
    QRandomGenerator64 generator(QDateTime::currentDateTime().toMSecsSinceEpoch());
    qint64 generatedNum = generator.bounded(0,100);
    if(generatedNum < 60){
        type = HEAL;
        pixmap = QPixmap(QDir::current().filePath("resources/heal.png"));
    }
    else if(generatedNum < 90){
        type = GHOST;
        pixmap = QPixmap(QDir::current().filePath("resources/ghost.png"));
    }
    else{
        type = DOUBLEDAMAGE;
        pixmap = QPixmap(QDir::current().filePath("resources/doubledamage.png"));

    }
}

PowerUp::~PowerUp(){}

PowerUp::Type PowerUp::getType()
{
    return this->type;
}
