#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression {
public:
    virtual double evaluate() const = 0;
    virtual ~Expression() {}
};

#endif // EXPRESSION_H
