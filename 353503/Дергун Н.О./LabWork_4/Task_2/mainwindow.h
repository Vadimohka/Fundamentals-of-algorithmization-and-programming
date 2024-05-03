#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGridLayout>
#include <QMainWindow>
#include "arraytable.h"
#include "sort.h"
#include "sortvisualizer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    int* _array = nullptr;
    int _size = 0;

    ArrayTable* _table;
    SortVisualizer* _visualizer;
    VSort* _sorts;
    QGridLayout* _mainLayout;

    void makeBtnsActive(bool status);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void slotSetArray();
    void slotMergeSort();
    void slotHeapSort();
    void slotQuickSort();
    void slotInterpolationSort();
    void slotFinish();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
