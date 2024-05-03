#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include <QFileSystemModel>
#include <QFuture>
#include <QFutureWatcher>
#include "FileSystemModel.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

    FileSystemModel* model = nullptr;
    QFutureWatcher<long> watcher;
  
public:
  MainWindow();

private slots:
  void openDir();
  void countElements();
  void setNumberOfElements();



protected:
  Ui::MainWindow *ui;
};