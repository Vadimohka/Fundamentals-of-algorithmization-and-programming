#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

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
  void pre_decimal();
  void decimal_to_binary(int n);
  void pre_accerman();
  int accerman(int m, int n);
  void pre_rotate_number();
  int rotate_number(int number, int temp);
  int g = 2 + 4 * 2;
  void pre_hanoi();
  void hanoi(int quantity, int from = 1, int to = 3, int buf_peg = 2);
};
#endif  // MAINWINDOW_H
