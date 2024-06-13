#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include "Queue.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
    Queue<int> queue;
    QString output;
    void addItem(QString);
public:
  MainWindow();

private slots:
void pushBackSlot();
void pushFrontSlot();
void popBackSlot();
void popFrontSlot();
void clearSlot();
void swapMinAndMax();
protected:
  Ui::MainWindow *ui;
};