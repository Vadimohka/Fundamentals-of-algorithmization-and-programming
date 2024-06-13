    #ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>

#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QRandomGenerator>
#include <QKeyEvent>

#include <fish.h>
#include <fishes.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
protected:
    virtual void keyPressEvent(QKeyEvent *ke)override;
    virtual void keyReleaseEvent(QKeyEvent *ke)override;
private slots:
    //QPainter*painter;
    //QStyleOptionGraphicsItem*option;
    void on_pushButton_clicked();
     void fishes(Fishes *it);
     bool eat(Fishes *it);

     //void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
     void on_exitButton_clicked();
     void move_left();

     void move_right();
 private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    int N=5, w, h, back, points=0;
    bool Left=false,Right=false;
    bool start=false;
    QTimer *timer;
    Fishes *it = new Fishes();
    Fish *item = new Fish();
};

#endif // WIDGET_H
