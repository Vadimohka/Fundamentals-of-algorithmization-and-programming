//
// Created by zgdarya on 5/30/24.
//

#ifndef L7_T3_STEK_H
#define L7_T3_STEK_H


#include <QString>
#include "StekNode.h"

class Stek {
    StekNode* last;
    StekNode* first;
    int _size;

public:
    Stek();
    void operator=(Stek &other);
    void push_back(int value);
    void pop_back();
    int peek_back();
    bool isEmpty();
    void clear();
    int size();
    QString toString();

    StekNode* begin();
    StekNode* end();
};


#endif //L7_T3_STEK_H
