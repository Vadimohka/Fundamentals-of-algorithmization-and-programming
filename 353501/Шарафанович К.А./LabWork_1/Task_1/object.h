#ifndef OBJECT_H
#define OBJECT_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>




class object: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    object();//конструктор
    ~object();// деструктор
    QGraphicsRectItem *rectangle;





private:
    QRectF boundingRect() const;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public :
  void MoveLeft();
  void MoveRight();

};

#endif // OBJECT_H
