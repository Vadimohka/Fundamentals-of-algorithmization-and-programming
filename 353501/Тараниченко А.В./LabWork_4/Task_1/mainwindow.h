#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sort.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QElapsedTimer>
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
    void on_Quick_sort_clicked();

    void on_Heap_sort_clicked();

    void on_Merge_sort_clicked();

    void on_Input_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    std::vector<int> sortedArray;
    std::vector<int> array;

     void drawSort(int arraySize, qint64 elapsedTime);

     Sort sorter;


};
#endif // MAINWINDOW_H
