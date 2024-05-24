#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QColor>

class Button:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    // constructors
    Button(QString name, int weight, int height, QGraphicsItem* parent=NULL);

    // public methods (events)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void setColors(const QColor &newColor1,const QColor &newColor2);

signals:
    void clicked();
private:
    QGraphicsTextItem* text;
    QColor color1=Qt::yellow;
    QColor color2=Qt::darkYellow;
};

#endif // BUTTON_H
