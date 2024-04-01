#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#include <expression.h>

class BinaryOperation : public Expression
{
public:
    BinaryOperation(Expression* x1, char operat, Expression* x2);
    double evaluate();
    ~BinaryOperation();
private:
    Expression* val1;
    Expression* val2;
    char type;
};

#endif // BINARYOPERATION_H
