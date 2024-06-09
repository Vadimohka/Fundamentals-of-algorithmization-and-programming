#pragma once

#include <QMainWindow>
#include <memory>
#include <QLibrary>
#include "Heap.h"
#include <qgraphicsscene.h>

class VisualBST;

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
  void update();

public slots:
  void randomize();

protected:
  Ui::MainWindow *ui;
  std::unique_ptr<Heap> bst;
  QLibrary lib;
};