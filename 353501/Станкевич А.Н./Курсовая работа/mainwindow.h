#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Player.h"
#include <QWidget>
#include <QGraphicsScene>
#include <QApplication>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include <QMessageBox>


#include <Enemy.h>

#define GAME_STOPED 0
#define GAME_STARTED 1

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int minX;
    int minY;
    int maxX;
    int maxY;

private slots:
    void onTimerTimeout();
    void slotDeleteCoin(QGraphicsItem * item);
    void slotCreateCoin();
    void on_pushButton_clicked();
    void slotGameOver();
    void slotGameEnd();
    void slotPause();
    void slotLcdNumberChanged(int value);
    void generateRandomWalls(QGraphicsScene* scene, int minX, int minY, int maxX, int maxY);
    void on_pushButton_3_clicked();

public slots:


private:
    QTimer *timerCreateCoin;
    QList<QGraphicsItem *> coins;
    double count;
    Ui::MainWindow *ui;
        QGraphicsScene *scene;
        HEROE *player;
    QTimer *timer;
        Enemy *enemy;
    int gameState;
    int timeRemaining;

};
#endif // MAINWINDOW_H
