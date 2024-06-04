#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include <QGraphicsRectItem>
#include "Vector.h"
#include "pair.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
  
    Q_OBJECT

public: 
  MainWindow();

  void on_pushButton_clicked();

    void on_pushButton_at_clicked();

    void on_pushButton_capacity_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_empty_clicked();

    void on_pushButton_maxSize_clicked();

    void on_pushButton_popBack_clicked();

    void on_pushButton_size_clicked();

    void on_pushButton_data_clicked();

    void on_pushButton_pushBack_clicked();

    void on_pushButton_resize_clicked();

    void on_pushButton_reserve_clicked();

    void on_pushButton_erase_clicked();

    void updateVec();

    void on_pushButton_begin_clicked();

    void on_pushButton_end_clicked();
protected:
  Ui::MainWindow *ui;
  Vector<Pair<Vector<int>, Vector<Pair<int,double>>>> pair;
  Vector<int> vec;
};