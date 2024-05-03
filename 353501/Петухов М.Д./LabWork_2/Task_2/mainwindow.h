#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include <QMessageBox>
#include "Dish.h"
#include "order.h"
#include <QFileDialog>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui {
  class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
  std::vector <Dish> menu;
  std::vector <Order> orders;
  bool wasInMenuCheck(const QString DishName);
  int findOrderInMenu(const QString calcDishName);
  void drawMenu();
  QString path;
public:
  MainWindow();

private slots:
  void addOrder();
  void addDish();
  void sortMenu();
  void calculateCheck();
  void sortByPopularity();
  void change();
  void openFile();
  void deleteOrder();
  void saveFile();
  void cancelOrder();
protected:
  Ui::MainWindow *ui;
};