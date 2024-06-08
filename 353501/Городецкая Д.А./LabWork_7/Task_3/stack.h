#ifndef STACK_H
#define STACK_H
#include<QVector>
template<typename T>
class stack
{
    struct data
    {
        T v;
        data * last=nullptr;

        data(const T& val=T()){v=val;}
    };
    data * head=nullptr;
    data * tail=nullptr;
    long long size_=0;

public:
    stack(){}
    ~stack()
    {
        clear();
    }
    void clear()
    {
        while(!empty())
            pop();
    }

    void push(const T& value)
    {
        data *el=new data();
        el->v=value;
        size_++;
        if(head==nullptr)
        {
            head=tail=el;
        }
        else {
            el->last=tail;
            //qDebug()<<"[1]"<<el<<" "<<tail<<" "<<el->last<<" "<<tail->last ;
            tail=el;
            //qDebug()<<"[2]"<<el<<" "<<tail<<" "<<el->last<<" "<<tail->last ;
        }
    }

    void pop()
    {
        if(head==nullptr)
        {
            throw "No elements in stack";
        }

        if(head==tail&&tail!=nullptr)
        {
            delete head;
            head=tail=nullptr;
            size_=0;
            return;
        }
        data * el=tail;
        //qDebug()<<"[DEL 1]"<<el<<" "<<tail<<" "<<el->last;
        tail=tail->last;
        //qDebug()<<"[DEL 2]"<<el<<" "<<tail<<" "<<el->last;
        delete el;
        size_--;
    }

    T &top()
    {
        return tail->v;
    }


    long long size()
    {
        return size_;
    }

    bool empty()
    {
        return size_==0;
    }
    QVector<T> to_QVec()
    {
        QVector<T> res;
        data *cur = tail;
        while (cur) {
            res.push_front(cur->v);
            cur = cur->last;
        }
        //qDebug()<<res;
        return res;

    }
};

#endif // STACK_H
