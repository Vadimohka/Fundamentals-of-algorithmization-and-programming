#include "queue.h"

Queue::Queue()
{

}

Queue::~Queue()
{
    delete[] array;
}

void Queue::addElement(int value)
{
    array[rear] = value;
    rear = (rear + 1) % size;
}

void Queue::deleteElement()
{
    array[front] = -999;
    front = (front + 1) % (size);
}

void Queue::createQueue(int value)
{
    size = value + 1;
    front = 0;
    rear = 0;
    array = new int[size];
    for (int i = 0; i < size; i++){
        array[i] = -999;
    }
}

void Queue::makeRandom()
{
    int number = 0;
    QString numberStr;
    bool flag = false;
    for (int i = 0; i < size; ++i) {
        do
        {
            number = QRandomGenerator::global()->bounded(1, 400);
            numberStr = QString::number(number);
        }
        while (numberStr.contains('0'));
        array[i] = number;
    }

}

QString Queue::print()
{
    QString str = nullptr;
    for (int i = 0; i < (size - 1); i++){
        if (array[i] != -999)
        {
            str += "  ";
            str += QString::number(array[i]);
        }
    }
    return str;
}

int Queue::ShowFirst()
{
    return array[front];
}

int Queue::ShowLast()
{
    if (front == rear)
        return - 1;
    return array[rear-1];
}

bool Queue::IsEmpty()
{
    if (front == rear)
        return - 1;
    return front == rear;
}

bool Queue::IsFull()
{
    return (rear + 1) % (size) == front;
}
