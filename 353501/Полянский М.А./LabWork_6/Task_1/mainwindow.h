#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "Kidtoy.h"
#include <QPrintDialog>
#include <QPrinter>
#include <qcheckbox.h>
#include <qlineedit.h>
#include <qnamespace.h>
#include <qpushbutton.h>
#include <qspinbox.h>
#include <QPainter>

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
  void fillData();

private slots:
  void on_print_clicked();

protected:
  Ui::MainWindow *ui;
  KidToy* kidtoy = new KidToy;
};