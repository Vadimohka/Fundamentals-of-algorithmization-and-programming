#ifndef SOLVER_H
#define SOLVER_H

#include "HashTable.h"
#include <QString>
#include <QTableWidget>

class VisualMap : public HashMap<QString> {
public:
  VisualMap();
  ~VisualMap();

  void randomize();

  void fillEntries(QTableWidget *entries);

  long countAboveAverage();

private:
  long calculateTotalSum();
};

#endif // SOLVER_H
