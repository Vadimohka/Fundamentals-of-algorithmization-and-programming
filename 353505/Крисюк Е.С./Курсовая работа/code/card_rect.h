#ifndef CARD_RECT_H
#define CARD_RECT_H

#include <QGraphicsRectItem>
#include <QString>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QList>
#include <QPair>

#include "allusersfile.h"
#include "card.h"

class Card_rect : public QGraphicsRectItem
{
private:

    void Add_rect(QGraphicsScene*);
    void Add_text(QGraphicsScene*);

    QList<QPair<QColor, QColor>> good_colors_list;

    void add_colors();

    QGraphicsPathItem* pathItem;
    QGraphicsTextItem* card_number_text;
    QGraphicsTextItem* money_text;

public:
    Card_rect(Card*, QGraphicsItem* parent = nullptr);

    Card* current_card;

    void Add_card_to_scene(QGraphicsScene*);

    void Rect_to_right();
    void Rect_to_left();
    void Rect_to_centre();;

};

#endif // CARD_RECT_H
