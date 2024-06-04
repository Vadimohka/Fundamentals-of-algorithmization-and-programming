#include "solider.h"

Solider::Solider() {}

void Solider::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QPainterPath path;

    path.addRoundedRect(x, y, w, h, 5, 5); // body
    painter->fillPath(path, QColor(232, 190, 172));
    painter->drawPath(path);

    path.addRoundedRect(x, y + h/5, w, h/4, 5, 5); // head

    path.addRoundedRect(x - w/3, y + 2 * h/5, w/3, h/2, 5, 5); // left arm
    path.addRoundedRect(x + w, y + 2 * h/5 + ady, w/3, h/2 + adh, 5, 5); // right arm

    painter->fillPath(path, QColor(0, 200, 0));
    painter->drawPath(path);

    QPainterPath hands;

    hands.addRoundedRect(x - w/3, y + 2 * h/5 + 3 * h/8, w/3, h/8, 5, 5); // left hand
    hands.addRoundedRect(x + w, y + 2 * h/5 + 3 * h/8 + hdy, w/3, h/8, 5, 5); // right hand
    painter->fillPath(hands, QColor(232, 190, 172));
    painter->drawPath(hands);
}

void Solider::salute()
{
    if (st)
    {
        int handpos = y + 2 * h/5 + 3 * h/8 + hdy;
        int armlength = h/2 + adh;
        if (handpos > y + h/5 && counter < 120)
        {
            hdy--;
            if (armlength > h/8 && counter < 20)
            {
                adh--;
            }
            else
            {
                counter = 20;
                adh++;
                ady--;
            }
        }
        else
        {
            if (counter < 120)
                counter++;
            else
            {
                if (handpos < y + 2 * h/5 + 3 * h/8)
                {
                    hdy++;
                    if (armlength > h/8 && counter < 121)
                    {
                        adh--;
                        ady++;
                    }
                    else
                    {
                        counter = 121;
                        adh++;
                    }
                }
                else
                {
                    st = false;
                    counter = 0;
                }
            }
        }
    }
}

