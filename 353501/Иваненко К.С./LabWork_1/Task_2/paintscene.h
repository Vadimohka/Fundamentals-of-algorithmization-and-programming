#pragma once

#ifndef PAINTSCENE_H
#define PAINTSCENE_H
 
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
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
 
    int typeFigure() const;                 // Возвращение текущего типа
    void setTypeFigure(const int type);     // Установка текущего типа
    void setMouseMode(const int type);     // Установка текущего типа

    void setRotationX(int value);
    void setRotationY(int value);
    void setRotation(int value);
    void setNumber(int value);
    int N;

    int returnArea();

    // Перечисление типов используемых фигур
    enum FigureTypes {
        SquareType,
        RombType,
        TriangleType,
        EllipseType,
        StarType,
        TEST
    };

    // Перечисление режимов мыши
    enum MouseMode {
        drawing,
        editing
    };
 
signals:
    void typeFigureChanged();               // Сигнал об изменении типа текущей фигуры
 
private:
    /* Объект для временного хранения рисуемой фигуры
     * Является объектом базового класса
     * */
    Figure *tempFigure;
    int m_typeFigure;   // текущий тип фигуры
    int m_mousemode;   // текущий режим


    QGraphicsPolygonItem* selectedPolygon = nullptr;

 
private:
    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    int rotationX;
    int rotationY;
    int rotation;
};
 
#endif // PAINTSCENE_H