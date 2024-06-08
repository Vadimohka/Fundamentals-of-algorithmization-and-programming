#ifndef NOTMYHASHTABLE_H
#define NOTMYHASHTABLE_H
#include "stack.h"
#include <QVector>
class HashTable
{
protected:
    int mod=3;
    QVector<stack<int>>table;

    bool prime(int x)
    {
        for(int i=2;i*i<=x;i++)
        {
            if(x%i==0)
                return false;
        }
        return true;
    }
    void updMod()
    {
        do{
            mod++;
        }while(!prime(mod));
    }
public:
    int hash(int key)
    {
        return key%mod;
    }
    HashTable(int tableSize)
    {
        mod=tableSize;
        updMod();
        table.resize(mod);
    }
    void insert(int key,int data)
    {
        table[hash(key)].push(data);
    }
    void remove(int key)
    {
        if(table[hash(key)].size()!=0)
            table[hash(key)].pop();
    }
    int size()
    {
        return mod;
    }
    void clear()
    {
        for(int i=0;i<mod;i++)
        {
            while(!table[i].empty())
                table[i].pop();
            //qDebug()<<table[i].size();
        }
    }
    stack<int>& at(int ind)
    {
        return table[ind];
    }
};
#endif // NOTMYHASHTABLE_H
