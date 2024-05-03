#pragma once

#include "student.h"
#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <qgraphicsscene.h>
#include <qlist.h>
#include <qspinbox.h>
#include <qtablewidget.h>

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

private slots:
  void handleAdd();
  void handleEdit();
  void handleDelete();
  void handleItemClicked(QTableWidgetItem *item);

  void populateTable(const QList<Student> &list);

  void sortByName();
  void sortByAvg();
  void showBest();
  void resetSort();
  void search();

  bool checkFields();

  void saveFile();
  void openFile();

private:
  int index;
  QList<Student> studentList;
  QList<Student> sortedList;
  QList<Student> searchList;
  
protected:
  Ui::MainWindow *ui;
};