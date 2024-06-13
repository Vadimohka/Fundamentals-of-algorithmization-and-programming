#ifndef CARDS_H
#define CARDS_H
#include<QPixmap>
#include<value.h>
#include<QVector>
#include<QHash>

class Card {
public:

    Card();

    enum suit { Spades, Hearts, Diamonds, Clubs };

    Card(suit suit, Value value);

    suit getSuit() const;

    Value getValue() const;

    QPixmap getImage() const;

    void setImage(QPixmap picture);

    bool isHigherThan(const Card& other) const;

    bool operator==(const Card &other) const;

    bool operator !=(const Card &other) const;

    bool operator<(const Card &other) const;

    bool operator>(const Card &other) const;

private:

    suit _suit;
    Value _value;
    QPixmap _image;
};

#endif // CARDS_H
