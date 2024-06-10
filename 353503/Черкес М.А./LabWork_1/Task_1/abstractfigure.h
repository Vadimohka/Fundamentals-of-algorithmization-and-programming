#ifndef ABSTRACTFIGURE_H
#define ABSTRACTFIGURE_H

#include<QGraphicsItem>
#include<QBrush>
#include<QGraphicsScene>
#include<QColor>
#include<QPainter>
#include<QPen>
#include<QWidget>
#include<QObject>
#include<QDebug>

class abstractFigure: public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF startPoint
                   READ startPoint WRITE setStartPoint
                       NOTIFY pointChanged)
    Q_PROPERTY(QPointF endPoint
                   READ endPoint WRITE setEndPoint
                       NOTIFY pointChanged)
public:
    explicit abstractFigure(QPointF point,QObject *parent = 0);
   // void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPointF startPoint() const;
    QPointF endPoint() const;
    void setStartPoint(const QPointF point);
    void setEndPoint(const QPointF point);

protected:
  //  QRectF rect;
  //  QBrush brush;
 //   virtual void drawFigure(QPainter *painter);
signals:
    void pointChanged();
private:
    QPointF MstartPoint;
    QPointF MendPoint;
   /* void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);*/
public slots:
    virtual QRectF boundingRect() const;
    void updateFigure();
};

#endif // ABSTRACTFIGURE_H
