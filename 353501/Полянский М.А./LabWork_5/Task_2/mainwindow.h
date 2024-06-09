#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include <qlineedit.h>

#include "customString.h"

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
  void setOutput(int n);
  void setTarget(const char* c);
  void setSource(const char* c);
 

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
  void on_chkbox_toggled(bool);


protected:
  Ui::MainWindow *ui;
  QLineEdit* tar;
  QLineEdit* sou;
};