#include "queuenumber.h"

QueueNumber::QueueNumber(int value, QueueNumber* next) {
    this->value = value;
    this->next = next;
}

QueueNumber::QueueNumber(int value) {
    this->value = value;
    next = nullptr;
}

int QueueNumber::getValue(){
    return value;
}

QueueNumber* QueueNumber::getNext(){
    return next;
}

void QueueNumber::setNext(QueueNumber* next){
    this->next = next;
}






