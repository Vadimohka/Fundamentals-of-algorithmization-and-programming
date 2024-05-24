#ifndef TOBINARY_H
#define TOBINARY_H
#include<QString>
#include<stdio.h>
class ToBinary
{
private:
    int sch=0;
    bool fl1=0;
    int exp=0;
public:
    QString get_first_bit(QChar);
    double get_exp1(double);
    double get_exp2(double);
    double get_normalized(double);
    double get_normalized1(double);
    QString convert_ch(double);

    QString convert_c(double);
};

#endif // TOBINARY_H
