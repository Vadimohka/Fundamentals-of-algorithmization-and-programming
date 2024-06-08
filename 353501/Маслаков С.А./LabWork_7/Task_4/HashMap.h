
#ifndef LAB7_HASHMAP_H
#define LAB7_HASHMAP_H
#include <cstddef>
#include <stdexcept>
#include <QIntegerForSize>
#include <vector>
#include <iostream>
#include <QString>
class HashMap {
public:
    struct Node {
        QString key;
        QString value;
        bool isOccupied;

        Node() : key(""), value(""), isOccupied(false) {}
    };
    Node* table;
    size_t numElements;

    size_t hash(const QString& key) const {
        size_t hashValue = 0;
        for (QChar ch : key) {
            hashValue = 37 * hashValue + ch.unicode();
        }
        return hashValue % size;
    }

    void rehash() {
        size_t oldSize = size;
        Node* oldTable = table;

        size *= 2;
        table = new Node[size];
        numElements = 0;

        for (size_t i = 0; i < oldSize; ++i) {
            if (oldTable[i].isOccupied) {
                insert(oldTable[i].key, oldTable[i].value);
            }
        }

        delete[] oldTable;
    }

public:
    size_t size;

    HashMap() : size(16), numElements(0) {
        table = new Node[size];
    }

    ~HashMap() {
        delete[] table;
    }

    void clear() {
        delete[] table;
        table = new Node[size];
        numElements = 0;
    }

    void remove(const QString& key) {
        size_t index = hash(key);
        size_t originalIndex = index;

        while (table[index].isOccupied) {
            if (table[index].key == key) {
                table[index].isOccupied = false;
                numElements--;
                return;
            }
            index = (index + 1) % size;
            if (index == originalIndex) {
                break;  // Avoid infinite loop
            }
        }
    }

    void insert(const QString& key, const QString& value) {
        if (numElements >= size / 2) {
            rehash();
        }
        size_t index = hash(key);
        while (table[index].isOccupied) {
            if (table[index].key == key) {
                table[index].value = value;
                return;
            }
            index = (index + 1) % size;
        }

        table[index].key = key;
        table[index].value = value;
        table[index].isOccupied = true;
        numElements++;
    }

    bool contains(const QString& key) const {
        size_t index = hash(key);
        size_t originalIndex = index;

        while (table[index].isOccupied) {
            if (table[index].key == key) {
                return true;
            }
            index = (index + 1) % size;
            if (index == originalIndex) {
                break;  // Avoid infinite loop
            }
        }

        return false;
    }

    QString& get(const QString& key) {
        size_t index = hash(key);
        size_t originalIndex = index;

        while (table[index].isOccupied) {
            if (table[index].key == key) {
                return table[index].value;
            }
            index = (index + 1) % size;
            if (index == originalIndex) {
                break;  // Avoid infinite loop
            }
        }

        throw std::out_of_range("Key not found");
    }
};
#endif // LAB7_HASHMAP_H

