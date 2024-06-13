#include <reverse.h>
#include <magicnumbers.h>

int reverse(int number, int rev = 0) {

    if (number == 0){
        return rev;
    }

    else{
        return reverse(number / TEN, rev * TEN + number % TEN);
    }
}
