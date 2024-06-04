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

public: 
  MainWindow();

  QVector<int> array;
  QVector<int> median;

  int size = 0;


  QString toString(QVector<int> arr, bool toMedian);
  void initArray();
  void quickSort(QVector<int> &array, int low, int high);
  int partition(QVector<int> &arr, int low, int high);
  void printArray(QVector<int> &arr, int N);
  void ToMedian();
protected:
  Ui::MainWindow *ui;
};