#ifndef MWSCENE_H
#define MWSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneEvent>
#include <QWheelEvent>
#include <QList>

#include "figure.h"
#include "rectangle.h"
#include "romb.h"
#include "circle.h"
#include "triangle.h"
#include "square.h"
#include "sixstar.h"
#include "star.h"
#include "hexagon.h"

class MWscene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit MWscene(QObject *parent = nullptr) : QGraphicsScene(parent) {}
    ~MWscene() override = default;

private:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;

    Figure *spawnFigure;
    Figure *item;
    QList<QGraphicsItem *> list;

    bool Blank = false;
    bool Rect = false;
    bool Rombius = false;
    bool Ellipsoid = false;
    bool Triangl = false;
    bool Sqre = false;
    bool SixStr = false;
    bool Staar = false;
    bool Hex = false;

    bool DragButtToggled = false;
    bool RotateButtonToggled = false;
    bool ScaleButtChecked = false;
    bool DeleteButtChecked = false;

    double cx, cy;
    int corners;

public slots:
    void blank_checked(bool);
    void buttRect_checked(bool);
    void buttRomb_checked(bool);
    void buttCircle_checked(bool);
    void buttTriangle_checked(bool);
    void buttSquare_checked(bool);
    void buttSixStar_checked(bool);
    void buttStar_checked(bool);
    void buttHexagon_checked(bool);

    void buttDrag_checked(bool);
    void buttRotate_checked(bool);
    void buttScale_checked(bool);
    void buttDelete_checked(bool);

    void getScale(double);
    void getRotation(double);
    void getCorners(double);

signals:
    void sendPerimeter(QString);
    void sendArea(QString);
};

#endif // MWSCENE_H
