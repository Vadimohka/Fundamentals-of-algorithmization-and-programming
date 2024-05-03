#pragma once

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <qgraphicsitem.h>
#include "figure.h"


class PaintScene : public QGraphicsScene
{
    Q_OBJECT
    // Свойство текущего типа используемой фигуры
    Q_PROPERTY(int typeFigure
               READ typeFigure WRITE setTypeFigure
               NOTIFY typeFigureChanged)

public:
    explicit PaintScene(QObject *parent = 0);
    ~PaintScene();

    int typeFigure() const;                 // Возвращение текщего типа
    void setTypeFigure(const int type);     // Установка текущего типа
    void setRotation(const int angle);
    void setScale(qreal mashtab);
    void setX(int x);
    void setY(int y);
    QString ChangeLabel();

    // Перечисление типов используемых фигур
    enum FigureTypes {
        RectangleType,
        RombType,
        TriangleType,
        CircleType,
        SquareType,
        Star5Type,
        Star6Type,
        Star8Type,
        HexagonType,
        otherfigureType,
        BrushType
    };

signals:
    void typeFigureChanged();               // Сигнал об изменении типа текущей фигуры

private:
    /* Объект для временного хранения рисуемой фигуры
     * Является объектом базового класса для всех трёх типов фигур в примере
     * */
    Figure *tempFigure;
    int posX;
    int posY;
    int m_typeFigure;   // текущий тип фигуры

private:
    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

};