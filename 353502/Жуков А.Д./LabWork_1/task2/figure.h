#ifndef FIGURE_H
#define FIGURE_H

#include <QGraphicsItem>
#include <QObject>
#include <QMouseEvent>
#include <QGraphicsSceneEvent>

class Figure : public QObject, public QGraphicsItem
{

    Q_OBJECT

public:
    explicit Figure(QPointF point, QObject *parent = nullptr);
    Figure(int corners, QPointF point, QObject *parent = nullptr);
    ~Figure() override = default;

    void setSP(const QPointF point);
    QPointF getSP() const;
    void setEP(const QPointF point);
    QPointF getEP() const;

    double getPerimeter();
    double getArea();

    QPointF getSEP() const;

protected:
    void setPerimeter(double);
    void setArea(double);

private:
    QPointF Spoint;
    QPointF Epoint;
    QPointF SEPoint;

    double area;
    double perimeter;

    QRectF boundingRect() const override;

    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

public slots:
    void upd();
};

#endif // FIGURE_H
