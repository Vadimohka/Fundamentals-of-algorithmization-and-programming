#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression
{
public:
    virtual double Evaluate() = 0;
    virtual ~Expression() {};
};


class Number : public Expression
{
public:
    Number(double num);

    double Evaluate() override;

private:
    double value;
};


class BinaryOperation : public Expression
{
public:
    BinaryOperation(Expression* left, const char action, Expression* right);
    ~BinaryOperation();
    double Evaluate() override;

private:
    char action;
    Expression* left;
    Expression* right;
};

#endif // EXPRESSION_H
