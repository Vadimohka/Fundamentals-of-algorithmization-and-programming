#include "nonegativestackhashtable.h"

NoNegativeStackHashTable::NoNegativeStackHashTable() {
    for(int i = 0; i < size; i++){
        table[i] = new Stack<int>();
    }
}

void NoNegativeStackHashTable::DeleteAllNegative()
{
    for(int i = 0; i < size; i++){
        if(table.at(i) != nullptr){
            int stackSize = table.at(i)->size();
            Stack<int> stack;

            for(int j = 0; j < stackSize; j++){
                int number = table.at(j)->pop();
                if(number > 0){
                    stack.put(number);
                }
            }
            delete table.at(i);
            table[i] = new Stack<int>();
            int newSizeStack = stack.size();
            for(int j = 0; j < newSizeStack; j++){
                table[j]->put(stack.pop());
            }
        }
    }
}

QString NoNegativeStackHashTable::stackToQString(int index)
{
    QString str = QString::number(index) + ".\t";
    if(table.at(index) != nullptr){
        int stackSize = table.at(index)->size();
        Stack<int> stack;

        for(int j = 0; j < stackSize; j++){
            int number = table.at(index)->pop();
            stack.put(number);
        }
        for(int j = 0; j < stackSize; j++){
            int number = stack.pop();
            str.push_back(QString::number(number) + '|');
            table[index]->put(number);
        }
    }
    str.push_back('\n');
    return str;
}
