#ifndef EXPRESSION_H
#define EXPRESSION_H

//I am booored
class Expression
{
public:
    Expression();
    virtual ~Expression() = default;
    virtual double evaluate() = 0;
};

#endif // EXPRESSION_H
