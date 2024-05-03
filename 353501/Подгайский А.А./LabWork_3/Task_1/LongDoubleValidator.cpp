#include "LongDoubleValidator.h"
#include <stdexcept>
#include <string>


bool LDValidator::checkInput(QString input) {
  bool passed_e = false, passed_dot = false, passed_digit = false;
  if (input.isEmpty())
    return false;

  bool sign = (input[0] == '-');
  if (sign && input.size() == 1)
    return false;

  // i is 1 if signed, 0 if no;
  for (long long i = (long long)sign, sz = input.size(); i < sz; ++i) {
    QChar c = input[i];
    if (c == 'e' && (passed_e || i == sz - 1 || i == sign || !passed_digit)) {
      return false;
    } else if (c == 'e') {

      passed_e = true;
      continue;
    }

    if (c == '.' && (passed_dot || i == sz - 1 || passed_e)) {
      return false;
    } else if (c == '.') {

      passed_dot = true;
      continue;
    }
    if (c == '-' && input[i - 1] == 'e' && i != sz - 1)
      continue;

    if (c >= '0' && c <= '9') {
      passed_digit = true;
      continue;
    }

    // checked all valid thingies
    return false;
  }

  //overflow check
  try{
    (void)std::stold(input.toStdString());
  } catch (...) {
    return false;
  }

  return true;
}
