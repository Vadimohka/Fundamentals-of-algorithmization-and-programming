#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneWheelEvent>
#include <QList>
#include <QPolygon>
#include <ellips.h>
#include <rectangle.h>
#include <triangle.h>
#include <romb.h>
#include <hexagon.h>
#include <righttriangle.h>
#include <star5.h>
#include <star6.h>
#include <star8.h>

class Scene : public QGraphicsScene
{
public:
    Scene(QObject *parent);
    QPointF getCenter() const;
    double getSquare() const;
    double getPerim() const;
    void setTypeFigure(int);
    void setTypeAct(int);
    int getTypeFigure();
    int getTypeAct();
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;
private:
    bool deleteFlag = false;
    shape *currItem = nullptr;
    //void wheelEvent(QGraphicsSceneWheelEvent *event);
    QList<QGraphicsItem *> selectedItem;
    int typeFigure = 0, typeAct = 0;
    double square = 0, perim = 0;
    //QPointF center = QPointF(0,0);
};

#endif // SCENE_H
