#include "hashtable.h"
#include <iostream>

HashTable::HashTable(int size) : table(size) {}

HashTable::~HashTable() {}

void HashTable::insert(int key, const std::string& value) {
    int index = hash(key);
    table[index].push(value);
}

bool HashTable::search(int key, std::string& value) const {
    int index = hash(key);
    if (!table[index].empty()) {
        value = table[index].top();
        return true;
    }
    return false;
}

void HashTable::remove(int key) {
    int index = hash(key);
    if (!table[index].empty()) {
        table[index].pop();
    }
}

void HashTable::clear() {
    for (auto& stack : table) {
        while (!stack.empty()) {
            stack.pop();
        }
    }
}

void HashTable::print() const {
    for (size_t i = 0; i < table.size(); ++i) {
        std::cout << "Bucket " << i << ": ";
        std::stack<std::string> temp = table[i];
        while (!temp.empty()) {
            std::cout << temp.top() << " ";
            temp.pop();
        }
        std::cout << std::endl;
    }
}

int HashTable::hash(int key) const {
    // Простая хеш-функция: берем остаток от деления на размер таблицы
    return key % table.size();
}
