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

    enum FigureTypes {
        SquareType,
        RombType,
        TriangleType,
        CircleType,
        RectType,
        EllipseType,
        ZvezdaType,
        HexType
    };

signals:
    void typeFigureChanged();               // Сигнал об изменении типа текущей фигуры
    void coordinatesChanged(int x, int y);

private:
    // Объект для временного хранения рисуемой фигуры
    FigureDraw *tempFigure;
    int m_typeFigure;   // текущий тип фигуры

private:
    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

};

#endif // PAINTSCENE_H

