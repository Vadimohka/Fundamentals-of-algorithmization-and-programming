#include "ToBin.h"
#include <cmath>
#include <qcontainerfwd.h>
#include <qdebug.h>
#include <qlogging.h>

QString ToBin::ConvertLongToBin(long long a) {
  if (a == 0)
    return "0";
  return ((a / 2 != 0) ? ConvertLongToBin(a / 2) : "") +
         (a % 2 == 0 ? "0" : "1");
}

QString ToBin::ConvertFracToBit(long double x) {
  if (std::isinf(x))
    return "";
  if (x < 1e-12)
    return "0";

  x *= 2;

  QString res = "0";
  if (x >= 1) {
    res = "1";
    x--;
  }

  return res + (x < 1e-12 ? "" : ConvertFracToBit(x));
}

QString ToBin::ConvertToBit(long double x) {
  bool isNeg = x < 0;
  if (isNeg)
    x = -x;

  long double dec = (long)x;
  long double frac = x - dec;

  qDebug() << (double)dec << (double)frac;

  QString decS = ConvertLongToBin(dec);
  QString fracS = ConvertFracToBit(frac);

  int ind = decS.indexOf('1');
  QString expS = ConvertLongToBin((decS.length() - ind - 1) + 65535);
  QString mantS = decS.sliced(ind + 1) + fracS;
  mantS = mantS.leftJustified(64, '0');
  mantS = mantS.sliced(0, 63);

  return QString(isNeg ? '1' : '0') + "   " + expS + "   " + mantS;
}