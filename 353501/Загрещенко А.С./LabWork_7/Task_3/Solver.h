#include "HashMap.h"
#include <QString>
#include <qcontainerfwd.h>
#include <qtablewidget.h>

class Solver: public HashMap<QString> {
public:
  Solver();
  ~Solver();

  void randomize();
  
  void fillEnties(QTableWidget *entries);

  long findTotalLen();
};