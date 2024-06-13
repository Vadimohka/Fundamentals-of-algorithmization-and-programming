#ifndef QUEUE_H
#define QUEUE_H
template<typename T>
class queue
{
    struct data
    {
        T v;
        data * next=nullptr;

        data(const T& val=T()){v=val;}
    };
    data * head=nullptr;
    data * tail=nullptr;
    long long size_=0;

public:
    ~queue()
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
            tail->next=el;
            tail=el;
        }
    }

    void pop()
    {
        if(head==nullptr)
        {
            throw "No elements in queue";
        }

        //while()
        data * el=head;
        head=head->next;
        delete el;
        size_--;
    }

    T &front()
    {
        return head->v;
    }

    T &back()
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
};
#endif // QUEUE_H
