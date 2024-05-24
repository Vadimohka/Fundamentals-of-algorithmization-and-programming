//
// Created by volodya-petarda on 3/3/24.
//

#ifndef GALAVA_MOVINGELLIPSE_H
#define GALAVA_MOVINGELLIPSE_H


#include <QGraphicsObject>

class movingEllipse : public QGraphicsObject {
    Q_OBJECT
public slots:

    void moveUp();

    void moveDown();

    void moveLeft();

    void moveRight();

    void subW();

    void addW();

    void subH();

    void addH();

public:
    movingEllipse(int x, int y, int w, int h);

    movingEllipse();

    [[nodiscard]] QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    void move(int x, int y);

    void setW(int tw);

    void setH(int th);

    void setPenColor(Qt::GlobalColor color);

    void setBrushColor(Qt::GlobalColor color);

private:
    Qt::GlobalColor brushColor = Qt::transparent, penColor = Qt::black;
    int xPos, yPos, w{}, h{};
};


#endif //GALAVA_MOVINGELLIPSE_H
