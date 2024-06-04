#ifndef GAMEPOINT_H
#define GAMEPOINT_H

#include <QGraphicsEllipseItem>
#include <QPainter>
#include <QBrush>
#include <QObject>
#include <QGraphicsItem>
#include <QPolygonF>
#include <QList>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsObject>

#include "gamescene.h"
class GamePoint : public QGraphicsObject
{
                                            Q_OBJECT
public:
    explicit GamePoint(int X,int Y, int Size);
    ~GamePoint();

    void getDifficulty(int d){this->difficulty = d;}
    void getType(int t) {this->type=t;}
    int setType(){return this->type;}
    int setDifficulty(){return this->difficulty;}
    void doActiv(){activity = 1; this->setEnabled(activity); borderColor = Qt::magenta;}
    void doUnActiv(){activity = 0; this->setEnabled(activity);if(flag){borderColor = Qt::red;}else{borderColor = Qt::blue;}}
    GameScene *setGameScene(){return this->gameScene;}
    void getGameScene(GameScene *a){this->gameScene=a;}
public slots:
    void changeBorderColor(Qt::GlobalColor color);
signals:
    void clickSignal(GamePoint*);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    QRectF boundingRect() const;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    Qt::GlobalColor borderColor;
    GameScene *gameScene;
    int x, y, size, difficulty,type;
    bool activity,flag=1;

};

#endif // GAMEPOINT_H
