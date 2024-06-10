#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <mydate.h>
#include <QDebug>
#include <QFileDialog>
#include <QMainWindow>
#include "QListWidget"

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

 private:
 private slots:
  void on_listWidgetItem_clicked(QListWidgetItem* item);
  void onDateChanged(const QDate& date);
  void onDateChanged2(const QDate& date);
  void readFromFileAndWriteToDate(QString filePath, QList<MyDate>& dates);
  void on_pushButton_pressed();
};
#endif  // MAINWINDOW_H
