#include "order.h"

Order::Order(QString name, int orderNumber, int tableNumber, int dishNumber) : dishName(name), 
                                                                                orderNumber(orderNumber), 
                                                                                tableNumber(tableNumber),
                                                                                dishNumber (dishNumber) {
};

QString Order::getName(){
    return dishName;
}

int Order::getOrderNumber(){
    return orderNumber;
}

int Order::getDishNumber(){
    return dishNumber;
}

int Order::getTableNumber(){
    return tableNumber;
}