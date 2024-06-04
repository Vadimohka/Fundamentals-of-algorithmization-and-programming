#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include <QGraphicsRectItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{

  
    Q_OBJECT

private:
  int viewWidth;
  int viewHeight;

  bool wasSorted = false;

public: 
  MainWindow();

  QGraphicsScene* scene;

  void heapify(QVector<int> &arr, int N, int i);
  // Main function to do heap sort
  void heapSort();

  void merge(QVector<int> &arr, int const left, int const mid,
           int const right);
  void mergeSort(QVector<int> &arr, int const begin, int const end);

  QVector<int> array;

  QVector<QGraphicsRectItem*> arrayRect;

  void printArray(QVector<int> &arr, int N);

  void initArray();

  int size = 0;

  void visualize();
  void visualize(int ind1toSwap, int ind2toSwap);

  int partition(QVector<int> &arr, int low,int high);  
  void quickSort(QVector<int> &arr, int low,int high);

  int binarySearch(int left, int right, int x);

  void blockButtons();
  void unblockButtons();
public slots:
  void startMergeSort(); 
  void startQuickSort();
  void startHeapSort();  
  void startSearch();

protected:
  Ui::MainWindow *ui;
};