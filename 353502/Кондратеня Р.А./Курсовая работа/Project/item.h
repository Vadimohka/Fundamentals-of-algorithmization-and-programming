#ifndef ITEM_H
#define ITEM_H

#include <QStandardItem>

#include "function.h"

class Item : public QStandardItem
{
public:
    Item();
    explicit Item(const QString& text);

};

#endif // ITEM_H
