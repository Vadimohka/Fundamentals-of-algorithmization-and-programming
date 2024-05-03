#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression
{
public:
    virtual double evaluate() = 0;
    virtual ~Expression() = default;
};

#endif // EXPRESSION_H
