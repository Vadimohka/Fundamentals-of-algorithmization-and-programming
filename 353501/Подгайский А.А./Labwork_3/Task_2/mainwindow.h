#pragma once

#include <QMainWindow>
#include <_types/_uint32_t.h>
#include <qgraphicsscene.h>
#include <QFutureWatcher>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
  Q_OBJECT

  QFutureWatcher< std::optional<uint32_t> > watcher;
// private:
//   const static int[] c_Limits = {100'000'000, }
  
public:
  MainWindow();

private slots:
  void calculate();
  void changeValue();

protected:
  Ui::MainWindow *ui;
};