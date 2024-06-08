#include "HashTable.h"
#include <QString>
#include <qcontainerfwd.h>
#include <qtablewidget.h>

class Solution: public HashTable<QString> {
public:
  Solution();
  ~Solution();

  void randomize();

  void fillEnties(QTableWidget *entries);

  long findTotalLen();
};
