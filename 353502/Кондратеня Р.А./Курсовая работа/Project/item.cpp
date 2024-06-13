#include "item.h"

Item::Item() : QStandardItem()
{
    this->setEditable(true);
}

Item::Item(const QString& text) : QStandardItem(text)
{

}
