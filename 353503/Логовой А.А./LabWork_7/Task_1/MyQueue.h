#ifndef MYQUEUE_H
#define MYQUEUE_H
#include<cstdint>
#include<stdexcept>
#include<QString>
template<typename T>
class Queue{

private:
    struct QueueNode {
        T data;
        QueueNode* next;
        QueueNode* prev;
    };

    QueueNode* _front;
    QueueNode* _end;
    int64_t _size{};
public:

    Queue() : _front(nullptr), _end(nullptr){

    }

    ~Queue() {
        clear();
        _front = nullptr;
    }

    bool isEmpty() const{
        return _size == 0;
    }

    void push_front(T element) {
        QueueNode* node = new QueueNode();
        node->data = element;
        node->prev = nullptr;

        if (_front == nullptr)
        {
            _front = _end = node;
        }
        else
        {
            node->next = _front;
            _front->prev = node;
            _front = node;
        }

        _size++;
    }

    void push_back(T element){
        QueueNode* node = new QueueNode();
        node->data = element;
        node->next = nullptr;
        if(_front == nullptr)
        {
            _front = _end =  node;
        }
        else
        {
            _end->next = node;
            _end = node;
        }
        _size++;
    }

    const T& front(){
        if(_front == nullptr){ throw std::out_of_range("you are out of the range"); }

        return _front->data;
    }

    const T& back() {
        if(_front == nullptr){ throw std::out_of_range("you are out of the range"); }

        return _end->data;
    }

    void pop_back() {
        if (_size == 0)
        {
            throw std::out_of_range("Queue is empty.");
        }
        QueueNode* temp = _front;
        _front = _front->next;
        if (_front)
        {
            _front->prev = nullptr;
        }
        else
        {
            _end = nullptr;
        }
        delete temp;
        _size--;
    }

    void pop_front() {
        if (_size == 0) {
            throw std::out_of_range("Queue is empty.");
        }
        QueueNode* temp = _front;
        _front = _front->next;
        if (_front)
        {
            _front->prev = nullptr;
        }
        else
        {
            _end = nullptr;
        }
        delete temp;
        _size--;
    }

    const T& previous() {
        if (_end == nullptr) {
            throw std::out_of_range("you are out of the range");
        }
        if (_end->prev == nullptr) {
            throw std::out_of_range("there is no previous element");
        }
        return _end->prev->data;
    }

    void swap(Queue& other){
        QueueNode* temp_front = other._front;
        QueueNode* temp_end = other._end;
        int64_t temp_size = other.size();

        other._front = _front;
        other._end = _end;
        other._size = _size;

        _front = temp_front;
        _end = temp_end;
        _size = temp_size;
    }

    void clear() {
        while (_front) {
            QueueNode* temp = _front;
            _front = _front->next;
            delete temp;
        }
        _end = nullptr;
        _size = 0;
    }

    QString print() const{
        QString result = "";
        QueueNode* temp = _front;
        while (temp)
        {
            result += QString::number(temp->data) + " ";
            temp = temp->next;
        }
        return result;
    }

    int64_t size() const{
        return _size;
    }

    void removeDuplicates() {
        if (_size <= 1 || !_front) {
            return;
        }

        QueueNode* current = _front;
        while (current) {
            QueueNode* runner = current->next;
            while (runner) {
                if (runner->data == current->data) {
                    QueueNode* temp = runner;
                    runner = runner->next;
                    if (runner) {
                        runner->prev = temp->prev;
                    } else {
                        _end = temp->prev;
                    }
                    if (temp->prev) {
                        temp->prev->next = runner;
                    } else {
                        _front = runner;
                    }
                    delete temp;
                    _size--;
                } else {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }

    void swapMinMax() {
        if (_size <= 1 || !_front) {
            return;
        }

        T maxElement = _front->data;
        T minElement = _front->data;
        QueueNode* current = _front;

        while (current) {
            maxElement = std::max(maxElement, current->data);
            minElement = std::min(minElement, current->data);
            current = current->next;
        }

        QueueNode* maxNode = nullptr;
        QueueNode* minNode = nullptr;
        current = _front;

        while (current) {
            if (current->data == maxElement) {
                maxNode = current;
            }
            if (current->data == minElement) {
                minNode = current;
            }
            current = current->next;
        }

        std::swap(maxNode->data, minNode->data);
    }

};

#endif // MYQUEUE_H
