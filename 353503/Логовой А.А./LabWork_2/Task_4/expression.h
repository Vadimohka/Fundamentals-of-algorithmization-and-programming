#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression{

public:
    Expression();
    virtual ~Expression();
    virtual double evaluate() const = 0;
};

#endif // EXPRESSION_H
