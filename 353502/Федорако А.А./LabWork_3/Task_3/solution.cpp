#include "solution.h"

Solution::Solution()
{

}

int Solution::functionReverce(int n)
{
   int degree = log10(n);
   if (n == 0) {
      return 0;
   }
   else {
      return (n % 10) * pow(10, degree) + functionReverce(n / 10);
   }
}

int Solution::pow(int a, int b) {
    if(b == 0) {
        return 1;
    }
    else return a * pow(a, b - 1);
}

int Solution::log10(int number, int result) {
    if(number < 10) {
        return result;
    }
    else {
        return log10(number / 10, result + 1);
    }
}
