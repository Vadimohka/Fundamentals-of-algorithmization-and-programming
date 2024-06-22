#include "hashtable.h"

HashTable::HashTable(int size) : tableSize(size) {
    table = new Stack[tableSize];
}

HashTable::~HashTable() {
    clear();
    delete[] table;
}

void HashTable::insert(int key, const QString& value) {
    int index = hashFunction(key);
    table[index].push(key, value);
}

bool HashTable::remove(int key) {
    int index = hashFunction(key);
    Stack::Node* current = table[index].top;
    Stack::Node* prev = nullptr;

    while (current != nullptr) {
        if (current->key == key) {
            if (prev == nullptr) {
                table[index].top = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

bool HashTable::find(int key, QString& value) {
    int index = hashFunction(key);
    return table[index].find(key, value);
}

void HashTable::clear() {
    for (int i = 0; i < tableSize; ++i) {
        table[i].clear();
    }
}

QString HashTable::toString() const {
    QString result;
    for (int i = 0; i < tableSize; ++i) {
        result += QString("Bucket %1: %2\n").arg(i).arg(table[i].toString());
    }
    return result;
}

int HashTable::hashFunction(int key) const {
    return key % tableSize;
}
