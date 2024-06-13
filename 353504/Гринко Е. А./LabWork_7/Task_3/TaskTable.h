#ifndef TASKTABLE_H
#define TASKTABLE_H

#include <HashTable.h>
#include <QString>

class TaskTable : public IntHashTable<QString> {
public:
    // returns -1 if empty() == true
    size_t getIndexOfMin() {
        qint64 min = LONG_LONG_MIN;
        size_t index = -1;
        for (size_t i = 0; i < _size; ++i) {
            auto stack = _data[i];
            while (!stack.empty()) {
                if (stack.top().key < min) {
                    index = i;
                }
                stack.pop();
            }
        }
        return index;
    }

    Stack<IntHashTable<QString>::KeyData> getByInnerIndex(size_t index) {
        if (index >= _capacity) {
            throw std::out_of_range("Hash table");
        }
        return _data[index];
    }
};

#endif // TASKTABLE_H
