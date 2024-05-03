#include <QString>

class Converter{

    static const int MANT_LEN = 64;
    static const int EXP_LEN = 15;
    static const int EXP_BIAS = (1 << (EXP_LEN-1)) - 1;

private:
    static bool checkInput(QString s);
    static QPair<QString, QString> getBinIntAndFrac(long double num);
    static QString toSimpleBin(long double num);
    static QString fracToBin(long double num);
    static int findFirst1Pos(const QPair<QString, QString>& int_frac);

public:
    static QString toIEE754(long double num);
};