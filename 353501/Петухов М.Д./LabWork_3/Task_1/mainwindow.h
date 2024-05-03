#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
  QString IntToBin(long long value);
  QString RealToBin(long double value);
  QString ToBin(double value);
  QString ToIEEE(long double value);
public:
  MainWindow();
  long double value;

private slots:
  void binarySetText();

protected:
  Ui::MainWindow *ui;
};