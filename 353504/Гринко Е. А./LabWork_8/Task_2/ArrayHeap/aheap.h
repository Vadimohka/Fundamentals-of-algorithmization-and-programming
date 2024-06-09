#ifndef AHEAP_H
#define AHEAP_H

#include <QtCore>

template <class T>
class AHeap
{
private:
    struct HeapElement
    {
    public:
        HeapElement(const T& val, int prio) : value(val), priority(prio) {}
        HeapElement(T&& val, int prio) : value(std::move(val)), priority(prio) {}

        T value;
        int priority;

        bool operator>(const HeapElement& other) const {
            return priority > other.priority;
        }
        bool operator<(const HeapElement& other) const {
            return priority < other.priority;
        }
    };

    QVector<HeapElement> _tree;

    //-----------------------------------------------------------------

    void siftUp(size_t index) {
        if (index >= _tree.size()) {
            return;
        }
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (_tree.at(index) > _tree.at(parentIndex)) {
                std::swap(_tree[index], _tree[parentIndex]);
                index = parentIndex;
            } else {
                return;
            }
        }
    }

    void siftDown(size_t index) {
        if (index >= _tree.size()) {
            return;
        }
        while (index * 2 + 1 < _tree.size()) {
            int kid = index * 2 + 1;
            if (kid + 1 < _tree.size() && _tree.at(kid) < _tree.at(kid + 1)) {
                ++kid;
            }
            if (_tree.at(index) < _tree.at(kid)) {
                std::swap(_tree[index], _tree[kid]);
                index = kid;
            } else {
                return;
            }
        }
    }

    //-----------------------------------------------------------------

public:
    AHeap() = default;

    //-----------------------------------------------------------------

    template <class TT>
    void add(int priority, TT&& value) {
        _tree.emplace_back(std::forward<TT>(value), priority);
        siftUp(_tree.size() - 1);
    }

    T& getMax() {
        if (_tree.empty()) {
            throw std::out_of_range("Heap is empty");
        }
        return _tree.front().value;
    }

    void pop() {
        if (_tree.empty()) {
            return;
        }
        _tree.front() = std::move(_tree.back());
        _tree.pop_back();
        siftDown(0);
    }

    //-----------------------------------------------------------------

    int setPriority(size_t index, int newPriority) {
        if (index >= _tree.size()) {
            throw std::out_of_range("Wrong index in the heap");
        }
        int formerPriority =  _tree.at(index).priority;
        _tree[index].priority = newPriority;
        if (formerPriority > newPriority) {
            siftDown(index);
        } else {
            siftUp(index);
        }
        return newPriority;
    }

    int getPriority(size_t index) {
        if (index >= _tree.size()) {
            throw std::out_of_range("Wrong index in the heap");
        }
        return _tree.at(index).priority;
    }

    //-----------------------------------------------------------------

    const T& operator[](size_t index) const {
        if (index >= _tree.size()) {
            throw std::out_of_range("Wrong index in the heap");
        }
        return _tree[index].value;
    }
    T& operator[](size_t index) {
        if (index >= _tree.size()) {
            throw std::out_of_range("Wrong index in the heap");
        }
        return _tree[index].value;
    }

    //-----------------------------------------------------------------
};

#endif // AHEAP_H
