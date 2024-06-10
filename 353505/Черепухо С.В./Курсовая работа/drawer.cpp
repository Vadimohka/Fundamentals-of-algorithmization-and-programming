#include "drawer.h"

Drawer::Drawer()
{

}

Drawer::Drawer(QPainter *painter)
{
    tempWorkSpace = new QPixmap(906, 547);
    tempWorkSpace->fill(QColor(0, 0, 0, 0));
    workSpace = new QPixmap(906, 547);
    transBack = new QPixmap(911, 549);
    workSpace->fill(QColor(0, 0, 0, 0));
    painter->begin(transBack);
    for(int i = 0; i < 46; i++)
        for(int j = 0; j < 28; j++)
            if((i + j) % 2 == 0)
                painter->fillRect(i * 20 , j * 20, 20, 20, QColor(170, 170, 170));
            else
                painter->fillRect(i * 20 , j * 20, 20, 20, QColor(240, 240, 240));
    painter->end();
}

void Drawer::base(QPainter *painter)
{
    QPen pen;
    pen.setWidth(3);
    painter->setPen(pen);
    painter->drawPixmap(610, 101, *transBack);
    painter->drawRect(611, 101, 910, 549);
}

void Drawer::drawPen(QPoint current)
{
    QPainter workSpacePainter(workSpace);
    workSpacePainter.fillRect(current.x() - 610 - penWidth/2, current.y() - 101 - penWidth/2, penWidth, penWidth, color);
}

void Drawer::drawErase(QPoint current)
{
    QPainter workSpacePainter(workSpace);
    workSpacePainter.setCompositionMode(QPainter::CompositionMode_Source);
    workSpacePainter.fillRect(current.x() - 610 - penWidth/2, current.y() - 101 - penWidth/2, penWidth, penWidth, Qt::transparent);
}

void Drawer::drawRect(QPoint first, QPoint current)
{
    if(current != lastCurrent)
        tempWorkSpace->fill(QColor(0, 0, 0, 0));
    QPainter tempWorkSpacePainter(tempWorkSpace);
    thePen.setColor(color);
    thePen.setWidth(penWidth);
    tempWorkSpacePainter.setPen(thePen);
    tempWorkSpacePainter.drawRect(first.x() - 610, first.y() - 101, current.x() - first.x(), current.y() - first.y());
    lastCurrent = current;
}

void Drawer::drawEllipce(QPoint first, QPoint current)
{
    if(current != lastCurrent)
        tempWorkSpace->fill(QColor(0, 0, 0, 0));
    QPainter tempWorkSpacePainter(tempWorkSpace);
    thePen.setColor(color);
    thePen.setWidth(penWidth);
    tempWorkSpacePainter.setPen(thePen);
    tempWorkSpacePainter.drawEllipse(first.x() - 610, first.y() - 101, current.x() - first.x(), current.y() - first.y());
    lastCurrent = current;
}

void Drawer::drawLine(QPoint first, QPoint current)
{
    if(current != lastCurrent)
        tempWorkSpace->fill(QColor(0, 0, 0, 0));
    QPainter tempWorkSpacePainter(tempWorkSpace);
    thePen.setColor(color);
    thePen.setWidth(penWidth);
    tempWorkSpacePainter.setPen(thePen);
    tempWorkSpacePainter.drawLine(first.x() - 610, first.y() - 101, current.x() - 610, current.y() - 101);
    lastCurrent = current;
}

void Drawer::saveFigure()
{
    QPainter workSpacePainter(workSpace);
    workSpacePainter.drawPixmap(0, 0, *tempWorkSpace);
    tempWorkSpace->fill(QColor(0, 0, 0, 0));
}

void Drawer::clear()
{
    workSpace->fill(QColor(0, 0, 0, 0));
}

void Drawer::draw(QPainter *painter)
{
    painter->drawPixmap(613, 102, *workSpace);
    painter->drawPixmap(613, 102, *tempWorkSpace);
}

Sprite Drawer::saveNewSprite()
{
    Sprite sprite;
    QPixmap *pixmap;
    int сwidth = workSpace->width(), сheight = workSpace->height(), cx = 0, cy = 0;
    bool checker = false;

    for(int i = 0; i < workSpace->width(); i++)
    {
        for(int j = 0; j < workSpace->height(); j++)
            if(workSpace->toImage().pixelColor(i, j).alpha() != 0)
            {
                checker = true;
                cx = i;
                break;
            }
        if(checker)
            break;
    }

    if(checker == false)
    {
        sprite.name = "ERRORSPRITE";
        return sprite;
    }

    checker = false;

    for(int i = 0; i < workSpace->height(); i++)
    {
        for(int j = 0; j < workSpace->width(); j++)
            if(workSpace->toImage().pixelColor(j, i).alpha() != 0)
            {
                checker = true;
                cy = i;
                break;
            }
        if(checker)
            break;
    }

    checker = false;

    for(int i = workSpace->width() - 1; i >= 0; i--)
    {
        for(int j = workSpace->height() - 1; j >= 0 ; j--)
            if(workSpace->toImage().pixelColor(i, j).alpha() != 0)
            {
                checker = true;
                сwidth = abs(i - cx - 1);
                break;
            }
        if(checker)
            break;
    }

    checker = false;

    for(int i = workSpace->height() - 1; i >= 0; i--)
    {
        for(int j = workSpace->width() - 1; j >= 0 ; j--)
            if(workSpace->toImage().pixelColor(j, i).alpha() != 0)
            {
                checker = true;
                сheight = abs(i - cy - 1);
                break;
            }
        if(checker)
            break;
    }

    sprite.name = "(" + QString::number(cx) + ", " + QString::number(cy) + ", " + QString::number(сwidth) + ", " + QString::number(сheight);

    pixmap = new QPixmap(сwidth + 2, сheight + 2);
    pixmap->fill(QColor(0, 0, 0, 0));
    QPainter pixmapPainter(pixmap);
    pixmapPainter.drawPixmap(-cx, -cy, *workSpace);

    sprite.image = pixmap;
    sprite.w = sprite.image->width();
    sprite.h = sprite.image->height();

    return sprite;
}

