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

  int index = -2;

public: 
  MainWindow();

  QGraphicsScene* scene;

  bool wasSorted = false;

  std::vector<int> array;

  QVector<QGraphicsRectItem*> arrayRect;

  void printArray(std::vector<int> &arr, int N);

  void initArray();

  int size = 0;

  int binarySearch(int l, int r, int x);

  int binpow (int digit, int power, int mod);
  void startSearch();

  void visualize(std::vector<int>& array);
  void visualize();
  void visualize(int ind1toSwap, int ind2toSwap);
  void interpolationSort(std::vector<int>& arr, int start, int size);
public slots:
  void startSort();

protected:
  Ui::MainWindow *ui;
};