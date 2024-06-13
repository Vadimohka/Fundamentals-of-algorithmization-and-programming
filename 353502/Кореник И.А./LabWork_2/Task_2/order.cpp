#include "order.h"


Order::Order(int _num,int _table, QString _dish, int _count)
{
    table = _table;
    dish = _dish;
    num = _num;
    count = _count;
}

Order::Order(QString input)
{
    QString _num, _table, _dish, _count;
    int i = 0;
    while(input[i] != ' '){
        _num.append(input[i]);
        i++;
    }
    i++;
    while(input[i] != ' '){
        _table.append(input[i]);
        i++;
    }
    i++;

    while(input[i] != ' '){
        _dish.append(input[i]);
        i++;
    }
    i++;

    while(i < input.size()){
        _count.append(input[i]);
        i++;
    }

    num = _num.toInt();
    table = _table.toInt();
    dish = _dish;
    count = _count.toInt();
}


/*void Order::change(int _table = this->table, QString _dish = this->dish, int _num = this->num)
{
    table = _table;
    dish = _dish;
    num = _num;
}*/
