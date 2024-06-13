#include "bitset.h"

BitSet::BitSet(int size,int number)
{
    this -> size = size;
    this -> number = number;

    int temp = number;

    for(int i = 0;i < size; ++i)
    {
        array.push_back(temp % 2);
        temp = temp / 2;
    }
    std::reverse(array.begin(), array.end());

}

int BitSet::getSize() {
    return size;
}

bool BitSet::all()
{
    for(int i = 0;i < size; ++i)
    {
        if(array[i]==0) {
            return false;
        }

    }
    return true;
}
bool BitSet::any()
{
    for(int i=0;i<size;++i)
    {
        if(array[i]==1) {
            return true;
        }
    }

    return false;
}
void BitSet::flip(int index)
{
    if(index == size)
    {
         for(int i = 0;i < size; ++i)
        {
            if(array[i] == 1) {
                array[i] = 0;
            }
            else {
                array[i]=1;
            }
        }
    }
    else if (index < size)
    {
        if(array[index] == 1) {
            array[index] = 0;
        }

        else {
            array[index] = 1;
        }
    }
}

bool BitSet::none()
{
    for(int i=0;i<size;++i)
    {
        if(array[i]==1){
            return true;
        }
    }

    return false;
}
void BitSet::set(int index)
{
    if(index==size)
    {
        for(int i=0;i<size;++i)
        {
            if(array[i] == 1) {
                array[i] = 0;
            }

            else array[i] = 1;
        }
    }

    else if(index < size)
    {
        if(array[index] == 1) {
            array[index] = 0;
        }

        else {
            array[index] = 1;
        }
    }
}

bool BitSet::test(int index)
{
    if(index<size)
    {
        if(array[index]==1){

            return true;
        }
    }

    return false;
}
QString BitSet::to_string()
{
    QString str;
    for(int i = size-1; i > 0;--i)
    {
        if(array[i]==1){
            str.push_back('1');
        }

        else{

            str.push_back('0');
        }
    }
    return str;
}
unsigned long long BitSet::to_ullong()
{
    unsigned long long number = 0;

    for(int i = size - 1; i > 0; --i)
    {
        number += array[i]*pow(2,i);
    }
    return number;
}
unsigned long BitSet::to_ulong()
{
    unsigned long number = 0;

    for(int i = size - 1; i > 0; --i)
    {
        number += array[i]*pow(2,i);
    }
    return number;
}
bool BitSet::operator[](int index)  {
    return test(index);
}
