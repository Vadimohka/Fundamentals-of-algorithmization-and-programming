#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "heaparray.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void addNode();

private slots:

    void on_insert_btn_clicked();

    void on_remove_btn_clicked();

    void on_print_btn_clicked();

    void on_getMax_btn_clicked();

    void on_extrMax_btn_clicked();

private:
    Ui::MainWindow *ui;
    QTreeWidget *tree;

    HeapArray<int> heap;
};
#endif // MAINWINDOW_H
