#ifndef QUEUE_H
#define QUEUE_H

#include <QVector>

template<typename T>
class Deque
{
    struct Data
    {
        T info;
        Data *next = nullptr;
        Data *prev = nullptr;

        Data(const T &inf = T(), Data *next = nullptr, Data *prev = nullptr)
            : info(inf)
            , next(next)
            , prev(prev)
        {}
    };

    Data *head = nullptr;
    Data *tail = nullptr;

public:
    Deque(){};

    void push(const T &val) {
        Data *newData = new Data();
        newData->info = val;

        if (head == nullptr) {
            head = newData;
            tail = newData;
        } else {
            tail->next = newData;
            newData->prev = tail;
            tail = newData;
        }
    }

    T pop() {
        if (!head) throw "Queue is empty";
        Data *popData = head;
        head = head->next;

        if (head == nullptr)
            tail = nullptr;
        else
            head->prev = nullptr;

        return popData->info;
        delete popData;
    }

    void insertAtPosition(const T &val, int pos) {
        if (pos < 0 || pos > size()) {
            throw "Invalid position";
            return;
        } else if (pos == size()) {
            push(val);
            return;
        }

        Data *newData = new Data(val);
        if (pos == 0) {
            newData->next = head;
            head->prev = newData;
            head = newData;
            return;
        }

        Data* prev = nullptr;
        Data* curr = head;

        while (pos) {
            prev = curr;
            curr = curr->next;
            pos--;
        }

        newData->next = curr;
        curr->prev = newData;
        prev->next = newData;
        newData->prev = prev;
    }

    QVector<T> toVector()
    {
        QVector<T> result;
        Data *curr = head;
        while (curr) {
            result.push_back(curr->info);
            curr = curr->next;
        }
        return result;
    }

    virtual ~Deque()
    {
        while (!empty()) pop();
    }

    bool empty() const { return !head; }

    int size() const {
        int count = 0;
        Data *curr = head;
        while (curr) {
            ++count;
            curr = curr->next;
        }
        return count;
    }

    T &front() const {
        if (!head) {
            throw "Queue is empty";
        }
        return head->inf;
    }

    T &back() const {
        if (!tail) {
            throw "Queue is empty";
        }
        return tail->inf;
    }

    void clear() {
        while (!empty()) pop();
    }

    void findMinMax(Data **min, Data **max)
    {
        if (head == nullptr) {
            *min = *max = nullptr;
            return;
        }

        *min = *max = head;
        Data *curr = head;

        while (curr != nullptr) {
            if (curr->info < (*min)->info)
                *min = curr;
            if (curr->info > (*max)->info)
                *max = curr;
            curr = curr->next;
        }
    }

    void swapMinMax()
    {
        Data *min, *max;
        findMinMax(&min, &max);

        if (min == nullptr || max == nullptr)
            return;

        // Меняем значения без перемещения узлов
        std::swap(min->info, max->info);

        //        Data * temp;
        //        temp->next=min->next;
        //        temp->prev=min->prev;
        //        min->next=max->next;
        //        min->prev=max->prev;
        //        max->next=temp->next;
        //        max->prev=temp->prev;
        //        delete temp;
    }
};
#endif // QUEUE_H
