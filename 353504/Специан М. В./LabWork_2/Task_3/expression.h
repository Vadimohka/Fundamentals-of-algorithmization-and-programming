#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression {
public:
    Expression();
    virtual double evaluate() const = 0;
    virtual ~Expression() {}

    // for task 4
    virtual bool isNumber() const { return false; }
    virtual bool isBinaryOperation() const { return false; }
};

#endif // EXPRESSION_H
