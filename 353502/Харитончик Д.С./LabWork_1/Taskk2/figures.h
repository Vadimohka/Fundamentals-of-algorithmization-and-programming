#ifndef FIGURES_H
#define FIGURES_H
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <cmath>
#include <QDebug>

class Figure : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    static int action;
    static QString figureNow;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

protected:
    QPointF centerOfFigure = QPointF(0.0, 0.0);
    QPointF previous = QPointF(0.0, 0.0);
    int angle = 0;

    virtual QRectF boundingRect() const = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;
    virtual void setCenterOfFigureNow(QPointF center);
    virtual void setPositionOfTheFigure(QPointF pos);
    virtual QPointF getScenePosition();
    virtual qreal squareOfFigure() = 0;
    virtual qreal perimetrOfFigure() = 0;


public:
    Figure();
    virtual ~Figure() = default;

    static void setAction(int newAction);
    virtual void resize(qreal changeSize);


    static void setFigureNow(const QString &newFigureNow);

    static QString getFigureNow();


    void setLeftRotation();
    void setRightRotation();

signals:
    void newItem(Figure* newFigure, QString newFigureForm);
    void deleteItem(Figure* deleteFigure);
    void mousePosition(QPointF now);
    void updateFigure();
    void centerSignal(QPointF center);
    void squareSignal(qreal square);
    void perimetrSignal(qreal perimetr);
    void mouseHasAlreadyClicked(QPointF point);
};

#endif // FIGURES_H
