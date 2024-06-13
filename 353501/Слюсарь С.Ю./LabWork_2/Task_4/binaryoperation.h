#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H
#include "number.h"

class BinaryOperation : public Number
{
public:
    BinaryOperation(Expression *num1, char op, Expression *num2);
    virtual ~BinaryOperation();
    double value_;
    double evaluate() override;
    Expression *num1_;
    Expression *num2_;

};

#endif // BINARYOPERATION_H
