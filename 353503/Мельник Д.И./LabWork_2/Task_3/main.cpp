#include <iostream>

class Expression {
public:
    virtual double evaluate() = 0;
};

class Number : public Expression {
private:
    double number;

public:
    Number(double number) {
        this->number = number;
    }

    double evaluate() override {
        return number;
    }
};

class BinaryOperation : public Expression {
private:
    Expression *leftNumber;
    Expression *rightNumber;
    char symbol;

public:
    BinaryOperation(Expression *leftNumber, char symbol, Expression *rightNumber) {
        this->leftNumber = leftNumber;
        this->rightNumber = rightNumber;
        this->symbol = symbol;
    }

    ~BinaryOperation() {
        delete leftNumber;
        delete rightNumber;
    }

    double evaluate() override {
        switch (symbol) {
            case '+':
                return (leftNumber->evaluate() + rightNumber->evaluate());

            case '-':
                return (leftNumber->evaluate() - rightNumber->evaluate());

            case '*':
                return (leftNumber->evaluate() * rightNumber->evaluate());

            case '/':
                {
                if (rightNumber->evaluate() == 0) std::cout << "Infinity\n";

                else return (leftNumber->evaluate() / rightNumber->evaluate());
                
                break;
                }

                default: 
                std::cout << "Error\n";
        }
        return 0;
    }
};

int main() {
Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
Expression* expr = new BinaryOperation(new Number(3), '+', sube);
std::cout << expr->evaluate() << std::endl;
delete expr;
}