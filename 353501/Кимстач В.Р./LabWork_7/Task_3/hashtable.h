//
// Created by darina on 5/28/24.
//

#ifndef TASK3_HASHTABLE_H
#define TASK3_HASHTABLE_H
#include <string>
#include "Stack.h"
#include <vector>

class HashTable {

protected:
    int capacity = 0;
    Stack<int>* table;
    int all = 0;

private:

    int CalculateHash(int value)
    {
        return value % capacity;
    }

public:
    HashTable() {
        table = new Stack<int>[17];
        capacity = 17;
    };

    HashTable(int k)
    {
        table = new Stack<int>[k];
        capacity = k;
    }

    ~HashTable()
    {
        delete[] table;
    }

    void reserve(size_t n)
    {
        if(capacity >= n)
            return;
        auto temp = new Stack<int> [n];
        for(int i = 0; i < capacity; i ++)
        {
            while(table[i].size() != 0)
            {
                int data = table[i].pop();
                int index = data % n;
                temp[index].push(data);
            }
        }
        table = temp;
        capacity = n;
    }

    void InsertValue(int value)
    {
        if(all == capacity)
            reserve(capacity * 2 + 1);
        int _index = CalculateHash(value);

        Stack<int> temp;
        while(table[_index].size() != 0)
        {
            if(table[_index].top() == value)
            {
                while(!temp.empty())
                {
                    table[_index].push(temp.pop());
                }
                return;
            }
            temp.push(table[_index].pop());
        }
        while(!temp.empty())
        {
            table[_index].push(temp.pop());
        }
        all ++;
        table[_index].push(value);
    }

    bool RemoveValue(int value)
    {
        int _index = CalculateHash(value);

        Stack<int> temp;
        while(table[_index].size() != 0)
        {
            if(table[_index].top() == value)
            {
                table[_index].pop();
                while(!temp.empty())
                {
                    table[_index].push(temp.pop());
                }
                all --;
                return true;
            }
            temp.push(table[_index].pop());
        }
        while(!temp.empty())
        {
            table[_index].push(temp.pop());
        }
        return false;
    }

    bool FindValue(int value)
    {
        int _index = CalculateHash(value);

        Stack<int> temp;
        while(table[_index].size() != 0)
        {
            if(table[_index].top() == value)
            {
                while(!temp.empty())
                {
                    table[_index].push(temp.pop());
                }
                return true;
            }
            temp.push(table[_index].pop());
        }
        while(!temp.empty())
        {
            table[_index].push(temp.pop());
        }
        return false;
    }

};


#endif //TASK3_HASHTABLE_H
