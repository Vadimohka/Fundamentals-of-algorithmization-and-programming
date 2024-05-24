#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include <QPainter>

class Figure : public QObject, public QGraphicsItem
{
    Q_OBJECT

    Q_PROPERTY(QPointF getStartPoint
                   READ getStartPoint WRITE setStartPoint
                       NOTIFY pointChanged)

    Q_PROPERTY(QPointF getEndPoint
                   READ getEndPoint WRITE setEndPoint
                       NOTIFY pointChanged)
public:
    Figure(QPointF point, QObject *parent = 0);

    QPointF getStartPoint() const;
    QPointF getEndPoint() const;

    void setStartPoint(const QPointF point);
    void setEndPoint(const QPointF point);

    virtual qreal getSFigure() const;
    virtual qreal getPFigure() const;

signals:
    void pointChanged();    // Сигнал об изменении точки

private:
    QPointF startPoint;
    QPointF endPoint;

protected:
    virtual QRectF boundingRect() const;
    qreal sFigure;
    qreal pFigure;
    qreal betweenPoint;

public slots:
    void updateFigure();     // Oбновления области, в которой содержится фигура
};

#endif // FIGURE_H
