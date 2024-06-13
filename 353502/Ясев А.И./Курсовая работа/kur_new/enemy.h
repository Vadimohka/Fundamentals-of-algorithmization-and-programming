#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QWidget>
#include <QQueue>
#include "tank.h"
class Enemy : public Tank
{
    Q_OBJECT
public:
    Enemy(qint8 x, qint8 y,QVector<QVector<bool>>* field, QGraphicsObject *parent = 0);
    ~Enemy();
protected:
    void takeDamage(qint8 damage) override;
    void move(qint64 stepSize) override;
    QTimer *tickTimer;
public slots:
    void onWallDestroy(QVector<QVector<bool>>* field);
    void onPlayerCellUpdate(Square::Cell cell);
private slots:
    void tick();
private:
     qint64 stepSize = 2;
    Square::Cell playerCell;
    QVector<QVector<bool>>* field;
    //bool isValidSquare(const QVector<QVector<bool>>& field, Square::Cell cell);
    bool isValidSquare(const QVector<QVector<bool>>& field, Square::Cell cell, QList<Enemy*> enemies = QList<Enemy*>());
    //Square::Direction findShortestPath(const QVector<QVector<bool>>& field, Square::Cell start, Square::Cell end);
    Square::Direction findShortestPath(const QVector<QVector<bool>>& field, Square::Cell start, Square::Cell end, QList<Enemy*> enemies = QList<Enemy*>());
    Square::Direction turnTo;
signals:
    void enemyDeathSignal();
};

#endif // ENEMY_H
