#include "extendedhashtable.h"
#include <numeric>

ExtendedHashTable::ExtendedHashTable(int size) : HashTable(size) {}

float ExtendedHashTable::calculateAverage() const {
    int totalKeys = 0;
    int sum = 0;

    for (int i = 0; i < tableSize; ++i) {
        Stack::Node* current = table[i].top;
        while (current != nullptr) {
            sum += current->key;
            totalKeys++;
            current = current->next;
        }
    }

    if (totalKeys == 0) return 0;
    return static_cast<float>(sum) / totalKeys;
}

int ExtendedHashTable::countKeysAboveAverage() const {
    float average = calculateAverage();
    int count = 0;

    for (int i = 0; i < tableSize; ++i) {
        Stack::Node* current = table[i].top;
        while (current != nullptr) {
            if (current->key > average) {
                count++;
            }
            current = current->next;
        }
    }

    return count;
}
