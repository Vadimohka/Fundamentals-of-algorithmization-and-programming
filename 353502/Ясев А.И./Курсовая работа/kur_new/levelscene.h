#ifndef LEVELSCENE_H
#define LEVELSCENE_H

#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QDateTime>
#include <QSet>
#include "player.h"
#include "enemy.h"
#include "steelwall.h"
#include "brickwall.h"
#include "powerup.h"
class LevelScene : public QGraphicsScene
{
    Q_OBJECT
public:
    LevelScene(qint8 difficulty);
    ~LevelScene();
    Player *getPlayer();
private:
    Player *player;
    QTimer *powerUpTimer;
    QVector<QVector<bool>>* field;
    void randomGenerateField(QRandomGenerator64 generator);
    void randomGenerateEnemies(QRandomGenerator64 generator, qint8 difficulty, qint8 playerX, qint8 playerY);
    qint8 currentEnemiesCount = 0;
public slots:
    void onPowerUpTimeout();
    void onWallDestroy(Square::Cell cell);
    void onPlayerChangeCell(Square::Cell cell);
    void onEnemyDeathSlot();
signals:
    void updatePlayerPos(Square::Cell cell);
    void enemyDeathSignal();
    void nextRoundSignal();
};

#endif // LEVELSCENE_H
