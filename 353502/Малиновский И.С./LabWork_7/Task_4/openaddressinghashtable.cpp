#include "openaddressinghashtable.h"
#include <cmath>

OpenAddressingHashTable::OpenAddressingHashTable(int size) : table(size) {}

int OpenAddressingHashTable::hash(int key) {
    static const double A = 0.6180339887499; // Коэффициент A
    return static_cast<int>(table.size() * (key * A - static_cast<int>(key * A)));
}

void OpenAddressingHashTable::insert(int key, const std::string& value) {
    int index = hash(key);
    while (table[index].key != 0) {
        index = (index + 1) % table.size();
    }
    table[index] = {key, value, false};
}

bool OpenAddressingHashTable::search(int key, std::string& value) {
    int index = hash(key);
    while (table[index].key != 0) {
        if (table[index].key == key && !table[index].deleted) {
            value = table[index].value;
            return true;
        }
        index = (index + 1) % table.size();
    }
    return false;
}

void OpenAddressingHashTable::remove(int key) {
    int index = hash(key);
    while (table[index].key != 0) {
        if (table[index].key == key && !table[index].deleted) {
            table[index].deleted = true;
            return;
        }
        index = (index + 1) % table.size();
    }
}
