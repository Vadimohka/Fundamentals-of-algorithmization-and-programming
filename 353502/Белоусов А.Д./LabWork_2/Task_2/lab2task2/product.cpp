#include "product.h"

Product::Product() = default;

Product::Product(QString name, int64_t code, Group group, double price, int64_t quantity) : name(new QString(name)), code(new int64_t(code)), group(new Group(group)), price(new double(price)), quantity(new int64_t(quantity))
{

}

Group* Product::GetGroup()
{
    return new Group(*group);
}

QString* Product::GetName()
{
    return new QString(*name);
}

int64_t* Product::GetCode()
{
    return new int64_t(*code);
}

int64_t* Product::GetQuantity()
{
    return new int64_t(*quantity);
}

double* Product::GetPrice()
{
    return new double(*price);
}

void Product::SetGroup(Group* group)
{
    *this->group = *group;
}

void Product::SetName(QString* name)
{
    *this->name = *name;
}

void Product::SetCode(int64_t* code)
{
    *this->code = *code;
}

void Product::SetQuantity(int64_t* quantity)
{
    *this->quantity = *quantity;
}

void Product::SetPrice(double* price)
{
    *this->price = *price;
}

QString *Product::ToQString()
{
    QString* answer = new QString;
    answer->append(group->ToQString());
    answer->append(QString::fromStdString(", "));
    answer->append(*name);
    answer->append(QString::fromStdString(", "));
    answer->append(QString::number(*code));
    answer->append(QString::fromStdString(", "));
    answer->append(QString::number(*quantity));
    answer->append(QString::fromStdString(", "));
    answer->append(QString::number(*price));
    answer->append(QString::fromStdString(", "));

    return answer;
}

void Product::FromQStringToInstance(QString *object)
{
    int size = object->size();
    QString* current = new QString("");
    int iterator = 0;

    for (;iterator<size;iterator++)
    {
        if (object->at(iterator) == ',')
        {
            group->FromQStringToInstance(current);
            iterator+=2;
            break;
        }

        current->append(object->at(iterator));
    }

    current->clear();

    for (;iterator<size;iterator++)
    {
        if (object->at(iterator) == ',')
        {
            *name = *current;
            iterator+=2;
            break;
        }

        current->append(object->at(iterator));
    }

    current->clear();

    for (;iterator<size;iterator++)
    {
        if (object->at(iterator) == ',')
        {
            *code = current->toLongLong();
            iterator+=2;
            break;
        }

        current->append(object->at(iterator));
    }

    current->clear();

    for (;iterator<size;iterator++)
    {
        if (object->at(iterator) == ',')
        {
            *quantity = current->toLongLong();
            iterator+=2;
            break;
        }

        current->append(object->at(iterator));
    }

    current->clear();

    for (;iterator<size;iterator++)
    {
        if (object->at(iterator) == ',')
        {
            *price = current->toDouble();
            break;
        }

        current->append(object->at(iterator));
    }

    delete current;
}
