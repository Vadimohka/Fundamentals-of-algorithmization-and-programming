#include "binaryoperation.h"

BinaryOperation::BinaryOperation() {}

BinaryOperation::BinaryOperation(Expression *left, char operation, Expression *right) : m_left(left), m_right(right), m_operation(operation) {}

BinaryOperation::~BinaryOperation()
{
    delete m_left;
    delete m_right;
}

double BinaryOperation::evaluate()
{
    switch (m_operation)
    {
    case '+':
        return m_left->evaluate() + m_right->evaluate();
    case '-':
        return m_left->evaluate() - m_right->evaluate();
    case '*':
        return m_left->evaluate() * m_right->evaluate();
    case '/':
        return m_left->evaluate() / m_right->evaluate();
    default:
        return 0;
    }
}
