#ifndef SHIP_H
#define SHIP_H

struct Ship
{
    int staff=0;
    char type='U'; //W - warship P - passenger C - cargo F - fishing Y - yacht U-undefined
    bool sank=false;
    double cost=0;

    char* name;
    long long attributes[2];//Lifting capacity displacement

};


#endif // SHIP_H
