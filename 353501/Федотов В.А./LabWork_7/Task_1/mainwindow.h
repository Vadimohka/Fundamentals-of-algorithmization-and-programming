#pragma once

#include "deque.h"

#include <QMainWindow>
#include <qgraphicsscene.h>
#include <qtablewidget.h>

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
    void pushFront();
    void pushBack();
    void popFront();
    void popBack();
    
    void convertToRing();

    void moveForward();
    void moveBackward();

    void updateTable();


protected:
    const int MAX_VAL = 99;

    TraversableDeque<int> *deque;
    QTableWidget *table;
    Ui::MainWindow *ui;
};
