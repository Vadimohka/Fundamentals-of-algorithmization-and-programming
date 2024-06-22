#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QString>
#include <QVector>

class Stack {
public:
    struct Node {
        int key;
        QString value;
        Node* next;
        Node(int k, const QString& v) : key(k), value(v), next(nullptr) {}
    };

    Node* top;

    Stack() : top(nullptr) {}

    void push(int key, const QString& value) {
        Node* newNode = new Node(key, value);
        newNode->next = top;
        top = newNode;
    }

    bool pop(int& key, QString& value) {
        if (top == nullptr) return false;
        Node* temp = top;
        key = top->key;
        value = top->value;
        top = top->next;
        delete temp;
        return true;
    }

    bool find(int key, QString& value) {
        Node* current = top;
        while (current != nullptr) {
            if (current->key == key) {
                value = current->value;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    void clear() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    QString toString() const {
        QString result;
        Node* current = top;
        while (current != nullptr) {
            result += QString("(%1, %2) -> ").arg(current->key).arg(current->value);
            current = current->next;
        }
        result += "NULL";
        return result;
    }
};

class HashTable {
public:
    HashTable(int size);
    ~HashTable();

    void insert(int key, const QString& value);
    bool remove(int key);
    bool find(int key, QString& value);
    void clear();
    QString toString() const;

protected:
    int hashFunction(int key) const;
    int tableSize;
    Stack* table;

private:
    int hash(int key) const;
};

#endif // HASHTABLE_H
