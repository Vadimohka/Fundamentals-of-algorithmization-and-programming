#include "Map.h"
#include <QMainWindow>
#include <qgraphicsscene.h>
#include <qguiapplication.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

  MapInspector* bstgui;

public:
  MainWindow();
  ~MainWindow();

private slots:
  void on_initBtn_clicked();
  void on_insertBtn_clicked();
  void on_removeBtn_clicked();
  void on_findBtn_clicked();

protected:
  Ui::MainWindow *ui;
};