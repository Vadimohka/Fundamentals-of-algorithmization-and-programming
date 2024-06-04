#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QElapsedTimer>
#include <QMainWindow>
#include <QMessageBox>

#include "arraytable.h"
#include "sort.h"
#include "search.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
    void sendWarning() const;

    int *_array = new int[1];
    int _arrSize = 1;
    int _capacity = 1;
    Ui::MainWindow *ui;
    ArrayTable* _table;
    QElapsedTimer* _timer;

    void setEnable(bool status);
    void startSort();
    void endSort(int time);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void slotArrayChanged();
    void slotMergeSort();
    void slotHeapSort();
    void slotQuickSort();
    void slotInterpolationSort();
    void slotBinarySearch();
};
#endif // MAINWINDOW_H
