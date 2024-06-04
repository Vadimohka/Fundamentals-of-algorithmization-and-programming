//
// Created by volodya-petarda on 5/11/24.
//

#ifndef LAB2_3_NUMBER_H
#define LAB2_3_NUMBER_H


#include "Expression.h"

class Number : public Expression{
public:
    Number(double number);
    double evaluate() override;
private:
    double number;
};


#endif //LAB2_3_NUMBER_H
