#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QWheelEvent>
#include <QKeyEvent>
#include "figure.h"

class CustomScene : public QGraphicsScene
{
    Q_OBJECT
    // Свойство текущего типа используемой фигуры
    Q_PROPERTY(int getTypeFigure
                   READ getTypeFigure WRITE setTypeFigure
                       NOTIFY typeFigureChanged)

public:
    CustomScene(QObject *parent = 0);
    int getTypeFigure() const;
    void setTypeFigure(const int type);

    qreal getYCenter() const;
    qreal getXCenter() const;
    qreal getSFigure() const;
    qreal getPFigure() const;

    // Перечисление типов используемых фигур
    enum FigureTypes {
        RectangleType,
        RombType,
        Triangle2Type,
        EllipseType,
        CircleType,
        SquareType,
        HexagonType,
        Triangle90Type,
        Star5Type,
        Star6Type,
        Star8Type,
        MoveType,
        DeleteType,
        BroomType,
        RestartType,
        ScaleType,
        RotationType,
        LineType
    };

signals:
    void typeFigureChanged();

private:
    Figure *tempFigure;
    int typeFigure;
    QList<QGraphicsItem *> foundItems;
    QPointF oldPos;
    bool isRotate;
    bool founded;
    qreal rotate;
    qreal scroll;
    QTimer* rotateTimerPlus;
    QTimer* rotateTimerMinys;
    qreal yCenter = 0, xCenter = 0, pFigure = 0, sFigure = 0;

private:
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void wheelEvent(QGraphicsSceneWheelEvent* event) override;

private slots:
    void rotateEventPlus();
    void rotateEventMinys();

};

#endif // CUSTOMSCENE_H
