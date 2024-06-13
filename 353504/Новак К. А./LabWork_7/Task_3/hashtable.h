#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <cstddef>
#include <QString>
#include <QListWidget>

template<typename T>
class Stack{
private:
    struct Node{
        T value;
        int key;

        Node* next;

        Node(int key, T value) : key(key), value(value), next(nullptr){}
    };

    Node *head;

public:

    Stack() : head(nullptr){}
    Stack(Stack &other) : head(nullptr){
        if(other.head == nullptr){
            return;
        }

        head = new Node(other.head->key,other.head->value);
        head->next = other.head->next;
    }

    ~Stack()
    {
        clear();
    }

    void clear()
    {
        while (head) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(int key, T value){
        Node* newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
    }


    void pop(int &key, T &value)
    {
        while (head == nullptr) {
            return;
        }

        Node *temp = head;
        key = head->key;
        value = head->value;
        head = head->next;
        delete temp;
    }
    void pop(){
        if(head == nullptr){
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    bool empty()
    {
        return head == nullptr;
    }

};


template<typename T>
class HashTable
{
private:
    Stack<T> *table;
    size_t _size;

    int hashFunction(int key){
        return key % _size;
    }

public:
    explicit HashTable(size_t size) : table(new Stack<T>[size])
                                        , _size(size){}
    ~HashTable(){
        delete[] table;
    }

    size_t size() const{
        return _size;
    }

    void insert(int key, T value){
        int hash = hashFunction(key);
        table[hash].push(key, value);
    }

    T find(int key){
        Stack<T> currStack = table[hashFunction(key)];

        int tempKey = 0;
        T tempValue;

        while(!currStack.empty()){
            currStack.pop(tempKey, tempValue);

            if(tempKey == key){
                return tempValue;
            }
        }

        return nullptr;
    }

    void ToWidget(QListWidget &widget)
    {
        Stack<QString> tempStack;
        QString tempString;
        int tempKey = 0;
        T tempValue;

        for (size_t i = 0; i < HashTable<T>::size(); ++i) {
            tempString = QString::number(i) + ". ";
            tempStack = HashTable<T>::table[i];

            while (!tempStack.empty()) {
                tempStack.pop(tempKey, tempValue);
                tempString += "Key: " + QString::number(tempKey) + " Value: " + tempValue + " -> ";
            }
            widget.addItem(tempString);
        }
    }


};

#endif // HASHTABLE_H
