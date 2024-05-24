#ifndef AKERMANNFUNCTION_H
#define AKERMANNFUNCTION_H

class AkermanFunction
{
private:
    int _m{0};
    int _n{0};

    int recursiveCalculation(int m, int n);
public:
    AkermanFunction();

    void setFirstArg(int m);
    void setSecondArg(int n);

    int getFirstArg();
    int getSecondArg();
    int startCalculation();
};

#endif // AKERMANNFUNCTION_H
