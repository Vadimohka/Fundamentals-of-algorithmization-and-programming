#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <QDebug>


class Expression
{
public:
    Expression();

    virtual double evaluate();
};

#endif // EXPRESSION_H
