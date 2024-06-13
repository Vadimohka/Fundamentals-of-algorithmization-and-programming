#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QTextEdit>
#include <MyLinkedList.h>
#include <cstdlib>

template<typename T>
class HashTable {
private:
    static const size_t INITIAL_TABLE_SIZE = 101;
    const double MAX_LOAD_FACTOR = 0.7;

    LinkedList<T>* table;
    size_t tableSize;
    size_t _size{};

    size_t hashFunction(int key) const {
        return static_cast<size_t>(key) % tableSize;
    }

    size_t nextPrime(size_t n) {
        static const int primes[] = {
            101, 211, 317, 521, 719, 1031, 1543, 2053, 3079, 6151,
            12289, 24593, 49157, 98317, 196613, 393241, 786433, 1572869,
            3145739, 6291469, 12582917, 25165843, 50331653, 100663319
        };

        for (size_t prime : primes) {
            if (prime > n) {
                return prime;
            }
        }

        return n * 2 + 1;
    }

    void rehash() {
        LinkedList<T>* oldTable = table;
        size_t oldTableSize = tableSize;

        tableSize = nextPrime(tableSize * 2);
        table = new LinkedList<T>[tableSize];

        for (size_t i = 0; i < oldTableSize; ++i) {
            for (const T& value : oldTable[i]) {
                insert(-1, value);
            }
        }

        delete[] oldTable;
    }

public:
    HashTable() : tableSize(INITIAL_TABLE_SIZE) {
        table = new LinkedList<T>[tableSize];
    }

    ~HashTable() {
        clear();
        delete[] table;
    }

    void insert(int key, T value) {
        size_t index = hashFunction(key);
        if (!table[index].contains(value)) {
            table[index].push(value);
            _size++;
            if (_size > tableSize * MAX_LOAD_FACTOR) {
                rehash();
            }
        }
    }

    bool contains(int key, T value) {
        size_t index = hashFunction(key);
        return table[index].contains(value);
    }

    void remove(int key, T value) {
        size_t index = hashFunction(key);
        if (table[index].contains(value)) {
            table[index].remove(value);
            _size--;
        }
    }

    bool isEmpty() const {
        return _size == 0;
    }

    void clear() {
        for (size_t i = 0; i < tableSize; ++i) {
            table[i].clear();
        }
        _size = 0;
    }

    void print(QTextEdit* text_edit) {
        QString res = "";
        text_edit->clear();
        for (size_t i = 0; i < tableSize; ++i) {
            if (!table[i].isEmpty())
            {
                std::string valueStr = table[i].toString().toStdString();
                res += "key: " + std::to_string(i) + " value: " + valueStr + "\n";
            }
            else
            {
                res += "key: " + std::to_string(i) + " value: " + "\n";
            }
        }
        text_edit->setText(res);
    }
};

#endif // HASHTABLE_H
