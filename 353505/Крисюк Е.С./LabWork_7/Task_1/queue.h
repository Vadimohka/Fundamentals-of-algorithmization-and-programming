#ifndef QUEUE_H
#define QUEUE_H


#include "element.h"

#include <QDebug>

template <typename t>

class Queue
{
    
private:
    
    Element<t>* head = nullptr;
    Element<t>* tail = nullptr;

    int length = 0;

    Element<t>* Move_ptr_to_pos(int pos) {

        Element<t>* new_tail_element = head;

        for(int i = 0; i < pos && i < length; ++i) {
            new_tail_element = new_tail_element -> next_element;
        }

        return new_tail_element;
    }
    
public:
    Queue() {};
    
    void push(t data){
        Element<t>* element = new Element(data);

        if(!head){
            head = element;
            tail = element;
        }
        else{
            tail -> next_element = element;
            tail = element;
        }

        length++;
    }
    
    void push_front(t data){
        Element<t>* element = new Element(data);

        if(!head){
            head = element;
            tail = element;
        }

        else {
            element -> next_element = head;
            head = element;
        }

        length++;
    }
    t pop(){
        if(length == 0){
            throw "Queue is empty =(";
        }


        t data = head -> data;

        Element<t>* new_head_elem = head -> next_element;

        delete head;

        head = new_head_elem;

        if(length == 1){
            tail = nullptr;
        }
        length--;

        return data;
    }


    t pop_back () {
        if(length == 0){
            throw "Queue is empty =(";
        }


        t data = tail -> data;

        Element<t>* new_tail_element = Move_ptr_to_pos(length - 2);

        delete tail;

        tail = new_tail_element;

        length--;


        return data;
    }


    bool empty(){
        return !head;
    }

    int size(){
        return length;
    }


    t front(){
        if(!head){
           throw "Queue is empty =(";
        }
        return head -> data;
    }


    t back() {
        if(!tail){

           throw "Queue is empty =(";
        }

        return tail -> data;
    }

    void swap(Queue<t> &second_queue){

        int second_queue_length = second_queue.size();

        t queue_element_data;


        if(length < second_queue.size()){

            while(!empty()){
                queue_element_data = this -> pop();

                second_queue.push(queue_element_data);
            }

            while(second_queue_length){
                queue_element_data = second_queue.pop();

                this -> push(queue_element_data);

                second_queue_length--;
            }
        }

        else {

            int first_queue_length = length;

            while(!second_queue.empty()){

                queue_element_data = second_queue.pop();

                this -> push(queue_element_data);

            }

            while(first_queue_length){
                queue_element_data = this -> pop();

                second_queue.push(queue_element_data);

                first_queue_length--;
            }

        }
    }


    void Move_rows(int first_index, int second_index, QString state){
        Queue<t> temp_queue;

        Element<t>* temp_element = Move_ptr_to_pos(first_index);


        for(int i = first_index; i < second_index + 1; ++i) {
            temp_queue.push(temp_element -> data);
            temp_element = temp_element -> next_element;

            this -> Delete_from_index(first_index);
        }


        if(state == "up") {

            for(int i = first_index - 1, j = 0; j < temp_queue.size(); ++i, ++j) {

                this -> Insert_to_pos(i, temp_queue.Get_element_of_index(j));

            }
        }

        else {

            int temp_index = second_index + 2 - temp_queue.size();

            for(int i = temp_index, j = 0; j < temp_queue.size(); ++i, ++j){
                this -> Insert_to_pos(i,temp_queue.Get_element_of_index(j));
            }
        }

    }


    t Delete_from_index(int index){


        if(index >= length){
            throw "Index out of range";
        }

        if(index == 0){
            return pop();
        }

        if(index == length - 1){
            return pop_back();
        }


        Element<t>* pre_delete_element = Move_ptr_to_pos(index - 1);

        Element<t>* temp = pre_delete_element -> next_element;

        t data = temp -> data;

        pre_delete_element -> next_element = temp -> next_element;

        delete temp;

        length--;

        return data;

    }

    void Insert_to_pos(int pos, t data){


        if(pos > length) {
            throw "Index out of range";
        }

        if(pos == 0){
            push_front(data);
            return;
        }


        if(pos == length){
            push(data);
            return;
        }

        Element<t>* pre_inserting_element = Move_ptr_to_pos(pos - 1);

        Element<t>* element = new Element(data);

        element -> next_element = pre_inserting_element -> next_element;


        pre_inserting_element -> next_element = element;

        length ++;

    }

    t Get_element_of_index(int index){

        Element<t>* temp = Move_ptr_to_pos(index);

        return temp -> data;

    }

    void Debug() {
        Element<t>* temp = head;

        qDebug() << "========================";

        for(int i = 0; i < length; ++i){
            qDebug() << temp -> data;

            temp = temp -> next_element;

        }

        qDebug() << "========================";
    }


};

#endif // QUEUE_H
