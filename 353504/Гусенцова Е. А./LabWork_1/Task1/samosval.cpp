#include "samosval.h"

void Samosval::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    drawSam(&painter);
}

void Samosval::drawSam(QPainter *painter)
{
    drawRec(painter);

    QPen pen;
    pen.setColor(Qt::black);
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(5);

    QBrush brushBlue;
    brushBlue.setColor(Qt::blue);
    brushBlue.setStyle(Qt::SolidPattern);

    QBrush brushBlack;
    brushBlack.setColor(Qt::black);
    brushBlack.setStyle(Qt::SolidPattern);

    QBrush brushGray;
    brushGray.setColor(Qt::lightGray);
    brushGray.setStyle(Qt::SolidPattern);

    QBrush brushYellow;
    brushYellow.setColor(Qt::yellow);
    brushYellow.setStyle(Qt::SolidPattern);

    QBrush brushWhite;
    brushWhite.setColor(Qt::white);
    brushWhite.setStyle(Qt::SolidPattern);

    QPolygon korpus;
    korpus <<QPoint(450,370)<<QPoint(300,370)<<QPoint(240,430)<<QPoint(210,550)<<QPoint(150,610)<<QPoint(150,755)<<QPoint(1020,755)<<QPoint(1020,640)<<QPoint(450,640);

    painter->setPen(pen);
    painter->setBrush(brushBlue);
    painter->drawPolygon(korpus);

    QPolygon window;
    window <<QPoint(330,430)<<QPoint(240,430)<<QPoint(210,550)<<QPoint(330,550);

    painter->setPen(pen);
    painter->setBrush(brushWhite);
    painter->drawPolygon(window);

    painter->setPen(pen);
    painter->setBrush(brushYellow);
    painter->drawEllipse(175,640,30,60);

    painter->setPen(pen);
    painter->setBrush(brushGray);
    painter->drawEllipse(300,700,110,110);
    painter->drawEllipse(690,700,110,110);
    painter->drawEllipse(870,700,110,110);

    painter->setPen(pen);
    painter->setBrush(brushBlack);
    painter->drawEllipse(332,732,46,46);
    painter->drawEllipse(722,732,46,46);
    painter->drawEllipse(902,732,46,46);

    painter->end();

}
