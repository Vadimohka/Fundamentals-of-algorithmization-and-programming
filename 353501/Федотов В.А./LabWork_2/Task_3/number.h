#pragma once

#include "expression.h"

class Number : public Expression {
public:
    Number(double value_);
    double getValue() override;
  
private:
    double value_;
};