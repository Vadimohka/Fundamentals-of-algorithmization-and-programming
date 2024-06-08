#ifndef ELEMENTS_H
#define ELEMENTS_H
#include <QPainter>
#include <QGraphicsItem>
class Elements : public QGraphicsObject
{
private:
    int n = 0;
    float sceneHeight = 400;
    float sceneWidht = 650;
    float width;
    float height;
    void paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void calculatepoints();
    QRectF boundingRect() const;
public:
    QVector<float> palki;
    int SearchedRect = 10000;
    void setN(int);
    int getN();
    Elements();
};
#endif // ELEMENTS_H
