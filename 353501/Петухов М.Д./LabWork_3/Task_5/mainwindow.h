#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include <QDir>
#include <QFileDialog>
#include <QTreeWidget>

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

  void countFoldersAndFiles(const QString& path, int& folderCount, int& fileCount);

private slots:
  QPair<long, long> setTree(const QString &folderPath, QTreeWidgetItem *parentItem);
  void open();

protected:
  Ui::MainWindow *ui;
};