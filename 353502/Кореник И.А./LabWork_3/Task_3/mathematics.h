#ifndef MATHEMATICS_H
#define MATHEMATICS_H


class Mathematics
{
public:
    Mathematics();

    int inverse (int number);

private:
    int digitsCount(int number);

    int _inverse (int number, int digits);

    int binPow(int a, int n);
};

#endif // MATHEMATICS_H
