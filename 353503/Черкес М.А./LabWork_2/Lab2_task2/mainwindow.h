#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <trains.h>
#include <QMainWindow>
#include <QVector>
#include <QLineEdit>
#include <QString>
#include <QMessageBox>
#include <QMouseEvent>

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
  QVector<Trains> trainsArray;
  void loadDataFromFile();
  void addTrain();
  bool checkInput(QLineEdit* lineEdit1, QLineEdit* lineEdit2, QLineEdit* lineEdit3, QLineEdit* lineEdit4);
  void mousePressEvent(QMouseEvent *event) override;
  void exitW();
  void saveDataToFile();
  void listSort();
};
#endif  // MAINWINDOW_H
