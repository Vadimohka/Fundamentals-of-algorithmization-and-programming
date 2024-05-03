#pragma once

#include "hanoiGraphics.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <qtablewidget.h>
#include "ui_mainwindow.h"
#include <qcontainerfwd.h>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <qnamespace.h>
#include <qpushbutton.h>
#include <qspinbox.h>
#include <qthread.h>

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

private slots:
    void start();
    void resetDisks();
    void changeSpeed(int speed);


private:
    QGraphicsScene *scene;
    HanoiGraphics *graphics;
  
protected:
    Ui::MainWindow *ui;
};
