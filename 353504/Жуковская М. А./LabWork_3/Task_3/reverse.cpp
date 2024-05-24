#include "reverse.h"

Reverse::Reverse()
{

}

int Reverse::recursion(int n, int a){
    if(n==0){
        return a;
    }
    else{
        return recursion(n/10, 10*a + n%10);
    }
}
