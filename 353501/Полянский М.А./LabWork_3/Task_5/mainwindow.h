#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "Counter.h"
#include "folderView.h"
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
  void onPushButton();
 

protected:
  Ui::MainWindow *ui;
  FoldersView* fold;
};