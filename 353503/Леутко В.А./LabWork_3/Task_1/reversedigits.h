#ifndef REVERSEDIGITS_H
#define REVERSEDIGITS_H

class ReverseDigits
{
public:
    ReverseDigits();
    static int reverse(int n);
private:
    static int reverseRecursive(int n, int reversed);
};

#endif // REVERSEDIGITS_H
