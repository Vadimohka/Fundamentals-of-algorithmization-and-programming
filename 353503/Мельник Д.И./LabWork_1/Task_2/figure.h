#ifndef FIGURE_H
#define FIGURE_H
#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include <QString>

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

    QRectF boundingRect() const;    // Область, в которой содержится фигура

    void setStartPoint(const QPointF point);    // Установка стартовой точки
    void setEndPoint(const QPointF point);      // Установка конечной точки
    virtual double area() { return 0.0; }
    virtual double perimeter() { return 0.0;}

signals:
    void pointChanged();        // Сигнал об изменении точки

private:
    QPointF m_startPoint;   // Стартовая точка
    QPointF m_endPoint;     // Конечная точка


public slots:
    void updateRomb();     // Слот обновления области, в которой содержится фигура
};

#endif // FIGURE_H
