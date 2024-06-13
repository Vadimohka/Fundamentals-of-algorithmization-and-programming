#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QString>
#include <QVector>
#include <QPair>
#include <QRandomGenerator>
#include <random>


struct Data {
    int key;
    QString value;
    bool isOccupied;
    bool isDeleted;
};

class HashTable {
private:
    int tableSize;
    QVector<Data> table;
    QVector<int> collisionIndices;
    int a, b;
    static const int p = 3079;
    std::mt19937 gen;
public:
    HashTable(int size) : tableSize(size), gen(std::random_device{}()) {
        table.resize(tableSize);
        for (int i = 0; i < tableSize; ++i) {
            table[i].isOccupied = false;
            table[i].isDeleted = false;
        }

        std::uniform_int_distribution<> disA(1, p - 1);
        std::uniform_int_distribution<> disB(0, p - 1);
        a = disA(gen);
        b = disB(gen);
    }

    int hashFunction(int key) {
        //  (a * key + b) % p % tableSize
        long long hash = static_cast<long long>(a) * key + b;
        hash %= p;
        return static_cast<int>(hash % tableSize);
    }

    void resizeTable() {
        int newSize = nextPrime(tableSize * 1.5);
        QVector<Data> newTable(newSize);

        for (int i = 0; i < newSize; ++i) {
            newTable[i].isOccupied = false;
            newTable[i].isDeleted = false;
        }

        for (const Data& entry : table) {
            if (entry.isOccupied && !entry.isDeleted) {
                int index = hashFunction(entry.key);
                while (newTable[index].isOccupied) {
                    index = (index + 1) % newSize;
                }
                newTable[index] = entry;
            }
        }

        table = std::move(newTable);
        tableSize = newSize;
    }

    int nextPrime(int n) {
        while (true) {
            bool isPrime = true;
            for (int i = 2; i * i <= n; ++i) {
                if (n % i == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                return n;
            }
            ++n;
        }
    }

    void add(int key, const QString& value) {
        int loadFactor = std::count_if(table.begin(), table.end(), [](const Data& entry) {
            return entry.isOccupied && !entry.isDeleted;
        });

        if (loadFactor > tableSize * 0.75) {
            resizeTable();
        }

        int index = hashFunction(key);
        bool collisionOccurred = false;
        while (table[index].isOccupied) {
            if (!collisionOccurred) {
                collisionIndices.push_back(index);
                collisionOccurred = true;
            }
            index = (index + 1) % tableSize;
        }

        table[index] = {key, value, true, false};
    }

    QString find(int key) {
        int index = hashFunction(key);
        int originalIndex = index;

        while (table[index].isOccupied || table[index].isDeleted) { // Изменено здесь
            if (!table[index].isDeleted && table[index].key == key) {
                return table[index].value;
            }
            index = (index + 1) % tableSize;
            if (index == originalIndex) {
                break;
            }
        }
        return QString();
    }

    void remove(int key) {
        int index = hashFunction(key);

        while (table[index].isOccupied) {
            if (!table[index].isDeleted && table[index].key == key) {

                table[index].isDeleted = true;
                return;
            }
            index = (index + 1) % tableSize;
        }
    }

    void clear() {
        for (int i = 0; i < tableSize; ++i) {
            table[i].isOccupied = false;
            table[i].isDeleted = false;
        }
    }

    unsigned int generateRandomNumber()
    {
        return QRandomGenerator::global()->bounded(10000);
    }

    QString generateRandomString(unsigned int length)
    {
        QString randomString;
        static const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                       "abcdefghijklmnopqrstuvwxyz";

        for (unsigned int i = 0; i < length; ++i) {
            randomString
                += alphanum[QRandomGenerator::global()->bounded(static_cast<int>(sizeof(alphanum) - 1))];
        }

        return randomString;
    }

    void fillWithRandomData(int numEntries)
    {
        for (int i = 0; i < numEntries; ++i) {
            add(generateRandomNumber(), generateRandomString(10));
        }
    }

    QVector<QVector<QPair<int, QString>>> displayHash() {
        QVector<QVector<QPair<int, QString>>> result(tableSize);

        for (int i = 0; i < tableSize; i++) {
            if (table[i].isOccupied && !table[i].isDeleted) {

                result[i].append(qMakePair(table[i].key, table[i].value));
            }

        }
        return result;
    }

    int getSize() const {
        return tableSize;
    }
    QVector<int> getCollisionIndices() const {
        return collisionIndices;
    }
};


#endif // HASHTABLE_H
