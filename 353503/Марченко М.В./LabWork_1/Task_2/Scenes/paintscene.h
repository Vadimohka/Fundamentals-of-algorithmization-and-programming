#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include "Figures/figure.h"

class PaintScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit PaintScene(QObject *parent = 0);
    ~PaintScene();

    int typeFigure() const;                 // Возвращение текщего типа
    void setTypeFigure(const int type);     // Установка текущего типа
    Figure* getFigure() const;

    // Перечисление типов используемых фигур
    enum FigureTypes {
        SquareType,
        RombType,
        TriangleType,
        RectangleType,
        CircleType,
        Star5Type,
        Star6Type,
        Star8Type,
        HexagonType,
        ArrowType
    };


signals:
    void typeFigureChanged();               // Сигнал об изменении типа текущей фигуры
    void SetLabelS(qreal S);
    void SetLabelP(qreal P);

private:
    /* Объект для временного хранения рисуемой фигуры
     * Является объектом базового класса для всех трёх типов фигур в примере
     * */
    Figure *tempFigure = nullptr;
    int m_typeFigure;   // текущий тип фигуры
    QGraphicsItem* itemUnderMouse;

private:
    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    //Добавляем удаление через клавиатуру
    void keyPressEvent(QKeyEvent* event);
};

#endif // PAINTSCENE_H
