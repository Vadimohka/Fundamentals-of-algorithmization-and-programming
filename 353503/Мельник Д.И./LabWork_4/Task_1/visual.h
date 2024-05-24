#ifndef VISUAL_H
#define VISUAL_H

#include <QGraphicsItem>
#include <QObject>
#include <QRandomGenerator>
#include <QVector>
#include <QPair>

class Visual : public QObject {
  Q_OBJECT
 private:
  QRandomGenerator* _randomGer;
  QVector<QGraphicsRectItem*> _items;

  int _speed = 50;

  void quickSort(int low, int high);
  int partition(int low, int high);
  void mergeSort(int l, int r);
  void merge(int l, int m, int r);
  void heapSort(int n);
  void heapify(int n, int i);

 public:
  Visual();
  void createItem(const int& count);
  void swapItem(const int& ind1, const int& ind2);
  void setSpeed(const int &speed);

  void quickSortStart();
  void heapSortStart();
  void mergeSortStart();
  void endSort();

  QVector<QGraphicsRectItem*> GetItems();

 signals:
  void updatedScene();
};

#endif  // VISUAL_H
