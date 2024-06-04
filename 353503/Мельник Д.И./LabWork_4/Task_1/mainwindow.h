#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "visual.h"

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();
 public slots:
  void updateScene();
 private slots:
  void on_lineEdit_2_textChanged(const QString& arg1);

  void on_lineEdit_textChanged(const QString& arg1);

  void on_pushButton_clicked();

  void on_radioButton_2_toggled(bool checked);

  void on_radioButton_toggled(bool checked);

  void on_radioButton_3_toggled(bool checked);

 private:
  Ui::MainWindow* _ui;
  QGraphicsScene* _scene;
  Visual* _visual;

  bool isQuick = false;
  bool isHeap = false;
  bool isMerge = false;
};
#endif  // MAINWINDOW_H
