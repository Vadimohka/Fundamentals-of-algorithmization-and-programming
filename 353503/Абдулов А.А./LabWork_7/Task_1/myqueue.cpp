#include "myqueue.h"

MyQueue::MyQueue() {
    count = 0;
    begin = nullptr;
    end = nullptr;
    info = "";
}

void MyQueue::push(int num){
    QueueNumber* newNumber = new QueueNumber(num);

    if(begin == nullptr){
        begin = newNumber;
        end = newNumber;
    }else{
        end->setNext(newNumber);
        end = newNumber;
    }

    info += " | " + QString::number(newNumber->getValue()) + " | ";
    count++;
}

int MyQueue::pop(){
    int value = begin->getValue();

    QueueNumber* next = (begin == end ? nullptr : begin->getNext());

    delete begin;


    if(begin == end || begin->getNext() == end) end = next;

    begin = next;

    QString strValue = " | " + QString::number(value) + " | ";

    info.remove(0, strValue.size());
    count--;
    return value;
}



int MyQueue::front(){
    return begin->getValue();
}


int MyQueue::back(){
    return end->getValue();
}

bool MyQueue::isEmpty(){
    return count == 0;
}

int MyQueue::size(){
    return count;
}

void MyQueue::fnct(){

    QueueNumber* currentNumber = begin;
    QueueNumber* minNumber = begin;
    QueueNumber* beforeMinNumber = begin;

    while(currentNumber->getNext() != nullptr){
        if(minNumber->getValue() > currentNumber->getNext()->getValue()){
            minNumber = currentNumber->getNext();
            beforeMinNumber = currentNumber;
        }

        currentNumber = currentNumber->getNext();
    }

    if(minNumber != begin){
        beforeMinNumber->setNext(minNumber->getNext());
        minNumber->setNext(begin);
        begin = minNumber;

        QString minNum = " | " + QString::number(minNumber->getValue()) + " | ";
        int i = info.indexOf(minNum);

        info.remove(i, minNum.size());
        info.insert(0, minNum);
    }
}





