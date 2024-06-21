#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression
{
public:
    Expression() = default;
    virtual double evaluate();
    virtual ~Expression() = default;
};

#endif // EXPRESSION_H
