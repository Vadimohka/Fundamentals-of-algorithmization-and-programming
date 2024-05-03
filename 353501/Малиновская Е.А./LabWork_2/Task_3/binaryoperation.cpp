#include "binaryoperation.h"

BinaryOperation::BinaryOperation(Expression* leftOperand, char operation, Expression* rightOperand)
    : m_leftOperand(leftOperand), m_operation(operation), m_rightOperand(rightOperand)
{
}

BinaryOperation::~BinaryOperation()
{
    delete m_leftOperand;
    delete m_rightOperand;
}

double BinaryOperation::evaluate() const
{
    double leftValue = m_leftOperand->evaluate();
    double rightValue = m_rightOperand->evaluate();

    switch (m_operation) {
    case '+':
        return leftValue + rightValue;
    case '-':
        return leftValue - rightValue;
    case '*':
        return leftValue * rightValue;
    case '/':
        return leftValue / rightValue;
    default:
        return 0.0;
    }
}
