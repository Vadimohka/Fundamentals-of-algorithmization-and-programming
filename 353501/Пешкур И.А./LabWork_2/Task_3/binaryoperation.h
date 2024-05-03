#include "expression.h"

class BinaryOperation : public Expression{

private:

    Expression* leftNum;
    Expression* rightNum;
    char binOperator;

public:

    BinaryOperation( Expression* leftNum , char binOperator , Expression* rightNum );
    ~BinaryOperation();
    double evaluate() override;

};