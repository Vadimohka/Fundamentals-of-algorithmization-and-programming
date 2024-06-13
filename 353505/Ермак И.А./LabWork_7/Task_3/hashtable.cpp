#include "hashtable.h"
#include <sstream>
#include <stdexcept>

HashTable::HashTable(int size) : tableSize(size), table(size) {}

void HashTable::insert(int key, int value) {
    int index = hashFunction(key);
    Stack& stack = table[index];


    std::vector<KeyValuePair> elements = stack.getElements();
    for (const auto& elem : elements) {
        if (elem.key == key) {
            return;
        }
    }

    stack.push({key, value});
}

void HashTable::remove(int key) {
    int index = hashFunction(key);
    Stack& stack = table[index];
    std::vector<KeyValuePair> elements = stack.getElements();
    stack = Stack();
    for (const auto& elem : elements) {
        if (elem.key != key) {
            stack.push(elem);
        }
    }
}

int HashTable::getValue(int key) const {
    int index = hashFunction(key);
    const Stack& stack = table[index];
    std::vector<KeyValuePair> elements = stack.getElements();
    for (const auto& elem : elements) {
        if (elem.key == key) {
            return elem.value;
        }
    }
    throw std::runtime_error("Key not found");
}

Stack HashTable::getStack(int index) const {
    if (index >= 0 && index < tableSize) {
        return table[index];
    }
    return Stack();
}

std::string HashTable::toString() const {
    std::ostringstream oss;
    for (int i = 0; i < tableSize; ++i) {
        oss << "Stack " << i << ": ";
        Stack stack = table[i];
        std::vector<KeyValuePair> elements = stack.getElements();
        for (const auto& elem : elements) {
            oss << "{" << elem.key << ", " << elem.value << "} ";
        }
        oss << "\n";
    }
    return oss.str();
}

int HashTable::getSize() const {
    return tableSize;
}

int HashTable::hashFunction(int key) const {
    return key % tableSize;
}
