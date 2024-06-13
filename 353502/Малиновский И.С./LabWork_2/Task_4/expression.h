#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression {
public:
    virtual ~Expression() = default;
    virtual double evaluate() const = 0;

protected:
    enum ExpressionType {
        NUMBER,
        BINARY_OPERATION
    };

    virtual ExpressionType getType() const = 0;

    friend bool check_equals(Expression const* left, Expression const* right);
};

bool check_equals(Expression const* left, Expression const* right) {
    if (left == nullptr || right == nullptr) {
        return false;
    }
    return left->getType() == right->getType();
}

#endif // EXPRESSION_H
