#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>

#include "pair.h"
#include "../Task_4/vector.h"

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
    void pushBack1();
    void pushBack2();
    void popBack1();
    void popBack2();
    void insert1();
    void insert2();
    void erase1();
    void erase2();

    void table1Clicked(int row, int column);
    void table2Clicked(int row, int column);
    void populateTable1();
    void populateTable2();


private:
    int selectedRow = -1;
    int selectedCol = -1;
    int selectedTable = -1;
    
    Vector<int> firstVector;
    Vector<Pair<int, double>> secondVector;

protected:
    Ui::MainWindow *ui;
};
