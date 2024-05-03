#ifndef PAINTSCENE_H
#define PAINTSCENE_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "figure.h"
#include "romb.h"
#include "square.h"
#include "star.h"
#include "five_points_star.h"
#include "six_points_star.h"
#include "eight_points_star.h"
#include "pen.h"
#include "hexagon.h"
#include <vector>


class PaintScene : public QGraphicsScene
{
    Q_OBJECT

public:

    explicit PaintScene(QObject *parent = nullptr);
    enum FigureTypes {
        SquareTypeScene,
        RombTypeScene,
        TriangleTypeScene,
        RectangleTypeScene,
        CircleTypeScene,
        FivePointerStarTypeScene,
        SixPointerStarTypeScene,
        EightPointerStarTypeScene,
        ChangePositionTypeScene,
        HexagonTypeScene,
        ActionFigureChangePositionScene,
    };
    void setTypeFigure(int type);
    void actionRotateFigureRight();
    void actionRotateFigureLeft();
    void actionFigureSizeDecrease();
    void actionFigureSizeIncrease();
    void clearScene();
    void updateNowFigureSelection();
    void changeToNextPointerSetFigure();
    void changeToPreviosPointerSetFigure();
    void deleteFigure();
    int getTypeFigure();
    int getPointerSetFigure();
    int getSizeSetFigures();
    Figure* getNowFigureSelection();
private:
    std::vector<Figure*> setFigures = {};
    Figure* nowFigureSelection;
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    int typeFigure;
    int pointerSetFigure;
};
#endif // PAINTSCENE_H
