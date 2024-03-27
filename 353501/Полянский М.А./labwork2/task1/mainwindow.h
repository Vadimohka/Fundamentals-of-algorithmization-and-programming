#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include <QFile>
#include "date.h"

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
private:
  void getRow(); 
  void onNewClick();
  void updateTable();
  void onOpenClick();
  void loadFile(QByteArray contents);
  void selectRow();
  void deleteRow();
  void updateInfo();
  
private slots:
  void addNew();
  void edit();
  void updateRow(int row);

protected:
  Ui::MainWindow *ui;
  QVector<Date> datesList;
  QFile* file =nullptr;
  QVector<int> filePos;
  int selRow;
};