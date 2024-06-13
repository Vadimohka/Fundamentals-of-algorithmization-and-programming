#ifndef EXPRESSION_H
#define EXPRESSION_H


class Expression
{
public:
    virtual ~Expression() = default;
    virtual double evaluate() = 0;
};

#endif // EXPRESSION_H
