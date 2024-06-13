#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "binary_array_heap/binary_array_heap.h"
#include "binary_list_heap/binary_list_heap.h"

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

private slots:
    void on_extractMaxPushButton_clicked();

    void on_getMaxPushButton_clicked();

    void on_insertPushButton_clicked();

private:
    Ui::MainWindow *ui;
    BinaryArrayHeap arrayBinHeap;
    BinaryListHeap listBinHeap;
    void printHeapAsArray(BinaryArrayHeap &h);
};

#endif // MAINWINDOW_H
