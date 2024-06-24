#ifndef QUEUENUMBER_H
#define QUEUENUMBER_H

class QueueNumber{
public:
    QueueNumber(int value, QueueNumber* next);
    QueueNumber(int value);

    int getValue();
    QueueNumber* getNext();
    void setNext(QueueNumber* next);

private:
    int value;
    QueueNumber* next;
};

#endif // QUEUENUMBER_H
