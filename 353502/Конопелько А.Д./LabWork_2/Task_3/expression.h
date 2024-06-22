#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression
{
public:
    Expression();
    virtual ~Expression() = default;
    virtual double count() = 0;
};

#endif // EXPRESSION_H
