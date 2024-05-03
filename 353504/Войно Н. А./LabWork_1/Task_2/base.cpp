#include "base.h"

base::base() {}


void base::centerMasse(QGraphicsScene *scene, int &x, int &y)
{
    bool ok;
    x = QInputDialog::getInt(this, tr("Введите координаты"), tr("X:"), 100, 0, 10000, 1, &ok);
    y = QInputDialog::getInt(this, tr("Введите координаты"), tr("Y:"), 100, 0, 10000, 1, &ok);

    QList<QGraphicsItem*> items = scene->items();
    for(QGraphicsItem* item : items) {
        item->setPos(x, y);
    }
}
void base::up(QGraphicsScene *scene, int &x, int &y)
{
    QList<QGraphicsItem*> items = scene->items();
    for(QGraphicsItem* item : items) {
        item->setPos(item->pos().x(), item->pos().y() - 3);
        y -= 3;
    }

}

void base::down(QGraphicsScene *scene, int &x, int &y)
{
    QList<QGraphicsItem*> items = scene->items();
    for(QGraphicsItem* item : items) {
        item->setPos(item->pos().x(), item->pos().y() + 3);
        y += 3;
    }

}

void base::left(QGraphicsScene *scene, int &x, int &y)
{
    QList<QGraphicsItem*> items = scene->items();

    for(QGraphicsItem* item : items) {
        item->setPos(item->pos().x() - 3, item->pos().y());
        x -= 3;
    }
}

void base::right(QGraphicsScene *scene, int &x, int &y)
{
    QList<QGraphicsItem*> items = scene->items();
    for(QGraphicsItem* item : items) {
        item->setPos(item->pos().x() + 3, item->pos().y());
        x += 3;
    }
}

void base::rotateLeft(QGraphicsScene *scene, int x, int y, int a)
{
    if(a == 0)
    {
        QList<QGraphicsItem*> items = scene->items();
        for(QGraphicsItem* item : items) {
            item->setTransformOriginPoint(item->boundingRect().center());
            item->setRotation(item->rotation()-3);
        }
    }
    else if(a == 1)
    {
        QList<QGraphicsItem*> items = scene->items();
        for(QGraphicsItem* item : items) {
            item->setTransformOriginPoint(x, y);
            item->setRotation(item->rotation()-3);
        }
    }

}

void base::rotateRight(QGraphicsScene *scene, int x, int y, int a)
{
    QList<QGraphicsItem*> items = scene->items();
    for(QGraphicsItem* item : items) {
        item->setTransformOriginPoint(item->boundingRect().center());
        item->setRotation(item->rotation()+3);
    }
}

void base::moveToObject(QGraphicsView *view, int x, int y)
{
    view->centerOn(x, y);

}


