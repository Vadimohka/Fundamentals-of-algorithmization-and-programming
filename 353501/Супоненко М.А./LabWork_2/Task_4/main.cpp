#include <iostream>
#include <sstream>

class Expression {
public:
    virtual ~Expression() {}
    virtual std::string getType() const = 0;
};

class Number : public Expression {
private:
    double value;
public:
    Number(double val) : value(val) {}
    virtual std::string getType() const override {
        return "Number";
    }
    double getValue() const {
        return value;
    }
};

class BinaryOperation : public Expression {
private:
    char op;
    Expression *left;
    Expression *right;
public:
    BinaryOperation(Expression *l, char operation, Expression *r) : op(operation), left(l), right(r) {}
    virtual ~BinaryOperation() {
        delete left;
        delete right;
    }
    virtual std::string getType() const override {
        return "BinaryOperation";
    }
};

Expression* inputNumber() {
    double num;
    std::string input;
    std::cout << "Enter a number: ";
    std::getline(std::cin, input);
    std::istringstream iss(input);
    if (iss >> num) {
        return new Number(num);
    } else {
        return nullptr;
    }
}

bool check_equals(Expression const* left, Expression const* right) {
    if (left && right) {
        std::string leftType = left->getType();
        std::string rightType = right->getType();
        return leftType == rightType;
    }
    return false;
}

int main() {
    Expression* num1 = inputNumber();
    Expression* num2 = inputNumber();
    Expression* binOp1 = new BinaryOperation(inputNumber(), '+', inputNumber());
    Expression* binOp2 = new BinaryOperation(inputNumber(), '-', inputNumber());

    if (num1 && num2 && binOp1 && binOp2) {
        std::cout << "num1 == num2: " << check_equals(num1, num2) << std::endl;
        std::cout << "binOp1 == binOp2: " << check_equals(binOp1, binOp2) << std::endl;
        std::cout << "num1 == binOp1: " << check_equals(num1, binOp1) << std::endl;
    } else {
        std::cerr << "Failed to input expressions." << std::endl;
    }

    delete num1;
    delete num2;
    delete binOp1;
    delete binOp2;

    return 0;
}
