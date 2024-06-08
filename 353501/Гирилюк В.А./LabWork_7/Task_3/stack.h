#ifndef STACK_H
#define STACK_H



template <typename T> class Stack{
    struct Node{
        T value;

        Node(int value){
            this->value = value;
        }

        Node *next = nullptr;
        Node *previous = nullptr;
    };
public:
    Stack(){}

    void put(T value)
    {
        if(stackSize == 0){
            first = new Node(value);
            end = first;
        }
        else{
            end->next = new Node(value);
            end->next->previous = end;
            end = end->next;
        }
        ++stackSize;
    }

    T pop()
    {
        if(stackSize > 1){
            T value = end->value;
            end = end->previous;
            delete (end->next);
            --stackSize;
            return value;
        }
        else if(stackSize == 1){
            T value = end->value;
            delete first;
            first = nullptr;
            end = nullptr;
            --stackSize;
            return value;
        }

        return 0;
    }

    int size()
    {
        return stackSize;
    }

    bool isEmpty()
    {
        return first == nullptr;
    }

    void clear()
    {
        while(stackSize > 0){
            pop();
        }
    }

private:

    Node *first = nullptr;
    Node *end = nullptr;
    int stackSize = 0;
};

#endif // STACK_H
