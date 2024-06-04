
#include "MyCardHBL.h"
#include "MyCard.h"
#include <QDebug>

int MyCardHBL::count() const
{
    // QVector::size() returns the number of QLayoutItems in m_items
    return m_items.size();
}

QLayoutItem *MyCardHBL::itemAt(int idx) const
{
    // QVector::value() performs index checking, and returns nullptr if we are
    // outside the valid range
    return m_items.value(idx);
}

QLayoutItem *MyCardHBL::takeAt(int idx)
{
    // QVector::take does not do index checking
    return idx >= 0 && idx < m_items.size() ? m_items.takeAt(idx) : 0;
}

void MyCardHBL::addItem(QLayoutItem *item)
{
    m_items.append(item);
}

MyCardHBL::~MyCardHBL()
{
    // Delete all items
    QLayoutItem* item;
    while ((item = takeAt(0)))
        delete item;
}

void MyCardHBL::setGeometry(const QRect &r)
{
    // First layout the parent geometry
    QLayout::setGeometry(r);

    // Don't do anything if no elements
    if (m_items.size() == 0)
        return;

    // Calculate the width and height
    int i = 0;

    // Iterate all over items
    while (i < m_items.size())
    {
        // Calculate the geometry per item
        QLayoutItem* o = m_items.at(i);
        QRect geom(r.x() + (i * spacing()), r.y(), MyCard::getCardScreenSize().width(), MyCard::getCardScreenSize().height());
        o->setGeometry(geom);
        ++i;
    }
}

QSize MyCardHBL::sizeHint() const
{
    QSize s(0, 0);
    int n = m_items.count();

    // If we have more than 0 items
    if (n > 0)
        s = MyCard::getCardScreenSize(); // Default size

    // Iterate over items and expand all item's sizes
    int i = 0;
    while (i < n) {
        QLayoutItem *o = m_items.at(i);
        s = s.expandedTo(o->sizeHint());
        ++i;
    }

    // Calculate final size
    return s + n * QSize(spacing(), 0);
}

QSize MyCardHBL::minimumSize() const
{
    // Iterate over all items and calculate their minimum size
    QSize s(0, 0);
    int n = m_items.count();
    int i = 0;
    while (i < n) {
        QLayoutItem *o = m_items.at(i);
        s = s.expandedTo(o->minimumSize());
        ++i;
    }
    return s + n * QSize(spacing(), 0);
}

int MyCardHBL::getItemCount() const
{
    return m_items.size();
}

QLayoutItem *MyCardHBL::getFirstItem() const
{
    return m_items.front();
}

void MyCardHBL::clear()
{
    for(QLayoutItem* item: m_items)
    {
        this->removeItem(item);
    }
    m_items.clear();
}

void MyCardHBL::push_back(QWidget *card)
{
    // As there is no QLayout-method that inserts a widget at a specific index, we have to add the widget
    // to the layout first, so it becomes an LayoutItem, then we can rearrange the list of the 3 current cards
    addWidget(card);
    QLayoutItem* temp = m_items.back();
    m_items.pop_back();
    m_items.push_front(temp);
}
