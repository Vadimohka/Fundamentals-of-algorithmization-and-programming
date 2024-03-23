#include <iostream>

class Expression {
public:
    virtual double evaluate() = 0;
    virtual ~Expression() {}
};  

class Number : public Expression {
private:
    double num;
public:
    Number(double number) : num(number) {
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
    BinaryOperation(Expression *left, char type, Expression *right) : left(left), type(type), right(right){
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
                    return -1;
                }
                break;
            default:
                std::cout << "No such operation\n";
                return -1;
        }
    }
};

int main() {
    Expression *sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression *expr = new BinaryOperation(new Number(3), '+', sube);
    std::cout << expr->evaluate() << "\n";
    delete expr;
}