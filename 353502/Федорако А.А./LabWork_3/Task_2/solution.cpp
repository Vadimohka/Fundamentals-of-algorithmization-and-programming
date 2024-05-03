#include "solution.h"

Solution::Solution()
{

}

long Solution::functionAckerman(int firstNumber, int secondNumber) {

    if(firstNumber == 0) return secondNumber + 1;
    else if(firstNumber > 0 && secondNumber == 0) return functionAckerman(firstNumber - 1, 1);
    else return functionAckerman(firstNumber-1,functionAckerman(firstNumber, secondNumber-1));
}
