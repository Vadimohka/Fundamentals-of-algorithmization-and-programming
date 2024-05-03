#include <QString>

class BinaryConverter {
    
    union DoubleBits {
        double value;
        struct {
            unsigned long long mantissa : 52;
            unsigned long long exponent : 11;
            unsigned long long sign : 1;
        } raw;
    };

public:
    BinaryConverter(double val);

    QString getSign();
    QString getExponent();
    QString getMantissa();
    QString getBinary();    

private:
    QString sign;    
    QString mantissa;
    QString exponent;
    QString s_Value;
    QString getBinaryString(unsigned long long n, int bits);
};