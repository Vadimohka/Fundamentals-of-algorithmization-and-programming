#include "data.h"

mydata::data() {}

void mydata::setData(QStandardItemModel *model, QModelIndex *index)
{
    model->setData(index, "привет");
}
