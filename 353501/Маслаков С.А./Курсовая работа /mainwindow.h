#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene>
#include <QMainWindow>
#include <QPixmap>
#include <QGraphicsItem>
#include <QResizeEvent>
#include "snake.h"
#include <QKeyEvent>
#include <QTimer>
#include "food.h"
#include "Pepper.h"
#include "ItemsContainer.h"
#include "SnakeAI.h"
#include "menuwindow.h"
#include "database.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int col,QString log,QWidget *parent = nullptr);
    ~MainWindow();
    Snake* snake;
private:
    Database database;
    int snakeColorIndex;
    QString snakeName;
    struct SnakeInfo{
        QString name;
        int length;
    };
    QVector<SnakeInfo> info;
    void pauseGame();
    void continueGame();
    void keyPressEvent(QKeyEvent* event);
    void startGame();
    SnakeAI* snakeAI;
    QGraphicsRectItem * back;
    Ui::MainWindow *ui;
    MenuWindow* menuwindow;
    QGraphicsScene* scene;
    QGraphicsTextItem* scoreBoard;
    void calculateScores();
    int numberOfAiSnakes;
    void spawnStones();
    void spawnFood();
    void spawnPeppers();
private slots:
    void quitToMenu();
    void addNewSnakeAI();
    void gameOver();
    void moveScreen();
};
#endif // MAINWINDOW_H
