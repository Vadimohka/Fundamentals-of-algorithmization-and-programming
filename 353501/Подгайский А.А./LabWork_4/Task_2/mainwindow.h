#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "SortVisualiser.h"
#include <QScopedPointer>
#include <QElapsedTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

  SVector elements;
  bool isActive = false;
  QScopedPointer<SortVisualiser> visualiser;
  QScopedPointer<QElapsedTimer> timer;

  const size_t ELEMENTS_SIZE = 1e4;


private:
  void fillTestData();
  void clearBinpowLabels();

public:
  MainWindow();

protected:
  void closeEvent(QCloseEvent* event) override;

private slots:
  void startSort();
  void startSearch();
  void reset();

protected:
  Ui::MainWindow *ui;
};