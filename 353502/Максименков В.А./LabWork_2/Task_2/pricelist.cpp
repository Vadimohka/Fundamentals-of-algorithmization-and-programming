#include "pricelist.h"
#include <algorithm>

QVector<int> PriceList::getCode() const
{
    return code;
}

int PriceList::getNumber() const
{
    return number;
}

QVector<double> PriceList::getPrice() const
{
    return price;
}

QVector<QString> PriceList::getName() const
{
    return name;
}

void PriceList::codeSort()
{
    for (int i = 0; i < number; ++i)
    {
        for (int j = i+1; j < number; ++j)
        {
            if (code[i] > code[j])
            {
                std::swap(code[i], code[j]);
                std::swap(price[i], price[j]);
                std::swap(name[i], name[j]);
            }
        }
    }
}

void PriceList::priceSort()
{
    for (int i = 0; i < number; ++i)
    {
        for (int j = i+1; j < number; ++j)
        {
            if (price[i] > price[j])
            {
                std::swap(code[i], code[j]);
                std::swap(price[i], price[j]);
                std::swap(name[i], name[j]);
            }
        }
    }
}

PriceList::PriceList() {}

void PriceList::add(int code, double price, QString name)
{
    this->code.push_back(code);
    this->price.push_back(price);
    this->name.push_back(name);
    ++number;
}


void PriceList::correct(int row, int code, double price, const QString &name)
{
    this->code[row-1] = code;
    this->price[row-1] = price;
    this->name[row-1] = name;
}


void PriceList::del(int row)
{
    code.removeAt(row-1);
    price.removeAt(row-1);
    name.removeAt(row-1);
    --number;
}
