#include "Reverse.h"

unsigned long long Reverse::reverse(unsigned long long number, unsigned long long output){

    if(number == 0){
        return output;
    }
    else{
        unsigned long long lastDigit = number % 10;
        return reverse(number / 10, output * 10 + lastDigit);
    }
}
