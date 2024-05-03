#include "binaryoperation.h"

BinaryOperation :: BinaryOperation( Expression* leftNum , char binOperator , Expression* rightNum ) : leftNum( leftNum ) , binOperator( binOperator ) , rightNum( rightNum ){}

BinaryOperation :: ~BinaryOperation()
{

    delete leftNum;
    delete rightNum;

}

double BinaryOperation :: evaluate()
{

    if( binOperator == '+' )
        return leftNum -> evaluate() + rightNum -> evaluate();

    if( binOperator == '-' )
        return leftNum -> evaluate() - rightNum -> evaluate();

    if( binOperator == '*' )
        return leftNum -> evaluate() * rightNum -> evaluate();

    if( binOperator == '/' && rightNum -> evaluate() != 0 )
        return leftNum -> evaluate() / rightNum -> evaluate();

    return 1.23456789;

}