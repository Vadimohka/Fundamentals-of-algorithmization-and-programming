#ifndef QUEUE_H
#define QUEUE_H


template <typename T> class Queue
{
    struct Node{
        T value;

        Node(int value){
            this->value = value;
        }

        Node *next = nullptr;
        Node *previous = nullptr;
    };
public:
    Queue(){}

    void enqueue(T value)
    {
        if(queueSize == 0){
            first = new Node(value);
            end = first;
        }
        else{
            end->next = new Node(value);
            end->next->previous = end;
            end = end->next;
        }
        ++queueSize;
    }

    T dequeue()
    {
        if(queueSize > 1){
            T value = first->value;
            first = first->next;
            delete (first->previous);
            --queueSize;
            return value;
        }
        else if(queueSize == 1){
            T value = end->value;
            delete first;
            first = nullptr;
            end = nullptr;
            --queueSize;
            return value;
        }

        return 0;
    }

    int size()
    {
        return queueSize;
    }

    bool isEmpty()
    {
        return first == nullptr;
    }

    void clear()
    {
        while(queueSize > 0){
            dequeue();
        }
    }

private:

    Node *first = nullptr;
    Node *end = nullptr;
    int queueSize = 0;
};

#endif // QUEUE_H
