#include "cards.h"

Card::Card() = default;

Card::Card(suit suit_, Value value) : _suit(suit_), _value(value){}

Card::suit Card::getSuit() const
{
    return _suit;
}

Value Card::getValue() const
{
    return _value;
}

QPixmap Card::getImage() const
{
    return _image;
}

void Card::setImage(QPixmap picture)
{
    this->_image = picture;
}

bool Card::operator==(const Card &other) const {
    return _suit == other._suit && _value == other._value;
}

bool Card::operator !=(const Card &other) const {
    return _suit == other._suit && _value == other._value;
}

bool Card::operator<(const Card &other) const {
    if (_suit == other._suit) {
        return _value < other._value;
    } else {
        return _suit < other._suit;
    }
}

bool Card::operator>(const Card &other) const {
    if (_suit == other._suit) {
        return _value > other._value;
    } else {
        return _suit >  other._suit;
    }
}
