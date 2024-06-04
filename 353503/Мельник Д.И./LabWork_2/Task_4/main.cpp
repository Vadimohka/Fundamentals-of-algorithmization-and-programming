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

            default: std::cout << "Error\n";
        }
         return 0;
    }
};

bool check_equals(Expression const* leftNumber, Expression const* rightNumber) {
    return  *(double **)leftNumber == *(double **)rightNumber;
}

int main() {
    Expression *n1 = new Number(69);
    Expression *n2 = new Number(96);
    Expression *a = new BinaryOperation(n1, '+', n2);
    Expression *b = new BinaryOperation(n1, '*', n2);

    std::cout << *(double **)n1 << "\n" << *(double **)n2 << "\n" << *(double **)a << "\n" << *(double **)b << "\n\n";
    std::cout << (check_equals(a, b) ? "Equals\n" : "Aren't equals\n");
    std::cout << (check_equals(n1, b) ? "Equals\n" : "Aren't equals\n");
}