#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression {

public:
    virtual double evaluate() = 0;
    virtual ~Expression();
};

#endif  // EXPRESSION_H
