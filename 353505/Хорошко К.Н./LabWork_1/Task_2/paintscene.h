#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneWheelEvent>
#include "figure.h"
#include "circle.h"
#include "elips.h"
#include "hexagon.h"
#include "rectangle.h"
#include "romb.h"
#include "square.h"
#include "star_eight.h"
#include "star_five.h"
#include "star_six.h"
#include "triangle.h"
#include "draw.h"
#include <QCursor>
#include <QKeyEvent>


class PaintScene : public QGraphicsScene
{

    Q_OBJECT

public:
    explicit PaintScene(QObject *parent = 0);

    int typeFigure() const;
    void setTypeFigure(const int type);

    enum FigureTypes {
        CircleType,
        ElipsType,
        HexagonType,
        RectangleType,
        RombType,
        SquareType,
        Star_EightType,
        Star_FiveType,
        Star_SixType,
        TriangleType,
        DrawType
    };

    QString s;
    QString p;
    QString x;
    QString y;
    QString xy;
    double X;
    double Y;
    double S;
    double P;
    void updateLabel();

    QPointF lastPos;
    bool pressed = false;
    Figure *at = nullptr;
     Figure *it = nullptr;


    bool rot = false;
    bool size = true;
    bool del = false;

    int maxW = 0;
    int maxH = 0;


signals:
    void typeFigureChanged();

private:
    Figure *tempFigure;
    int m_typeFigure;

private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void wheelEvent(QGraphicsSceneWheelEvent *event);
    void keyPressEvent(QKeyEvent *event);

    QVector<QPointF> *points_draw;
    QPointF previousPoint;
};

#endif // PAINTSCENE_H
