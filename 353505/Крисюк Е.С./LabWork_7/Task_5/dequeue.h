#ifndef DEQUEUE_H
#define DEQUEUE_H

#include <QDebug>
#include "iterator.h"

#include "node.h"

template<typename t>

class Dequeue
{
private:
    Node<t>* front = nullptr;
    Node<t>* back = nullptr;

    int length = 0;
    int nodes_count = 0;

public:
    Dequeue() {};

    t &operator[](int index){
        if(index < 0 || index >= length){
            throw "index out of range";
        }

        Node<t>* index_node = front;

        int count = 0;

        while(index_node != nullptr && count + index_node -> count <= index){
            count += index_node -> count;
            index_node = index_node -> next;
        }

        return index_node -> data[index - count];
    }

    void push_back(t value){
        if(nodes_count == 0){
            front = new Node<t>;

            back = front;

            back -> data[0] = value;

            back -> count ++;
            nodes_count ++;
        }
        else{
            if(back -> count < 4){
                back -> data[back -> count] = value;
                back -> count ++;

            }
            else{
                back -> next = new Node<t>;

                back -> next -> prev = back;

                back = back -> next;

                back -> data[0] = value;
                back -> count ++;
                nodes_count++;
            }
        }

        length++;
    }



    void push_front(t value) {

        if(nodes_count == 0){
            front = new Node<t>;
            back = front;

            front -> data[0] = value;

            front -> count ++;
            nodes_count++;

        }

        else{

            if(front -> count < 4){

                for (int i = front->count - 1; i >= 0; --i) {
                    front -> data[i + 1] = front -> data[i];
                }
                front -> data[0] = value;
                front -> count++;
            }

            else{
                front -> prev = new Node<t>;

                front -> prev -> next = front;

                front = front -> prev;

                front -> data[0] = value;

                front -> count ++;
                nodes_count ++;
            }
        }

        length ++;
    }

    void pop_back(){

        if(length != 0) {

            if(back -> count > 1){
                back -> count --;
            }
            else{
                Node<t>* temp = back;

                back = back -> prev;

                if(back){
                    delete temp;
                    back -> next = nullptr;
                }

                else{
                    delete[] temp -> data;
                    delete temp;

                    front = nullptr;
                    back = nullptr;
                    nodes_count = 0;
                }
            }

            length--;

        }
    }


    void pop_front() {

        if(length != 0){

            if(front -> count > 1){

                for(int i = 0; i < front -> count - 1; ++i){

                    front -> data[i] = front -> data[i + 1];
                }

                front -> count --;
            }

            else {
                Node<t>* temp = front;

                front = front -> next;

                if(front){

                    delete temp;

                    front -> prev = nullptr;
                }
                else {
                    delete[] temp -> data;
                    delete temp;

                    back = nullptr;
                    front = nullptr;
                    nodes_count = 0;
                }
            }
            length--;
        }
    }

    bool empty(){
        return length == 0;
    }

    void clear() {
        while(length != 0){
            pop_back();
        }
    }

    int size(){
        return length;
    }

    Iterator<t> begin(){
        return Iterator<t> (front, 0);
    }

    Iterator<t> end(){
        return Iterator<t> (back -> next, 0);
    }

    void Debug() {
        Node<t>* temp = front;


        while(temp != nullptr) {
            for(int i = 0; i < temp -> count; ++i){

                qDebug() << temp -> data[i];
            }

            temp = temp -> next;
        }
    }



};

#endif //DEQUEUE_H
