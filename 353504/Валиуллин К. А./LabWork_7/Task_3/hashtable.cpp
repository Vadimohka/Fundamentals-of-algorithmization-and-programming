#include "hashtable.h"

void HashTable::push(int key, int value) {
    int index = hashFunction(key);
    table[index].push(value);
}

bool HashTable::pop(int key, int &value) {
    int index = hashFunction(key);
    if (!table[index].isEmpty()) {
        value = table[index].pop();
        return true;
    }
    return false;
}

void HashTable::clear() {
    for (auto &stack : table) {
        stack.clear();
    }
}

QString HashTable::print() const {
    QString result;
    for (int i = 0; i < table.size() ; ++i) {
        if (!table[i].isEmpty()) {
            result += "Ключ: " + QString::number(i - 10) + ":";
            QStack<int> temp = table[i];
            while (!temp.isEmpty()) {
                result += " " + QString::number(temp.pop());
            }
            result += "\n";
        }
    }
    return result;
}

int HashTable::hashFunction(int key) const {
    return (key + 10) % table.size();
}
