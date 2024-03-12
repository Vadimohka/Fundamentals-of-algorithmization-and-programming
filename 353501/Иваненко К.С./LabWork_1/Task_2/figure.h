#pragma once

#ifndef FIGURE_H
#define FIGURE_H
 
#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
 
class Figure : public QObject, public QGraphicsItem
{
    Q_OBJECT
    // Свойство стартовой точки, относительно которой отрисовываем фигуру
    Q_PROPERTY(QPointF startPoint
               READ startPoint WRITE setStartPoint
               NOTIFY pointChanged)
    // Свойство конечной точки, до куда отрисовываем фигуру
    Q_PROPERTY(QPointF endPoint
               READ endPoint WRITE setEndPoint
               NOTIFY pointChanged)
public:
    explicit Figure(QPointF point, QObject *parent = 0);
    ~Figure();
 
    QPointF startPoint() const; // Стартовая точка
    QPointF endPoint() const;   // Конечная точка
 
    void setStartPoint(const QPointF point);    // Установка стартовой точки
    void setEndPoint(const QPointF point);      // Установка конечной точки

    void setNumber(int value);
    void setRotation(int value);
    void setRotationX(int value);
    void setRotationY(int value);
    int returnArea();
    int N;
    int rotation;
    int rotationX;
    int rotationY;
    int area;
    QPointF center;

signals:
    void pointChanged();    // Сигнал об изменении точки
 
private:
    QPointF m_startPoint;   // Стартовая точка
    QPointF m_endPoint;     // Конечная точка
 
    QRectF boundingRect() const;    // Область, в которой содержится фигура
 
public slots:
    void updateRomb();     // Слот обновления области, в которой содержится фигура
};
 
#endif // FIGURE_H