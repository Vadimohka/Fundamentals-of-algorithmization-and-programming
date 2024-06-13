#include <QVector>
#include "stack.h"

class HashTable {
protected:
    int capacity;
    QVector<Stack> table;

    bool isSimple(int n);
    int nextSimpleNumber(int n);
    int hashFunction(int key);

public:
    HashTable(int V);
    void insertItem(int key, int data);
    void deleteItem(int key);
    QVector<QVector<QPair<int, int>>> hashTableToVector();
    void clear();
    int get(int key);
};

