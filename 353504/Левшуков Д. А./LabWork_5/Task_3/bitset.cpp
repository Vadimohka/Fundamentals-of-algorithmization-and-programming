#include "bitset.h"
#include <QDebug>

unsigned long long *bitset::data()
{
    return data_;
}

int bitset::size()
{
    return size_;
}

void bitset::resize(int newSize)
{
    if(capacity<(newSize+BLOCK-1)/BLOCK)
        capacity=(newSize+BLOCK-1)/BLOCK;

    unsigned long long *tmp=new unsigned long long[capacity];

    for(int i=0;i<size_/BLOCK;i++)
        tmp[i]=data_[i];
    for(int i=size_/BLOCK;i<capacity;i+=BLOCK)
        tmp[i]=0;

    delete[] data_;
    data_ = new unsigned long long[capacity];
    size_ = newSize;

    for(int i=0;i<capacity;i++)
        data_[i]=tmp[i];
    delete[]tmp;

}

bitset::bitset(int size)
{
    capacity=(size+BLOCK-1)/BLOCK;
    data_ = new unsigned long long[capacity];

    for(int i=0;i<size;i++)
        data_[i]=0;

    this->size_=size;
}

bitset::~bitset()
{
    delete []data_;
    data_=nullptr;
    size_=capacity=0;
}

bool &bitset::operator[](int ind)
{
    if(ind>=size_||ind<0) throw;

    bool & ref=(bool &)(data_[(ind+BLOCK-1)/BLOCK] |= (1 << (ind % BLOCK)));
    return ref;
}

bool bitset::operator[](int ind) const
{
    if(ind>=size_||ind<0) throw;

    bool z=data_[(ind+BLOCK-1)/BLOCK] | (1 << (ind % BLOCK));
    return z;
}

bool bitset::all()
{
    for(int i=0;i<size_/BLOCK;i++)
        if(data_[i]!=MAX_VALUE)
            return false;

    if(size_%BLOCK!=0)
        return data_[size_/BLOCK]==1<<(size_%BLOCK)-1;
    return true;
}

bool bitset::any()
{
    char c=size_%BLOCK;

    if(c>=1)
        c=1;
    else
        c=0;

    for(int i=0;i<(size_/BLOCK+c);i++)
        if(data_[i]!=0)
            return true;
    return false;
}

int bitset::count()
{
    int res=0;

    char c=size_%BLOCK;

    if(c>=1)
        c=1;
    else
        c=0;

    for(int i=0;i<size_/BLOCK+c;i++)
    {
        unsigned long long v=data_[i];

        while(v)
        {
            res+=(v&1);
            v>>=1;
        }

    }

    return res;
}

void bitset::flip()
{
    for (int i = 0; i < size_; i++)
    {
        data_[i / BLOCK] ^= (1 << (i % BLOCK));
    }
}

void bitset::flip(int pos)
{
    if(pos>=size_||pos<0)
        throw;

    data_[pos / BLOCK] ^= (1 << (pos % BLOCK));
}

bool bitset::none()
{
    return !any();
}

void bitset::reset()
{
    char c=size_%BLOCK;

    if(c>=1)
        c=1;
    else
        c=0;

    for(int i=0;i<size_/BLOCK+c;i++)
        data_[i]=0;
}

void bitset::reset(int pos)
{
    if (pos >= 0 && pos < size_)
    {
        data_[pos / BLOCK] &= ~(1 << (pos % BLOCK));
    }
}

void bitset::set()
{
    for(int i=0;i<size_/BLOCK;i++)
        data_[i]=MAX_VALUE;

    if(size_%BLOCK)
        data_[size_/BLOCK]=(MAX_VALUE>>(BLOCK-size_%BLOCK));
}

void bitset::set(int pos)
{
    if(pos>=size_||pos<0)
        throw;

    data_[pos / BLOCK] |= (1 << (pos % BLOCK));
}

bool bitset::test(int pos)
{
    if(pos>=size_||pos<0)
        throw;

    return (data_[pos / BLOCK] & (1 << (pos % BLOCK)));
}

std::string bitset::to_string()
{
    std::string s;

    for (int i = size_ - 1; i >= 0; i--)
    {
        if(test(i))
            s+="1";
        else
            s+="0";
    }

    return s;
}

unsigned long long bitset::to_ullong()
{
    unsigned long long res = 0;
    for (int i = size_ - 1; i >= 0; i--)
    {
        if (test(i))
        {
            res |= (1ULL << i);
        }
    }
    return res;
}


