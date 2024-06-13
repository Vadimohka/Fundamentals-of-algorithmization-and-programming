//
// Created by acryoz on 14.3.24.
//

#ifndef UNTITLED5_NUMBER_H
#define UNTITLED5_NUMBER_H

#pragma once
#include "Expression.h"


class Number: public Expression{
public:
    Number(double);
    double evaluate() const override;
    ~Number() override = default;
private:
    double value;
};


#endif //UNTITLED5_NUMBER_H
