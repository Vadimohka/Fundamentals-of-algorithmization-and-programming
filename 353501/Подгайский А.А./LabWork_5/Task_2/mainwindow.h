

#include <QMainWindow>
#include <qgraphicsscene.h>

#include <qlineedit.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

  private:
    QLineEdit* target;
    QLineEdit* source;
  
public:
  MainWindow();
  ~MainWindow();

private:
  void setOutput(int n);
  void setTarget(const char*);
  void setSource(const char*);


private slots:
  void on_scmp_clicked();
  void on_sncmp_clicked();
  void on_scoll_clicked();
  void on_scpy_clicked();
  void on_sncpy_clicked();
  void on_scat_clicked();
  void on_sncat_clicked();
  void on_slen_clicked();
  void on_stok_clicked();
  void on_strxfrm_clicked();
  void on_serr_clicked();

  void on_chkBox_toggled(bool);

protected:
  Ui::MainWindow *ui;
};