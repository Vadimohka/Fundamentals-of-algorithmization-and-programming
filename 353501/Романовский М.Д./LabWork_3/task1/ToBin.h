#include <QString>

struct Res {
  QString sign;
  QString exp;
  QString mant;
};

class ToBin {
public:
  static QString ConvertLongToBin(long long x);
  static QString ConvertFracToBit(long double x);

  static QString ConvertToBit(long double x);
};