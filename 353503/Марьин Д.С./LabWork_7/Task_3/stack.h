#ifndef STACK_H
#define STACK_H

#include <QDebug>

template <typename T>
struct Node
{
    T data;
    Node* next;
};

template <typename T>
class Stack
{
public:
    Stack();
    Stack(Stack<T> const &stack);
    ~Stack();
    void push(T data);
    T pop();
    T peek();
    bool isEmpty();
    size_t getSize() { return size; }
    void print();
    std::string toString();
private:
    Node<T>* top;
    size_t size{};
};

template <typename T>
Stack<T>::Stack(Stack<T> const &stack) : top(nullptr)
{
    size = 0;
    Node<T>* temp = stack.top;
    while (temp != nullptr)
    {
        push(temp->data);
        temp = temp->next;
    }
}

template <typename T>
Stack<T>::Stack() : top(nullptr)
{}

template <typename T>
Stack<T>::~Stack()
{
    while (top != nullptr)
    {
        Node<T>* temp = top;
        top = top->next;
        delete temp;
    }
}

template <typename T>
void Stack<T>::push(T data)
{
    Node<T>* temp = new Node<T>;
    temp->data = data;
    temp->next = top;
    top = temp;
    size++;
}

template<typename T>
T Stack<T>::pop()
{
    if (top == nullptr)
    {
        qDebug() << "Stack is empty" << "\n";
        return T();
    }
    Node<T>* temp = top;
    T data = top->data;
    top = top->next;
    delete temp;
    return data;
}

template<typename T>
T Stack<T>::peek()
{
    if (top == nullptr)
    {
        qDebug() << "Stack is empty" << "\n";
        return T();
    }
    return top->data;
}

template<typename T>
bool Stack<T>::isEmpty()
{
    return top == nullptr;
}

template<typename T>
void Stack<T>::print()
{
    Node<T>* temp = top;
    qDebug() << "Stack: ";
    while (temp != nullptr)
    {
        qDebug() << temp->data << " ";
        temp = temp->next;
    }
    qDebug() << "\n";
}

template<typename T>
std::string Stack<T>::toString()
{
    std::string result;
    Node<T>* temp = top;
    while (temp != nullptr)
    {
        result += std::to_string(temp->data) + " ";
        temp = temp->next;
    }
    return result;
}

#endif // STACK_H
