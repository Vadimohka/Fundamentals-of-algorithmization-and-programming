#include "LongValidator.h"
#include <qvalidator.h>
#include <algorithm>

QValidator::State LongValidator::validate(QString &text, int &pos) const {
  bool accept = false;

  if(text.isEmpty() || text == '-'){
    accept = true;
  } else {

    bool ok;
    (void)text.toLong(&ok);
    int sizeBound = 
            (text[0] == '-' 
            ? 19 : 18);
    accept = ok && (text.size() <= sizeBound);
  }

  return accept ? QValidator::Acceptable : QValidator::Invalid;
   
 
}