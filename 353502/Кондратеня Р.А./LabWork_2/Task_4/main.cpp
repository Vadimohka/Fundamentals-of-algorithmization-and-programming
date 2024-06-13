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

bool check_equals(Expression const* left, Expression const* right) {
    return  *(double *)left == *(double *)right;
}

int main() {
    auto *n1 = new Number(1);
    auto *n2 = new Number(2);
    auto *a = new BinaryOperation(n1, '-', n2);
    auto *b = new BinaryOperation(n1, '/', n2);
    std::cout << *(double *)n1 << "\n" << *(double *)n2 << "\n" << *(double *)a << "\n" << *(double *)b << "\n\n";
    std::cout << (check_equals(a, b) ? "Yes\n" : "No\n");
    std::cout << (check_equals(n1, b) ? "Yes\n" : "No\n");
}
