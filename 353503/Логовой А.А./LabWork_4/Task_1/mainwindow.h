#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <sortvisualizer.h>
#include <QRandomGenerator>
#include <QLayout>
#include <sort.h>
#include <sorttheard.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    static void skip(int ms);

private slots:
    void on_merge_sort_clicked();

    void on_quick_sort_clicked();

    void on_heap_sort_clicked();

    void on_interpolation_sort_clicked();

    void on_shuffle_clicked();

    void on_bin_search_clicked();

    void on_interpolation_search_clicked();

private:

    int size;

    int* arr;

    Ui::MainWindow *ui;

    SortVisualizer* sort_visualizer;

    SortThread* sorter;

};
#endif // MAINWINDOW_H
