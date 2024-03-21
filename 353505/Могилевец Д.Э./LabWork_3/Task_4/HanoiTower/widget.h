#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "hanoitowersolver.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QStack>
#include "mover.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void updateTable();
    void updateGraphics();

    void on_pushButton_clicked();

    void on_backButton_clicked();

    void on_forwardButton_clicked();

private:
    Ui::Widget *ui;
    HanoiTowerSolver solver;
    int amOfMoves = 0;
    QGraphicsScene* scene;

    QStack<QGraphicsRectItem*> sterzhni[3];

    QGraphicsRectItem* ster1;
    QGraphicsRectItem* ster2;
    QGraphicsRectItem* ster3;

    Mover mover;

    int i = 0;

    QTimer* animationTimer;
    QTimer* forwardTimer;
    QTimer* backTimer;

    QGraphicsTextItem *aItem;
    QGraphicsTextItem *bItem;
    QGraphicsTextItem *cItem;
};
#endif // WIDGET_H
