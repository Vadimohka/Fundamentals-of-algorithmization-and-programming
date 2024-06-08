#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qgraphicsscene.h>
#include <climits>
#include "myhashtable.h"

class MyHashTable;

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
    void update();

protected:
    Ui::MainWindow *ui;
    MyHashTable *myhashtable;

private slots:
    void on_randBtn_clicked();
    void on_clearBtn_clicked();
    void on_getBtn_clicked();
    void on_setBtn_clicked();
    void on_delBtn_clicked();

};
#endif // MAINWINDOW_H
