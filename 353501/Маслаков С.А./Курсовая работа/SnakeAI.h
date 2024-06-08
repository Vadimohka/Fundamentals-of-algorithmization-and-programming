
#ifndef SNAKE_GAME_SNAKEAI_H
#define SNAKE_GAME_SNAKEAI_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "food.h"
#include "Pepper.h"
#include "SnakePart.h"
#include <QGraphicsTextItem>
class SnakeAI : public QObject{
    Q_OBJECT
    QString name;
    int lenght;
    int speed;
    bool PepperEffectActive;
    QVector<SnakePart*> body;
    QString direction;
    QPointF startpos;
    bool alive;
    QTimer* SnakeAIMoveTimer;
    QTimer* PepperAIActiveTimer;
    void CheckCollision();
    int color;
    QGraphicsEllipseItem* boundary;
    int pepperAITimerRemainingTime;
    QGraphicsTextItem* name_label;
    QString getSafeDirection();
    void calculateClosestWay();
    bool collidesWithStones(int x, int y);
    bool isMoveSafe(QPointF headpos, QString dir);
signals:
    void addNewSnakeAiSignal();
private slots:
    void move();
    void PepperDisactive();
public:
    QString getName();
    int getLength();
    void pause_snakeAI();
    void continue_snakeAI();
    QPointF getAIHeadPos();
    void setDirection(QString);
    QString getDirection();
    void setSpeed(int);
    int getSpeed();
    SnakeAI(QGraphicsScene*,float,float,QString);
    void destroySnake();
};


#endif //SNAKE_GAME_SNAKEAI_H
