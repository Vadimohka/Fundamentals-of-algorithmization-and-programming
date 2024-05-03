#include "dyarray_data.h"
#include <iostream>


dyarray::dyarray()
{
    array_size=0;
    v=nullptr;
    positions=nullptr;
}


long long dyarray::size()
{
    return array_size;
}


void dyarray::push_back(Date a, int pos)
{
    if(a.get_day()==-8888)return;
    v=(Date *)realloc(v,(++array_size)*sizeof(Date));
    positions=(int *)realloc(positions,(array_size)*sizeof(int));
    v[array_size-1]=a;

    positions[array_size-1]=pos;
    //qDebug()<<"In push_back "<<a.get_year()<<" "<<v[array_size-1].get_year();
}


void dyarray::pop_back()
{
    v=(Date *)realloc(v,(--array_size)*sizeof(Date));
}


std::string dyarray::get_string(long long ind)
{
    return v[ind].get_date();
}


Date dyarray::get(long long ind)
{
    return v[ind];
}


int dyarray::get_pos(long long ind)
{
    if(ind>=array_size||ind<0)return (int)-1;
    return positions[ind];
}

void dyarray::upd(int ind, int delta)
{
    if(ind==array_size)return;
    positions[ind]+=delta;
    upd(ind+1,delta);
}


void dyarray::update(Date new_value, long long ind)
{
    int old_size=v[ind].get_date().size();
    v[ind]=new_value;
    int new_size=v[ind].get_date().size();
    upd(ind,new_size-old_size);
}


void dyarray::clear()
{
    free(v);
    v=nullptr;
    array_size=0;
}

