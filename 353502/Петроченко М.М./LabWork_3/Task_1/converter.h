
#ifndef LAB3_TASK1_CONVERTER_H_
#define LAB3_TASK1_CONVERTER_H_

#include <QString>

const long double LD_PRECISION_FLOOR = 1e-17;

class Converter {
    static QString ldToBin(long double);
    static QString llToBin(int64_t);

   public:
    static QString toBin(long double);
};


#endif  //LAB3_TASK1_CONVERTER_H_
