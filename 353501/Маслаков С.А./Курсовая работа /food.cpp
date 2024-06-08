#include "food.h"

Food::Food(): QGraphicsPixmapItem()
{
    QString imagePath = ":/images/f" + QString::number((rand() % 6) + 1) + ".png";
    setPixmap(QPixmap(imagePath));
    setPos(rand() % 4000, rand() % 4000);

}
Food::Food(long double x,long double y)
{
    QString imagePath = ":/images/f" + QString::number((rand() % 6) + 1) + ".png";
    setPixmap(QPixmap(imagePath));
    setPos(x, y);
}