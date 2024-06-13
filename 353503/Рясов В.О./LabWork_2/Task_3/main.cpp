#include <iostream>
#include <string>


class Expression
{
public:
    virtual ~Expression() {};

    virtual double evaluate() const = 0;
};


class Number : public Expression
{
    double value;

public:
    Number() { value = 0; };
    Number(double num) : Expression() { value = num; };
    ~Number() {};


    double evaluate() const { return value; };
};


enum Action
{
    add = 0,
    sub,
    mult,
    divi
};


class BinaryOperation : public Expression
{
    Expression *left, *right;
    Action action;
public:
    BinaryOperation(Expression* left, std::string action, Expression* right)
    {
        if (action == "--")
        {
            this->action = sub;
        }
        else if (action == "*")
        {
            this->action = mult;
        }
        else if (action == "/")
        {
            this->action = divi;
        }
        else
        {
            this->action = add;
        }

        this->left = left;
        this->right = right;
    };
    ~BinaryOperation() { delete left; delete right; };

    double evaluate() const
    {
        switch (action)
        {
            case add:
                return left->evaluate() + right->evaluate();

            case sub:
                return left->evaluate() - right->evaluate();

            case divi:
                return left->evaluate() / right->evaluate();

            case mult:
                return left->evaluate() * right->evaluate();
        }
    };
};


bool check_equals(Expression const* left, Expression const* right)
{
    return *(void***)left == *(void***)right;
}


int main()
{
    Expression* sube = new BinaryOperation(new Number(4.5), "*", new Number(5));
    Expression* expr = new BinaryOperation(new Number(3), "+", sube);
    std::cout << expr->evaluate() << std::endl;
    Expression *r = new Number(2);
    Expression *f = new Number(4);
    if (check_equals(expr, sube))
        std::cout << "equal\n";
    else
        std::cout << "unequal\n";
    if (check_equals(r, f))
        std::cout << "equal\n";
    else
        std::cout << "unequal\n";
    if (check_equals(r, sube))
        std::cout << "equal\n";
    else
        std::cout << "unequal\n";
    delete expr;
    delete r;
    delete f;
    return 0;
}