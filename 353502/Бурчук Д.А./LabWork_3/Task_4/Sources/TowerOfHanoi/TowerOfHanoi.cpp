#include "../../Headers/TowerOfHanoi.h"

TowerOfHanoi::TowerOfHanoi() {
    _numberOfRings = 10;

    _sticks.emplace_back(_numberOfRings);
    _sticks.emplace_back(0);
    _sticks.emplace_back(0);
}

void TowerOfHanoi::drawStick(QPainter *painter) {
    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::black);
    painter->setPen(pen);
    painter->setBrush(Qt::yellow);
    painter->drawRect(-200 + WIDTH - 10, 200, 20, HEIGHT + 55);
    painter->drawRect(-200 + WIDTH * 2, 200, 20, HEIGHT + 55);
    painter->drawRect(-200 + WIDTH + 2 * WIDTH + 10, 200, 20, HEIGHT + 55);
    painter->drawRect(-205 + WIDTH / 2, 230 + HEIGHT, 3 * WIDTH + 30, 25);
    for (int i = 0; i < _numberOfRings; i++) {
        QBrush brush(QColor((i * 55 * i) % 225 + 30, (i * 100 * i) % 255, 250 - (i * i * 10 * i) % 175, 255));
        painter->setBrush(brush);
        painter->drawRect(_rings[i].ring());
        painter->drawRect(_rings[i].center().x() - 2, _rings[i].center().y() - 2, 4, 4);
    }
}

void TowerOfHanoi::setNumberOfRings(uint numberOfRings) {
    if (numberOfRings > MAX_COUNT_OF_RINGS) {
        this->_numberOfRings = MAX_COUNT_OF_RINGS;
    } else if (numberOfRings < MIN_COUNT_OF_RINGS) {
        this->_numberOfRings = MIN_COUNT_OF_RINGS;
    } else {
        this->_numberOfRings = numberOfRings;
    }
    for (auto &ring: _rings) { ring.setPos(1); }
    for (int i = 0; i < _numberOfRings; i++) {
        _rings[i].setHeight((float) (HEIGHT / 10 / 2));
        _rings[i].setWidth((float) (WIDTH - WIDTH / (10) * (9 - i)) / 2);
        _rings[i].setPoint(
                QPointF(-210 + (WIDTH + 10) * _rings[i].pos()//- (_rings[i].width() + 20 * i) / 2,
                        ,
                        200 + HEIGHT / MAX_COUNT_OF_RINGS * (1 + i) +
                                (MAX_COUNT_OF_RINGS - _numberOfRings) * _rings[i].height() * 2));
    }
}

void TowerOfHanoi::makeRings() {
    for (int i = 0; i < _numberOfRings; i++) {
        qDebug() << i << ".1";
        _rings.emplace_back();
    }
    for (int i = 0; i < _numberOfRings; i++) {
        qDebug() << i << ".2";
        _rings[i].setHeight((float) (HEIGHT / 10 / 2));
        _rings[i].setWidth((float) (WIDTH - WIDTH / (10) * (9 - i)) / 2);
        _rings[i].setPoint(
                QPointF(-200 + (WIDTH) *_rings[i].pos()//- (_rings[i].width() + 20 * i) / 2,
                        ,
                        200 + HEIGHT / MAX_COUNT_OF_RINGS * (1 + i) +
                                (MAX_COUNT_OF_RINGS - _numberOfRings) * _rings[i].height() * 2));
    }
}

void TowerOfHanoi::setStick(int from, int to) {
    _sticks[from - 1]--;
    _sticks[to - 1]++;
}

int TowerOfHanoi::stick(int to) {
    return _sticks[to - 1];
}

void TowerOfHanoi::setStickStart(int first, int second, int third) {
    _sticks[0] = first;
    _sticks[1] = second;
    _sticks[2] = third;
}

uint TowerOfHanoi::numberOfRings() {
    return _numberOfRings;
}


/*
for (int i = 0; i < _numberOfRings; i++) {
    for (int j = 1; j < 4; j++) {
        if (_rings[i].pos() == j) {
            std::cout << i +1 << ' ';
        } else {
            std::cout << 0 << ' ';
        }
    }
    std::cout << '\n';
}
std::cout << '\n';
*/
