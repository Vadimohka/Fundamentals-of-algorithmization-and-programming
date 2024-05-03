#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression
{
public:
    Expression();
    virtual ~Expression();

    virtual double evaluate();
};

#endif // EXPRESSION_H
