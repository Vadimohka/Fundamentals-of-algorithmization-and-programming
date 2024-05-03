#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "date.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QFileDialog>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <qcontainerfwd.h>
#include <qdatetime.h>
#include <qdebug.h>
#include <qtablewidget.h>
#include <QEvent>

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
  void on_tableWidget_itemSelectionChanged();
  void on_openFile_clicked();       
  void updateTable();
  void on_userDateChanged();
  
private:
  QFile *newFile;
  bool event(QEvent *e);

protected:
  Ui::MainWindow *ui;    
  QVector<Date> dates;
   QString filePath = QFileDialog::getOpenFileName(this, "Open Text File", "",
                                                  "Text Files (*.txt)");
};