#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QStringList>
#include <QVBoxLayout>

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
  void interpolationSort(QVector<int>& arr);
  void handleButtonClick();
  int binpow(int digit, int powder, int mod);
  void search();
  void clear();

 private:
  Ui::MainWindow* ui;
};
#endif  // MAINWINDOW_H
