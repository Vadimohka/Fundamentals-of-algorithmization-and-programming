#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "figure.h"

class PaintScene : public QGraphicsScene
{
    Q_OBJECT
    Q_PROPERTY(int typeFigure
                   READ typeFigure WRITE setTypeFigure
                       NOTIFY typeFigureChanged)

public:
    explicit PaintScene(QObject *parent = nullptr);
    ~PaintScene();

    int typeFigure() const;
    int typeAction() const;
    int buffTypeFigure() const;

    void setTypeFigure(const int type);
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

    QString figureInformation() const;

    enum FigureTypes {
        NoneType,
        ParallelogramType,
        EllipseType,
        RectangleType,
        RombType,
        TriangleType,
        RegularPolygonType,
        StarType
    };

    enum FigureActions {
        NoneAction,
        ChangeSizeAction,
        MoveAction,
        RotateAction,
        ScaleAction
    };

    Figure *tempFigure;

signals:
    void typeFigureChanged();

private:
    int m_typeFigure;
    int m_typeAction;
    int m_buffTypeFigure;

private:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PAINTSCENE_H
