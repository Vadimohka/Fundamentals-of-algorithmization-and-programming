#include "queue.h"
#include <QDebug>
#include <QListView>

template <typename T>
Queue<T>::Queue()
{
    head = nullptr;
    _size = 0;
}

template<typename T>
Queue<T>::~Queue()
{
    Node<T>* tmp = head;
    Node<T>* tmp2 = nullptr;
    while(tmp)
    {
        tmp2 = tmp->nextNode;
        delete tmp;
        tmp = nullptr;
        tmp = tmp2;
    }

    _size = 0;
}

template<typename T>
bool Queue<T>::empty()
{
    return (_size == 0);

}

template<typename T>
size_t Queue<T>::size()
{
    return _size;
}

template<typename T>
T& Queue<T>::front()
{
    if(_size > 0) return (head->_value);
    else throw "queue is empty";
}

template<typename T>
T& Queue<T>::back()
{
    Node<T>* tmp = head;

    for(int i = 1; i < _size; i++)
    {
        tmp = tmp->nextNode;
    }

    if(_size > 0) return tmp->_value;

    else throw "queue is empty";
}

template<typename T>
void Queue<T>::push(T element)
{
    Node<T>* _element = new Node<T>(element);
    _element->nextNode = nullptr;

    if(_size == 0) head = _element;
    else
    {
        Node<T>* tmp = head;

        for(int i = 1; i < _size; i++)
        {
            tmp = tmp->nextNode;
        }

        tmp->nextNode = _element;

    }

    _size++;
}

template<typename T>
void Queue<T>::pop()
{
    if(_size > 0)
    {
        Node<T>* tmp = head;
        head = head->nextNode;

        delete tmp;

        _size--;
    }
    else throw "queue is empty";
}

template<typename T>
void Queue<T>::clear()
{
    Node<T>* tmp = head;
    Node<T>* tmp2 = nullptr;
    while(tmp)
    {
        tmp2 = tmp->nextNode;
        delete tmp;
        tmp = nullptr;
        tmp = tmp2;
    }

    _size = 0;
}

template<typename T>
void Queue<T>::insertAfterMax(Queue<T> &q2)
{
    int max_value = ((head) ? (head->_value) : 0);
    size_t max_index = 0;

    Node<T>* tmp = head;

    if(tmp)
    {
        for(int i = 1; i < _size; i++)
        {
            tmp = tmp->nextNode;

            if(tmp->_value > max_value)
            {
                max_value = tmp->_value;
                max_index = i;
            }
        }

        tmp = head;

        for(int i = 0; i < max_index; i++)
        {
            tmp = tmp->nextNode;
        }

        Node<T>* tmpContinuation;
        tmpContinuation = tmp->nextNode;

        Node<T>* tmp2 = q2.head;

        for(int i = 0; i < q2.size(); i++)
        {
            tmp->nextNode = new Node<T>(tmp2->_value);
            tmp->nextNode->nextNode = tmpContinuation;

            tmp2 = tmp2->nextNode;
            tmp = tmp->nextNode;
            tmpContinuation = tmp->nextNode;

            _size++;
        }
    }

    else
    {
        Node<T>* tmp2 = q2.head;

        for(int i = 0; i < q2.size(); i++)
        {
            push(tmp2->_value);

            tmp2 = tmp2->nextNode;
        }
    }


}

template<typename T>
void Queue<T>::print(QListWidget* list)
{
    Node<T>* tmp = head;

    list->clear();

    while(tmp)
    {
        list->addItem(QString::number(tmp->_value));
        tmp = tmp->nextNode;
    }

}
