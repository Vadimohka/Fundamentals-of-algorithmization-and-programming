#include "line.h"

class House : public Line {
public:
    House();

    // Line* window1, *window2;
    Line* door;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRect bounding() const;


};
