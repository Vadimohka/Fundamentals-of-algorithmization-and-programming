#ifndef PAINTSCENE_H
#define PAINTSCENE_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QCursor>
#include <QGraphicsView>
#include <QPoint>
#include <QTime>
#include <QtCore>

#include "figure.h"


class PaintScene : public QGraphicsScene
{
    Q_OBJECT

    Q_PROPERTY(int typeFigure READ typeFigure WRITE setTypeFigure NOTIFY typeFigureChanged FINAL)

public:
    PaintScene(QObject *parent = 0);
    ~PaintScene();

    int typeFigure() const;
    void setTypeFigure(const int type);

    enum FigureTypes {
        RectangleType,
        RombType,
        TriangleType,
        EllipseType,
        SquareType,
        CircleType,
        HexagonType,
        Star_5Type,
        Star_6Type,
        Star_8Type,
        DeleteType,
        WarpType
    };
    Figure* currentFigure() const;

    QPointF getStartPoint();
    QPointF getEndPoint();
    void rotationFigure(QGraphicsSceneMouseEvent *event);
    void moveFigure(QGraphicsSceneMouseEvent *event);
    void setStartPoint(QPointF startPoint);
    void setEndPoint(QPointF endPoint);
    signals:
    void typeFigureChanged();
    void areaChanged(double area);
    void perimeterChanged(double perimeter);


private slots:
    void rotateLeft();
    void rotateRight();

private:
    Figure *tempFigure = nullptr;
    int m_typeFigure;
    bool deletButtonActive;
    QPointF startp, endp;
    QTimer *rotationTimer;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void wheelEvent(QGraphicsSceneWheelEvent *event);
    void keyPressEvent(QKeyEvent *shiftKey);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PAINTSCENE_H
