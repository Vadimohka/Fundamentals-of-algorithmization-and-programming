#include "derivedhashtable.h"
#include <limits>

DerivedHashTable::DerivedHashTable(int size) : HashTable(size) {}

int DerivedHashTable::getStackWithMaxKey() const {
    int maxKey = std::numeric_limits<int>::min();
    int maxStackIndex = -1;

    for (int i = 0; i < getSize(); ++i) {
        Stack stack = getStack(i);
        std::vector<KeyValuePair> elements = stack.getElements();
        for (const auto& elem : elements) {
            if (elem.key > maxKey) {
                maxKey = elem.key;
                maxStackIndex = i;
            }
        }
    }

    return maxStackIndex;
}
