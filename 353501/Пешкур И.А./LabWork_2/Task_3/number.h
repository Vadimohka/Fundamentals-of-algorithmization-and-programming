#include "expression.h"

class Number : public Expression{

private:

    double numb;

public:

    Number( double numb );
    double evaluate() override;

};