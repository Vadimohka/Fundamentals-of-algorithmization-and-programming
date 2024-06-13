#include <QMainWindow>
#include "MyBST.h"
#include <qgraphicsscene.h>
#include <qguiapplication.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

  BSTGui* bstgui;

public:
  MainWindow();
  ~MainWindow();

  void fillList(const std::vector<BSTGui::Node> &nodes);

  private slots:
  void on_initBtn_clicked();
  void on_balanceBtn_clicked();
  void on_insertBtn_clicked();
  void on_removeBtn_clicked();
  void on_findBtn_clicked();

  void on_inOrderBtn_clicked();

  void on_depthBtn_clicked();

protected:
  Ui::MainWindow *ui;
};
