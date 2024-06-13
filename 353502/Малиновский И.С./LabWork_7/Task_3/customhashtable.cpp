#include "customhashtable.h"

CustomHashTable::CustomHashTable(int size) : HashTable(size) {}

void CustomHashTable::removeNegativeKeys() {
    for (size_t i = 0; i < table.size(); ++i) {
        if (i == 0) {
            removeNegativeKeys(i);
        }
    }
}

void CustomHashTable::removeNegativeKeys(int index) {
    while (!table[index].empty()) {
        table[index].pop();
    }
}
