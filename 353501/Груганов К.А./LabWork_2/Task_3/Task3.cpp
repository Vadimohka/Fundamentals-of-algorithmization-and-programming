#include <iostream>

class Expression
{
public:
    virtual double evaluate() = 0;
    virtual ~Expression(){};
};

class Number : public Expression
{
public:
    Number(double value) : my_value(value) {}

    double evaluate() override
    {
        return my_value;
    }

private:
    double my_value;
};

class BinaryOperation : public Expression
{
public:
    BinaryOperation(Expression *left, char operation, Expression *right) : my_left(left), my_operation(operation), my_right(right){};
    double evaluate() override
    {
        switch (my_operation)
        {
        case '+':
            return my_left->evaluate() + my_right->evaluate();
        case '-':
            return my_left->evaluate() - my_right->evaluate();
        case '/':
            return my_left->evaluate() / my_right->evaluate();
        case '*':
            return my_left->evaluate() * my_right->evaluate();
        default:
            return 0.0;
        }
    }
    ~BinaryOperation()
    {
        delete my_left;
        delete my_right;
    }

private:
    Expression *my_left;
    Expression *my_right;
    char my_operation;
};

int main()
{
    Expression *sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression *expr = new BinaryOperation(new Number(3), '+', sube);
    std::cout << (*expr).evaluate() << '\n';
    delete expr;
    return 0;
}
