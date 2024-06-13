#ifndef AHEAP_H
#define AHEAP_H

#include <QtCore>

template<typename T>
class AHeap
{
private:
    struct Element{
        T value;
        int priority;

        Element(int prio, const T val) : priority(prio), value(val){}
        Element(int prio, T&& val) : priority(prio), value(std::move(value)) {}


        bool operator>(const Element& other) const {
            return priority > other.priority;
        }
        bool operator<(const Element& other) const {
            return priority < other.priority;
        }
    };

    QVector<Element> _tree;

    void siftUp(size_t ptr){
        if(ptr >= _tree.size()){
            return;
        }

        while(ptr >= 1){
            if(_tree.at(ptr) > _tree.at((ptr - 1) / 2)){
                std::swap(_tree.at(ptr), _tree.at((ptr - 1) / 2));
                ptr = (ptr - 1) / 2;
            }
            else{
                return;
            }
        }
    }

    void siftDown(size_t ptr){
        if(ptr >= _tree.size()){
            return;
        }

        while(ptr * 2 + 1 < _tree.size()){
            int kid = ptr * 2 + 1;

            if(kid + 1 < _tree.size() && _tree.at(kid) < _tree.at(kid + 1)){
                ++kid;
            }
            if(_tree.at(ptr) < _tree.at(kid)){
                std::swap(_tree.at(ptr), _tree.at(kid));
                ptr = kid;
            }
            else{
                return;
            }
        }
    }


public:
    AHeap() = default;

    template <class TT>
    void add(int priority, TT&& value) {
        _tree.emplace_back(std::forward<TT>(value), priority);
        siftUp(_tree.size() - 1);
    }

    T& getMax() {
        if (_tree.empty()) {
            return;
        }
        return _tree.front().value;
    }

    void popMax() {
        if (_tree.empty()) {
            return;
        }
        _tree.front() = std::move(_tree.back());
        _tree.pop_back();
        siftDown(0);
    }

    void setPriority(size_t index, int newPriority) {
        if (index >= _tree.size()) {
            return;
        }
        int formerPriority =  _tree.at(index).priority;
        _tree[index].priority = newPriority;
        if (formerPriority > newPriority) {
            siftDown(index);
        } else {
            siftUp(index);
        }
    }

    int getPriority(size_t index) {
        if (index >= _tree.size()) {
            return 0;
        }
        return _tree.at(index).priority;
    }


};

#endif // AHEAP_H
