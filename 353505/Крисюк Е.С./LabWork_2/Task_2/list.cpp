#include "list.h"

List::List()
{

}

List_Array::List_Array(){
    size = 10;
    array = new List*[size];
    for (int i = 0; i < size; ++i) {
        array[i] = new List();
    }
}
List_Array& List_Array::instance(){
    static List_Array instance;
    return instance;
}

List* List_Array::get_Index(int index){

    if(index >= 0 && index <= size){
        return array[index];
    }
    return nullptr;
}
