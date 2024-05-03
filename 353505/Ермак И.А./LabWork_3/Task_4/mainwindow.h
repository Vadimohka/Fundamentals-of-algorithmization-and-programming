#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hanoitower.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QStack>
#include "move.h"
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void updateTable();
    void updateGraphics();

    void on_pushButton_clicked();

   // void on_backButton_clicked();

  //  void on_forwardButton_clicked();

private:
    Ui::MainWindow *ui;
    HanoiTower solver;
    int amOfMoves = 0;
    QGraphicsScene* scene;

    QStack<QGraphicsRectItem*> sterzhni[3];

    QGraphicsRectItem* ster1;
    QGraphicsRectItem* ster2;
    QGraphicsRectItem* ster3;

    Move move;

    int i = 0;

    QTimer* animationTimer;
    QTimer* forwardTimer;
    QTimer* backTimer;

    QGraphicsTextItem *aItem;
    QGraphicsTextItem *bItem;
    QGraphicsTextItem *cItem;
};

#endif // MAINWINDOW_H
