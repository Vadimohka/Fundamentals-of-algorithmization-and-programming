#include "bitset.h"

bitset::bitset(int size,int a)
{
    this->size=size;
    this->a=a;
    int k=a;
    for(int i=0;i<size;++i)
    {
        initial.push_back(k%2);
        k=k/2;
    }
    std::reverse(initial.begin(), initial.end());

}
bitset::~bitset() {

}


int bitset::getSize() {
    return size;
}
bool bitset::all()
{
    for(int i=0;i<size;++i)
    {
        if(initial[i]==0) return false;
    }
    return true;
}
bool bitset::any()
{
    for(int i=0;i<size;++i)
    {
        if(initial[i]==1) return true;
    }
    return false;
}
void bitset::flip(int k)
{
    if(k==size)
    {
         for(int i=0;i<size;++i)
        {
            if(initial[i]==1) initial[i]=0;
            else initial[i]=1;
        }
    }
    else if (k<size)
    {
        if(initial[k]==1) initial[k]=0;
        else initial[k]=1;
    }
}

bool bitset::none()
{
    for(int i=0;i<size;++i)
    {
        if(initial[i]==1) return true;
    }
    return false;
}
void bitset::set(int k)
{
    if(k==size)
    {
        for(int i=0;i<size;++i)
        {
            if(initial[i]==1) initial[i]=0;
            else initial[i]=1;
        }
    }
    else if(k<size)
    {
        if(initial[k]==1) initial[k]=0;
        else initial[k]=1;
    }
}

bool bitset::test(int k) const
{
    if(k<size)
    {
        if(initial[k]==1) return true;
    }
    return false;
}
QString bitset::to_string()
{
    QString h;
    for(int i=size-1;i>0;--i)
    {
        if(initial[i]==1) h.push_back('1');
        else h.push_back('0');
    }
    return h;
}
unsigned long long bitset::to_ullong()
{
    unsigned long long h=0;
    for(int i=size-1;i>0;--i)
    {
        h+=initial[i]*pow(2,i);
    }
    return h;
}
unsigned long bitset::to_ulong()
{
    unsigned long h=0;
    for(int i=size-1;i>0;--i)
    {
        h+=initial[i]*pow(2,i);
    }
    return h;
}
bool bitset::operator[](int pos)const  {
    return test(pos);
}
bool& bitset::operator[](int pos) {
    static bool ex;
    if (pos < 0 || pos >= size)
        return ex;
    return reinterpret_cast<bool&>(initial[pos / 2] |= (1 << (pos % 2)));
}
