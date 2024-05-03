#include <iostream>
#include "expression.h"
#include "binaryoperation.h"
#include "number.h"

bool checkIfEquals( Expression const* first , Expression const* second )
{

    return *( void*** )first == *( void*** )second;

}

int main(){

    Expression* sube = new BinaryOperation( new Number( 4.5 ) , '*' , new Number( 5 ) );
    Expression* expr = new BinaryOperation( new Number( 3 ) , '+' , sube );

    std :: cout << expr -> evaluate() << "\n";

    delete expr;

    std :: cout << checkIfEquals( new Number( 3 ) , new Number( 2 ) ) << "    " << checkIfEquals( new BinaryOperation( new Number( 3 ) , '+' , new Number( 3 ) ) , new Number( 5.5 ) ) << "\n";


    return 0;

}