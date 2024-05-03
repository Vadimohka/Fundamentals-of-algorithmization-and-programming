#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include <QObject>
#include <QPainter>
#include <QTimer>
#include <cmath>
#include <QtMath>

int const initialPerimeter = 0;
class Figure : public QGraphicsItem
{
public:
    explicit Figure(QPointF point);
    enum FigureTypes {
        FigureSquare,
        FigureRomb,
        FigureTriangle,
        FigureRectangle,
        FigureCircle,
        FigureFivePointerStar,
        FigureSixPointerStar,
        FigureEightPointerStar,
        FigurePen,
        ActionChangePosition
    };
    int getTypeFigure() const;
    void setTypeFigure(int type);

    void setFirstPoint(const QPointF point);
    QPointF getFirstPoint() const;

    void setSecondPoint(const QPointF point);
    QPointF getSecondPoint() const;

    void setFirstPointExternally(const QPointF point);
    void setSecondPointExternally(const QPointF point);

    void resetNullRotateAngle();

    void addValueRotateAngle(int valueChangeAngle);

    int getRotateAngle();

    double getHorizontalSide() const;
    double getVerticalSide() const;
    void countHorizontalSide();
    void countVerticalSide();
    QRectF boundingRect() const override;
    void setCentreFigure();
    void setCentreFigureExternally(const QPointF point);
    QPointF getCentreFigure();
    void countQuarter();
    int getQuarter() const;
    void setArea(double newAreaValue);
    double getArea();
    void setPerimetr(double newPerimetrValue);
    double getPerimetr();
    void setMoveFigureAlongX(double valueMoveFigureAlongX);
    void setMoveFigureAlongY(double valueMoveFigureAlongY);
    double getMoveFigureAlongX();
    double getMoveFigureAlongY();
private:
    int typeFigure;
    int quarter;
    int rotateAngle;
    QPointF firstPoint;
    QPointF secondPoint;
    QPointF centreFigure;
    double area;
    double perimetr;
    double horizontalSide;
    double verticalSide;
    double moveFigureAlongX;
    double moveFigureAlongY;
};

#endif // FIGURE_H

