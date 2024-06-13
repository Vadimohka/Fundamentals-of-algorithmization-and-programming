#include <iostream>

class Expression {
public:
    virtual double evaluate() = 0;
};

class Number : public Expression {
private:
    double num;
public:
    explicit Number(double number) {
        this->num = number;
    }

    double evaluate() override {
        return num;
    }
};

class BinaryOperation : public Expression {
private:
    Expression *left;
    Expression *right;
    char type;
public:
    BinaryOperation(Expression *left, char type, Expression *right) {
        this->left = left;
        this->right = right;
        this->type = type;
    }

    ~BinaryOperation() {
        delete left;
        delete right;
    }

    double evaluate() override {
        switch (type) {
            case '+':
                return (left->evaluate() + right->evaluate());
            case '-':
                return (left->evaluate() - right->evaluate());
            case '*':
                return (left->evaluate() * right->evaluate());
            case '/':
                if (right->evaluate() != 0) {
                    return (left->evaluate() / right->evaluate());
                } else {
                    std::cout << "Error\n";
                }
                break;
            default:
                std::cout << "What u fucking doing\n";
        }
    }
};

int main() {
    Expression *sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression *expr = new BinaryOperation(new Number(3), '+', sube);
    std::cout << expr->evaluate() << "\n";
    delete expr;
}
