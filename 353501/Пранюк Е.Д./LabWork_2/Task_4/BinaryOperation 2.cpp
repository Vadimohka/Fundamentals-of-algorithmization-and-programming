#include "BinaryOperation.h"

BinaryOperation::BinaryOperation(Expression* left,char op,Expression* right) : left(left),op(op),right(right)
{

}
BinaryOperation::~BinaryOperation()
{
    delete this->left;
    delete this->right;
}
double BinaryOperation::evaluate()
{
    switch (this->op)
    {
        case '+':
        return this->left->evaluate() + this->right->evaluate();
        break;

        case '-':
        return this->left->evaluate() - this->right->evaluate();
        break;

        case '*':
        return this->left->evaluate() * this->right->evaluate();
        break;

        default:
        return 0;
        break;
    }

}