#include "sortvisuals.h"

SortVisuals::SortVisuals(QRectF initSize, QObject* parent) : QGraphicsScene(initSize, parent)
{

}

void SortVisuals::reset(Vector<int>* _list)
{
    clear();
    items.clear();

    list = _list;
    length = width() / list->size();
    heightPerI = height() / *std::max_element(list->begin(), list->end());

    for (int i = 0; i < list->size(); ++i)
    {
        QGraphicsRectItem *item = new QGraphicsRectItem();
        item->setPen(Qt::SolidLine);

        float a = (float)i / list->size();
        item->setBrush(QBrush(QColor(255 - a*255, 255 - a*255, 255 - a*255)));
        item->setRect(i * length, 0, length, list->at(i) * heightPerI);
        items.push_back(item);
        addItem(item);
    }
}

void SortVisuals::updateItem(int i)
{
    items[i]->setRect(i * length, 0, length, list->at(i) * heightPerI);
}

void SortVisuals::updateSearch(int i)
{
    if (search != nullptr)
    {
        removeItem(search);
        delete search;
        search = nullptr;
    }

    QGraphicsRectItem *s = new QGraphicsRectItem();
    s->setPen(Qt::SolidLine);
    s->setBrush(Qt::blue);
    s->setRect(i * length, 0, width() / 200, list->at(i) * heightPerI);
    search = s;
    addItem(search);
}
