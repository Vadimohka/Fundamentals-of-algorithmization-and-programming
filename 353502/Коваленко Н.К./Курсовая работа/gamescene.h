#ifndef GAMESCENE_H
#define GAMESCENE_H

#pragma once

#include <QGraphicsScene>
#include <QPixmap>
#include "game.h"
#include "level.h"

class QTimer;
class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(int i, QObject *parent = nullptr);
    int numberOfBlocks;

    enum class Diff {
        Easy, Middle, High
    };
    Diff m_diff;


signals:
private slots:
    void update();

private:
    void paddleBot();
    void loadPixmap();
    void loadLevel(int i);
    void clampPaddle();
    void stuckBall();
    void checkVictory();
    void drawScore();
    void reset(int i);
    void resetWin(int i);
    void renderScene();

    QPixmap m_paddlePixmap;
    QPixmap m_blocksPixmap[5];
    QPixmap m_bgPixmap;
    QPixmap m_ballPixmap;
    QPixmap m_game_over_bgPixmap;
    QPixmap m_pause_bgPixmap;
    QPixmap m_victoryPixmap;
    QPixmap m_allNumbersPixmap;
    QPixmap m_MenuPixmap;

    Game m_game;
    Level m_level;
    QTimer* m_timer;

    int m_paddleXpos;
    int m_paddleYpos;
    int m_ballXpos;
    int m_ballYpos;

    double bot_paddleXpos;
    double bot_paddleYpos;

    bool m_moveRight, m_moveLeft;
    QVector<QGraphicsPixmapItem*> m_blockItems;
    // QGraphicsScene interface
protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;
};

#endif // GAMESCENE_H
