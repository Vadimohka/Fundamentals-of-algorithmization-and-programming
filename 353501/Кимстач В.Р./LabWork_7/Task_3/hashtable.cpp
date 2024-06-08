// #include "hashtable.h"

// HashTable::HashTable(int V) {
//     capacity = getNextPrime(V);
//     table.resize(capacity);
// }

// bool HashTable::isPrime(int n) {
//     if (n <= 1)
//         return false;
//     for (int i = 2; i * i <= n; i++) {
//         if (n % i == 0)
//             return false;
//     }
//     return true;
// }

// int HashTable::getNextPrime(int n) {
//     while (!isPrime(n))
//         n++;
//     return n;
// }

// int HashTable::hashFunction(int key) {
//     return key % capacity;
// }

// void HashTable::insertItem(int key, int data) {
//     int index = hashFunction(key);
//     int originalIndex = index;

//     // Применяем линейное зондирование
//     while (table[index].occupied) {
//         index = (index + 1) % capacity;
//         if (index == originalIndex) {
//             // Таблица заполнена, нет места для нового элемента
//             return;
//         }
//     }

//     table[index].key = key;
//     table[index].data = data;
//     table[index].occupied = true;
// }

// void HashTable::deleteItem(int key) {
//     int index = hashFunction(key);
//     int originalIndex = index;

//     // Применяем линейное зондирование
//     while (table[index].occupied && table[index].key != key) {
//         index = (index + 1) % capacity;
//         if (index == originalIndex) {
//             // Элемент не найден
//             return;
//         }
//     }

//     if (table[index].occupied && table[index].key == key) {
//         table[index].occupied = false;
//     }
// }

// QVector<QVector<int>> HashTable::displayHash() {
//     QVector<QVector<int>> result;
//     for (int i = 0; i < capacity; i++) {
//         QVector<int> slotContent;
//         if (table[i].occupied) {
//             slotContent.append(table[i].key);
//             slotContent.append(table[i].data);
//         }
//         result.append(slotContent);
//     }
//     return result;
// }

// void HashTable::clear() {
//     for (auto & i : table) {
//         i.occupied = false;
//     }
// }

// struct HashTableEntry {
//     int key;
//     int data;
//     bool occupied = false;
// };
