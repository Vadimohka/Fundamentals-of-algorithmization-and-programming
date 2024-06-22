#include "stack.h"

Stack::Stack()
{
    top = -1;
}

void Stack::push(int number){

    if(top == max_size){
        throw "Stack overflow";
    }

    ++top;

    list[top] = number;
}

int Stack::pop() {
    if(top == -1) {
        throw "Stack havent elements";
    }

    int element = list[top];

    --top;

    return element;
}
bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == max_size - 1;
}

int Stack::size() {
    return top + 1;
}


QList<int>* Stack::Stack_to_list(){
    QList<int>* array = new QList<int>;

    for(int i = top; i >= 0; --i){
        array -> append(this -> list[i]);
    }

    return array;
}

void Stack::clear(){

    while(!isEmpty()){
        this -> pop();
    }
}
