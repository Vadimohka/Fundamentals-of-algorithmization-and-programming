#include <iostream>

class Expression
{
public:
    virtual ~Expression() {};
    virtual double evaluate() const = 0;
};

class Number : public Expression
{
private:
    double value;
public:
    Number(double value) : value(value) {}
    double evaluate() const override { return value; }

};

class BinaryOperation : public Expression
{
private:
    Expression* left;
    Expression* right;
    char oprtr;

public:
    BinaryOperation(Expression* left, char op, Expression* right)
            : left(left), right(right), oprtr(op) {}

    ~BinaryOperation()
    {
        delete left;
        delete right;
    }
    double evaluate() const
    {
        double lVal = left->evaluate();
        double rVal = right->evaluate();
        switch (oprtr)
        {
            case '+':
                return lVal + rVal;
            case '-':
                return lVal - rVal;
            case '*':
                return lVal * rVal;
            case '/':
                if(rVal == 0) {
                    std::cout << "error!\n";
                    return 0;
                }
                else
                    return lVal / rVal;

            default:
                std::cout << "error!!!\n";
        }
    }

};


int main() {
    Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression* expr = new BinaryOperation(new Number(3), '+', sube);
    std::cout << expr->evaluate() << std::endl;
    delete expr;
}