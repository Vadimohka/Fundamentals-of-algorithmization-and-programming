#pragma once

class HeapInspector
{
public:
    virtual ~HeapInspector() {}
    virtual void setVal(int val) = 0;
    virtual void setPos(int val) = 0;
    virtual HeapInspector *createChild() = 0;
};

class Heap
{
public:
    virtual ~Heap(){};
    virtual void push(long x) = 0;
    virtual long pop() = 0;
    virtual bool empty() = 0;
    virtual void clear() = 0;
    virtual void inspect(HeapInspector *ins) {}
};
