#include "hanoivisual.h"
#include <QGraphicsRectItem>

HanoiVisuals::HanoiVisuals() : scene(new QGraphicsScene(this)), timer(new QTimer)
{
    list = nullptr;
    timer->start(10);
    connect(timer, &QTimer::timeout, this, &HanoiVisuals::update);

    for (auto pos : RODS_POS)
    {
        scene->addRect(pos - BASE_W / 2, 280, BASE_W, 40, Qt::SolidLine, Qt::lightGray);
        scene->addRect(pos - ROD_W / 2, 280 - ROD_H, ROD_W, ROD_H, Qt::SolidLine, Qt::lightGray);
    }
}

void HanoiVisuals::reset(int _ringsCount, QVector<QPair<int, int>> *_list)
{
    currentAction = 0;
    state = -1;
    ringsCount = _ringsCount;
    list = _list;

    for (int i = 0; i < 3; ++i)
    {
        for (auto item : rods[i])
        {
            scene->removeItem(item);
        }
        rods[i].clear();
    }
    for (int i = ringsCount - 1; i >= 0; --i) {
        QGraphicsRectItem *ring = new QGraphicsRectItem(0, 0, RING_SIZE_W_ITER * i + RING_SIZE_W_ITER, RING_SIZE_H);
        ring->setPos(-360 - (RING_SIZE_W_ITER * i + RING_SIZE_W_ITER) / 2,
                     280 - RING_SIZE_H * ringsCount + (RING_SIZE_H * i));

        // Вычисляем значение оттенка в диапазоне от 0 до 360 (360 делится на количество колец)
        int hue = static_cast<int>((i * 360.0) / ringsCount);

        // Устанавливаем цвет кисти, используя значения оттенка, насыщенности и значения
        ring->setBrush(QColor::fromHsv(hue, 255, 255));

        rods[0].push_back(ring);
        scene->addItem(ring);
    }
}

void HanoiVisuals::update()
{
    if (list == nullptr)
    {
        return;
    }

    switch (state)
    {
    case Finished:
        if (currentAction <= currentSelection)
        {
            state = GoingUp;
            source = list->at(currentAction).first - 1;
            target = list->at(currentAction).second - 1;
            ++currentAction;
        }
        break;
    case GoingUp:
        if (rods[source].last()->y() > -280)
        {
            rods[source].last()->moveBy(0, -20);
        }
        else
        {
            state = MovingHorizontally;
        }
        break;
    case MovingHorizontally:
        if (rods[source].last()->x() < RODS_POS[target] - rods[source].last()->rect().width() / 2)
        {
            rods[source].last()->moveBy(20, 0);
        }
        else if (rods[source].last()->x() > RODS_POS[target] - rods[source].last()->rect().width() / 2)
        {
            rods[source].last()->moveBy(-20, 0);
        }
        else
        {
            state = GoingDown;
        }
        break;
    case GoingDown:
        if (rods[source].last()->y() < 280 - RING_SIZE_H * (rods[target].size() + 1))
        {
            rods[source].last()->moveBy(0, 20);
        }
        else
        {
            rods[target].push_back(rods[source].last());
            rods[source].resize(rods[source].size() - 1);
            state = Finished;
        }
        break;
    }
}

void HanoiVisuals::setSelection(int _selected)
{
    currentSelection = _selected;
    if (state == -1)
    {
        state = Finished;
    }
}

void HanoiVisuals::setSpeed(int _speed)
{
    speed = _speed;
    timer->setInterval(11 - speed);
}
