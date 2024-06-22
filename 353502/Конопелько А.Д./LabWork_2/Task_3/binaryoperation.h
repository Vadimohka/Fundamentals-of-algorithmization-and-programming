#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H
#include "expression.h"

class BinaryOperation : public Expression
{
private:
    char type{'+'};
    Expression* left;
    Expression* right;
public:
    BinaryOperation();
    ~BinaryOperation() override;
    BinaryOperation(Expression* left, char type, Expression* right);
    virtual double count() override; // ?
};

#endif // BINARYOPERATION_H
