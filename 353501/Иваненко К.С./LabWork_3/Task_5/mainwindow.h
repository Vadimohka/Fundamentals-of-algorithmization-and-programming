#pragma once

#include <QMainWindow>
#include <QFile>

namespace fs = std::filesystem;


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
      
public:
  int fileCount;
  int folderCount;
  QTimer *timer;
  QFile *file;
  void calculate();
  MainWindow();
  ~MainWindow();

protected:
  Ui::MainWindow *ui;
};
