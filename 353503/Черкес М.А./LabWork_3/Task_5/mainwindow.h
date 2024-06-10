#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidget>
#include <QMainWindow>

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = nullptr);
  ~MainWindow() override;

 private:
  Ui::MainWindow* ui;
  void countFoldersAndFiles(const QString& path, int& folderCount,
                            int& fileCount, QListWidget* listWidget,
                            int64_t level = 0);
  void pre_countFiles();
  void OpenDirectory();
  QString openedFolderPath;
  void openSelectedFile();
};
#endif  // MAINWINDOW_H
