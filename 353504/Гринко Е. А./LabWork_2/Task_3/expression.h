#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QObject>

class Expression : public QObject
{
    Q_OBJECT
public:
    explicit Expression(QObject *parent = nullptr);
    virtual double evaluate() const = 0;
    virtual ~Expression();
};

class Number : public Expression
{
    Q_OBJECT
private:
    double value;
public:
    Number(double val, QObject *parent = nullptr);
    virtual double evaluate() const override;
    virtual ~Number();
};

class BinaryOperation : public Expression
{
    Q_OBJECT
private:
    Expression* leftOperand;
    Expression* rightOperand;
    char operation;
public:
    BinaryOperation(Expression* left, char op, Expression* right, QObject *parent = nullptr);
    virtual double evaluate() const override;
    virtual ~BinaryOperation();
};

#endif // EXPRESSION_H
