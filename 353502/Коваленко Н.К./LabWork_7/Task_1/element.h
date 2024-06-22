#ifndef ELEMENT_H
#define ELEMENT_H


template <typename t>


class Element
{

public:
    Element(t data){
        this -> data = data;
        next_element = nullptr;
    };

    Element* next_element;
    t data;
};

#endif // ELEMENT_H
