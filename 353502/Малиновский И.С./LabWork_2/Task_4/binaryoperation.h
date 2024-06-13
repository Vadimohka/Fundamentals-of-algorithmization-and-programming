#ifndef BINARY_OPERATION_H
#define BINARY_OPERATION_H

#include "expression.h"

class BinaryOperation : public Expression {
public:
    BinaryOperation(Expression* left, char op, Expression* right)
        : left(left), op(op), right(right) {}

    virtual ~BinaryOperation() {
        delete left;
        delete right;
    }

    virtual double evaluate() const override {
        double leftValue = left->evaluate();
        double rightValue = right->evaluate();
        switch (op) {
            case '+':
                return leftValue + rightValue;
            case '-':
                return leftValue - rightValue;
            case '*':
                return leftValue * rightValue;
            case '/':
                if (rightValue == 0)
                    throw std::runtime_error("Division by zero");
                return leftValue / rightValue;
            default:
                throw std::invalid_argument("Invalid operator");
        }
    }

protected:
    virtual ExpressionType getType() const override {
        return BINARY_OPERATION;
    }

private:
    Expression* left;
    Expression* right;
    char op;
};

#endif // BINARY_OPERATION_H
