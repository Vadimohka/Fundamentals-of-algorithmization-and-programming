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
    void setScale(double value);
    void setRotation(int value);
    void setRotationX(int value);
    void setRotationY(int value);
    void setOuterRadius(int value);
    void setInnerRadius(int value);
    void setSideA(int value);
    void setSideB(int value);
    void setAngel(int value);
    // Треугольник
    void setPointA_x(int value);
    void setPointA_y(int value);
    void setPointB_x(int value);
    void setPointB_y(int value);
    void setPointC_x(int value);
    void setPointC_y(int value);
    int returnPointA_x();
    int returnPointA_y();
    int returnPointB_x();
    int returnPointB_y();
    int returnPointC_x();
    int returnPointC_y();

    void setIsDrawingFirstTime(bool value);
    double returnArea();
    double returnPerimeter();
    double returnCenterX();
    double returnCenterY();
    double returnOuterRadius();
    double returnInnerRadius();
    double returnSideA();
    double returnSideB();
    double returnAngel();
    int returnNumber();
    int N;
    double scale;
    int rotation;
    int rotationX;
    int rotationY;
    double sideA;
    double sideB;
    double sideC;
    double area;
    double perimeter;
    double angel;
    double outerRadius;
    double innerRadius;
    QPointF center;
    QPointF pointA;
    QPointF pointB;
    QPointF pointC;
    int A_x;
    int A_y;
    int B_x;
    int B_y;
    int C_x;
    int C_y;

    bool is_drawing_first_time;

signals:
    void pointChanged();    // Сигнал об изменении точки
 
private:
    QPointF m_startPoint;   // Стартовая точка
    QPointF m_endPoint;     // Конечная точка
 
    QRectF boundingRect() const;    // Область, в которой содержится фигура
 
public slots:
    void updateRomb();     // Слот обновления области, в которой содержится фигура

protected:
    QVector<QPointF> points;

};
 
#endif // FIGURE_H