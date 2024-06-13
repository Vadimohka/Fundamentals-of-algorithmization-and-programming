#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "shape.h"

class MainScene : public QGraphicsScene
{
    Q_OBJECT

public:
    MainScene(QObject *parent = nullptr);
    ~MainScene();

    int typeShape() const;
    int typeAction() const;
    int buffTypeShape() const;

    void setTypeShape(const int type);
    void setTypeAction(const int type);

    void changeStartPointX(double x);
    void changeStartPointY(double y);
    void changeEndPointX(double x);
    void changeEndPointY(double y);
    void changeCenterX(double x);
    void changeCenterY(double y);
    void changeWidth(double x);
    void changeHeight(double y);

    void scaleIncrease();
    void scaleDecrease();
    void moveTop();
    void moveDown();
    void moveLeft();
    void moveRight();
    void rotateLeft();
    void rotateRight();

    QString ShapeInformation() const;

    enum ShapeTypes {
        NoneType,
        ParallelogramType,
        EllipseType,
        RectangleType,
        RombType,
        TriangleType,
        RegularPolygonType,
        StarType
    };

    enum ShapeActions {
        NoneAction,
        ChangeSizeAction,
        MoveAction,
        RotateAction,
        ScaleAction
    };

    Shape *tempShape;

signals:
    void typeShapeChanged();

private:
    int m_typeShape;
    int m_typeAction;
    int m_buffTypeShape;

private:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MAINSCENE_H
