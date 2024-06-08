#include "order.h"

Order::Order(QString name, int orderNumber, int tableNumber, int dishNumber) : dishName(name),
    orderNumber(orderNumber),
    tableNumber(tableNumber),
    dishNumber (dishNumber) {
    };

QString Order::getDishName(){
    return dishName;
}

int Order::getOrderNum(){
    return orderNumber;
}

int Order::getQuantity(){
    return dishNumber;
}

int Order::getTableNum(){
    return tableNumber;
}
