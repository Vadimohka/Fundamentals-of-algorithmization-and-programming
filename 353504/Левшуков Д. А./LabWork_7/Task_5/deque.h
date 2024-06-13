#ifndef DEQUE_H
#define DEQUE_H

#include <cstddef>
#include "block.h"
#include "iterator.h"

template<typename T>
class Deque
{
    block<T>*begin_=nullptr;
    block<T>*end_=nullptr;
    size_t size_=0;


public:
    ~Deque(){clear();}


    void push_back(const T& x)
    {
        if(end_==nullptr||end_->right==3)
        {
            block<T> * new_block=new block<T>;
            if(empty())
            {
                new_block->next=new_block->prev=new_block;
                begin_=end_=new_block;
            }
            else //Not empty
            {
                //Update right
                end_->next=new_block;
                new_block->prev=end_;
                //Update first
                new_block->next=begin_;
                begin_->prev=new_block;
                //Update end
                end_=new_block;
            }
        }
        else
            end_->right++;//Update index of array of block (MAX INDEX = 3)

        end_->data[end_->right]=x;
        size_++;
    }

    void push_front(const T& x)
    {
        if(begin_==nullptr||begin_->left==0)
        {
            block<T> * new_block=new block<T>;
            new_block->data[3]=x;
            new_block->left=new_block->right=3;
            if(empty())
            {
                new_block->next=new_block->prev=new_block;
                begin_=end_=new_block;
                begin_->left--;
            }
            else //Not empty
            {
                new_block->prev=end_;
                new_block->next=begin_;
                begin_->prev=end_->next=new_block;
                begin_=new_block;
            }
        }
        else
        {
            begin_->left--;
            begin_->data[begin_->left]=x;
        }
        size_++;
    }

    void pop_back()
    {
        if(empty())return;
        size_--;

        if(end_!=nullptr)
        {
            end_->right--;
            if(end_->right==-1)
            {
                block<T> *tmp=end_;
                if(end_==begin_)
                    end_=begin_=nullptr;
                else
                {
                    end_=end_->prev;
                    end_->next=begin_;
                    begin_->prev=end_;
                }
                delete tmp;
                tmp=nullptr;
            }

        }
    }
    void pop_front()
    {
        if(empty())return;
        size_--;

        if(begin_!=nullptr)
        {
            begin_->left++;
            if(begin_->left==4)
            {
                block<T> *tmp=begin_;
                if(end_==begin_)
                    end_=begin_=nullptr;
                else
                {
                    begin_=begin_->next;
                    begin_->prev=end_;
                    end_->next=begin_;
                }
                delete tmp;
                tmp=nullptr;
            }

        }
    }
    size_t size()
    {
        return size_;
    }
    void clear()
    {
        while(!empty())
        pop_back();
    }
    bool empty()
    {
        return size_==0;
    }
    iterator<T>begin()
    {
        return iterator(begin_, begin_->left);
    }
    iterator<T>end()
    {
        return ++iterator<T>(end_, end_->right);
    }
    T &operator[](size_t ind) {
        block<T>* ptr=begin_;
        while(ind<4)
        {
            ind--;
            ptr=ptr->next;
        }
        return ptr->data[ind];
    }
};

#endif // DEQUE_H
