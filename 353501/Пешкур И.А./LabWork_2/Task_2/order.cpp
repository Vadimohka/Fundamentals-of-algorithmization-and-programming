#include "order.h"

Order::Order() {}

void Order :: setValue( long long newTable , QString newDish , long long newAmmount , long long newPrice )
{

    TableNumber = newTable;
    Dishes.push_back( newDish );
    Ammount.push_back( newAmmount );
    TotalPrice += newAmmount * newPrice;

}

QString Order :: getDishes()
{

    QString TotalDish = "";

    TotalDish += Dishes.at( 0 ) + "( " + QString :: number( Ammount.at( 0 ) ) + " )";

    for( long long i = 1 ; i < Dishes.size() ; ++ i )
    {

        TotalDish += ", " + Dishes.at( i ) + "( " + QString :: number( Ammount.at( i ) ) + " )";

    }

    return TotalDish;

}

long long Order :: getTable()
{

    return TableNumber;

}

long long Order :: getTotalPrice()
{

    return TotalPrice;

}
