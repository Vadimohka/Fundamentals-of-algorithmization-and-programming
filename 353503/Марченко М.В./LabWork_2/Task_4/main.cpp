#include <iostream>

class Expression {
public:
    virtual double evaluate() const = 0;
    virtual ~Expression() = default;
    virtual int getType() const = 0;
};

class Number : public Expression {
private:
    double value;

public:
    explicit Number(double value) : value(value) {} //член-данные value инициализируются непосредственно при создании объекта

    double evaluate() const override {
        return value;
    }
};

class BinaryOperation : public Expression {
private:
    Expression* left;
    Expression* right;
    char operation;

public:
    BinaryOperation(Expression* left, char operation, Expression* right)
        : left(left), right(right), operation(operation) {}

    double evaluate() const override {
        double leftValue = left->evaluate();
        double rightValue = right->evaluate();

        switch (operation) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
        default:
            std::cout << "Invalid operation: " << operation << std::endl;
            return 0.0;
        }
    }

    ~BinaryOperation() override{
        delete left;
        delete right;
    }
};

bool check_equals(Expression const* left, Expression const* right) {
    return  *(void **)left == *(void **)right;
}

